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

const int dummy = (1LL << 30) - 1;

struct Segtree{
    
    int size;
    vector<ll> OR;
    vector<ll> AND;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        OR.assign(2 * size, 0);
        AND.assign(2 * size, 0);
    }

    void apply_or(int x, int lx, int rx, int l, int r, ll v){
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            OR[x] |= v;
            AND[x] |= v;
            return;
        }
        int m = (lx + rx) / 2;
        apply_or(x * 2 + 1, lx, m, l, r, v);
        apply_or(x * 2 + 2, m, rx, l, r, v);
        AND[x] = (AND[x * 2 + 1] & AND[x * 2 + 2] ) | OR[x]; 
    }

    void apply_or(int l, int r, ll v){
        apply_or(0, 0, size, l, r, v);
    }

    ll find_and(int x, int lx, int rx, int l, int r){
        if(lx >= r || rx <= l) return dummy;
        if(l <= lx && rx <= r) return AND[x];
        int m = (lx + rx) / 2;
        ll a1 = find_and(x * 2 + 1, lx, m, l, r);
        ll a2 = find_and(x * 2 + 2, m, rx, l, r);
        return ( a1 & a2 ) | OR[x];
    }

    ll find_and(int l, int r){
        return find_and(0, 0, size, l, r);
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
            tree.apply_or(l, r, v);
        }
        else{
            ll l, r; cin >> l >> r;
            cout << tree.find_and(l, r) << endl;
        }
    }
    return 0;
}