#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,n;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int cnt=0;
        for(int i=0;i<n;i++)
            if(s[i]=='*')
                cnt++;
        int i=0,sum=0,ans=0;
        while(2*sum<cnt)
        {
            if(s[i]=='*')
                sum++;
            if(s[i]=='.')
                ans+=sum;
            i++;
        }
        int sum2=0,j=n-1;
        while(j>=i)
        {
            if(s[j]=='*')
                sum2++;
            else
                ans+=sum2;
            j--;
        }
        cout<<ans<<endl;
    }
}
