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
const int N = 1e6 + 5;


int main(){
    Shazam;
    vector<int> in(N);
    vector<int> best_gcd(N);
    int n; cin >> n;
    vector<int> a(n);
    get(a);
    for(int i = 0; i < n; i++){
        in[a[i]]++;
    }
    int cnt = 0;
    for(int i = 1; i < N; i++){
        for(int j = i; j < N; j += i){
            if(in[j]){
                best_gcd[i] = gcd(best_gcd[i], j);
            }
        }
        cnt += best_gcd[i] == i;
    }
    cout << cnt - n << endl;
    
    return 0;
}