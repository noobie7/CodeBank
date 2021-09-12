/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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
    string s; cin>>s;
    int n = (int)s.size();
    vector<vector<ll>> dp(n,vector<ll> (13));
    ll p10 = 10;
    if(s.back()!='?'){
        dp[n-1][s.back()-'0']++;
    }
    else{
        for(int dig = 0; dig < 10; dig++){
            dp[n-1][dig%13]++;
        }
    }
    auto add = [&](ll &a ,ll b){
        a = (a+b)%mod1;
    };
    for(int i = n-2; i >= 0; i--){
        if(s[i]=='?'){
            for(int dig = 0; dig < 10; dig++){
                for(int mod = 0; mod < 13; mod++){
                    add(dp[i][(dig*p10%13 + mod)%13], dp[i+1][mod]);
                }
            }
        }
        else{
            for(int mod = 0; mod < 13; mod++){
                add(dp[i][(mod + (s[i]-'0')*p10%13)%13] , dp[i+1][mod]);
            }
        }
        p10 = p10*10%13;
    }
    cout<<dp[0][5]<<endl;
    return 0;
}