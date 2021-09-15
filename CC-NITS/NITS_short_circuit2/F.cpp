/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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
#define mytype multiset<int>


multiset<ll> ele;
vector<ll> a;
int n;
int get_index(ll val){
    auto it = ele.begin();
    return distance(it, ele.find(val));
}

struct Segtree{
    int size;
    vector<ll> sum;
    
    void init(int n){
        size = 1;
        while(size < n) size<<=1;
        sum.assign(2*size, 0);
    }

    void build(){
        build(0,0,size);
    }
    void build(int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < a.size()){
                cout<<lx<<" "<<get_index(a[lx])<<" "<<endl;
                sum[x] = a[get_index(a[lx])];
            }
            return;
        }
        int m = (lx + rx)/2;
        build(x*2+1,lx,m);
        build(x*2+2,m,rx);
        sum[x] = sum[x*2+1] + sum[x*2+2];
    }
    void set(int i, ll val){
        set(i, val, 0,0,size);
    }
    
    void set(int i, ll val, int x, int lx, int rx){
        if(rx-lx==1){
            int id = get_index(val);
            sum[x] = a[id];
            return;
        }
        int m = (lx + rx)/2;
        if(i < m){
            set(i,val,x*2+1,lx,m);
        }
        else{
            set(i,val,x*2+2,m,rx);
        }
        sum[x] = sum[x*2+1] + sum[x*2+2];
    }
    ll query(int k){
        return query(n-k,size, 0, 0, size);
    }
    ll query(int l, int r, int x, int lx, int rx){
        if(rx<=l || r<=lx) return 0;
        if(l<=lx && rx<=r) return sum[x];
        int m = (lx+rx)/2;
        return query(l,r,x*2+1, lx, m) + query(l,r,x*2+2,m,rx);
    }

};

int main(){
    Shazam;
    int m; 
    cin>>n>>m;
    a.assign(n,0);
    get(a);
    for(ll i : a){
        ele.insert(i);
    }
    Segtree seg;
    seg.init(n);
    seg.build();
    for(int i = 0 ; i < seg.sum.size(); i++){
        cout<<seg.sum[i]<<" ";
    }
    cout<<endl;
    // for(int i = 0 ; i < m; i++){
    //     int type; cin>>type;
    //     if(type==1){
    //         int pos, val;
    //         cin>>pos>>val;
    //         pos--;
    //         seg.set(get_index(a[pos]), -a[pos]);
    //         ele.erase(ele.find(a[pos]));
    //         ele.insert(val);
    //         a[pos] = val;
    //         seg.set(get_index(val), val);
    //     }
    //     else{
    //         int k; cin>>k;
    //         cout<<seg.query(k)<<endl;
    //     }
    // }
    return 0;
}