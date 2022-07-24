vll seg_tree;
vll a;
int n, q;
 
ll query(int left, int right, int root = 1, int high = n-1, int low = 0)
{
    if (low > right || high < left)
        return 0;
    if (low >= left && high <= right)
        return seg_tree[root];
    int middle = (high + low) / 2;
    return max(query(left, right, 2 * root, middle, low), query(left, right, 2 * root + 1, high, middle + 1));
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
    for(int i=0; i<n; i++) cin >> a[i];
    n = (1 << (32 - __builtin_clz(n)));
    seg_tree.resize(2 * n);
    for (int i = 0; i < a.size(); i++)
        seg_tree[i + n] = a[i];
    for (int i = n - 1; i >= 0; i--)
        seg_tree[i] = max(seg_tree[i * 2], seg_tree[i * 2 + 1]);
}

//query(l-1, r-1)
//query(pos-1, val)
