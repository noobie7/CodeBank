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
    int nag = 205;
    vector<int> prime(nag, 1);
    prime[0] = prime[1] = 0;
    for(int i = 2; i < nag; i++){
        for(int j = 2 * i; j <= nag && prime[i] == 1; j += i){
            prime[j] = 0;
        }
    }
    int a, b; cin >> a >> b;
    int c, d; cin >> c >> d;
    int ok = 1;
    for(int i = a; i <= b; i++){
        int temp = 0;
        for(int j = c; j <= d; j++){
            if(prime[i + j]){
                temp |= 1;
            }
        }
        ok &= temp;
    }
    cout << (ok ? "Aoki" : "Takahashi") << endl;
    return 0;
}