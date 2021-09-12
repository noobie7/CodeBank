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
    int nag = 1e6 + 5;
    vector<ll> cnt(nag);
    for(ll i = 1; i < nag; i++){
        cnt[i] = 2 * i - 1;
        if(i > 2) cnt[i] += cnt[i - 2];
    } 
    test(){
        ll l, r; cin >> l >> r;
        // 0 6
        // [0 6] - > (0 + 0, .. . . . .. . ., 6 + 0)
        // [1 5] - > (1 + 1, 2 + 1, 3 + 1, 4 + 1, 5 + 1)
        // [2 4] - > (2 + 2, 3 + 2, 4 + 2)
        // [3 3] - > (3 + 3)
        // 7 5 3 1
        // 13 
        // [1 4] - > (1 + 1, 2 + 1, 3 + 1, 4 + 1)
        // [2 3] - > (2 + 2, 3 + 2)
        // 4 2 
        // 7 + 3
        ll  len = r - l - l + 1;
        if(len > 0)
            cout << cnt[len] << endl;
        else 
            cout << 0 << endl;
    }

    return 0;
}