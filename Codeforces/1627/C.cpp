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
        vector<int> deg(n);
        vector<vector<int>> g(n);
        map<pair<int,int>, int> f;
        for(int i = 0; i < n - 1; i++){
            int a, b; cin >> a >> b;
            a--;
            b--;
            deg[a]++, deg[b]++;
            g[a].push_back(b);
            g[b].push_back(a);
            f[{min(a, b), max(a, b)}] = i;
        }
        if(*max_element(all(deg)) > 2){
            cout << -1 << endl;
            continue;
        }
        int root = -1;
        int des = -1;
        for(int i = 0; i < n; i++){
            if(deg[i] == 1){
                if(root == -1)
                    root = i;
                else    
                    des = i;
            }
        }
        assert(count(all(deg), 1) == 2);
        vector<int> ans(n - 1);
        int p = -1;
        int turn = 0;
        while(root != des){
            int u = root;
            int v = g[u][0];
            if(v == p){
                v = g[u][1];
            }
            ans[f[{min(u, v), max(u, v)}]] = (turn & 1 ? 2 : 3);
            turn ^= 1;
            p = u;
            root = v;
        }
        pra(ans);
    }
    return 0;
}