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
        int k; cin >> k;
        string s; cin >> s;
        string t = "";
        for(int i = 0; i < (k-1) ; i++) t += "()";
        for(int i = 0; i < (n - (k - 1)*2)/2 ; i++) t += "(";
        for(int i = 0; i < (n - (k - 1)*2)/2 ; i++) t += ")";
        vector<pair<int,int>> ops;
        for(int i = 0; i < n; i++){
            if(s[i] == t[i]) continue;
            int j = i + 1;
            while( j < n && s[j] != t[i]){ j++;}
            ops.push_back({i+1, j+1});
            reverse(s.begin() + i, s.begin() + j + 1); 
        }
        cout << ops.size() << endl;
        assert(s==t);
        for(auto pp : ops)
            cout << pp.ff << " " << pp.ss << endl;
    }
    return 0;
}