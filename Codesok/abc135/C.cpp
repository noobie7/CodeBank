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
    vector<int> a(n + 1);
    get(a);
    reverse(all(a));
    ll score = 0;
    for(int i = 0; i < n; i++){
        int k; cin >> k; 
        int temp = a.back();
        a.back() -= min(temp, k);
        score    += min(temp, k);
        k        -= min(temp, k);
        a.pop_back();
        if(k){
            int t = a.back();
            a.back() -= min(t, k);
            score    += min(t, k);
        }
    }
    cout << score << endl;
    return 0;
}