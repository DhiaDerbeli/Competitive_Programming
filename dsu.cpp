vector<int> root, sz;
struct dsu
   {

      dsu(int n)
      {
         sz.resize(n + 1, 1);
         root.resize(n + 1);
         for (int i = 1; i <= n; i++) root[i] = i;
      }

      int find(int u){
         return (root[u] == u ? u : root[u] = find(root[u])) ; 
      }
         
      bool same(int u, int v)
      {

         if (find(u) == find(v)) return true;
         return false;
      }


      void join(int u, int v){
         u = find(u);
         v = find(v);
         if (sz[u] < sz[v]) swap(u, v);
         root[v] = u;
         sz[u] += sz[v];
      }
 };
// create an instance : dsu ds(n) 
