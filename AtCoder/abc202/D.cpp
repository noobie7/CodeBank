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
    int a, b; cin >> a >> b;
    ll k; cin >> k;
    vector<vector<ll>> dp(a + 1, vector<ll>(b + 1));
    dp[0][0] = 1;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            if(i)
                dp[i][j] += dp[i - 1][j];
            if(j)
                dp[i][j] += dp[i][j - 1];
        }
    }
    while(a > 0 && b > 0){
        if( k <= dp[a - 1][b]){
            cout << "a";
            a--;
        }
        else{
            k -= dp[a - 1][b];
            cout << "b";
            b--;
        }
    }
    cout << string(a, 'a');
    cout << string(b, 'b') << endl;
    return 0;
}