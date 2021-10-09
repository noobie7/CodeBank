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
    string s; cin >> s;
    int n = s.size();
    sort(s.rbegin(), s.rend());
    ll ans = 0;
    for(int mask = 0; mask < (1 << n); mask++){
        ll a = 0, b = 0;
        for(int bit = 0; bit < n; bit++){
            if(mask & (1 << bit)){
                if(a == 0 && s[bit] == '0')
                    goto here;
                a *= 10;
                a += (s[bit] - '0');
            }
            else{
                if(b == 0 && s[bit] == '0')
                    goto here;
                b *= 10;
                b += (s[bit] - '0');
            }
        }
        ans = max(ans, a * b);
        here:;
    }
    cout << ans << endl;
    return 0;
}