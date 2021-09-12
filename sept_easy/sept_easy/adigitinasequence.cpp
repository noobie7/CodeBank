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
        ll a, b; cin >> a >> b;
        ll k; cin >> k;
		k--;
        vector<int> partition(-1);
        int len = 1;
        ll last_mul = 0;
        ll sum = 0;
        
        while(true){
			if(len < to_string(a).size()){
				len++;
				continue;
			}
            ll lo = 0;
            ll hi = 1e9;
            while(hi - lo > 1){
                ll mid = lo + (hi - lo) / 2;
                if(to_string(a + mid * b).size() <= len)
                    lo = mid;
                else 
                    hi = mid;
            }
            partition.push_back(lo - partition.back());
            last_mul = lo;
            sum += partition.back() * len;
            if(sum == k){
                cout << to_string(a + b * last_mul).back() << endl;
                return 0;
            }
            if(sum > k) break;
            len++;
        }
        //pra(partition);
		k -= sum;
        ll skip = k / len;
        last_mul += skip + 1;
		cout << len << " " << a + last_mul * b << endl;
        cout << to_string(a + last_mul * b)[len - (k % len)] << endl;
    }
    return 0;
}