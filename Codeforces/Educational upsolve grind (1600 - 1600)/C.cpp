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
    int n; cin >> n;
    vector<ll> a(n);
    get(a);
    int m; cin >> m;
    vector<ll> b(m);
    get(b);
    
    int ans = 0;
    int i = 0;
    int j = 0;
    ll ca = a[i++];
    ll cb = b[j++];
    while(i < n && j < m){
        if(ca == cb){
            ans++;
            ca = a[i++];
            cb = b[j++];
            continue;
        }
        if(ca < cb){
            ca += a[i++];
            continue;
        }
        else{
            cb += b[j++];
            continue;
        }
    }
    while(i < n) ca += a[i++];
    while(j < m) cb += b[j++];
    if(ca != cb) ans = 0;
    else if(ca) ans++;
    cout << (ans == 0 ? -1 : ans) << endl;
    return 0;
}