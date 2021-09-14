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
    vector<ll> a(n); 
    get(a);
    vector<ll> b(m);
    get(b);
    sort(all(a));
    sort(all(b));
    vector<ll> diff1(1,0), diff2;
    for(int i = 1; i < n; i += 2){
        diff1.push_back( diff1.back() + a[i] - a[i-1]);
    }
    for(int i = 1; i < n - 1; i += 2){
        diff2.push_back( a[i+1] - a[i]);
    }
    diff2.push_back(0);
    int x = diff2.size();
    for(int i = x - 2; i >= 0; i--){
        diff2[i] += diff2[i+1];
    }
    ll mn = 2e18;

    for(ll num : b){
        int pos = lower_bound(all(a), num) - a.begin();

        mn = min( mn , diff1[max(0,pos/2)] + abs(num - ((pos&1)?a[max(0,pos-1)] : a[min(n-1,pos)])) + (diff2[min(x-1,pos/2 )]));
    }
    cout << mn << endl;
    return 0;
}