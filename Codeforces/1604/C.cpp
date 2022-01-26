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
        vector<int> a(n);
        get(a);
        int ok = 1;
        for(int i = 0; i < min(21, n); i++){
            int c = 0;
            for(int j = 2; j <= i + 2; j++){
                c |= (a[i] % j != 0);
            }
            ok &= c;
        }
        cout << ( (ok) ? "Yes" : "No") << endl;
    }
    return 0;
}