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
    test(){
        int n; cin >> n;
        int p3 = 1;
        for(int i = 1; i <= n; i++){
            p3 *= 3;
        }
        vector<int> a;
        ll ans = 0;
        cout << p3 << endl;
        for(int mask = 0; mask < p3; mask++){
            a.clear();
            int k = mask;
            for(int i = 0; i < n; i++){
                a.push_back(k % 3);
                k /= 3;
            }
            assert(a.size() == n);
            for(int i = 1; i + 1 < n; i++){
                if(a[i] > a[i + 1] && a[i] > a[i - 1]){
                    ans++;
                }
                if(a[i] < a[i + 1] && a[i] < a[i - 1]){
                    ans++;
                }
            }
        }
        cout <<  ans << endl;
    }
    return 0;
}