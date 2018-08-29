#include <stdio.h>
#include <stdlib.h>

void search(char T[], char P[]) {
	
	int n = strlen(T);
	int m = strlen(P);
	printf("\nlengths %d, %d ", n,m);
	int match = 0;
	
	for(int i=0; i<n-m; i++){
		int j = 0;
		while(j<m && T[i+j]==P[j]){
			j++;
			if(j==m){
				match++;
				printf("\nPattern found at index %d ", i);
			}
		}
	}
	if(match==0){
		printf("\nThere is no substring of %s matching %s ", T,P);
	}
}

int main(){
    char text[100],pat[100];
	//char text[]="abacaabacab";
	//char pattern[]="abacab";
	printf("\n ENTER THE TEXT    : ");
	gets(text);
	printf("\n ENTER THE PATTERN : ");
	gets(pattern);
	printf("\n---------------------------------------------------");
	search(text, pattern);
	return 0;
}
