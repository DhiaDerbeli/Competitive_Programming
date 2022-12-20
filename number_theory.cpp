// number theory

typedef long long ll;
const int N = 3e5 + 3;
const ll MOD = 998244353;

bool is_prime(int x){
    for(ll i=2; i*i<=x; i++){
        if(x % i == 0) return false;
    }
    return true;
}

bool prime[N] ;
void seive(){
    for(int i=0; i<N; i++) prime[i] = 1;
    for (int p = 2; p * p <N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}

ll expo(ll a, ll p){
    ll k = 1;
    while(p){
       if(p&1) k*=a;
       a*=a;
       p>>=1;
       a%=MOD;
       k%=MOD;
    }
    return k;
}

ll fact(ll n){
    ll ans = 1;
    for(ll i=2; i<=n; i++){
        ans *= i;
        ans %= MOD;
    }
    return ans;
}

ll mul(ll a, ll b){
    return ((a*b)%MOD);
}

ll inv(ll a){
    return (expo(a,MOD-2));
}

ll cnk(ll n, ll k){
    return(mul(fact(n),mul(inv(fact(k)), inv(fact(n-k)))));
}
    
