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
    test(){
        int n; cin>>n;
        vector<int> ans(n,-1);
        vector<vector<int>> g(n);
        for(int i = 0 ; i < n-1; i++){
            int a,b; cin>>a>>b;
            a--;
            b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        queue<int> q;
        q.push(0);
        ans[0] = 1;
        while(!q.empty()){
            int tp = q.front();
            q.pop();
            for(int v : g[tp]){
                if(ans[v]!=-1) continue;
                q.push(v);
                ans[v] = !ans[tp];
            }
        }
        for(int i : ans){
            cout<<i+1<<" ";
        }
        cout<<endl;
    }
    return 0;
}