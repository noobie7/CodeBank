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
        int n, k; cin >> n >> k;
        vector<int> cnt(26);
        string s; cin >> s;
        for(char c : s){
            cnt[c - 'a']++;
        }
        int cntPairs = 0, cntOdd = 0;
        for(int i = 0; i < 26; i++){
            cntPairs += cnt[i] / 2;
            cntOdd   += cnt[i] % 2;
        }
        int ans = 2 * ( cntPairs / k );
        cntOdd += 2 * ( cntPairs % k );
        cout << ans + (cntOdd >= k) << endl;
    }
    return 0;
}