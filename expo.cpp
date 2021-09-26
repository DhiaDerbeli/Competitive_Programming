ll expo(ll a, int p){
    ll k = 1;
    while(p){
       a%=MOD;
       k%=MOD;
       if(p&1) k*=a;
       a*=a;
       p>>=1;
    }
    return k;
  }
