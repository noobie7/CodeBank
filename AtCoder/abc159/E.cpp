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
    int n,m,k; cin>>n>>m>>k;
    vector<string> a(n);
    get(a);
    vector<int> id(n);
    ll ans = INT_MAX;
    for(int mask = 0; mask < (1<<(n - 1)); mask++){
        int g = 1;
        id.clear();
        for(int i = 1,  t = mask; i < n; t >>= 1, i++){
            g += (t & 1);
            id[i] = g - 1;
        }
        ll curr = g - 1;
        vector<int> dp(curr + 1);
        for(int col = 0; col < m; col++){
            bool ovrflw = 0;
            for(int row = 0; row < n; row++){
                dp[id[row]] += a[row][col] == '1';
                if(dp[id[row]] > k) ovrflw = 1;
            }
            if(ovrflw){
                curr++;
                fill(all(dp), 0);
                for(int row = 0; row < n; row++){
                    dp[id[row]] += a[row][col] == '1';
                    if(dp[id[row]] > k){
                        curr = ans;
                        break;
                    }
                }
            }
            
        }
        ans = min(ans, curr);
    }
    cout<<ans<<endl;
    return 0;
}