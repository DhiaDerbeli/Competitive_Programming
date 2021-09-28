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

const ll INF=1e12;
vector<vector<pair<ll , int>>> g ;
vector<int> p ;
vector<ll> d ;
priority_queue < pair<ll,int> , vector< pair<ll,int> > , greater< pair<ll,int> > > pq;
 
 
int main()
{
   int n;
   int m;
   cin>>n>>m;
   g.resize(n+1);
   p.resize(n+1);
   d.resize(n+1 , INF);
   for(int i=0;i<m;i++){
        int a,b;
        ll w;
        cin>>a>>b>>w;
        g[a].pb({w,b});
        g[b].pb({w,a});
   }
   d[1]=0;
   p[1]=-1;
   pq.push({0,1});
   while(!pq.empty()){
        int a=pq.top().second ;
        pq.pop();
        for( auto edge : g[a]){
            int b = edge.second ;
            ll w = edge.first ;
            if( d[a] + w < d[b]){
                d[b]=d[a]+w;
                p[b]=a;
                pq.push({d[b] , b}) ;
            }
        }
   }
   if(d[n]==INF){
    cout << -1 << endl;
    return 0;
    }
    stack<int> s;
    int i=n;
    while(p[i]!=-1){
        s.push(p[i]) ;
        i=p[i];
    }
    while(!s.empty()){
        cout << s.top() << " " ;
        s.pop();
    }
    cout << n ;
}