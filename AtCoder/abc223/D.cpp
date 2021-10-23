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
    int n; cin >> n;
    int m; cin >> m;
    vector<int> indeg(n);
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        indeg[b]++;
    }
    priority_queue<int> q;
    for(int i = 0; i < n; i++){
        if(indeg[i] == 0){
            q.push(-i);
        }
    }
    vector<int> ans;
    while(!q.empty()){
        int u = abs(q.top());
        q.pop();
        ans.push_back(u + 1);
        for(int v : g[u]){
            indeg[v]--;
            if(indeg[v] == 0){
                q.push(-v);
            }
        }
    }
    if(ans.size() != n){
        cout << -1 << endl;
    }
    else{
        pra(ans);
    }
    return 0;
}