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
    int n; cin >> n;
    int q; cin >> q;
    vector<int> x(n);
    get(x);
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    map<int, vector<int>> ans;
    function<vector<int>(int, int)> dfs = [&](int u, int p){
        vector<int> res(1, x[u]); 
        for(int v : g[u]){
            if(p == v) continue;
            auto curr =  dfs(v, u);
            while(curr.size()){
                res.push_back(curr.back());
                curr.pop_back();
            }
        }
        sort(res.rbegin(), res.rend());
        while(res.size() > 20){
            res.pop_back();
        }
        ans[u] = res;
        return res;
    };
    dfs(0, -1);
   
    for(int i = 0; i < q; i++){
        int u, r; cin >> u >> r;
        u--;
        r--;
        cout << ans[u][r] << endl;
    }


    return 0;
}