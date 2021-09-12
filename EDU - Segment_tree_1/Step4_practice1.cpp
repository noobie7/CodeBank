/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

pair<ll,ll> combine(pair<ll,ll> & a, pair<ll,ll> & b){
        return make_pair(a.ff + b.ff, a.ss + b.ss);
}

struct Segtree{
    int size;
    vector<pair<ll,ll>> sums;

    void init(int n){
        size = 1;
        while( size < n ) size *= 2;
        sums.assign(2*size , {0LL,0LL});
    }
    void build( vector<ll>& a){
        build(a,0,0,size);
    }
    void build( vector<ll>& a, int x, int l, int r){
        if(r-l==1){
            if(l < a.size()){
                sums[x] = ((l&1^1)?make_pair(a[l],-a[l]):make_pair(-a[l],a[l]));
            }
            return ;
        }
        int m = (l + r)/2;
        build(a, x*2 + 1, l, m);
        build(a, x*2 + 2, m, r);
        sums[x] = combine(sums[x*2 + 1], sums[x*2 + 2]);
    }
    void set(int i, int val){
        set(i, val, 0, 0, size);
    }
    void set(int i, ll val, int x, int l, int r){
        if(r-l==1){
            sums[x] = ((l&1^1)?make_pair(val,-val):make_pair(-val,val));
            return ;
        }
        int m = (l + r)/2;
        if(i < m)
            set( i, val, x*2 + 1, l, m);
        else
            set( i, val, x*2 + 2, m, r);

        sums[x] = combine(sums[x*2 + 1], sums[x*2 + 2]);
    }
    ll range(int l, int r){
        return range(l , r, 0, 0, size);
    }
    ll range(int l, int r, int x, int lx, int rx){
        if(rx <= l || r <= lx) return 0;
        if(l  <= lx&& rx<=  r) return ((l&1^1)?sums[x].ff:sums[x].ss);
        int m = (lx + rx)/2;
        return range(l,r,x*2+1, lx,m) + range(l,r,x*2+2, m, rx);
    }

};

int main(){
    Shazam;
    int n;
    cin>>n;
    vector<ll> a(n);
    get(a);
    Segtree seg;
    seg.init(n);
    seg.build(a);
    int q; 
    cin>>q;
    for(int i = 0; i < q; i++){
        int type; 
        cin>>type;
        if(!type){
            ll p,val;
            cin>>p>>val;
            --p;
            seg.set(p,val);
        }
        else{
            int l,r; 
            cin>>l>>r;
            --l;
            cout<<seg.range(l,r)<<endl;

        }
    }
    return 0;
}