/*
"Won't stop untill I'm Phenomenal"
- Phenomenal, EMINEM
*/
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
    string s; cin>>s;
    vector<int> cnt(2019);
    cnt[0]++;
    int n = s.size();
    int mod = 2019;
    ll p10 = 1;
    ll curr = 0;
    ll ans = 0;
    for(int i = n-1; i>=0; i--){
        curr = (curr + p10*(s[i]-'0')%mod)%mod;
        ans += cnt[curr];
        cnt[curr]++;
        p10 = p10*10%mod;
    }
    cout<<ans<<endl;
    return 0;
}