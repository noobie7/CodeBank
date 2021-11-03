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
    double n; cin >> n;
    double a, b;
    cin >> a >> b;
    double c, d;
    cin >> c >> d;
    double x = (a + c) / 2.0;
    double y = (b + d) / 2.0;
    double angle = 2.0 * acos(-1) / n;
    double e = (a - c) / 2.0;
    double f = (b - d) / 2.0;
    double p = x + e * cos(angle) - f * sin(angle);
    double q = y + e * sin(angle) + f * cos(angle);
    cout << fixed << setprecision(10) << p << " " << q << endl;
    return 0;
}