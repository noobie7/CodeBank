/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
#define ff first
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define ss second
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

struct Segtree{
    int size;
    vector<ll> op;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        op.assign(size * 2 ,0);
    }

    void add(int x, int lx, int rx, int l, int r, int v){
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r){
            op[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        add(x * 2 + 1, lx , m, l, r, v);
        add(x * 2 + 2, m , rx, l, r, v);
    }

    void add(int l, int r, int v){
        add(0, 0, size, l, r, v);
    }

    ll get(int x, int l, int r, int i){
        if(r - l == 1){
            return op[x];
        }
        int m = (l + r) / 2;
        ll res = 0;
        if(i < m)
            res = get(x * 2 + 1, l, m, i);
        else 
            res = get(x * 2 + 2, m, r, i);
        return res + op[x];
    }

    ll get(int &i){
        return get(0, 0, size, i);
    }
    
    

};

int main(){
    Shazam;
    int n; cin >> n;
    int q; cin >> q;
    Segtree tree;
    tree.init(n);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r, v; cin >> l >> r >> v;
            tree.add(l, r, v);
        }
        else{
            int i; cin >> i;
            cout << tree.get(i) << endl;
        }
    }

    return 0;
}