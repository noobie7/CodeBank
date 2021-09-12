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

#define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;
int tim = 1;
struct Segtree{
    
    int size;
    vector<pair<int,int>> a;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        a.assign(2 * size, {0,0});
    }

    void set(int x, int lx, int rx, int l, int r, int v){
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            a[x] = {v, tim};
            return ; 
        }
        int m = (lx + rx) / 2;
        set(x * 2 + 1, lx, m, l, r, v);
        set(x * 2 + 2, m, rx, l, r, v);
    }

    void set(int l, int r, int v){
        set(0, 0, size, l, r, v);
    }

    auto find(int x, int l, int r, int p){
        if(r - l == 1){
            return a[x];
        }
        int m = (l + r) / 2;
        pair<int,int> res;
        if(p < m)
            res = find(x * 2 + 1, l, m, p);
        else
            res = find(x * 2 + 2, m, r, p);
        if(a[x].ss > res.ss){
            return a[x];
        }
        else{
            return res;
        }
    }

    auto find(int p){
        return find(0, 0, size, p);
    }

};


int main(){
    Shazam;
    int n, q; cin >> n >> q;
    Segtree tree;
    tree.init(n);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r, v; cin >> l >> r >> v;
            tree.set(l, r, v);
            tim++;
        }
        else{
            int p; cin >> p;
            cout << tree.find(p).ff << endl;
        }
    }
    return 0;
}