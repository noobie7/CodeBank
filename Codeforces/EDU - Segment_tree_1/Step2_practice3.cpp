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
    vector<int> maxi;

    void init(int n){
        size = 1;
        while(size < n){
            size*=2;
        }
        maxi.assign(size*2, 0);
    }

    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx - lx  ==1){
            if( lx < a.size()){
                maxi[x] = a[lx]; 
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, x*2 + 1, lx, m);
        build(a, x*2 + 2, m, rx);
        maxi[x] = max(maxi[x*2 + 1], maxi[x*2 + 2]);
    }
    void set(int i, int val){
        set(i, val, 0, 0, size);
    }
    void set(int i, int val, int x, int lx, int rx){
        if(rx - lx == 1){
            maxi[x] = val;
            return;
        }
        int m = (lx + rx)/2;
        if(i < m){
            set(i, val, x*2 + 1, lx, m);
        }
        else{
            set(i, val, x*2 + 2,  m, rx);
        }
        maxi[x] = max(maxi[x*2 + 1], maxi[2*x + 2]);
    }
    int query(int val){
        if(val > maxi[0])
            return -1;
        return query(val, 0, 0, size);
    }
    int query(int val, int x, int lx, int rx){
        if(rx - lx == 1){
            return lx;
        }
        int res;
        int m = (lx + rx)/2;
        if(val <= maxi[x*2 + 1]){
            res = query(val, x*2 + 1, lx, m);
        }
        else{
            res = query(val, x*2 + 2, m, rx);
        }
        return res;
    }
};

int main(){
    Shazam;
    int n,m; cin>>n>>m;
    vector<int> a(n);
    for(int &i : a){
        cin>>i;
    }
    Segtree seg;
    seg.init(n);
    seg.build(a);   
    while(m--){
        int type; cin>>type;
        if(type==1){
            int i, val;
            cin>>i>>val;
            seg.set(i,val);
        }
        else{
            int val;
            cin>>val;
            cout<<seg.query(val)<<endl;
        }
    }
    return 0;
}