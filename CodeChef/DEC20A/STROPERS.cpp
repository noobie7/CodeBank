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

int idx = 1e4;

int main(){
    Shazam;
    test(){
        string s; cin >> s;
        int n; n = (int)s.size();
        vector<unordered_set<int>> uni(n + 1);
        vector<unordered_set<string>> evr(n + 1);
        auto freq = [&](string &t){
            int cntodd = 0, cnteve = 0;
            int x = t.size();
            for(int i = 0; i < x; i++){
                if(t[i] == '1'){
                    int curr = 1;
                    int j = i + 1;
                    while(j < x && t[j] == '1') j++, curr++;
                    i = j - 1;
                    cntodd += (curr & 1);
                    cnteve += (curr & 1 ^ 1);
                }
            }
            if(cnteve || cntodd >= 2){
                return cntodd;
            }
            if(cntodd)
                return idx++;
            return -1;
        };
        string ip;
        for(int len = 1; len <= n; len++){
            for(int i = 0; i + len <= n; i++){
                ip = s.substr(i, len);
                evr[len].insert(ip);
            }
        }
        for(int len = 1; len <= n; len++){
            for(auto ss : evr[len]){
                ip = ss;
                int res = freq(ip);
                //cout << ip << " " << res << endl;
                uni[len].insert(res);
            }
        }
        ll ans = 0;
        for(auto p : uni){
            ans += (int)p.size();
        }
        cout << ans << endl;
    }
    return 0;
}