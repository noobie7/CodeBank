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
const double eps = 1e-8;


int main(){
    Shazam;
    int n, k; cin >> n >> k;
    vector<double> a(n), b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    auto ok = [&](double x){
        vector<long double> l(n);
        for(int i = 0; i < n; i++) l[i] = a[i] - x * b[i];
        sort(l.rbegin(), l.rend());
        for(int i  = 1; i < n; i++){
            l[i] += l[i - 1];
            if(i >= k - 1 && l[i] >= eps)
                return true;
        }
        return false;
    };

    double lo = -eps;
    double hi = 1e9 + 5;
    while(hi - lo > eps){
        double mid = lo + (hi - lo) / 2;
        if(ok(mid)) lo = mid;
        else        hi = mid;
    }
    
    cout << fixed << setprecision(12) << lo << endl;

    return 0;
}