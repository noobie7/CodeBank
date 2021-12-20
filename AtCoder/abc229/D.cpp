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
    string s; cin >> s;
    int n, k; cin >> k;
    n = (int)s.size();
    k = min(n, k);
    vector<int> pref(n), suff(n);
    pref[0] = (s[0] == 'X');
    for(int i = 1; i < n; i++){
        if(s[i] == '.'){
            pref[i] = 0;
            continue;
        }
        pref[i] = pref[i - 1] + 1;
    }
    suff[n - 1] = (s[n - 1] == 'X');
    for(int i = n - 2; i >= 0; i--){
        if(s[i] == '.'){
            suff[i] = 0;
            continue;
        }
        suff[i] = suff[i + 1] + 1;
    }
    vector<int> points;
    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '.'){
            points.push_back(i);
            cnt = 0;
            continue;
        }
        cnt += 1;
        ans = max(cnt, ans);
    }
    for(int i = 0, j = min((int)points.size(), k) - 1; j < points.size(); i++, j++){
        
        int filled = points[j] - points[i] + 1;
        if(points[i]){
            filled += pref[points[i] - 1];
        }
        if(points[j] != n - 1){
            filled += suff[points[j] + 1];
        }
        
        ans = max(ans, filled);
    }
    cout << ans << endl;
    return 0;
}