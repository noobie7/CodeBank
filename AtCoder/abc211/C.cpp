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
const int mod = 1e9 + 7;



int main(){
    Shazam;
    string s; cin >> s;
    int n = s.size();
    vector<ll> dp(n);
    for(int i = 0; i < n; i++){
        dp[i] = (s[i] == 'c');
        if(i) dp[i] += dp[i - 1];
    }

    string theChosenOne = "hokudai";
    for(int c = 0; c < 7; c++){
        vector<ll> curr(n);
        for(int i = 1; i < n; i++){
            if(s[i] == theChosenOne[c]){
                curr[i] = dp[i];
            }
            curr[i] = (curr[i] + curr[i - 1]) % mod;
        }
        dp = curr;
    }
    cout << dp.back() << endl;
    return 0;
}