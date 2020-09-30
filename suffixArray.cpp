#include <bits/stdc++.h>
#define fst ios_base::sync_with_stdio(false); cin.tie(NULL); 
#define chk(x) cout << (#x) << " is " << (x) << endl
#define ll long long
using namespace std;

void count_sort(vector<int> &p, vector<int> &c) {
    int n = p.size(), i;
    vector<int> pos(n, 0), p_new(n);
    for(i = 0; i < n; ++i)
        pos[c[i]]++;
    for(i = 0; i < n; ++i)
        pos[i] += pos[i-1];
    pos.insert(pos.begin(), 0);
    for(auto k : p) {
        p_new[pos[c[k]]] = k;
        ++pos[c[k]];
    }
    p = p_new;
}

int main() {
    string s;
    cin >> s;
    s += "$";
    int n = s.size(), i, k = 0;
    vector<int> p(n), c(n), c_new(n);
    vector<pair<char, int>> a(n);
    for(i = 0; i < n; ++i) 
        a[i] = {s[i], i};
    sort(a.begin(), a.end());
    for(i = 0; i < n; ++i) 
        p[i] = a[i].second;
    for(c[p[0]] = 0, i = 1; i < n; ++i) 
        if(a[i].first == a[i-1].first)
            c[p[i]] = c[p[i-1]];
        else
            c[p[i]] = c[p[i-1]] + 1;
    while((1<<k) < n && c[p[n-1]] != n-1) {
        for(i = 0; i < n; ++i) 
            p[i] = (p[i] - (1<<k) + n) % n;
        count_sort(p, c);
        for(c_new[p[0]] = 0, i = 1; i < n; ++i) 
            if(c[p[i-1]] == c[p[i]] && c[(p[i-1] + (1<<k))%n] == c[(p[i] + (1<<k))%n])
                c_new[p[i]] = c_new[p[i-1]];
            else
                c_new[p[i]] = c_new[p[i-1]] + 1;
        ++k;
        c = c_new;
    }
    for(i = 0; i < n; ++i)
        cout << p[i] << " ";
}