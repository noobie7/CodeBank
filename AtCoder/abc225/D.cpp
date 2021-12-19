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
    int q; cin >> q;
    vector<int> front(n + 1, -1);
    vector<int> back(n + 1, -1);
    while(q--){
        int t; cin >> t;
        if(t == 1){
            int x, y; cin >> x >> y;
            back[x] = y;
            front[y] = x;
        }
        if(t == 2){
            int x, y; cin >> x >> y;
            back[x] = -1;
            front[y] = -1;
        }
        if(t == 3){
            int x; cin >> x;
            while(front[x] != -1){
                x = front[x];
            }
            vector<int> ans;
            while(x != -1){
                ans.push_back(x);
                x = back[x];
            }
            cout << ans.size() << " ";
            pra(ans);
        }
    }
    return 0;
}