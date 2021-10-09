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
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].ff >> a[i].ss;
        a[i].ss += a[i].ff;
    }
    set<int> bag;
    for(auto pp : a){
        bag.insert(pp.ff);
        bag.insert(pp.ss);
    }
    vector<int> dec;
    map<int,int> f;
    int c = 0;
    for(int i : bag){
        f[i] = c++;
        dec.push_back(i);
    }
    vector<int> ans(n + 1);
    vector<int> cnt(c + 1);
    for(int i = 0; i < n; i++){
        cnt[f[a[i].ff]] += 1;
        cnt[f[a[i].ss]] -= 1;
    }
    for(int i = 1; i <= c; i++){
        cnt[i] += cnt[i - 1];
    }
    for(int i = 0; i + 1 <= c; i++){
        ans[cnt[i]] += dec[i + 1] - dec[i];
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;

}