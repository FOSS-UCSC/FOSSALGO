#include<iostream>
#include<math.h>
using namespace std;
// #define INF 100000

int INF=100000;

int bottomUprod(int c[], int n){
    int r[n+1];
    r[0]=0;
    int j=0;
    int i=0;

    for(j=1;j<=n;j++){
        int maxrev=-1*INF;
        for(i=1;i<=j;i++){
            maxrev=max(maxrev, c[i]+r[j-i]);
        }
        r[j]=maxrev;
    }
    return r[n];
}

int main(){
    int n=0;
    cin>>n;
    int r[n+1];
    int c[n];
    
    for(int i=0;i<=n;i++){
        cin>>c[i];
    }

    cout<<bottomUprod(c,n);
    return 0;

}
