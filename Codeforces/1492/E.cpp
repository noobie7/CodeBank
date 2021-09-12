/*
    i have to write sqrt decomposition from scratch
*/
#define dbg(...)
#define db(...)
#define dbgl(...)
#define assrt(c)   
#include "bits/stdc++.h"
using namespace std;using ll=long long;using ld = long double;
#define _(_1, _2, _3, _4, NAME, ...) NAME
#define f3(i, a, b, inc) for(int i = (a) - (inc < 0); (inc) > 0 ? i < (b) : i >= (b); i += (inc))
#define f2(i, a, b) f3(i, a, b, 1 - 2*(a > b))
#define f1(i, n) f2(i, 0, n)
#define f0(i) f2(i, 0, n)
#define fr(...) _(__VA_ARGS__, f3, f2, f1 , f0)(__VA_ARGS__)
#define trav(i,x) for(auto& i: x)
#define sz(x) ((int)(x).size())
#define len(x) ((int)(x).length())
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define all(x) begin(x),end(x)
const int mod = 1e9+7,inf = 1e9 , N = 1e5 + 100;
const ll MOD = 1e9+7,INF = 1e19; ld tic,tac;
int tc = 1;

ll color[N], path[N],tin[N], tout[N] , cnt[N], ccnt[N],sum[N], ans[N];
vector<int> g[N];
ll n, timer;
void dfs(int v, int p = -1)
{
   tin[v] = ++timer;
   path[timer] = color[v];
   for (auto to : g[v])
      if (to != p)
         dfs(to, v);
   tout[v] = timer;
}
namespace sqrtDecomp{
    const int block = 400;
    struct Mo{
       int l, r, id;
       Mo (int l, int r, int id) : l(l), r(r), id(id) {}
       bool operator <(const Mo &N)const{
          return l / block == N.l / block ? r < N.r : l / block < N.l / block;
       }
    };
    int l = 1,r = 0;
    multiset<int> mx;
    void add(int pos){
       sum[cnt[path[pos]]] -= path[pos];
       cnt[path[pos]]++;
       mx.insert(cnt[path[pos]]);
       sum[cnt[path[pos]]] += path[pos];
    }
    void del(int pos){
       sum[cnt[path[pos]]] -= path[pos];
       mx.erase(mx.lower_bound(cnt[path[pos]]));
       cnt[path[pos]]--;
       sum[cnt[path[pos]]] += path[pos];
    }
    void processquery(Mo cur){
        while (l > cur.l)
            add(--l);
        while (r > cur.r)
            del(r--);
        while (r < cur.r)
            add(++r);
        while (l < cur.l)
            del(l++);
    };

};
using namespace sqrtDecomp;
void solve(){
    cin>>n;
    fr(i,1,n+1) 
        cin>>color[i];
    fr(i,n-1)
    {
        int u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1);
    vector<Mo> queries;
    fr(i,1,n+1)
        queries.pb(Mo(tin[i], tout[i], i));
    sort(queries.begin(), queries.end());

    vector<ll> ans(n+1);
    for(auto cur:queries){
        processquery(cur);
        ans[cur.id] = sum[*--mx.end()];
    }
    fr(i,1,n+1) cout << ans[i] << " "; cout << endl;
}

int main(){
    ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);cout << fixed << setprecision(10);
    if(tc != 1)cin>>tc;
    for (int i = 1; i <= tc; ++i){
        // n = i;
        if(!ONLINE_JUDGE) cerr << "\nWhile solving TC " << i << ":\n", tic = clock(); 
        solve(); 
        if(!ONLINE_JUDGE) tac = clock(), cerr << "\nTC " << i << " done in:: " << 1000 * (tac-tic) / CLOCKS_PER_SEC << " ms\n";
    }
    if(!ONLINE_JUDGE) cerr << "\nGG in: " << 1000 * ((ld)clock()) / CLOCKS_PER_SEC << " ms\n";
    return 0;
}