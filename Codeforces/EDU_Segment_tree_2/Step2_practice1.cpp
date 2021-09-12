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
    vector<ll> mins;

    void init(int n){
        size = 1;
        while( size < n ) size *= 2;
        op.assign(2 * size, 0);
        mins.assign(2 * size, 0);
    }

    void add(int x, int lx, int rx, int l, int r, ll v){
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            op[x] += v;
            mins[x] += v;
            return;
        }
        int m = (lx + rx) / 2;
        add(x * 2 + 1, lx, m, l, r, v);
        add(x * 2 + 2, m, rx, l, r, v);
        mins[x] = min(mins[x * 2 + 1], mins[x * 2 + 2]) + op[x];

    }

    void add(int l, int r, ll v){
        add(0, 0, size, l, r, v);
    }

    ll get_min(int x, int lx, int rx, int l, int r){
        if(lx >= r || rx <= l) return LLONG_MAX;
        if(l <= lx && rx <= r) return mins[x];
        int m = (lx + rx) / 2;
        ll m1 = get_min(x * 2 + 1, lx, m, l, r);
        ll m2 = get_min(x * 2 + 2, m, rx, l, r);
        return min(m1, m2) + op[x];
    }

    ll get_min(int l, int r){
        return get_min(0, 0, size, l, r);
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
            ll l, r, v; cin >> l >> r >> v;
            tree.add(l, r, v);
        }
        else{
            ll l, r; cin >> l >> r;
            cout << tree.get_min(l, r) << endl;
        }
    }
    return 0;
}