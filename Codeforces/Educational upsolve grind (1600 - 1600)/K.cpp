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
    ll n, k; cin >> n >> k;
    auto nc = [&](ll n, ll r){
        ll ans = 1;
        for(int i = 0; i < r; i++){
            ans *= (n - i);
            ans /= (i + 1);
        }
        return ans;
    };
    ll ans = 0;
    for(int i = 0; i <= min(k,n); i++){
        ll ways = nc(n, i);
        vector<int> permute;
        for(int j = 0; j < i; j++){
            permute.push_back(j);
        }
        ll count = 0;
        do{
            int ok = 1;
            for(int j = 0; j < i; j++){
                if(permute[j] == j ){
                    ok = 0;
                }
            }
            if(ok) count++;
        }while(next_permutation(all(permute)));
        ans += count * ways;
    }
    cout << ans << endl;
    return 0;
}