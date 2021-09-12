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
    int n,p; cin>>n>>p;
    string s; cin>>s;
    if(p==2||p==5){
        ll ans = 0;
        for(int i = 0 ; i < n; i++){
            if((int)(s[i]-'0')%p == 0)
                ans += i+1;
        }
        cout<<ans<<endl;
        return 0;
    }
    vector<ll> cnt(p);
    cnt[0] = 1;
    ll pw = 1;
    ll ans = 0;
    ll curr = 0;
    for(int i = n-1; i>=0; i--){
        curr = ((s[i]-'0')*pw%p + curr)%p;
        ans+=cnt[curr];
        cnt[curr]++;
        pw = pw*10%p;
    }
    cout<<ans<<endl;
    return 0;
}