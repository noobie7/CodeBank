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
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int m; cin >> m;
    vector<vector<int>> g(10);
    for(int i = 0; i < m; i++){
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    string s = "999999999";
    for(int i = 1; i < 9; i++){
      int p; cin >> p;
      s[p - 1] = (char)(i + '0');
    }

    queue<string> q;
    q.push(s);
    map<string, int> f;
    f[s] = 0;
    while(!q.empty()){
      auto s = q.front();
      q.pop();
      int u;
      for(int i = 1; i <= 9; i++){
        if(s[i - 1] == '9')
          u = i;
      }
      for(auto v : g[u]){
        string t = s;
        swap(t[v - 1], t[u - 1]);
        if(f.count(t)) continue;
        f[t] = f[s] + 1;
        q.push(t);
      }
    }
    if(f.count("123456789") == 0) 
      cout << -1 << endl;
    else 
      cout << f["123456789"] << endl;
    return 0;
}