#include<iostream>

using namespace std;

int CheckMatch(int a){
	if(a!=-1){
		cout<<"Match is found";
	}else{
		cout<<"Match is not found";
	}
}


int binarySearch(int arr[],int l,int r,int x){
	if(r>=l){
		int mid = l + (r-1)/2;
		if(arr[mid]==x)
			return mid;
		if(arr[mid]>x)
			return binarySearch(arr,l,mid-1,x);	
		else
			return binarySearch(arr,mid+1,r,x);
	}
	return -1;
	//we return -1 if the element is not found
}


int main(){
	//we can either input a array by user input or 
	//for the simplicity I use the pre defined array for the search
	int ans,num;
	int arr[]={45,21,78,11,6,90};
	
	cout<<"Input the number to search : ";
	cin>>num;
	
	ans = binarySearch(arr,0,6,num);
	CheckMatch(ans);
	
	
	return 0;
}
