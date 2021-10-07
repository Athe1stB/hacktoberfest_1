#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll partition(vector<ll>&a,ll low,ll high){
	ll i=low,pivot=a[high];
	for(ll j=low;j<high;j++){
		if(a[j]<pivot){
			swap(a[i],a[j]);
			i++;
		}
	}
	swap(a[i],a[high]);
	return i;
	
}

void quickSort(vector<ll>&a,ll low,ll high){
	if(low<high){
		ll pi=partition(a,low,high);
		quickSort(a,low,pi-1);
		quickSort(a,pi+1,high);
	}
}



int main(){
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll>a(n);
		for(ll i=0;i<n;i++){
			cin>>a[i];
		}
		quickSort(a,0,n-1);
		for(ll i=0;i<n;i++){
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
