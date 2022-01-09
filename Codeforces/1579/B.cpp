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
    vector<int> a(n);
    get(a);
    vector<array<int, 3>> op;
    for(int i = 0; i < n; i++){
      int min_pos = i;
      for(int j = i + 1; j < n; j++){
        if(a[j] < a[min_pos]){
          min_pos = j;
        }
      }
      if(min_pos > i){
        op.push_back({i + 1, min_pos + 1, min_pos - i });
        int opt = a[min_pos];
        for(int j = min_pos; j > i; j--){
          a[j] = a[j - 1];
        }
        a[i] = opt;
      }
    }
    cout << op.size() << endl;
    for(int i = 0; i < op.size(); i++){
      for(int j = 0; j < 3; j++){
        cout << op[i][j] << " ";
      }
      cout << endl;
    }
  }
  return 0;
}