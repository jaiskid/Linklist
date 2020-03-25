#include<bits/stdc++.h>
using namespace std;
bool inverse(int *arr,int n){
	for(int i=0;i<n;i++){
	if(arr[arr[i]]!=i){
	return false;
	}
	}
	return true;
}
int main(){
	int n;
	cin>>n;
	int arr[10005];
	for(int i=0;i<n;i++){
	cin>>arr[i];
	}
	if(inverse(arr,n)){
		cout<<"true";
	}
	else{
		cout<<"false";/
	}

}