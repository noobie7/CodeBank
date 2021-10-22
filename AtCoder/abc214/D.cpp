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
    ll ans = 0;
    priority_queue<pair<ll, pair<int,int>>> q;
    for(int i = 0; i < n - 1; i++){
        ll a, b, c; cin >> a >> b >> c;
        a--, b--;
        q.push({-c, {a, b}});
    }
    vector<list<int>> idx(n);
    for(int i = 0; i < n; i++){
        idx[i].push_back(i);
    }
    vector<int> leader(n);
    iota(all(leader), 0);
    while(!q.empty()){
        auto edge = q.top();
        q.pop();
        ll w = edge.ff;
        ll a = edge.ss.ff;
        ll b = edge.ss.ss;
        a = leader[a];
        b = leader[b];
        ans += -1 * w * (ll)idx[a].size() * (ll)idx[b].size();
        if(idx[a].size() > idx[b].size()){
            swap(a, b);
        }
        for(int i : idx[a]){
            leader[i] = b;
            idx[b].push_back(i);
        }
    }
    cout << ans << endl;
    
    return 0;
}