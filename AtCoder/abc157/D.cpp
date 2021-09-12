/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
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
int id, comp_count;
vector<vector<int>> g(1e5 + 5);
vector<int> vis(1e5 + 5);
vector<int> component_id(1e5 + 5);
vector<int> c_size(1e5 + 5);
void dfs(int u){
    vis[u] = true;
    component_id[u] = id;
    //c_size[id]++;
    comp_count++;
    for(int b : g[u]){
        if(!vis[b])
            dfs(b);
    }
}

int main(){
    Shazam;
    int n, m, k; cin>>n>>m>>k;
    for(int i = 0 ; i < m; i++){
        int a, b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    id = 1;
    for(int i = 1; i <=n; i++ ){
       if(!vis[i]){ 
        comp_count = 0;
        dfs(i);
        c_size[id++] = comp_count;
       }
    }
    vector<int> ans(n+1,-1);
    for(int i = 0; i < k; i++){
        int a,b; cin>>a>>b;
        if(component_id[a]==component_id[b])
            ans[a]--, ans[b]--;
    }
    for(int i = 1; i < n+1; i++){
        cout<<c_size[component_id[i]] + ans[i] - g[i].size()<<" ";
    }
    cout<<endl;

    return 0;
}