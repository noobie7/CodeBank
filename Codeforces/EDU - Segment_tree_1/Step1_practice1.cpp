/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
*/
#include<bits/stdc++.h>
using namespace std;
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
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

struct Segtree{
    int size;
    vector<ll> sums;

    void init(int n){
        size = 1;
        while(size < n ) {
            size*=2;
        }
        sums.assign(2*size,0);
    }

    void build(vector<ll> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx<(int)a.size()){
                sums[x] = a[lx];         
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, x*2 + 1, lx, m);
        build(a, x*2 + 2, m, rx);
        sums[x] = sums[x*2 + 1] + sums[x*2 + 2];
    }
    void build(vector<ll> &a){
        build(a,0,0,size);
    }

    void set(int i, ll val, int x, int lx, int rx){
        if(rx-lx==1){
            sums[x] = val;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m){
            set(i, val, x*2 + 1, lx, m);
        }
        else{
            set(i, val, x*2 + 2, m, rx);
        }
        sums[x] = sums[x*2 + 1] + sums[x*2 + 2];
    }
    void set(int i, ll val){
        set(i,val,0, 0, size);
    }
    ll sum(int l, int r, int x, int lx, int rx){
        if(lx>=r || rx<=l)
            return 0;
        if(l<=lx && rx<=r)
            return sums[x];
        int m = (lx+rx)/2;
        ll s1 = sum(l, r, x*2 + 1, lx, m);
        ll s2 = sum(l, r, x*2 + 2, m, rx);
        return s1 + s2;
    }
    ll sum(int l, int r){
        return sum(l,r,0,0,size);
    }

};



int main(){
    Shazam;
    int n,m; cin>>n>>m;
    Segtree seg;
    seg.init(n);
    vector<ll> a(n);
    for(int i = 0; i< n; i++){
        cin>>a[i];
       // seg.set(i,a[i]);
    }

    seg.build(a);
    
    while(m--){
        int type; cin>>type;
        if(type == 1){
            int i;
            ll b; 
            cin>>i>>b;
            seg.set(i,b);
        }
        else{
            int l,r; cin>>l>>r;
            cout<< seg.sum(l,r)<<endl;
        }
    }
    return 0;
}