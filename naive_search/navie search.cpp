#include<iostream>
using namespace std;


int main() {
	
   string mainString = "ABCCBACABACABACABACACAACBABAC";
   string pattern = "BAC";
   int result[mainString.size()];
   int index = -1;
   cout<<"source String: "<<mainString<<endl;
	cout<<"pattern String: "<<pattern<<endl<<endl;
	int patLen = pattern.size();
   int strLen = mainString.size();

   for(int i = 0; i<=(strLen - patLen); i++) {
      int j;
      for(j = 0; j<patLen; j++) {     
         if(mainString[i+j] != pattern[j])
            break;
      }

      if(j == patLen) { 
         index++;
         result[index] = i;
      }
   }
	
   for(int i = 0; i <= index; i++) {
      cout << "Pattern found at position: " << result[i]<<endl;
   }
}
