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

vector<int> vis;
vector<vector<int>> g;
int cnt = 0;
int ok ;

void dfs(int u){
    vis[u] = 1;
    cnt++;
    for(int i : g[u]){
        if(vis[i] == 2) continue;
        if(vis[i] == 1){
            ok = 1;
            continue;
        }
        dfs(i);
    }
    vis[u] = 2;
}

int main(){
    Shazam;
    test(){
        int n; cin >> n;
        int m; cin >> m;
        vector<pair<int,int>> a(m);
               
        for(int i = 0; i < m; i++){
            cin >> a[i].ff >> a[i].ss;
            a[i].ss--;
            a[i].ff--;
        }
        int ans = 0;
        vector<int> in(n);
        vis = vector<int> (n);
        g = vector<vector<int>> (n);
        for(auto pp : a){
            if(pp.ss == pp.ff){
                vis[pp.ss] = 2;
            }
            else{
                g[pp.ff].push_back(pp.ss);
                in[pp.ss]++;
            }
        }
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 2) continue;
            if(!g[i].size()) continue;
            if(in[i] == 0){
                cnt = 0;
                dfs(i);
                ans += cnt - 1;
            } 
        }

        for(int i = 0; i < n; i++){
            if(vis[i] == 2) {
                continue;
            }
            if(!g[i].size()) {
                continue;
            }
            cnt = 0;
            ok = 0;
            if(!vis[i]){
                dfs(i);
                ans += cnt + ok;
            }
        }
        cout << ans << endl;
    }
    return 0;
}