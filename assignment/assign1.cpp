#include<bits/stdc++.h>

using namespace std;

int main() {
	int t,n,i;
	cout<<"Enter t: "<<endl;
	cin>>t;
	
	while(t--) {
		cin>>n;
		
		int arr[n+1];
		
		for(i=0;i<n;i++) {
			cin>>arr[i];
		}
		
		sort(arr,arr+n);
		
		int max1 = INT_MIN;
		int max2 = INT_MIN;
		
		for(i=0;i<n;i++) {
			if(arr[i]>max1) {
				max2 = max1;
				max1 = arr[i];
			}
		}
		
		for(i=0;i<n;i++) {
			if(arr[i]!=max1 && arr[i]!=max2) {
				cout<<arr[i]<<" ";
			}
		}
		
		
	}
	
	
	return 0;
}
