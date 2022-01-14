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
#define pra(a) for(auto i : a) cout<<a[i]<<" ";	cout<<endl;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    test(){
        int n; cin >> n;
        vector<int> a(n);
        get(a);
        if(count(all(a), a.front()) == n){
            cout << "YES" << endl;
            continue;
        }
        vector<int> x(n);
        x[0] = a[0];
        for(int i = 1; i < n; i++){
            x[i] = a[i] ^ x[i - 1];
        }
        if(x.back() == 0){
            cout << "YES" << endl;
            continue;
        }
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(x[i] == (x[j] ^ x[i])){
                    if((x[n - 1] ^ x[j]) == (x[j] ^ x[i])){
                        cout << "YES" << endl;
                        goto here;
                    }
                }
            }
        }
        cout << "NO" << endl;
        continue;
        here:;
    }
    return 0;
}