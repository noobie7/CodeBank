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

struct M{
    int cnt[41] = {0};
};

M combine( M & a, M & b){
    M res;
    for(int i = 0; i < 41; i++){
        res.cnt[i] = a.cnt[i] + b.cnt[i];
    }
    return res;
}

struct segtree{
    int size;
    vector<M> sums;

    void init(int n){
        size = 1;
        while(size < n) size *= 2;
        sums.resize(2*size);
    }
    
    void build(vector<M> & a){
        build(a, 0, 0, size);
    }

    void build(vector<M> & a, int x, int l, int r){
        if(r-l==1){
            if(l < a.size())
                sums[x] = a[l];
            return;                
        }
        int m = (l + r)/2;
        build(a, x*2 + 1, l , m);
        build(a, x*2 + 2, m , r);
        sums[x] = combine(sums[x*2 + 1] , sums[x*2 + 2]);
    }

    void set(int i, M val){
        set(i, val, 0, 0, size);
    }
    void set(int i, M val, int x, int l, int r){
        if(r-l==1){
            sums[x] = val;
            return;
        }
        int m = (l + r)/2;
        if(i < m) set(i, val, x*2 + 1, l, m);
        else      set(i, val, x*2 + 2, m, r);
        sums[x] = combine(sums[x*2 + 1], sums[x*2 + 2]);
    }
    M range(int l, int r){
        return range(l, r, 0, 0, size);
    }
    M range(int l, int r, int x, int lx, int rx){
        if(r <= lx || rx <= l) {M nu; return nu;}
        if(l <= lx && rx <= r) {return sums[x];}
        int m = (lx + rx)/2;
        M res1 = range(l,r,x*2 + 1, lx, m);
        M res2 = range(l,r,x*2 + 2, m, rx);
        M res = combine(res1, res2);
        return res;
    }

};


int main(){
    Shazam;
    int n,q; cin>>n>>q;
    vector<int> a(n);
    get(a);
    vector<M> helper(n);
    for(int i = 0; i < n; i++){
        helper[i].cnt[a[i]] = 1;
    }
    segtree seg;
    seg.init(n);
    seg.build(helper);
    for(int i = 0; i < q; i++){
        int type; cin>>type;
        if(type == 1){
            int l, r; cin>>l>>r;
            --l;
            M res = seg.range(l,r);
             
        }
    }
    return 0;
}