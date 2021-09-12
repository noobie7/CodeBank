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
    int n = 1e6;
    vector<int> is(n, 1);
    is[0] = is[1] = 0;
    for(int i = 2; i * i <= n; i++){
        for(int j = 2 * i ; j <= n && is[i]; j += i){
            is[j] = 0;
        }
    }
    vector<int> primes;
    for(int i = 2; i < n; i++){
        if(is[i])
            primes.push_back(i);
    }
    int x; cin >> x;
    cout << *lower_bound(all(primes), x) << endl;
    return 0;
}