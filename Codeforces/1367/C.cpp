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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        string pref = "1", suff = "1";
        if(s.front() == '0'){
            for(int i = 0; i < k; i++){
                pref += "0";
            }
        }
        if(s.back() == '0'){
            for(int i = 0; i < k ; i++){
                suff += "0";
            }
            reverse(all(suff));
        }
        string fin = pref + s + suff;
        s = fin;
        n = s.size();;
        vector<int> cnt;
        for(int i = 0; i < n; i++ ){
            if(s[i] == '1'){
                int c = 0;
                int j = i + 1;
                while(j < n && s[j] == '0'){
                    j++;
                    c++;
                }
                i = j - 1;
                cnt.push_back(c);
            }
        }
        int ans = 0;
 
        for(ll i : cnt){
            ans += max((i / (k + 1)) - (i % (k + 1) != k), 0LL);
        }
        cout << ans << endl;
    }
    return 0;
}