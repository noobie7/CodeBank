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
        vector<int> a(n + 1);
        int ok = 1;
        vector<int> b(n);
        get(b);
        sort(b.rbegin(), b.rend());
        for(int i = 0; i < n; i++){
            ll num = b[i];
            while(num > n || a[num]){
                num >>= 1;
            }
            if(num) 
                a[num] = 1;
            else 
                ok = 0;
        }
        cout << (ok ? "Yes" : "No") << endl;   
    }
    return 0;
}