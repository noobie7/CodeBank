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
        int cnt = 0;
        for(int i = n - 2; i >= 0; i--){
            while(a[i] && a[i] >= a[i + 1]){
                a[i] /= 2;
                cnt++;
            }
        }
        int ok = 1;
        for(int i = 0; i + 1 < n; i++){
            ok &= (a[i] < a[i + 1]);
        }
        cout << (ok ? cnt : -1) << endl;
    }
    return 0;
}