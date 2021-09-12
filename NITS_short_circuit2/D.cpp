/*
"Won't stop until I'm phenomenal."
- Phenomenal, Eminem
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
    test(){
        string s; cin>>s;
        int n = (int)s.size();
        vector<map<char,ll>> pref(n);
        map<char,ll> curr;
        for(int i = 0; i < n; i++){
            curr[s[i]]++;
            pref[i] = curr;
        }
        auto add = [&](ll &a, ll b){
            a = (a%mod1+b%mod1)%mod1;
        };
        ll ans = 1;
        for(int i = 0; i < n; i++){
            ll contribution = 0;
            for(auto pp : pref[n-1]){
                if(pp.ff!=s[i])
                   add(contribution , pp.ss - ((pref[i].count(pp.ff))?pref[i][pp.ff] : 0));
            }
            add(ans, contribution);
        }
        cout<<ans<<endl;
    }
    return 0;
}