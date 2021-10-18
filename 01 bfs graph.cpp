#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;


#define pb push_back
#define READ(t,n) for(int g=0;g<n;g++) cin>>t[g];
#define PRINT(t) for(auto i:t) cout<<i<<" ";cout<<endl;
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl '\n'
#define REP(i,n) for(int i=0 ; i<n ; i++)

const int N = 1e5 + 5;
vi graph[N] ;
int n , m;
bool visited[N] ;
int dist[N] ;
int pre[N] ;
queue<int> q;
stack<int> s;


void bfs(int source, int destination){
    q.push(source);
    visited[source] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x == destination) break;
        for(int i:graph[x]){
            if(visited[i]) continue;
            visited[i] = 1;
            dist[i] = dist[x] + 1;
            pre[i] = x;
            q.push(i);
        }
    }
}

void test_case(){
    int n, m;
    cin >> n >> m;
    while(m--){
        int x , y;
        cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    bfs(1,n);
    if(dist[n] == 0) cout << "IMPOSSIBLE"<< endl;
    else{
        cout << dist[n] + 1 << endl;
        s.push(n);
        while(n!=1) {
            s.push(pre[n]);
            n = pre[n] ;
        }
        while(!s.empty()){
            cout << s.top() << " ";
            s.pop();
        }
    }
    
}
 

 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) test_case();
}
