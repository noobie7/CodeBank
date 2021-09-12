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

struct u {
    ll mx = 0, pr =  0, su = 0 , tot = 0;
};

u combine(u a, u b){
    u nu;
    nu.mx = max({a.mx, b.mx, a.su + b.pr});
    nu.pr = max({a.pr, a.tot + b.pr});
    nu.su = max({b.su, b.tot + a.su});
    nu.tot = a.tot + b.tot;
    return nu;
}

struct Segtree{
    int size;
    vector<u> a;
    vector<ll> op;
    void init(int n){
        size = 1;
        while( size < n ) size *= 2;
        u nu;
        a.assign(2 * size, nu); 
        op.assign(2 * size,0);
    }
    
    ll neutral_values = 0;
    ll no_operation = LLONG_MAX;

    ll apply_op1(ll a, ll b, ll len){
        if( b == no_operation) return a;
        return b ;
    }


    void apply_mod_op1(ll &x, ll b, ll len){
        ll y = x;
        x = apply_op1(y, b, len);
    }

    u apply_op2(u x, ll b, ll len){
        if(b == no_operation) return x;
        u nu;
        nu.tot = b * len;
        nu.pr = max(0LL, b * len);
        nu.mx = max(0LL, b * len);
        nu.su = max(0LL, b * len);
        return nu;
    }

    void apply_mod_op2(u &x, ll y, ll len){
        x = apply_op2(x, y, len);
    }

    void propagate(int x, int l , int r){
        if(r - l == 1) return;
        int m = (l + r) / 2;
        apply_mod_op1(op[2 * x  + 1], op[x], m - l);
        apply_mod_op2(a[2 * x + 1], op[x], m - l);
        apply_mod_op1(op[2 * x + 2], op[x], r - m );
        apply_mod_op2(a[2 * x + 2], op[x], r - m);
        op[x] = no_operation;
    }

    void modify(int x, int lx, int rx, int l, int r, ll val){
        propagate(x, lx, rx);
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            apply_mod_op1(op[x], val, rx - lx);
            apply_mod_op2(a[x], val, rx - lx);
            return ;
        }
        int m = (lx + rx) / 2;
        modify(x * 2 + 1, lx, m, l, r, val);
        modify(x * 2 + 2, m, rx, l, r, val);
        a[x] = combine(a[x * 2 + 1], a[x * 2 + 2]);
    }

    void modify(int l, int r, ll v){
        modify(0, 0, size, l, r, v);
    }
   
};

int main(){
    Shazam;
    int n, m; cin >> n >> m;
    Segtree tree;
    tree.init(n);
    while(m--){
        int l, r; cin >> l >> r;
        ll v; cin >> v;
        tree.modify(l, r, v);
        cout << tree.a[0].mx << endl;
    }
    return 0;
}