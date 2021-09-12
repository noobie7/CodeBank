/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

vector<vector<int>> g(2e5 + 5);
vector<int> par(2e5 + 5);
vector<ll> ans(2e5 + 5);
vector<pair<int,int>> egdes(2e5 + 5);
void dfs1(int u, int p = -1){
    for(int v : g[u]){
        if(v == p) continue;
        par[v] = u;
        dfs1(v, u);
    }
}

void dfs2(int u, int p , ll curr){
    ans[u] += curr;
    for(int v : g[u]){
        if(p == v) continue;
        dfs2(v, u, ans[u]);
    }
}

int main(){
    Shazam;
    int n; cin >> n;
    for(int i = 1; i < n; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        egdes[i] = {a,b};
    }
    dfs1(1);
    int q; cin >> q;
    while(q--){
        ll t, e, x; cin >> t >> e >> x;
        int a = (t == 1? egdes[e].ff : egdes[e].ss );
        int b = (t == 1? egdes[e].ss : egdes[e].ff );
        if(a == par[b]){
            ans[1] += x;
            ans[b] -= x;
        } 
        else{
            ans[a] += x;
        }
    }
    ll curr = 0;
    dfs2(1, -1, curr);
    for(int i = 1;i <= n; i++){
        cout << ans[i] << endl;
    }
    cout << endl;
    return 0;
}