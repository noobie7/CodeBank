/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;

int dp[30005][4][1005];

int main(){
    Shazam;
    int n; cin >> n;
    string s; cin >> s;
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            for(int num = 0; num < 1000; num++){
                if(!dp[i][j][num]) continue;
                dp[i + 1][j][num] = 1;
                if(j <= 2){
                    dp[i + 1][j + 1][num * 10 + s[i] - '0'] = 1;
                }
            }
        }
    }
    int ans = 0;
    for(int num = 0; num < 1000; num++){
        ans += (dp[n][3][num]);
    }
    cout << ans << endl;
    return 0;
}