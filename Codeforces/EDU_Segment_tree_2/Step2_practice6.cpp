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
#define fl(i,a,b) for(int i = a ; i <b ;i++)
#define get(a) fl(i,0,a.size())  cin>>a[i];
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

struct Segtree{
    int size;
    vector<ll> op;
    vector<ll> values;
    
    ll neutral_element = 0;
    ll no_operation = LLONG_MAX;

    ll modify_op(ll a, ll b, ll len){ 
        if(b == no_operation) return a;
        return b * len;
    }
    ll calc_op(ll a, ll b){
        return a + b;
    }
    void apply_mod_op(ll &a, ll b, ll len){
        a = modify_op(a, b, len);
    }
    
    void propagate(int x, int l, int r){
        if(r - l == 1) return;
        int m = (l + r) / 2;
        apply_mod_op(op[x * 2 + 1], op[x], 1);
        apply_mod_op(values[x * 2 + 1], op[x], m - l);
        apply_mod_op(op[x * 2 + 2], op[x], 1);
        apply_mod_op(values[x * 2 + 2], op[x], r - m);
        op[x] = no_operation;
    }
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        op.assign(2 * size , 0);
        values.assign(2 * size, 0);
    }
    void modify(int x, int lx, int rx, int l, int r, ll v){
        propagate(x, lx, rx);
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            apply_mod_op(op[x], v, 1);
            apply_mod_op(values[x], v, rx - lx);
            return;
        }
        int m = (lx + rx) / 2;
        modify(x * 2 + 1, lx, m, l, r, v);
        modify(x * 2 + 2, m, rx, l, r, v);
        values[x] = calc_op(values[x * 2 + 1], values[x * 2 + 2]);
    }
    void modify(int l, int r, ll v){
        modify(0, 0, size, l, r, v);
    }
    ll calc(int x, int lx, int rx, int l, int r){
        propagate(x, lx, rx);
        if(lx >= r || rx <= l) return neutral_element;
        if(l <= lx && rx <= r) return values[x];
        int m = (lx + rx) / 2;
        ll res1 = calc(x * 2 + 1, lx, m, l, r);
        ll res2 = calc(x * 2 + 2, m, rx, l, r);
        ll res = calc_op(res1, res2);
        return res;
    }
    ll calc(int l, int r){
        return calc(0, 0, size, l, r);
    }
};

int main(){
    Shazam;
    Segtree tree;
    int n, q; cin >> n >> q;
    tree.init(n);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll l, r, v; cin >> l >> r >> v;
            tree.modify(l, r, v);
        }
        else{
            ll l, r; cin >> l >> r;
            cout << tree.calc(l, r) << endl;
        }
    }
    return 0;
}
