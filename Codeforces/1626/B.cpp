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
        string s; cin >> s;
        map<int, int> f;
        int pos = -1;
        int last_double = -1;
        int n = s.size();
        for(int i = 0; i + 1 < n; i++){
            int pre = (s[i] - '0') * 10 + (s[i + 1] - '0');
            int new_num = (s[i] - '0') + (s[i + 1] - '0');
            if(new_num > 9){
                last_double = i;
            }
        }

        if(last_double != -1){
            pos = last_double;
            int new_num = (s[pos] - '0') + (s[pos + 1] - '0');
            string rep = to_string(new_num);
            s[pos] = rep[0];
            s[pos + 1] = rep[1];
            cout << s << endl;
            continue;
        }
        pos = 0;
        int new_num = (s[pos] - '0') + (s[pos + 1] - '0');
        string rep = to_string(new_num);
        s[pos + 1] = rep[0];

        for(int i = 1; i < n; i++){
            cout << s[i];
        }
        cout << endl;
        
        continue;
    }
    return 0;
}