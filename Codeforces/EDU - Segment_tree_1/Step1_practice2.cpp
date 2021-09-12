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
    vector<ll> mini;
    //init function
    void init(int n){
        size = 1;
        while(size < n){
            size *=2;
        }
        mini.assign(2*size, 1e9 + 5);
    }
    //build call
    void build(vector<ll> &a){
        build(a,0,0,size);
    }
    //build function
    void build(vector<ll> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < a.size()){
                mini[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, x*2 + 1, lx, m);
        build(a, x*2 + 2, m, rx);
        mini[x] = min(mini[x*2 + 1], mini[x*2 + 2]);
    }
    //set call
    void set(int i, ll val){
        set(i, val, 0, 0, size);
    }
    //set function
    void set(int i, ll val, int x, int lx, int rx){
        if(rx-lx==1){
            mini[x] = val;
            return;
        }
        int m = (lx + rx)/2;
        if(i < m){
            set(i, val, x*2 + 1, lx, m);
        }else{
            set(i, val, x*2 + 2, m, rx);
        }
        mini[x] = min(mini[x*2 + 1], mini[x*2 + 2]);
    }
    //range query call 
    ll get_min(int l, int r){
       return get_min(l,r,0,0,size);
    }
    //range query function
    ll get_min(int l, int r, int x, int lx, int rx){
        if(lx>=r || rx <= l) return 1e9 + 5;
        if(l <= lx && rx <= r) return mini[x];
        int m = (lx+rx)/2;
        ll min1 = get_min(l,r,x*2+1,lx, m);
        ll min2 = get_min(l,r,x*2+2,m, rx);
        return min(min1, min2);
    }
};



int main(){
    Shazam;
    int n,m; cin>>n>>m;
    vector<ll> a(n);
    for(ll &i : a)
        cin>>i;
    Segtree seg;
    seg.init(n);
    seg.build(a);
    while(m--){
        int type; cin>>type;
        if(type==1){
            int i;
            ll val;
            cin>>i>>val;
            seg.set(i,val);
        }
        else{
            int l,r; cin>>l>>r;
            cout<<seg.get_min(l,r)<<endl;
        }
    }
    return 0;
}