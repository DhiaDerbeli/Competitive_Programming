// spanning tree

#include <bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
typedef long long ll;
vector<vector<int>> edge;

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
        edge.push_back({w,x,y});
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