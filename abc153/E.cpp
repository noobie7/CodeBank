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
    int h,n; cin>>h>>n;
    vector<int> dp(h+1, 1e9 + 9);
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        int a,b; cin>>a>>b;
        for(int j = 0; j < (int)dp.size(); j++){
            int nj =  min(j + a, h);
            dp[nj] = min(dp[nj], dp[j] + b);
        }
    }
    cout<<dp[h]<<endl;
    return 0;
}