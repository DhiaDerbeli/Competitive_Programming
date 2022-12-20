// matrix expo

#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

typedef long long ll;
const ll MOD = 1e9 + 7;
 
struct Matrix{
    ll a[2][2]{{0,0},{0,0}};
    Matrix operator * (Matrix& other){
        Matrix product;
            REP(i,2)REP(j,2)REP(k,2){
                product.a[i][k]+=(a[i][j]*other.a[j][k])%MOD;
                product.a[i][k]=product.a[i][k]%MOD;
            }
        return product;
    }
};
 
Matrix expo_pow(Matrix a, int p){
    Matrix reslt;
    REP(i,2) reslt.a[i][i]=1;
    while(p>0){
        if(p%2)
            reslt=reslt*a;
        a=a*a;
        p/=2;
    }
    return reslt;
}