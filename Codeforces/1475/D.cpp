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
        int m; cin >> m;
        vector<ll> a(n), b(n);
        get(a);
        get(b);
        vector<ll> one, two;
        for(int i = 0; i < n; i++){
            if(b[i] == 1){
                one.push_back(a[i]);
            }
            else{
                two.push_back(a[i]);
            }
        }
        sort(all(one));
        reverse(all(one));
        sort(all(two));
        reverse(all(two));
        for(int i = 1; i < one.size(); i++){
            one[i] += one[i - 1];
        }
        for(int i = 1; i < two.size() ; i++){
            two[i] += two[i - 1];
        }
        int ans = 2 * n + 1;
        int curr = m;
        for(int i = 0; i <= one.size(); i++){
            m = curr;
            if(!i){
                if(two.size() == 0) continue;
                int pos = lower_bound(all(two), m) - two.begin();
                if(pos < two.size() && two[pos] >= m)
                    ans = min(ans, 2 * pos + 2);    
            }
            else{
                m -= one[i - 1];
                if(m <= 0){
                    ans = min(ans, i);
                }
                else{
                    if(two.size() == 0) continue;
                    int pos = lower_bound(all(two), m) - two.begin();
                    if(pos < two.size() && two[pos] >= m){
                        ans = min(ans, i + 2 * pos + 2);
                    }
                }
            }
        }
        if(ans == 2*n + 1){
            cout << -1 << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}