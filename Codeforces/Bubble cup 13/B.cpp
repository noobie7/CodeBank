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

vector<vector<pair<ll,ll>>> g(1e4 + 5);
vector<ll> dp(1e4 + 5);
int n;


ll sol(int i, int last = - 1){
    if(i>n+1) return 0;
    if(dp[i]!=-1) return dp[i];
    ll res = n+2;
    for(auto v : g[i]){
        res = min(res, v.ss);
    }
    return dp[i] = res;
}

int main(){
    Shazam;
    int m; cin>>n>>m;
    for(int i = 0 ; i < m; i++){
        int a; cin>>a;
        int b,c; cin>>b>>c;
        g[a].push_back({b,c});
    }
    dp.assign(n+1,-1);
    cout<<sol(1)<<endl;
    return 0;
}