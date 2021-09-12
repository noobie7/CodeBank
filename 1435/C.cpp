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
    vector<ll> off(6);
    get(off);
    int n; cin>>n;
    vector<ll> a(n);
    get(a);
    vector<vector<ll>> x(n, vector<ll> (6)); 
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < 6; j++){
            x[i][j] = a[i]-off[j];
        }
        sort(all(x[i]));
    }
    vector<pair<ll, int>> diffs;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < 6; j++){
            diffs.push_back({x[i][j],i});
        }
    }
    sort(all(diffs));
    multiset<int> best;
    for(int i = 0; i < n; i++){
        best.insert(x[i][0]);
    }
    vector<int> ptr(n);
    ll ans = 1e18;
    ll mx = *prev(best.end());
    ll mn = *best.begin();
    ans = min(ans, mx-mn);
    for(auto p : diffs){
        best.erase(best.find(x[p.ss][ptr[p.ss]]));
        ++ptr[p.ss];
        if(ptr[p.ss] == 6) break;
        best.insert( x[p.ss][ptr[p.ss]] );
        mx = *prev(best.end());
        mn = *best.begin();
        ans = min(ans, mx - mn);
    }
    cout<<ans<<endl;
    return 0;
}