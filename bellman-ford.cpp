#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

const int N = 5000;
const ll INFLL = 1e18;

vector<pair<ll, int>> g[N];
bool mark[N];
ll d[N];

void test_case(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) d[i] = INFLL;
    d[0] = 0;
    memset(mark, false, sizeof(mark));
    while(m--){
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({w, y});
    }
    for(int i = 0; i<n; i++){
        bool done = true;
        for(int j = 0; j<n; j++){
            for(auto p: g[j]){
                ll w = p.first;
                int nxt = p.second;
                if(d[nxt] > d[j] + w){
                    done = false;
                    d[nxt] = d[j] + w;
                }
            }
        }
        if(done){
            cout << d[n - 1] << endl;
            return;
        }
    }
    cout << -1 << endl;
}