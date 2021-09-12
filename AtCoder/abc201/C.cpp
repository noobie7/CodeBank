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
    string s; cin >> s;
    int ans = 0;
    auto check = [&](int digit, string &a, int flag){
        if(flag){
            bool ok = 0;
            for(int i = 0; i < 4; i++){
                ok |= ((a[i] - '0' == digit) == flag);
            }
            return ok;
        }
        bool ok = 1;
        for(int i = 0; i < 4; i++){
            ok &= ((a[i] - '0' == digit) == flag);
        }
        return ok;
    };

    for(int i = 0; i < 10000; i++){
        string t = to_string(i);
        string a(4 - t.size(), '0');
        if(a.size()) a += t;
        else         a  = t;
        int good = 1;
        for(int dig = 0; dig < 10; dig++){
            if(s[dig] == 'x'){
                good &= check(dig, a, 0);
            }
            if(s[dig] == 'o'){
                good &= check(dig, a, 1);
            }
        }
        ans += good;
    }
    cout << ans << endl;
    return 0;
}