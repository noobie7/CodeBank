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
    ll d; cin >> d;
    vector<pair<ll,ll>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].ff >> a[i].ss;
    }
    auto sorter = [&](pair<ll,ll> &a, pair<ll,ll> &b){
        if(a.ss == b.ss){
            return a.ff < b.ff;
        }
        return a.ss < b.ss;
    };
    sort(a.rbegin(), a.rend(), sorter);
    vector<pair<ll,ll>> b = a;
    int ans = 0;
    while(a.size()){
        int i = (int)a.size() - 1;
        int j = i;
        while(j >= 0){  
            if(a[j].ff > a[i].ss + d - 1) break;
            j--;
        }
        while(j + 1 < (int)a.size())
            a.pop_back();
        ans++;
    }
    
    cout << ans << endl;
    return 0;
}