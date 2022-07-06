/*
    "An anomaly, I'm Muhammad Ali
    Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;

vector<int> in(2e5 + 5);
vector<int> out(2e5 + 5);
vector<vector<int>> g(2e5 + 5);
vector<pair<int, int>> ans(2e5 + 5);
int t = 1;
vector<int> leaves;
void dfs1(int u, int p){
    
    if(g[u].size() == 1 && u){
        leaves.push_back(u);
    }
    for(int v : g[u]){
        if(v == p)
            continue;   
        dfs1(v, u);
    }
}
map<int, pair<int, int>> init;
pair<int,int> dfs2(int u, int p){
    ans[u] = {0, 0};
    if(init.count(u)){
        return ans[u] = init[u];
    }
    int l = INT_MAX;
    int r = INT_MIN;
    for(int v : g[u]){
        if(v == p)
            continue;
        auto pp = dfs2(v, u);
        l = min(pp.first, l);
        r = max(pp.second, r);
    }
    return ans[u] = make_pair(l, r);
}


int main(){
    ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(0, -1);
    int c = 1;
    for(int i : leaves){
        init[i] = {c, c};
        c++;
    }
    dfs2(0, -1);
    for(int i = 0; i < n; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    
    return 0;
}