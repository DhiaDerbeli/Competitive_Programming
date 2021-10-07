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

vector<bool> prime ;
 
void seive(int n)
{
    prime[0] = 0;
    prime[1] = 0;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    //for (int p = 2; p <= n; p++)
        //if (prime[p])
            //cout << p << " ";
}

int main()
{
    int n;
    cin >> n;
    prime.resize(n+1, true);
    seive(n);
    return 0;
}
