/*
"Do I really belong in this game I ponder, I just wanna play my part."
- Guts over fear, Eminem
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
    vector<pair<int,pair<int,int>>> dp(1004,{-1,{-1,-1}});
    dp[3] = {1,{0,0}};
    dp[5] = {0,{1,0}};
    dp[7] = {0,{0,1}};
    for(int i = 3; i < 1004; i++){
        if(dp[i].ff==-1) continue;
        if(i+3 < 1004) dp[i+3] = {dp[i].ff + 1, {dp[i].ss.ff,dp[i].ss.ss}};
        if(i+5 < 1004) dp[i+5] = {dp[i].ff, {dp[i].ss.ff+1,dp[i].ss.ss}};;
        if(i+7 < 1004) dp[i+7] = {dp[i].ff , {dp[i].ss.ff,dp[i].ss.ss+1}};;
    }
    test(){
        int i; cin>>i;
        if(dp[i].ff==-1) cout<<-1<<endl;
        else cout<<dp[i].ff<<" "<<dp[i].ss.ff<<" "<<dp[i].ss.ss<<endl;
    }
    return 0;
}