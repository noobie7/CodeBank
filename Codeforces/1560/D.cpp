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
    vector<string> p;
    for(int i = 0; i < 63; i++){
        p.push_back(to_string(1LL << i));
    }
    
    auto process = [&](string s, string t){
        int moves = INT_MAX;
        int n = s.size();
        string x = "";
        int ptr = 0;
        int score = 0;
        for(int i = 0; i < t.size(); i++){
            while(ptr < s.size() && s[ptr] != t[i]){
                ptr++;
            } 
            if(ptr == s.size()) 
                break;
            score++;
            ptr++;
        }
        return (int)(t.size() + s.size() - 2 * score);
    };

    test(){
        int n; cin >> n;
        string s = to_string(n);
        int mn = INT_MAX;
        for(auto t : p){
            mn = min(mn, process(s, t));
        }
        cout << mn << endl;
    }
    return 0;
}