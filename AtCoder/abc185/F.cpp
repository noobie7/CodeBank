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
    vector<ll> xors;
    void init(int n){
        size = 1;
        while(size < n ) {
            size*=2;
        }
        xors.assign(2 * size, 0);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                xors[x] = a[lx];         
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, x*2 + 1, lx, m);
        build(a, x*2 + 2, m, rx);
        xors[x] = xors[x*2 + 1] ^ xors[x*2 + 2];
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }

    void set(int i, int val, int x, int lx, int rx){
        if(rx-lx==1){
            xors[x] ^= val;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i, val, x*2 + 1, lx, m);
        }
        else{
            set(i, val, x*2 + 2, m, rx);
        }
        xors[x] = xors[x*2 + 1] ^ xors[x*2 + 2];
    }
    void set(int i, ll val){
        set(i,val,0, 0, size);
    }
    int xorit(int l, int r, int x, int lx, int rx){
        if(lx>=r || rx<=l)
            return 0;
        if(l<=lx && rx<=r)
            return xors[x];
        int m = (lx+rx)/2;
        ll s1 = xorit(l, r, x*2 + 1, lx, m);
        ll s2 = xorit(l, r, x*2 + 2, m, rx);
        return s1 ^ s2;
    }
    ll xorit(int l, int r){
        return xorit(l,r,0,0,size);
    }

};


int main(){
    Shazam;
    Segtree tree;
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n); get(a);
    tree.init(n);
    tree.build(a);
    while(q--){
        int t; cin >> t; 
        if(t == 1){
            int pos, val;
            cin >> pos >> val;
            pos--;
            tree.set(pos, val);
        }
        else{
            int l, r; cin >> l >> r;
            l--;
            cout << tree.xorit(l, r) << endl;
        }
    }
    
    return 0;
}