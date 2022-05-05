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
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define get(a) for(auto &i : a)  cin>>i;
#define pra(a) for(auto i : a) cout<< i <<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n; cin >> n;
        vector<int> a(n + 1);
        vector<int> leaves;
        vector<int> par(n + 1);
        vector<int> vis(n + 1);
        vector<vector<int>> g(n + 1);
        vector<int> dis(n + 1);
        queue<int> q;
        vector<vector<int>> ans;
        vector<int> curr;
        int root;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        
        for(int i = 1; i <= n; i++){
            if(i == a[i]){
                root = i;
                continue;
            }
            g[a[i]].push_back(i);
        }
        
        q.push(root);
        int mx = 0;
        int mx_at = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(g[u].size() == 0){
                leaves.push_back(u);
            }
            for(int v : g[u]){
                par[v] = u;
                dis[v] = dis[u] + 1;
                if(mx < dis[v]){
                    mx = dis[v];
                    mx_at = v;
                }
                q.push(v);
            }
        }


        root = mx_at;
        while(root != a[root]){
            curr.push_back(root);
            vis[root] = 1;
            root = a[root];
        }
        curr.push_back(root); 
        vis[root] = 1;
        reverse(all(curr));
        ans.push_back(curr);


        for(int i : leaves){
            if(i == mx_at) continue;
            curr.clear();
            root = i;
            while(!vis[root]){
                curr.push_back(root);
                vis[root] = 1;
                root = a[root];     
            }
            reverse(all(curr));
            ans.push_back(curr);
        }
        cout << ans.size() << endl;
        for(auto v : ans){
            cout << v.size() << endl;
            for(int i : v){
                cout << i << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}