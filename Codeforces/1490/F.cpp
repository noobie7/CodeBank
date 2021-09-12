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
        map<int,int> f;
        for(int i = 0; i < n; i++){
            int k; cin >> k;
            f[k]++;
        }
        set<int> bag;
        vector<int> cnt(n + 2);
        for(auto pp : f){
            cnt[pp.ss]++;
        }
        vector<int> og = cnt;
        vector<int> suff(n + 2);
        for(int i = n; i >= 0; i--){
            if(cnt[i]){
                bag.insert(i);
            }
            suff[i] = cnt[i] * i + suff[i + 1];
            cnt[i] += cnt[i + 1];
        }
        int ans = inf;
        int pref = 0;
        for(int i : bag){
            ans = min(ans, pref + suff[i + 1] - (cnt[i + 1]) * i );
            pref += og[i] * i;
        }

        cout << ans << endl;
    }
    return 0;
}