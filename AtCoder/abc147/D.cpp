// /*
// "Won't stop until I'm phenomenal."
// - Phenomenal, Eminem
//  */
// #include<bits/stdc++.h>
// using namespace std;
// typedef long long int ll;
// #define ff first
// #define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
// #define ss second
// #define all(c) c.begin(),c.end()
// #define endl "\n"
// #define test() int t; cin>>t; while(t--)
// #define fl(i,a,b) for(int i = a ; i <b ;i++)
// #define get(a) fl(i,0,a.size())  cin>>a[i];
// #define pra(a) fl(i,0,a.size()) cout<<a[i]<<" ";	cout<<endl;
// #define pr(a,n) fl(i,0,n) cout<<a[i]<<" ";	cout<<endl;
// const ll INF = 2e18;
// const int inf = 2e9;
// const int mod1 = 1e9 + 7;



// int main(){
//     Shazam;
//     int n; cin>>n;
//     vector<ll> a(n);
//     for(ll &i : a)
//         cin>>i;
//     vector<vector<int>> table(63, vector<int> (n));
//     for(int bit = 0; bit < 63; bit++){
//         for(int i = 0 ; i < n; i++){
//             table[bit][i] = ((a[i]&(1LL<<bit)) > 0);
//         }
//     }
//     auto add = [&](ll &a, ll b){
//         a = (a + b)%mod1;
//     };
//     ll ans = 0;
//     for(int bit = 0; bit < 63; bit++){
//         ll x = count(table[bit].begin(), table[bit].end(),0);
//         ll y = n - x;
//         add(ans, (1LL<<bit)%mod1*y%mod1*x%mod1);
//     }
//     cout<<ans<<endl;
//     return 0;
// }
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
    vector<ll> a(n);
    for(ll &i : a)
        cin>>i;
    vector<vector<int>> table(61, vector<int> (n));
    for(int bit = 0; bit < 61; bit++){
        for(int i = 0 ; i < n; i++){
            table[bit][i] = ((a[i]&(1LL<<bit)) > 0);
            if(i)
                table[bit][i]+=table[bit][i-1];
        }
    }
    auto add = [&](ll &a, ll b){
        a = (a + b)%mod1;
    };
    ll ans = 0;
    for(int bit = 0; bit < 61; bit++){
        for(int i = 0; i < n-1; i++){
            if(!(a[i]&(1LL<<bit)))
                add(ans, (table[bit][n-1]-table[bit][i-1])*((1LL<<bit)%mod1)%mod1);
            else
                add(ans, (n- i   - (table[bit][n-1]-table[bit][i-1]))*((1LL<<bit)%mod1)%mod1);
        }
    }
    cout<<ans<<endl;
    return 0;
}