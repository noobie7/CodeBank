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



int main(){
    Shazam;
    int n, m; cin >> n >> m;
    int k; cin >> k;
    map<int, vector<int>> ro, co;
    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        ro[a].push_back(b);
        co[b].push_back(a);
    }
    for(int i = 1; i < n + 1; i++){
        ro[i].push_back(m + 1);
    }
    for(int i = 1; i < m + 1; i++){
        co[i].push_back(n + 1);
    }
    for(auto pp : ro){
        sort(all(pp.ss));
    }
    for(auto pp : co){
        sort(all(pp.ss));
    }

    vector<ll> xlim(n + 1), clim(m + 1);
    vector<ll> ct(m + 1);
    for(int i = 1; i <= n; i++){
        xlim[i] = ro[i].front() - 1;
    }
    for(int i = 1; i <= m; i++){
        clim[i] = co[i].front() - 1;
    }
    ll ans = 0;
    for(int i = 1; i <= clim[1]; i++){
        ans += xlim[i];
        
    }
    cout << ans << endl;
    for(int i = 2; i <= xlim[1]; i++){
        cout << clim[i] << " " << clim[1] << endl;
        ans += max(0LL, clim[i] - clim[1]);
    }
    cout << ans << endl;
    return 0;
}