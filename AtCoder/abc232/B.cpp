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
    string s, t; cin >> s >> t;
    vector<int> a(s.size());
    vector<int> b(t.size());
    for(int i = 0; i < s.size(); i++){
        a[i] = (s[i] - s[0]);
    }
    for(int i = 0; i < t.size(); i++){
        b[i] = (t[i] - t[0]);
    }
    for(int shift = 0; shift <= 26; shift++){
        for(int i = 0; i < a.size(); i++){
            a[i] = (a[i] + 1) % 26;
            b[i] = (b[i] + 1) % 26;
        }
        if(a == b){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}