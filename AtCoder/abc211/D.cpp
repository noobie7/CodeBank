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
const int mod = 1e9 + 7;



int main(){
    Shazam;
    int n, m; cin >> n >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dis(n, inf);
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            if(dis[v] == inf){
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
    vector<ll> dp(n);
    auto add = [&](ll &a, ll b){
        a = (a + b)%mod;
    };
    dp[0] = 1;
    q.push(0);
    map<int, int> ins;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : g[u]){
            if(dis[v] == dis[u] + 1){
                dp[v] += dp[u];
                dp[v] %= mod;
                if(!ins[v]){
                    q.push(v);
                    ins[v] = 1;
                }
            }
        }
    }
    cout << dp[n - 1] << endl;
    return 0;
}