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
    int n; cin>>n;
    int k; cin>>k;
    vector<long double> a(n);
    for(long double &i : a) cin>>i,  i = (i+1)/2;
    long double ans = 0, sum ;
    for(int i = 0; i < k; i++) ans += a[i];
    sum = ans;
    for(int i = k; i < n; i++){
        sum-=a[i-k];
        sum+=a.at(i);
        ans = max(ans, sum);
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}