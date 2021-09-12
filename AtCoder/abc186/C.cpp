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
    auto dec = [&](int x){
        while(x){
            if(x % 10 == 7) return true;
            x /= 10;
        }
        return false;
    };
    auto oct = [&](int x){
        string r = "";
        while(x){
            r.push_back((char)('0' + (x % 8)));
            x /= 8;
        }
        reverse(all(r));
        int res = 0;
        for(int i = 0; i < r.size(); i++){
            res *= 10;
            res += (r[i] - '0');
        }
        return dec(res);
    };
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        if(dec(i) || oct(i)) ans++;
    }
    cout << n - ans << endl;
    return 0;
}