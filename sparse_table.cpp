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
#define REP(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007

vector<vi> t;


void build(int n){
    int LOG = 32 - __builtin_clz(n);
    t.resize(n, vi(LOG + 1));
    cout << LOG << endl;
    for(int i = 0 ; i<n ; i++){
        cin >> t[i][0] ;
    }
    for( int i = 1 ; i < LOG ; i++){
        for( int j =  0; j + (1<<i) - 1 < n ; j++){
            t[j][i] = min(t[j][i-1] , t[j + (1<<(i-1))][i-1]);
        }
    }
    for(auto i:t){
        for(int j:i) cout << j << " " ;
        cout << endl;
    }
}

void query(int l , int r){
    int len = r-l+1;
    int k = 31 - __builtin_clz(len);
    cout << min( t[l][k] , t[r-(1<<k)+1][k] ) << endl;
}

int main()
{
    int n;
    cin >> n;
    build(n);
    int q;
    cin >> q;
    while(q--){
        int l,r;
        cin >> l >> r;
        query(l-1,r-1);
    }
    return 0;
}