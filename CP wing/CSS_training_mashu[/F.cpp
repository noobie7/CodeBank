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
    vector<vector<int>> a(n, vector<int>(6));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            cin >> a[i][j];
        }
    }
    vector<vector<int>> cnt(1005 , vector<int> (3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            
            int pw = 1;
            for(int t = 0; a[i][j] && t < 3; t++){
                int from = a[i][j] * pw;
                int to = (a[i][j] + 1) * pw;
                for(int b = from; b < to ; b++){
                    cnt[b][i] = 1;
                }
                pw *= 10;
            }
            for(int b = 0; b < 1004; b += 10){
                cnt[b][i] = 1;
            }
        }
    }
    ll ans = 0;
    for(int i = 1; i < 10; i++){
        if(count(all(cnt[i]), 1)) ans++;
        else break;
    }
    if(ans < 9){
        cout << ans << endl;
        return 0;
    }
    for(int i = 10 ; i < 100 ; i++){
        if(count(all(cnt[i]), 1) > 1) ans++;
        else break;
    }
    if(ans < 99){
        cout << ans << endl;
        return 0;
    }
    for(int i = 100; i < 1005; i++){
        if(count(all(cnt[i]),1) > 2) ans++;
        else break;
    }
    cout << ans << endl;
    return 0;
}