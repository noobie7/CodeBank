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
    vector<pair<int,int>> ed(m);
    for(int i = 0; i < m; i++){
        cin >> ed[i].ff >> ed[i].ss;
    }
    int k; cin >> k;
    vector<pair<int,int>> donate(k);
    for(int i = 0; i < k; i++){
        cin >> donate[i].ff >> donate[i].ss;
    }
    int ans = 0;
    for(int i = 0; i < (1 << k); i++){
        int curr = 0;
        vector<int> cnt(n + 1);
        for(int bit = 0; bit < k; bit++){    
            if( ( i & (1 << bit) ) > 0){
                cnt[donate[bit].ss]++;
            }
            else{
                cnt[donate[bit].ff]++;
            }
        }
        for(auto pp : ed){
            curr += (cnt[pp.ff] && cnt[pp.ss]);
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;
    return 0;
}