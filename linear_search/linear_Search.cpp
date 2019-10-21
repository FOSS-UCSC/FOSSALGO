#include<iostream>

using namespace std;

int search(int arr[],int n,int x){
	for(int k=0;k<n;k++){
		if(arr[k]==x){
			return k;
		}
	}
	return -1;//if the match is bot found
}


int main(){
	int num;
	int array[]={90,70,40,500,10,67,11};
	//input what number you need to search
	cout<<"Input the number to search : ";
	cin>>num;
	
	int res = search(array,7,num);
	if(res!=-1){
		cout<<"Match is found";
	}else{
		cout<<"Match is not found";
	}
	
	
	return 0;
}
