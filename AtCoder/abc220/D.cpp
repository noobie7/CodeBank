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
#define pr(a,n) fl(i,0,n) cout<<a[i]<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod = 998244353;



int main(){
    Shazam;
    int n; cin >> n;
    vector<int> a(n);
    get(a);
    vector<vector<int>> dp(n, vector<int> (10));
    dp[0][a[0]] = 1;

    auto get_added_from = [&](int i, int val){
        for(int j = 0; j < 10; j++){
            if((a[i] + j) % 10 == val){
                dp[i][val] += dp[i - 1][j];
                dp[i][val] %= mod;
            }
        }
    };

    auto get_multi_from = [&](int i, int val){
        for(int j = 0; j < 10; j++){
            if((a[i] * j) % 10 == val){
                dp[i][val] += dp[i - 1][j];
                dp[i][val] %= mod;
            }
        }
    };

    for(int i = 1; i < n; i++){
        for(int val = 0; val < 10; val++){
            get_added_from(i, val);
            get_multi_from(i, val);
        }
    }
    pra(dp.back());
    return 0;
}