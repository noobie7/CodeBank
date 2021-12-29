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
    test(){
      int n; cin >> n;
      vector<pair<int,int>> chords;
      int k; cin >> k;
      vector<int> used(2 * n + 1);
      for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        if(a > b) swap(a, b);
        chords.push_back({a, b});
        used[a] = used[b] = 1;
      }
      vector<int> unused;
      for(int i = 1; i <= 2 * n; i++){
        if(!used[i]){
          unused.push_back(i);
        }
      }
      for(int i = 0; i < n - k; i++){
        chords.push_back({unused[i], unused[i + n - k]});
      }
      auto intersect = [&](pair<int,int> a, pair<int, int> b){
        if(a.ff > b.ff){
          swap(a, b);
        }
        return (a.ss > b.ff and a.ss < b.ss);
      };
      int ans = 0;
      for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
          ans += intersect(chords[i], chords[j]);
        }
      }
      cout << ans << endl;
    }

    return 0;
}