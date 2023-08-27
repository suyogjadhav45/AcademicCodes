#include <iostream>
#include<math.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int n,x;
	    int arr[n];
	    cin>>n>>x;
	    int max=0;
	    for(int j=0;j<n;j++){
	        cin>>arr[j];
	        
	    }
	    for(int k=0;k<n;k++){
	        if(arr[k]>0){
	            x=x+arr[k];
	            max=x;
	        }
	        else{
	            x=x-arr[k];
	        }
	    }
	    cout<<max<<endl;
	    
	    
	}
	return 0;
}
