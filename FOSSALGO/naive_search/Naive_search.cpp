//c programe for Naive String matching algorithem
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int match(char *txt,char *pat){
    int n=strlen(txt);
    int m=strlen(pat);
    int i,j,k;
    for(i=0;i<(n-m+1);i++){
	//check patern match for i
        for(j=0;j<=m-1;j++){
            if(txt[i+j]!=pat[j])
                break;
        if(j==m-1){
           printf("Pattern found at %d\n",i);
        }
        }
    }
}
//driver programe
int main()
{
   char txt[]="ABCECGBCERBCETY";
   char pat[]="BCE";
   match(txt,pat);
   return 0;

}
