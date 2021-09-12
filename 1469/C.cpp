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
    test(){
        int n; cin >> n;
        ll k; cin >> k;
        k--;
        vector<ll> a(n); get(a);
        vector<ll> ul(n), ll(n);
        ul[0] = ll[0] = a[0];
        ul[n - 1] = ll[n - 1] = a[n - 1];
        for(int i = 1; i < n - 1; i++){
            ul[i] = min(a[i] + k, ul[i-1] + k);
            ll[i] = max(ll[i-1] - k, a[i]);
        }
        bool can = 1;
        for(int i = 1; i < n; i++){
            can &= (abs(ll[i - 1] - ul[i]) <= k &&  abs(ul[i - 1]- ll[i]) <= k );
        }
        cout << (can ? "Yes" : "No") << endl;
    }
    return 0;
}