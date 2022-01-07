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
        string s; cin >> s;
        int n = s.size();
        vector<int> vis(26);
        string order = "";
        for(int i = n - 1; i >= 0; i--){
            if(!vis[s[i] - 'a']){
                vis[s[i] - 'a'] = 1;
                order.push_back(s[i]);
            }
        }
        vector<int> cnt(26);
        for(int i = 0; i < 26; i++){
            cnt[i] = count(all(s), (char)(i + 'a'));
        }
        map<char,int> f;
        reverse(all(order));
        auto ok = [&](int i){
            ll tot = 0;
            for(auto pp : f){
                tot += pp.ss;
            }
            ll curr = tot;
            ll fin = tot;
            for(char c : order){
                curr -= f[c];
                fin += curr;
            }
            if(fin != n){
                return 0;
            }
            string t = s.substr(0, i + 1);
            int j = i + 1;
            string ss = t;
            for(char c : order){
                string rm = "";
                for(char ch : ss){
                    if(ch == c) continue;
                    rm += ch;
                }
                int x = 1;
                for(int k = 0; k < rm.size(); k++){
                    x &= (s[k + j] == rm[k]);
                }
                j += rm.size();

                if(x){
                    t += rm;
                    ss = rm;
                }
                else{
                    return 0;
                }
                
            }
            return (int)(s == t);
        };
        
        for(int i = 0; i < n; i++){
            f[s[i]]++;
            if(ok(i)){
                cout << s.substr(0, i + 1) << " " << order << endl;
                goto here;
            }
        }
        cout << -1 << endl;
        continue;
        here:;
    }
    return 0;
}