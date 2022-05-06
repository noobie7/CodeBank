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
#define Shazam ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);
#define all(c) c.begin(),c.end()
#define endl "\n"
#define test() int t; cin>>t; while(t--)
#define get(a) for(auto &i : a)  cin>>i;
#define pra(a) for(auto i : a) cout<< i <<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n; cin >> n;
        int k; cin >> k;
        string s; cin >> s;
        char mx = 'a';
        map<char, char> skip;
        for(int i = 0; k > 0 && i < n; i++){
            if(s[i] <= mx) continue;
            char from = s[i];
            char to = s[i];
            int skipped = 0;
            while(k > 0 && to > 'a'){
                k--;
                to--;
                if(to == mx && skip.count(mx)){
                    to = skip[mx];
                    skip.erase(mx);
                    mx = max(from, mx);
                    skip[mx] = to;
                    skipped = 1;
                    break;
                }
            }
            if(!skipped && from != to){
                mx = max(from, mx);
                skip[from] = to;
            }
        }
        vector<pair<char, char>> range;
        for(auto pp : skip){
            range.push_back({pp.first, pp.second});
            if(range.size()){
                assert(pp.first > range.back().second);
            }
        }
        for(char& c : s){
            for(auto pp : range){
                if(c <= pp.first && c > pp.second){
                    c = min(c, pp.second);
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}