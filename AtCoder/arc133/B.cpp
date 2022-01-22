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
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define get(a) for(auto &i : a)  cin>>i;
#define pra(a) for(auto i : a) cout<< i <<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin >> n;
    vector<int> a(n), b(n);
    get(a);
    get(b);
    map<int,int> f, g;
    for(int i = 0; i < n; i++){
        f[a[i]] = i;
        g[b[i]] = i;
    }
    vector<pair<int, int>> p;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j += i){
            p.push_back({f[i], -g[j]});
        }
    }
    sort(all(p));
    int ans = 0;
    vector<int> h;
    for(int i = 0; i < p.size(); i++){
        p[i].second *= -1;
        if(h.empty()){
            h.push_back(p[i].second);
        }
        else{
            int pos = lower_bound(all(h), p[i].second) - h.begin();
            if(pos < h.size()){
                h[pos] = p[i].second;
            }
            else{
                h.push_back(p[i].second);
            }
        }
        ans = max(ans, (int)h.size());
    }
    cout << ans << endl;
    return 0;
}