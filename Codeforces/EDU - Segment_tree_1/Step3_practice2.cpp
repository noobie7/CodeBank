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
    vector<int> sums;
    
    void init(int n){
        size = 1;
        while(size < n){
            size*=2;
        }
        sums.assign(2*size,0);
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < a.size()){
                sums[x] = a[lx];
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, x*2 + 1, lx, m);
        build(a, x*2 + 2, m, rx);
        sums[x] = sums[x*2 + 1] + sums[x*2 + 2];
    }
    void unset(int i){
        unset(i,0,0,size);
    }
    void unset(int i, int x, int lx, int rx){
        if(rx-lx==1){
            sums[x] = 0;
            return;
        }
        int m = (lx + rx)/2;
        if(i < m){
            unset(i, x*2 + 1, lx, m);
        }
        else
            unset(i, x*2 + 2, m, rx);
        sums[x] = sums[x*2 + 1] + sums[x*2 + 2];
    }
    int query(int k){
        return query(k, 0, 0, size);
    }
    int query(int k, int x, int lx, int rx){
        if(rx-lx==1){
            return lx;
        }
        int m = (lx + rx)/2;
        int res;
        if( k <= sums[x*2 + 2])
            res = query(k, x*2+2, m, rx);
        else
            res = query(k-sums[x*2+2], x*2 + 1, lx, m);
        return res;
    }
};


int main(){
    Shazam;
    int n; cin>>n; 
    vector<int> a(n);
    for(int &i : a)
        cin>>i;
    vector<int> filler(n,1);
    Segtree seg;
    seg.init(n);
    seg.build(filler);
    vector<int> ans(n);
    for(int i = n-1 ; i >= 0; i--){
        int res = seg.query(a[i]+ 1);
        seg.unset(res);
        ans[i] = res+1;
    }
    pra(ans);
   
    return 0;
}