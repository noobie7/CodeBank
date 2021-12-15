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
    int n; cin >> n;
    vector<pair<long double,long double>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].ff >> a[i].ss;
    }

    auto len = [&](auto &a,  auto &b){
        return sqrtl(abs(a.ff - b.ff) * abs(a.ff - b.ff)  + abs(a.ss - b.ss) * abs(a.ss - b.ss) );
    };
    auto ok = [&](auto a, auto b, auto c){
        vector<long double> l;
        l.push_back(len(a, b));
        l.push_back(len(b, c));
        l.push_back(len(c, a));
        sort(all(l));
        return (l[0] + l[1] > l[2] );
    };
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                ans += ok(a[i], a[j], a[k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}