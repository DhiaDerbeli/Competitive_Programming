ll expo(ll a, int p){
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
