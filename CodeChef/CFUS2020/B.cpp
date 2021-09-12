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

pair<ll,int> combine(pair<ll,int> a, pair<ll,int> b){
    pair<ll,int> res;
    res.ss = a.ss + b.ss;
    res.ff = a.ff + b.ff;
    return res;
}

struct Segtree{
    int size;
    vector<pair<ll,int>> min_count;

    void init(int n){
        size = 1;
        while(size < n){
            size *=2;
        }
        min_count.assign(2*size,{0,0});
    }
    void build(vector<int> &a){
        build(a,0,0,size);
    }
    void build(vector<int> &a, int x, int lx, int rx){
        if(rx-lx==1){
            if( lx< (int)a.size()){
                min_count[x] = {a[lx],(a[lx]%2)};
            }
            return;
        }
        int m = (lx + rx)/2;
        build(a, x*2 + 1, lx, m);
        build(a, x*2 + 2, m, rx);
        min_count[x] = combine(min_count[x*2 + 1], min_count[x*2 + 2]);
    }

    pair<int,int> query(int l, int r){
        if(l>=r) return {0,0};
        return query(l,r,0,0,size);
    }
    pair<int,int> query(int l, int r, int x, int lx, int rx){
        if(rx<=l || r<=lx) return {0,0};
        if(l<= lx && rx<=r) return min_count[x];
        int m = (lx + rx )/2;
        auto p1 = query(l,r, x*2 + 1, lx, m);
        auto p2 = query(l,r, x*2 + 2, m, rx);
        return combine(p1, p2);
    }
};


int main(){
    Shazam;
    test(){
        int n; cin>>n;
        vector<int> a(n);
        for(int &i : a)
            cin>>i;
        vector<ll> pref(n+1);
        vector<int> oddcnt(n+1);
        map<int,int> prev;
        ll ans = 0;
        for(int i = 1; i < n+1; i++){
            if(prev.count(a[i-1])){
                if(a[i-1]&1){
                    if((oddcnt[i-1]-oddcnt[prev[a[i-1]]])&1){
                        ans = max(ans, pref[i-1]-pref[prev[a[i-1]]]);
                    }
                }
                else{
                    if((i-1 - prev[a[i-1]] - oddcnt[i-1]+oddcnt[prev[a[i-1]]])&1^1){
                        ans = max(ans, pref[i-1]-pref[prev[a[i-1]]]);
                    }
                }
                
            }
            prev[a[i-1]] = i;
            pref[i] = pref[i-1] + a[i-1];
            oddcnt[i] = (a[i-1]&1) + oddcnt[i-1];
        }     
        cout<<ans<<endl;
    }
    return 0;
}