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
    
