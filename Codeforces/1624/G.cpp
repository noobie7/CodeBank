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
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            int w; cin >> w;
            a--;
            b--;
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }
        int mbit = 30;
        ll curr = (1LL << (mbit + 1)) - 1;
        function<void(int, vector<int> &)> dfs = [&](int u, vector<int> &used){
            used[u] = 1;
            for(auto vw : g[u]){
                auto v = vw.first;
                auto w = vw.second;
                if(!used[v] && (curr | w) == curr){
                    dfs(v, used);
                }
            }
        };

        auto calc = [&](int bit){
            ll d = (1LL << bit);
            curr -= d;
            vector<int> used(n);
            dfs(0, used);
            for(int i : used){
                if(!i){
                    curr += d;
                    break;
                }
            }
        };
        for(int bit = mbit; bit >= 0; bit--){
            calc(bit);
        }
        cout << curr << endl;
    }

    return 0;
}