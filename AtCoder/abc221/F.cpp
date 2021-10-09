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
const int mod = 998244353;



int main(){
    Shazam;
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    set<int> bag1, bag2;
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int at = -1;
    auto bfs = [&](int s){
        vector<int> dis(n + 1, inf);
        queue<int> q;
        dis[s] = 0;
        q.push(s);
        int mx = 0;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : g[u]){
                if(dis[v] != inf) continue;
                dis[v] = dis[u] + 1;
                mx = max(mx, dis[v]);
                q.push(v);
            }
        }
        if(at == -1){
            for(int i = 1; i <= n; i++){
                if(dis[i] == mx){
                    at = i;
                    bag1.insert(i);
                }
            } 
        }
        else{
            for(int i = 1; i <= n; i++){
                if(dis[i] == mx){
                    at = i;
                    if(bag1.find(i) == bag1.end())
                        bag2.insert(i);
                }
            }
        }
    };
    bfs(1);
    bfs(at);
    if(bag2.size() == 0){
        ll ans = 1; 
        for(int i = 0; i < bag1.size(); i++){
            ans = ans * 2 % mod;
        }
        ans -= (1 + bag1.size());
        ans += mod;
        ans %= mod;
        cout << ans << endl;
        return 0;
    }
    ll ans = (ll)bag1.size() * (ll)bag2.size() % mod;
    cout << ans << endl;
    return 0;
}