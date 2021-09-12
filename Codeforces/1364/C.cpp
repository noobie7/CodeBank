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
    int n; cin>>n;
    vector<int> b(n); 
    get(b);
    vector<int> vis(n+1);
    vector<int> ans(n,-1);
    for(int i = 1; i < n; i++){
        if(b[i]!=b[i-1]){
            ans[i] = b[i-1];
            vis[ans[i]] = 1;
        }
    }
    vis[b[n-1]] = 1;
    
    int m = 0;
    for(int i = 0; i < n; i++){
        while(vis[m]) m++;
        if(ans[i]==-1){
            ans[i] = m;
            vis[m] = 1;
        }
    }
    pra(ans);


    return 0;
}