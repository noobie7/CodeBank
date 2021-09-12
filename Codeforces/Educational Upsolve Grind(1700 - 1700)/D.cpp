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
        string s; cin >> s;
        int n = s.size();
        vector<int> nxt(n);
        int pos = -1;
        for(int i = 0; i < n; i++){
            nxt[i] = pos;
            if(s[i] == '1') pos = i;
        
        }
        
        auto calc = [&](int l, int r){
            ll res = 0;
            for(int i = l; i <= r; i++){
                res *= 2LL;
                res += (s[i] == '1');
            }
            return res;
        };
        ll ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                for(int j = i; j < min(n, i + 20); j++){
                    ll res = calc(i, j);
                    ll len = j - i + 1;
                    ans += (res == len);
                    if(res > len){
                        ans += (len + (- nxt[i] + i - 1) >= res);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}