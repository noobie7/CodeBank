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
    int k; cin>>k;
    deque<ll> lunlun;
    for(ll i = 1; i < 10; i++)
        lunlun.push_back(i);
    ll ans;
    for(int i = 1; i <= k; i++){
        ans = lunlun.front();
        lunlun.pop_front();
        if(ans%10) lunlun.push_back(ans*10LL + (ans%10) - 1);
        lunlun.push_back(ans*10LL + ans%10);
        if(ans%10<9) lunlun.push_back(ans*10LL + (ans%10) + 1);
    }
    cout<<ans<<endl;
    return 0;
}