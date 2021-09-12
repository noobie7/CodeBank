/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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

vector<vector<int>> g(2e5 + 5);
vector<int> vis(2e5 + 5);

void dfs(int u, int &mini, int &maxi){
    vis[u] = 1;
    mini = min(mini, u);
    maxi = max(maxi, u);
    for(int v : g[u]){
        if(!vis[v])
            dfs(v, mini, maxi);
    }
}

int main(){
    Shazam;
    int n,m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<pair<int,int>> range;
    for(int i = 1; i < n+1; i++){
        if(!vis[i]){
            int mini = i;
            int maxi = i;
            dfs(i, mini, maxi);
            range.push_back({mini,maxi});
        }
    }
    int ans = 0;
    int end = -1;
    for(auto pp : range){
        if(pp.ff<= end) 
            ans++;
        end = max(end, pp.ss);
    }
    cout<<ans<<endl;
    return 0;
}