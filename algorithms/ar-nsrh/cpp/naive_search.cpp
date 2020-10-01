#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h> 
using namespace std; 

void search(string,string);

int main()  
{  
    string txt = "HAMMAHAMMAHAMMA";  
    string pat = "HAM";  
    cout << "Pattern  "<< pat<<" \n";
    search(pat, txt);  
    cout<< "in Text : "<<txt;
    return 0;  
}  

void search(string pat, string txt)  
{  
    int p = pat.size();  
    int q = txt.size();  
    int i = 0;  
  
    while (i <= q - p)  
    {  
        int j;  
  
        for (j = 0; j < p; j++)  
            if (txt[i + j] != pat[j])  
                break;  
  
        if (j == p) 
        {  
            cout << "found at  " << i << endl;  
            i = i + p;  
        }  
        else if (j == 0)  
            i = i + 1;  
        else
            i = i + j; 
    }  
}  
  


