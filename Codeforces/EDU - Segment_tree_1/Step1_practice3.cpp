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

pair<int,int> combine(pair<int,int> a, pair<int,int> b){
    if(a.ff>b.ff){
        swap(a,b);
    } 
    if(a.ff==b.ff){
        return {a.ff, a.ss + b.ss};
    }
    else{
        return {a.ff, a.ss};
    }
}

struct Segtree{
    int size;
    vector<pair<int,int>> min_count;

    void init(int n){
        size = 1;
        while(size < n){
            size *=2;
        }
        min_count.assign(2*size, {INT_MAX,1});
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if( lx< (int)a.size()){
                min_count[x] = {a[lx],1};
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, x*2 + 1, lx, m);
        build(a, x*2 + 2, m, rx);
        min_count[x] = combine(min_count[x*2 + 1], min_count[x*2 + 2]);
    }
    void set(int i, int val){
        set(i,val, 0, 0, size);
    }
    void set(int i, int val, int x, int lx, int rx){
        if(rx-lx==1){
            min_count[x] = {val,1};
            return;
        }
        int m = (lx  + rx)/2;
        if(i < m){
            set(i, val, 2*x + 1, lx,m);
        }
        else{
            set(i, val, 2*x + 2, m, rx);
        }
        min_count[x] = combine(min_count[x*2 + 1], min_count[2*x + 2]);
    }
    pair<int,int> query(int l, int r){
        return query(l,r,0,0,size);
    }
    pair<int,int> query(int l, int r, int x, int lx, int rx){
        if(rx<=l || r<=lx) return {2e9,1};
        if(l<= lx && rx<=r) return min_count[x];
        int m = (lx + rx )/2;
        auto p1 = query(l,r, x*2 + 1, lx, m);
        auto p2 = query(l,r, x*2 + 2, m, rx);
        return combine(p1, p2);
    }
};


int main(){
    Shazam;
    int n,m; cin>>n>>m;
    vector<int> a(n);
    for(int &i : a)
        cin>>i;
    Segtree seg;
    seg.init(n);
    seg.build(a);
    while(m--){
        int t; cin>>t;
        if(t==1){
            int i,v; 
            cin>>i>>v;
            seg.set(i,v);
        }
        else{
            int l,r; cin>>l>>r;
            auto res = seg.query(l,r);
            cout<<res.ff<<" "<<res.ss<<endl;
        }
    }
    return 0;
}