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
#define READ(t,n) for(ll i=0;i<n;i++) cin>>t[i];
#define PRINT(t) for(auto i:t) cout<<i<<" ";cout<<endl;
#define debug(x) cerr << #x << " is " << x << "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endl "\n"

vector<vi> edge;

struct dsu
{
   vector<int> root, size;

   dsu(int n)
   {
      size.resize(n + 1, 1);
      root.resize(n + 1);
      for (int i = 1; i <= n; i++) root[i] = i;
   }

   int find(int u) { return root[u] == u ? u : root[u] = find(root[u]); }

   bool same(int u, int v)
   {

      if (find(u) == find(v)) return true;
      return false;
   }

   void join(int u, int v){
      u = find(u);
      v = find(v);
      if (size[u] < size[v]) swap(u, v);
      root[v] = u;
      size[u] += size[v];
   }
};

int main()
{
    int n, m;
    cin >> n >> m;
    dsu ds(n);
    for (int i = 0; i < m; i++)
    {
        int x,y,w;
        cin >> x >> y >> w ;
        edge.pb({w,x,y});
    }
    sort(all(edge));
    for(int i=0 ; i<m ; i++){
       for(int j=0 ; j<3 ; j++){
          cout << edge[i][j] << " " ;
       }
       cout << endl;
    }
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
      if(!ds.same(edge[i][1], edge[i][2])){
         ans += edge[i][0];
         ds.join(edge[i][1], edge[i][2]);
      }
    }

    cout << "Total weight " << ans << endl;
}