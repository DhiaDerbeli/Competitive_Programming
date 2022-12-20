// segment tree

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 1e9;

template<typename T>
struct segment_tree {
    vector<T> seg_tree, a;
    int n;
    T default_value;
    function<T(T, T)> func;
    segment_tree(vector<T> &a, int n, T default_value, function<T(T, T)> func): a(a), default_value(default_value), n(n), func(std::move(func)){};

    void build() {
        n = (1 << (32 - __builtin_clz(n)));
        seg_tree.resize(2 * n);
        for (int i = 0; i < a.size(); i++)
            seg_tree[i + n] = a[i];
        for (int i = n - 1; i >= 0; i--)
            seg_tree[i] = func(seg_tree[i * 2], seg_tree[i * 2 + 1]);
    }

    T query(int left, int right, int root = 1, int low = 0, int high = -1)
    {
        if(high == -1) high = n - 1;
        if (low > right || high < left)
            return default_value;
        if (low >= left && high <= right) {
            return seg_tree[root];
        }
        int middle = (high + low) / 2;
        return func(query(left, right, 2 * root, low, middle), query(left, right, 2 * root + 1, middle + 1, high));
    }

    void update(int pos, T value){
        int i = pos+n;
        seg_tree[i] = value;
        while(i){
            i >>= 1;
            seg_tree[i] = func(seg_tree[2*i] , seg_tree[2*i + 1]);
        }
    }
};

template<typename T>
T Min(T a, T b) {
    if(a > b) return b;
    return a;
}

template<typename T>
T Max(T a, T b) {
    if(a < b) return b;
    return a;
}

template<typename T>
T Sum(T a, T b) {
    return a + b;
}


void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    segment_tree<int> seg(a, n, INF, &Min<int>);
    seg.build();
    seg.query(0, n - 1);
    seg.update(1, -1);
}
