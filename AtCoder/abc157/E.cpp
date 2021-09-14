/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
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
    vector<int> cnt;
    
    void init(int n){
        size = 1;
        while(size <n){
            size*=2;
        }
        cnt.assign(2*size,0);
    }

    void build(string &a, char c){
        build(a, c,0,0,size);
    }
    void build(string &a, char c, int x, int lx, int rx){
        if(rx-lx==1){
            if(lx < (int)a.size())
                cnt[x] = (a[lx] == c);
            return;
        }
        int m = (lx + rx)/2;
        build(a,c,x*2+1, lx, m);
        build(a,c,x*2+2, m ,rx);
        cnt[x] = cnt[x*2+1] + cnt[x*2+2];
    }

    void set(int &id, int val){
        set(id,val,0,0,size );        
    }
    void set(int &id, int val, int x, int lx, int rx){
        if(rx-lx==1 ){
            cnt[x]+=val;
            return;
        }
        int m = (lx + rx)/2;
        if(id < m)
            set(id,val,x*2+1, lx, m);
        else
            set(id,val,x*2+2, m, rx);
        
        cnt[x] = cnt[x*2+1] + cnt[x*2+2];
    }
    int query(int l, int r){
        return query(l,r, 0, 0, size);
    }
    int query(int l, int r, int x, int lx, int rx){
        if(rx<=l || r <= lx) return 0;
        if(l<=lx && rx <= r) return cnt[x];
        int m = (lx + rx)/2;
        return query(l,r,x*2+1,lx,m) + query(l,r,x*2+2,m,rx);
    }
};


int main(){
    Shazam;
    int n; cin>>n;
    string s; cin>>s;
    int q; cin>>q;
    vector<Segtree> alpha(26);
    for(int i = 0 ; i < 26; i++){
        alpha[i].init(n);
        char h = (char)('a' + i);
        alpha[i].build(s, h);
    }
    while(q--){
        int t; cin>>t;
        if(t==1){
            int id;
            char c; 
            cin>>id;
            --id;
            cin>>c;
            if(s[id]==c) continue;
            int val = -1;
            alpha[s[id]-'a'].set(id,val);
            s[id] = c;
            val *= -1;
            alpha[s[id]-'a'].set(id,val);
        }
        else{
            int l,r; cin>>l>>r;
            --l;
            int ans = 0;
            for(int i = 0 ;i < 26; i++){
                if(alpha[i].query(l,r)) ans++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}