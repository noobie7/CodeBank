#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<vector<int>> g;
int bottom;
bool checkfordistance;
int dis;
int tip;
int n,a,b,c,d;
void dfs(int u, int p , int curr){
    bottom = max(curr, bottom);
    if(curr == bottom)
        tip = u;
    if(u==b && checkfordistance){
        dis = curr;
        return;
    }
    for(int v  : g[u]){
        if(v==p) continue;
        dfs(v,u,curr+1);
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        
        cin>>n>>a>>b>>c>>d;
        g = vector<vector<int>>(n+5);
        for(int i = 0 ; i < n-1; i++){
            int x,y; cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        checkfordistance = true;
        dfs(a,0,0);
        checkfordistance = false;
        if(dis <=c){
            cout<<"Alice"<<endl;
            continue;
        }
        bottom = 0;
        dfs(1,0,0);
        bottom = 0;
        dfs(tip, 0, 0);
        if(2*c >= bottom){
            cout<<"Alice"<<endl;
            continue;
        }
        if(d <= 2*c){
            cout<<"Alice"<<endl;
            continue;
        }
        cout<<"Bob"<<endl;
        
       
    }   
}