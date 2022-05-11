const int N = 2e5 + 3;
int fen[N];
int n;

void update(int val, int x){
    for(; x<n; x+=x&(-x)) fen[x] += val;
}

int get(int x){
    int res = 0;
    for(; x; x-=x&(-x)) res += fen[x];
    return res; 
}
