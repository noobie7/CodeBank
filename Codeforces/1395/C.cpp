/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
 */
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
    int n,m; cin>>n>>m;
    vector<ll> a(n+1), b(m+1);
    for(int i = 1; i < n+1; i++) cin>>a[i];
    for(int j = 1; j < m+1; j++) cin>>b[j];
    bool dp[n+1][1026];
    memset(dp, false, sizeof dp);
    dp[0][0] = 1;
    for(int i = 1 ; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
           for(int mask = 0; mask < (1LL<<9); mask++){
               if(dp[i-1][mask]){
                   dp[i][((a[i]&b[j])|mask)] = true; 
               }
           }
        }
    }
    for(int i = 0; i < i < 1025; i++){
        if(dp[n][i]){
            cout<<i<<endl;
            return 0;

        }
    }
}