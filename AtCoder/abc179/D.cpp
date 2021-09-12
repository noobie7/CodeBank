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
const int mod =  998244353;

set<int> jp;

void add(ll &a, ll b){
    a = (a + b)%mod;
}

vector<ll> dp;

ll solve(int i){
    if(i==1) return 1;
    if(dp[i]!=-1) return dp[i];
    ll res = 0;
    for(auto p : jp){
        if(i-p>=1)
            add(res, solve(i-p));
    }
    return dp[i] = res%mod;
}

int main(){
    Shazam;
    int n; cin>>n;
    int k; cin>>k;
    dp.assign(n+1,-1);
    for(int i = 0 ; i < k; i++){
        int a, b; cin>>a>>b;
        for(int j = a; j <= b; j++){
            jp.insert(j);
        }
    }
    cout<<solve(n)<<endl;
    return 0;
}