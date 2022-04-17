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
 
 
vll seg_tree;
vll a;
int n, q;
 
ll query(int root, int high, int low, int left, int right)
{
    if (low > right || high < left)
        return 0;
    if (low >= left && high <= right)
        return seg_tree[root];
    int middle = (high + low) / 2;
    return query(2 * root, middle, low, left, right) + query(2 * root + 1, high, middle + 1, left, right);
}

void update(int pos, ll value){
    int i = pos+n;
    seg_tree[i] = value;
    while(i){
        i >>= 1;
        seg_tree[i] = min(seg_tree[2*i] , seg_tree[2*i + 1]);
    }
}
 
void build()
{
    a.resize(n);
    READ(a, n);
    n = (1 << ((n&(n-1)) ? 32 : 31)- __builtin_clz(n));
    seg_tree.resize(2 * n);
    for (int i = 0; i < a.size(); i++)
        seg_tree[i + n] = a[i];
    for (int i = n - 1; i >= 0; i--)
        seg_tree[i] = seg_tree[i * 2] + seg_tree[i * 2 + 1];
}
 
int main()
{
    cin >> n >> q;
    build();
    while (q--)
    {
        int l, r, v;
        //cin >> v;
        cin >> l >> r;
        l--;
        r--;
        //update(l,r,v);
        cout << query(1, n - 1, 0, l, r) << endl;
    }
}
