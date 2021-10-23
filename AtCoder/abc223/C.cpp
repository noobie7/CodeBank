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
const double eps = 1e-6;



int main(){
    Shazam;
    int n; cin >> n;
    vector<pair<double,double>> a(n);
    double tot = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i].ff >> a[i].ss;
        tot += a[i].ff;
    }
    auto ok = [&](double x){
        double t1 = 0, t2 = 0;
        double c = 0;
        for(int i = 0; i < n; i++){
            if(a[i].ff + c >= x){
                double y = x - c;
                t1 += y / a[i].ss;
                break;
            }
            t1 += a[i].ff / a[i].ss;
            c  += a[i].ff;
        
        }
        c = 0;
        for(int i = n - 1; i >= 0; i--){
            if(a[i].ff + c >= tot - x){
                double y = (tot - x) - c;
                t2 += y / a[i].ss;
                break;
            }
            t2 += a[i].ff / a[i].ss;
            c  += a[i].ff;
        }
        return t1 <= t2;
    };
    auto bs = [&](double lo, double hi){
        while(hi - lo > eps){
            double mid = (hi + lo) / 2.0;
            if(ok(mid))
                lo = mid;
            else
                hi = mid;
        }
        return lo;
    };
    cout << fixed << setprecision(5) << bs(0.0, tot + eps) << endl;

    return 0;
}