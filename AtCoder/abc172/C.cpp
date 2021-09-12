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
    ll n, m, x; cin >> n >> m >> x;
    vector<ll> a(n), b(m); 
    get(a);
    get(b);

    for(int i = 1; i < n; i++) a[i] += a[i - 1];
    for(int i = 1; i < m; i++) b[i] += b[i - 1];

    int ans = 0;
    auto process = [&](){
        for(int i = 0; i < n; i++){
            if(a[i] > x) break;
            ll rem = x - a[i];
            int j = upper_bound(all(b), rem) - b.begin();
            j--;
            ans = max(ans, i + 1 + j + 1);
        }
    };
    process();
    swap(a, b);
    swap(n, m);
    process();
    cout << ans << endl;
    return 0;
}