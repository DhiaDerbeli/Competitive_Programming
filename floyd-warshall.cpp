#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

const int N = 500;
const ll INFLL = 1e18;

ll d[N][N];


void test_case(){
    int n, m, q;
    cin >> n >> m >> q;
    memset(d, 0x3f, sizeof(d));
    for(int i=0; i<n; i++) d[i][i] = 0;
    while(m--){
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--, y--;
        d[x][y] = min(d[x][y], w);
        d[y][x] = min(d[y][x], w);
    }
    for(int i=0; i<n; i++) for(int j= 0; j<n; j++) for(int k = 0; k<n; k++){
        d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        x--, y--;
        cout << (d[x][y] >= INFLL ? -1 : d[x][y]) << endl;
    }
}