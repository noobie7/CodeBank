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

const int nag = 2e5 + 5;
vector<vector<int>> g(nag);
vector<vector<pair<int, int>>> favcount(nag);
vector<int> counter(nag);
vector<int> f(nag);
vector<int> path;
int dfs(int u, int p = -1){
    path.push_back(u);
    int res = f[u];
    for(int v : g[u]){
        if(v != p){
            int curr =  dfs(v, u);
            if(!f[u])
                favcount[u].push_back({curr, v});
            res += curr;
        }
    }
    return counter[u] = res;
}
void dfs2(int u, int p = 0){
    path.push_back(u);
    for(auto pp : favcount[u]){
        int v = pp.ss;
        if(v != p){
            dfs(v, u);
        }
    }
}
int main(){
    Shazam;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        f[i+1] = (c == 'F');
    }
    for(int i = 2; i <= n; i++){
        int k; cin >> k;
        g[k].push_back(i);
    }
    dfs(1, 0);
    vector<ll> final(n);
    for(int i = 0; i < n; i++){
        final[i] = f[path[i]]; 
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(favcount[i].size()){
            sort(favcount[i].rbegin(), favcount[i].rend()); 
        }
    }
    dfs2(1);
    for(int i = 0; i < n; i++){
        final[i] = f[path[i]];
    }
    ll curr = 0;
    for(int i = n -1; i >= 0; i--){
        if(!final[i]){
            ans += curr;
        }
        curr += final[i];
    }

    cout << ans << endl;
    return 0;
}