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
        int n, m; cin >> n >> m;
        vector<vector<pair<int,int>>> g(n);
        vector<int> color(n, -1);
        vector<int> c(2);
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            string s; cin >> s;
            a--, b--;
            if(s == "crewmate"){
                g[a].push_back({b, 0});
                g[b].push_back({a, 0});
            }
            else{
                g[a].push_back({b, 1});
                g[b].push_back({a, 1});
            }
        }
        
        auto bfs = [&](int s){
            queue<int> q;
            q.push(s);
            color[s] = 1;
            c[0] = c[1] = 0;
            int ok = 1;
            while(q.size()){
                int u = q.front();
                c[color[u]]++;
                q.pop();
                for(auto pp : g[u]){
                    int v = pp.first;
                    int w = pp.second;
                    if(color[v] != -1){
                        if(color[v] != (color[u] ^ w)){
                            ok = 0;
                        }
                    }
                    else{
                        color[v] = color[u] ^ w;
                        q.push(v);
                    }
                }
            }  
            return ok;
        };
        int ok = 1;
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(color[i] == -1){
               ok &= bfs(i);
               ans += max(c[0], c[1]); 
            }
        }
        cout << (ok ? ans : -1) << endl;
    }
    return 0;
}