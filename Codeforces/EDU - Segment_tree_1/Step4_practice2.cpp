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
int r;
struct M{
    ll a = 1,b = 1,c = 1,d = 1;
};

M combine( M & m1, M & m2){
  M res; 
  /*
  | m1.a m1.b | | m2.a m2.b |
  | m1.c m1.d | | m2.c m2.d |
  */
  res.a = (m1.a * m2.a % r + m1.b * m2.c % r) % r;  
  res.b = (m1.a * m2.b % r + m1.b * m2.d % r) % r;  
  res.c = (m1.c * m2.a % r + m1.d * m2.c % r) % r;  
  res.d = (m1.c * m2.b % r + m1.d * m2.d % r) % r;    
  return res;
}

struct Segtree{
    int size;
    vector<M> t;

    void init(int n){
      size = 1;
      while(size < n) size *= 2;
      M nu;
      t.assign(2*size, nu);
    }

    void build(vector<M> &a){
      build(a,0,0,size);
    }
    void build(vector<M> &a, int x, int l, int r){
      if(r-l==1){
        if(l < a.size()){
          t[x] = a[l];
        }
        return;
      }
      int m = (l + r)/2;
      build(a, 2*x + 1, l, m);
      build(a, 2*x + 2, m, r);
      t[x] = combine(t[x*2 + 1], t[x*2 + 2]);
    }
    M range(int l, int r){
      return range(l,r,0,0,size);
    }
    M range(int l, int r, int x, int lx, int rx){
      if(r <= lx || rx <= l) {
        M res;
        res.a = 1, res.b = 0, res.c = 0, res.d = 1;
        return res;
      }
      if(l <= lx&&rx <= r)  return t[x];
      int m = (lx + rx)/2;
      M res1 = range(l,r,x*2 + 1, lx, m);
      M res2 = range(l,r,x*2 + 2,  m,rx);
      return combine(res1, res2);
    }
};


int main(){
    Shazam;

    cin>>r;
    int n; cin>>n;
    int q; cin>>q;
    vector<M> A(n);
    for(int i = 0 ; i < n; i++){
      cin>>A[i].a>>A[i].b>>A[i].c>>A[i].d;
    }
    Segtree seg;
    seg.init(n+1);
    seg.build(A);
    for(int i = 0; i < q; i++){
      int l, r; cin>>l>>r;
      l--;
      M res = seg.range(l,r);
      cout<<res.a<<" "<<res.b<<endl;
      cout<<res.c<<" "<<res.d<<endl;
      cout<<endl;
    }

    return 0;
}