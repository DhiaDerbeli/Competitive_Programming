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

const int N = 1e3 + 5;
int n, m, x_a , y_a, x_b, y_b;
int dx[4] = { 0 , 0 , 1 , -1 };
int dy[4] = {1 , -1 , 0 , 0 };
char dir[4] = {'R','L', 'D' , 'U'};
char grid[N][N] ;
int pre[N][N];
int dist[N][N];
bool visited[N][N];
queue<pii> q;


void test_case(){
    cin >> n >> m;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cin >> grid[i][j] ;
            if(grid[i][j] =='A') x_a = i , y_a = j;
            if(grid[i][j] == 'B') x_b = i , y_b = j;
        }
    }
    q.push({x_a, y_a});
    visited[x_a][y_a] = 1 ;
    while(!q.empty()){
        int x = q.front().first ;
        int y = q.front().second;
        for(int i=0 ; i<4 ; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx<0 || xx>= n || yy < 0 || yy>=m) continue ;
            if(visited[xx][yy] || grid[xx][yy] == '#') continue;
            dist[xx][yy] = dist[x][y] + 1;
            visited[xx][yy] = 1;
            pre[xx][yy] = i;
            if(xx == x_b && yy == y_b) break ;
            q.push({xx,yy});
        }
        q.pop();
    }
    if(!dist[x_b][y_b]) cout << "NO" << endl;
    else{
        cout << "YES" << endl << dist[x_b][y_b] << endl ;
        stack<char> s;
        while(x_b != x_a || y_b != y_a){
            int k = pre[x_b][y_b] ;
            s.push(dir[k]);
            x_b -= dx[k];
            y_b -= dy[k];
        }
        while(!s.empty()){
            cout << s.top() ;
            s.pop();
        }
        cout << endl;
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
