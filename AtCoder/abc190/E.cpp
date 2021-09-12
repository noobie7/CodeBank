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
const int inf = 1e9;
const int mod1 = 1e9 + 7;
vector<vector<int>> g(1e5 + 5);
map<int,vector<int>> dis;
vector<vector<int>> dp(1 << 18, vector<int>(18, inf));
int main(){
    Shazam;
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; 
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k; cin >> k;
    vector<int> c(k);
    get(c);
    auto operate = [&](int a){
        queue<int> q;
        dis[a] = vector<int> (1e5 + 5, inf);
        dis[a][a] = 0;
        q.push(a);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : g[u]){
                if(dis[a][v] == inf){
                    dis[a][v] = dis[a][u] + 1;
                    q.push(v);
                }
            }
        }
    };
    for(int i : c){
        operate(i);
    }
    for(int i = 0; i < k; i++){
        dp[(1 << i)][i] = 1;
    }

    for(int mask = 1; mask < (1 << k); mask++){
        for(int from = 0; from < k ; from++){
            for(int to = 0; to < k && ((mask >> from ) & 1 ); to++){
                dp[mask |(1 << to)][to] = min(dp[mask | (1 << to)][to], dp[mask][from] + dis[c[from]][c[to]]);
            }
        }
    }
    int ans = inf;
    for(int i = 0; i < k; i++)
        ans = min(ans, dp[(1 << k) - 1][i]);
    if(ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}