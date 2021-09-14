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
        ll n, a, b, c; 
        cin >> n >> a >> b >> c;
        string s; cin >> s;
        ll cnt0 = count(all(s),'0');
        ll cnt1 = n - cnt0;
        if(cnt0 > cnt1){
            swap(cnt0, cnt1);
            swap(a , b);
        }
        ll ans = cnt0 * a + cnt1 * b;
        for(int i = 1; i <= cnt0 ; i++){
            ans = min(ans ,  (i + cnt1 ) * b + (cnt0 - i) * a + c * i);
        }
        for(int i = 0; i <= cnt1; i++){
            ans = min(ans, (cnt0 + i) * a + (cnt1 - i)*b + c * i);
        }
        cout << ans << endl;
    }
    return 0;
}