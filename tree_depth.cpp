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
#define REP(i,n) for(int i=0 ; i<n ; i++)


void test_case(){
    int n, k ;
    cin >> n >> k;
    vector<vi> graph(n);
    for(int i=0 ; i<n-1 ; i++){
        int x, y;
        cin >> x >> y;
        graph[x-1].pb(y-1);
        graph[y-1].pb(x-1);
    }
    queue<int> q;
    vi ind(n), dep(n);
    for(int i=0 ; i<n ; i++){
        ind[i] = graph[i].size();
        if(ind[i]==1) q.push(i);
    } 
    while(!q.empty()){
        int x = q.front() ;
        q.pop();
        for(auto i:graph[x]){
            if(ind[i] == 1) continue ;
            ind[i]--;
            dep[i] = max(dep[i], dep[x] + 1);
            if(ind[i] == 1) q.push(i);
        }
    }
    PRINT(dep);
}
 

 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) test_case();
}
