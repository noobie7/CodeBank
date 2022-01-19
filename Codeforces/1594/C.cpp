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
        char c; cin >> c;
        string s; cin >> s;
        int odd = 0, eve = 0;
        for(int i = 0; i < n; i++){
            if(s[i] != c){
                (i & 1 ? eve++ : odd++);
            }
        }
        if(!eve && (!odd)){
            cout << 0 << endl;
            continue;
        }
        auto a1 = [&](){
            string t = s;
            int score = count(t.begin(), t.begin() + t.size() - 1, c) != (t.size() - 1);
            score += (t.back() != c);
            return score;
        };
        auto a2 = [&](){
            string t = s;
            int pos = -1;
            for(int i = 1; i <= n; i++){
                if(s[i - 1] == c)
                    pos = i;
            }
            if(pos == -1){
                return pos;
            }
            for(int i = 1; i <= n; i++){
                if(i % pos){
                    if(t[i - 1] != c){
                        t[i - 1] = c;
                    }
                }
            }
            if(count(all(t), c) != n){
                return -1;
            } 
            return pos;
        };
        int res2 = a2();
        int res1 = a1();
        if(res2 != -1){
            cout << 1 << endl;
            cout << res2 << endl;
            continue;
        }

        cout << a1() << endl;
        if(a1() == 2)
            cout << n << " " << n - 1 << endl;
        else if(a1() == 1)
            cout << (s.back() == c ? n : n - 1) << endl;

    }
    return 0;
}