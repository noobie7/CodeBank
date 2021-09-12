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

struct node{
    ll max_seg;
    ll pref;
    ll suff;
    ll tot;
};
node get_node(ll &x){
    node the_node;
    the_node.max_seg = max(x,0LL);
    the_node.pref = max(x,0LL);
    the_node.suff = max(x,0LL);
    the_node.tot = x;
    return the_node;
}
node combine(node &a, node &b){
    node result;
    result.max_seg = max(a.max_seg, max(b.max_seg, a.suff+b.pref));
    result.pref = max(a.tot + b.pref, a.pref);
    result.suff = max(b.tot + a.suff, b.suff);
    result.tot = a.tot + b.tot;
    return result;
}
struct Segtree
{
    int size;
    vector<node> t;

    void init(int n){
        size = 1;
        while(size < n){
            size *= 2;
        }
        ll dummy = 0;
        t.assign(2*size, get_node(dummy));
    }
    void build(vector<ll> &a){
        build(a,0,0,size);
    }
    void build(vector<ll> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < a.size()){
                t[x] = get_node(a[lx]);
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, x*2 + 1, lx, m);
        build(a, x*2 + 2, m, rx);
        t[x] = combine(t[x*2 + 1], t[x*2 + 2]);
    }
    void set(int i, ll val){
        set(i,val,0,0,size);
    }
    void set(int i, ll val, int x, int lx, int rx){
        if(rx-lx==1){
            t[x] = get_node(val);
            return;
        }
        int m = (lx + rx)/2;
        if(i < m){
            set(i, val, x*2 + 1, lx, m);
        }
        else{
            set(i, val, x*2 + 2, m, rx);
        }
        t[x] = combine(t[x*2 + 1], t[x*2 + 2]);
    }
};

int main(){
    Shazam;
    int n,m; cin>>n>>m;
    vector<ll> a(n);
    for(ll &i : a){
        cin>>i;
    }
    Segtree seg;
    seg.init(n);
    seg.build(a);
    cout<<seg.t[0].max_seg<<endl;
    while(m--){
        int i; 
        ll val;
        cin>>i>>val;
        seg.set(i,val);
        cout<<seg.t[0].max_seg<<endl;
    }
    return 0;
}