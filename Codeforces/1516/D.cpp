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
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define get(a) for(auto &i : a)  cin>>i;
#define pra(a) for(auto i : a) cout<< i <<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;
const int N = 1e5 + 5;


int main(){
    Shazam;
    vector<int> p[N];
    vector<vector<int>> dp(20, vector<int> (N));
    vector<int> next(N);
    int n; cin >> n;
    int q; cin >> q;
    vector<int> a(n);
    get(a);
    for(int i = 2; i < N; i++){
        if(p[i].empty()){
            next[i] = n + 1;
            for(int j = i; j < N; j += i){
                p[j].push_back(i);
            }
        }
    }
    dp[0][n + 1] = n + 1;
    for(int i = n; i > 0; i--){
        dp[0][i] = dp[0][i + 1];
        for(int j : p[a[i - 1]]){
            dp[0][i] = min(dp[0][i], next[j]);
            next[j] = i;
        }
    }
    for(int i =  1; i < 20; i++){
        for(int j = 1; j <= n + 1; j++){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    while(q--){
        int l, r; cin >> l >> r;
        int ans = 0;
        for(int i = 19; i >= 0; i--){
            if(dp[i][l] <= r){
                ans += (1 << i);
                l = dp[i][l];
            }
        }
        cout << ans + 1 << endl;
    }
    return 0;
}