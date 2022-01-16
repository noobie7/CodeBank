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
#define pra(a) for(auto i : a) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin >> n;
    vector<int> a(n);
    get(a);
    auto ok = [&](){
        bitset<200005> b;
        ll s = 0;
        for(int i : a){
            s += i;
        }
        if(s & 1){
            return 0;
        }
        b[0] = 1;
        for(int i : a){
            b |= (b << i);
        }
        return (int)b[s / 2];
    };
    if(ok() == 1){
        int mn = 50;
        int ans;
        for(int i = 0; i < n; i++){
            mn = min(mn, __builtin_ctz(a[i]));
            if(__builtin_ctz(a[i]) == mn){
                ans = i + 1;
            }
        }
        cout << 1 << endl << ans << endl;
        return 0;
    }
    cout << 0 << endl;
    return 0;
}