#include <bits/stdc++.h>
using namespace std;
int main() {
	long long t,N;
	cin>>t;
	while(t--){
	    cin>>N;
	    long long min=1000000001;
	    long long int a=0,b=0,c=0,flag=0,plag=0,pa=0,pb=0;
	    long long int arr[N]={0},brr[N]={0};
	    vector<long long int> vec;
	    for(long long int i=0;i<N;++i){
	        cin>>arr[i];
	    }
	    for(long long int i=0;i<N;++i){
	        cin>>brr[i];
	    }
	    sort(arr,arr+N);
	    sort(brr,brr+N);
	    for(long long int i=0;i<2*N;++i)
	    {
	        if(arr[i]<min)min=arr[i];
	        if(brr[i]<min)min=brr[i];
	        if(arr[pa]==brr[pb])
	        {
	            pa++;
	            pb++;
	        }
	        else if(arr[pa]>brr[pb])
	        {
	           
	            vec.push_back(brr[pb]);
	            pb++;
	        }
	        else if(arr[pa]<brr[pb]){
	          
	            vec.push_back(arr[pa]);
	            pa++;
	            
	        }
	        if(pa==N){
	            for(int i=pb;i<N;++i){
	               
	               vec.push_back(brr[i]);    
	            }
	            break;
	        }
	        if(pb==N){
	            for(int i=pa;i<N;++i){
	               vec.push_back(arr[i]);    
	            }
	            break;
	        }
	    }
	    long long int sum=0;
	    sort(vec.begin(), vec.end()); 
	    for(int i=0;i<vec.size()/2;++i){
	        if(vec[2*i]!=vec[2*i+1])
	            flag=1;
	     }
	     
	    for(int i=0;i<vec.size()/2;++i){
	        sum+=vec[i];
	    }
        if(vec.size()%2!=0){
            cout<<-1;
        }
        else if(flag){
             cout<<-1<<endl;
         }	    
        else{
            if(((vec.size()/2)*min)<sum/2)
            cout<<((vec.size()/2)*min)<<"\n";
            else if(sum%2==0)
            cout<<sum/2<<endl;
            else 
            cout<<-1;
         }
	    
	}
}
