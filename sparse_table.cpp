#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> t;


void build(int n){
    int LOG = 32 - __builtin_clz(n);
    t.resize(n, vector<int>(LOG + 1));
    cout << LOG << endl;
    for(int i = 0 ; i<n ; i++){
        cin >> t[i][0] ;
    }
    for( int i = 1 ; i < LOG ; i++){
        for( int j =  0; j + (1<<i) - 1 < n ; j++){
            t[j][i] = min(t[j][i-1] , t[j + (1<<(i-1))][i-1]);
        }
    }
    for(auto i:t){
        for(int j:i) cout << j << " " ;
        cout << endl;
    }
}

void query(int l , int r){
    int len = r-l+1;
    int k = 31 - __builtin_clz(len);
    cout << min( t[l][k] , t[r-(1<<k)+1][k] ) << endl;
}

int main()
{
    int n;
    cin >> n;
    build(n);
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        query(l-1,r-1);
    }
    return 0;
}