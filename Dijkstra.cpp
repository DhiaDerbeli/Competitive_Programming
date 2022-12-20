#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 3;
typedef pair<ll, int> edge;

vector<edge> g[N];
bool visited[N];
ll d[N];

void test_case(){
    int n, m;
    cin >> n >> m;
    memset(d, 0x3f, sizeof(d));
    memset(visited, false, sizeof(visited));
    priority_queue<edge, vector<edge>, greater<edge>> q;
    while(m--){
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--, y--;
        g[x].push_back({w, y});
    }
    d[0] = 0;
    q.push({0, 0});
    while(q.size()){
        int node;
        ll dist;
        tie(dist,  node) = q.top();
        q.pop();
        visited[node] = true;
        for(edge e: g[node]){
            int nxt;
            ll w;
            tie(w, nxt) = e;
            if(visited[nxt]) continue;
            if(d[nxt] > w + dist){
                d[nxt] = w + dist;
                q.push({d[nxt], nxt});
            }
        }
    }
    for(int i=0; i<n; i++) cout << d[i] << " ";
}