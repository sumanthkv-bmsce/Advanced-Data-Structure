#include<bits/stdc++.h>

using namespace std;

int main() {
	
	int l,r,i;
	
	cout<<"Enter "<<endl;
	cin>>l>>r;
	bool isvisited[10];
	
	
	
	for(i=l;i<=r;i++) {
		
		for(int j=0;j<=9;j++) {
			isvisited[j] = false;
		}
		
		int flag = 1,num = i;
		
		while(num) {
			int rem = num%10;
			
			if(isvisited[rem]==true) {
				flag = 0;
				break;
			}
			
			isvisited[rem] = true;
			
			num/=10;
		}
		
		if(flag==1) {
			cout<<i<<" ";
		}
		
		
	}
	
	return 0;
}
