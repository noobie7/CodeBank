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
#define pra(a) fl(i,0,a.size()) cout<<a[i]<<endl;
#define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin >> n;
    int m; cin >> m;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        if(a > b){
            swap(a, b);
        }
        g[a].push_back(b);
    }
    vector<int> leader(n);
    vector<list<int>> lister(n);
    iota(all(leader), 0);
    for(int i = 0 ; i < n; i++){
        lister[i].push_back(i);
    }
    int i = n - 1;
    vector<int> ans(n);
    int comp = 0;
    while(i >= 0){
        ans[i] = comp;
        comp++;
        for(int v : g[i]){
            v = leader[v];
            int I = leader[i];
            if(I!= v){
                comp--;
                if(lister[I].size() > lister[v].size()){
                    swap(I, v);
                }
                for(int u : lister[I]){
                    leader[u] = v;
                    lister[v].push_back(u);
                }
            }
        }
        i--;    
    }
    pra(ans);
    return 0;
}