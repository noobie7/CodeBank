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
    vector<vector<int>> cnt(10,vector<int>(10));
    for(int i = 1; i <=n; i++){
        string s = to_string(i);
        int x = s.back() - '0';
        int y = s.front() -'0';
        cnt[x][y]++;
    }
    ll ans = 0;
    for(int i = 1;i < 10; i++){
        for(int j = 1; j < 10; j++){
            ans += 1LL*cnt[i][j]*cnt[j][i];
        }
    }
    cout<<ans<<endl;
    return 0;
}