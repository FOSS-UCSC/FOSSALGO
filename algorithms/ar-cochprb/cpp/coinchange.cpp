#include<iostream>
#include<math.h>
using namespace std;

int INF = 100000;

int bottomUpcoin(int c[], int n, int k){
    int m[n+1];
    int s[n+1];
    m[0] = 0;
    s[0] = 0;
    int i = 0, j = 0, mini = 0, coin = 0;

    for(j = 1 ; j <= n ; j++){
        mini = INF;

        for(i = 1 ; i <= k ; i++){
            if(j >= c[i]){
                if(1+m[j-c[i]]<mini){
                    mini = 1+m[j-c[i]];
                    coin = i;
                }
            }
        }
        m[i] = mini;
        s[j] = coin;
    }

    int l = n;
    while(l>0){
        // cout << c[s[l]];
        printf("%d\n",c[s[l]]);
        l = l - c[s[l]];
    }

    return m[n];
}

int main(){
    int n = 0, k = 0;
    cin >> k;
    int c[k];
    
    for(int i = 0 ; i <= k ; i++){
        cin>>c[i];
    }
    cin >> n;
    int m[n+1];
    int s[n+1];

    bottomUpcoin(c,n,k);
    return 0;
}
