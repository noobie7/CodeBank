/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
using namespace std;
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
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    ll a, b, x;
    cin >> a >> b >> x;
    ll ans = 0;
    for(ll dig_count = 1; dig_count <= 10; dig_count++){
        ll upper_cap = 1;
        for(int i = 0; i < dig_count; i++) upper_cap *= 10;
        upper_cap--;
        ll temp = x;
        temp -= dig_count * b;
        if(temp < a) continue;
        ans = max(ans, min({1000000000LL, upper_cap, temp / a}));
    }
    cout << ans << endl;
    return 0;
}