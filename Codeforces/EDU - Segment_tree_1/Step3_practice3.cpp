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
        sums.assign(size*2, 0);
    }
    void set(int i, int val){
        set(i, val, 0, 0, size);
    }
    void set(int i, int val, int x, int lx, int rx){
        if( rx - lx ==1){
            sums[lx] = val;
            return;
        }
        int m = (lx + rx)/2;
        if(i < m)
            set(i, val, x*2 + 1, lx, m);
        else
            set(i, val, x*2 + 2,  m, rx);
        sums[x] = sums[x*2 + 1] + sums[x*2 + 2];
    }
    int query(int l, int r){
        return query(l, r, 0, 0, size);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(rx <= l || r <= lx) return 0;
        if(l <= lx && rx <= r) return sums[x];
        int m = (lx + rx)/2;
        return query(l,r,x*2+1,lx,m) + query(l,r,x*2+2,m,rx);
    }
};

int main(){
    Shazam;
    int n; cin>>n;
    vector<int> a(2*n);
    for(int i = 0 ; i < 2*n; i++) cin>>a[i], a[i]--;
    map<int,int> left_end;
    for(int i = 0 ; i < 2*n; i++){
        if(!left_end.count(a[i])){
            left_end[a[i]] = i;
        }
    }
    Segtree seg;
    seg.init(2*n);
    vector<int> ans(n);
    vector<int> encountered(n);
    for(int i = 0; i < 2*n; i++){
        if(!encountered[a[i]]){
            encountered[a[i]] = 1;
            continue;
        }
        ans[a[i]] = seg.query(left_end[a[i]],i);
        seg.set(left_end[a[i]],1);
    }
    pra(ans);
    return 0;
}