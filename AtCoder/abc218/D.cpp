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
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].ff >> a[i].ss;
    }
    ll ans = 0;
    map<int, vector<int>> f;
    for(int i = 0; i < n; i++){
        f[a[i].ss].push_back(a[i].ff);
    }
    vector<vector<int>> g;
    for(auto pp : f){
        g.push_back(pp.ss);
    }
    for(int i = 0; i < g.size(); i++){
        map<int, int> cnt;
        for(int v : g[i]){
            cnt[v]++;
        }
        for(int j = i + 1; j < g.size(); j++){
            map<int,int> curr = cnt;
            for(int v : g[j]){
                curr[v]++;
            }
            ll counter = 0;
            for(auto pp : curr){
                counter += (pp.ss == 2);
            }
            ans += (counter * (counter - 1)) / 2;
        }

    }
    cout << ans << endl;
    return 0;
}