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


struct Segtree{
    int size;
    vector<ll> sums;

    void init(int n){
        size = 1;
        while(size < n){ size *= 2;}
        sums.assign(2*size, 0);
    }

    void set(int i, ll val){
        set(i,val, 0, 0, size);
    }
    void set(int i, ll val, int x, int l, int r){
        if(r-l==1){
            sums[x]+=val;
            return;
        }
        int m = (l + r)/2;
        if(i < m)
            set(i,val,x*2 + 1, l , m);
        else
            set(i,val,x*2 + 2, m , r);
        sums[x] = sums[x*2 + 1] + sums[x*2 + 2];
    }
    ll range(int l, int r){
        return range(l,r,0,0,size);
    }
    ll range(int l, int r, int x, int lx, int rx){
        if(rx <= l || r <= lx) return 0;
        if(l  <= lx&& rx<=  r) return sums[x];
        int m = (lx + rx)/2;
        return range(l,r,x*2 + 1, lx , m) + range(l,r,x*2 + 2, m, rx);
    }

};

int main(){
    Shazam;
    int n,q; cin>>n>>q;
    Segtree seg;
    seg.init(n+1);
    for(int i = 1; i <= q; i++){
        int type; cin>>type;
        if(type==1){
            int l,r,v; cin>>l>>r>>v;
            seg.set(l,v);
            seg.set(r,-v);           
        }
        else{
            int p; cin>>p;
            cout<< seg.range(0,p+1)<<endl;
        }
    }
    return 0;
}