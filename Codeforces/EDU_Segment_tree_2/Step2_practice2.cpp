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
const int mod = 1e9 + 7;

struct Segtree{
    int size;
    vector<ll> op;
    vector<ll> sums;
    
    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        op.assign(2 * size , 1);
        sums.assign(2 * size , 0);
    }

    void build(vector<ll> &a, int x, int l, int r){
        if(r - l == 1){
            if(l < a.size()){
                sums[x] = a[l];
            }
            return ;
        }
        int m = (l + r) / 2;
        build(a, x * 2 + 1, l , m);
        build(a, x * 2 + 2, m , r);
        sums[x] = (sums[x * 2 + 1] + sums[x * 2 + 2] );
    }

    void build(vector<ll> &a){
        build(a, 0, 0, size);
    }

    void range_mul(int x, int lx, int rx, int l, int r, ll v){
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            op[x] = op[x] * v % mod;
            sums[x] = sums[x] * v % mod;
            return ;
        }
        int m = (lx + rx) / 2;
        range_mul(x * 2 + 1, lx, m, l, r, v);
        range_mul(x * 2 + 2, m, rx, l, r, v);
        sums[x] = (sums[x * 2 + 1] + sums[x * 2 + 2] ) % mod;
        sums[x] = (sums[x] * op[x]) % mod;
    }

    void range_mul(int l, int r, ll v){
        range_mul(0, 0, size, l, r, v);
    }

    ll range_sum(int x, int lx, int rx, int l, int r){
        if(lx >= r || rx <= l) return 0;
        if(l <= lx && rx <= r) return sums[x];
        int m = (lx + rx) / 2;
        ll m1 = range_sum(x * 2 + 1, lx, m, l, r);
        ll m2 = range_sum(x * 2 + 2, m, rx, l, r);
        return ((m1 + m2 ) % mod * op[x]) % mod;  
    }

    ll range_sum(int l, int r){
        return range_sum(0, 0, size, l, r);
    }
};

int main(){
    Shazam;
    int n, q; cin >> n >> q;
    vector<ll> a(n,1);
    Segtree tree;
    tree.init(n);
    tree.build(a);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            ll l, r, v; cin >> l >> r >> v;
            tree.range_mul(l, r, v);
        }
        else{
            ll l, r; cin >> l >> r;
            cout << tree.range_sum(l, r) << endl;
        }
    }  
    return 0;
}