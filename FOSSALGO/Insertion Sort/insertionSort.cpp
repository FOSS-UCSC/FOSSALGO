#include<iostream>
#include<sstream>
#include<string>
#include<vector>

using namespace std;

void findNums(string nums, vector<int> &arr);

int main() {
	cout << "Enter the elements you want : "; // enter inputs with space seperated integers
	string nums;
	getline(cin, nums, '\n');
	vector<int> arr;

	findNums(nums.append(" "), arr);
	
	for(int i = 1; i < arr.size(); i++) {
		int element = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > element) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = element;
	}

	for(int i = 0; i < arr.size(); i++) {
		cout << arr.at(i) << " ";
	}
	
	return 0;
}

void findNums(string nums, vector<int> &arr) {
	if(nums[0] == 0) return;
//	cout << nums << endl;
	string delimiter = " ";
	int extInt = 0;
	
	string temp;
	int nextSplit = nums.find(delimiter);
	temp = nums.substr(0, nextSplit);
//		cout << "temp : " << temp << endl;
	stringstream extracted(temp);
		
	extracted >> extInt;
//		cout << "extracted : " << extInt << endl;
	arr.push_back(extInt);
	int len = nums.length() - (nextSplit + delimiter.length());
	string nextString = nums.substr((nextSplit + 1), len);
//		cout << "next string : " << nextString << endl;
	findNums(nextString, arr);
}
