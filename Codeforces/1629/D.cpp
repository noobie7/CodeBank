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

    // jac_nikola OP

    Shazam;
    test(){
        int n; cin >> n;
        int f1[26], f2[26][26], f3[26][26][26];
        for(int i = 0; i < 26; i++){
            f1[i] = 0;
            for(int j = 0; j < 26; j++){
                f2[i][j] = 0;
                for(int k = 0; k < 26; k++){
                    f3[i][j][k] = 0;
                }
            }
        }
        vector<string> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i].size() == 1)
                f1[a[i][0] - 'a']++;
            if(a[i].size() == 2)
                f2[a[i][0] - 'a'][a[i][1] - 'a']++;
            if(a[i].size() == 3)
                f3[a[i][0] - 'a'][a[i][1] - 'a'][a[i][2] - 'a']++;
        }
        int ok = 0;
        for(int i = 0; i < n; i++){
            if(a[i].size() == 1)
                f1[a[i][0] - 'a']--;
            if(a[i].size() == 2)
                f2[a[i][0] - 'a'][a[i][1] - 'a']--;
            if(a[i].size() == 3)
                f3[a[i][0] - 'a'][a[i][1] - 'a'][a[i][2] - 'a']--;

            if(a[i].size() == 1)
                //a
                ok = 1;
            if(a[i].size() == 2){
                // aa
                ok |= (a[i][0] == a[i][1]);

                // ab + ba
                ok |= (f2[a[i][1] - 'a'][a[i][0] - 'a']);

                // ab + Xba
                for(int j = 0; j < 26; j++){
                    ok |= (f3[j][a[i][1] - 'a'][a[i][0] - 'a']);
                }
            }
            if(a[i].size() == 3){
                
                // aba, aaa
                ok |= (a[i][0] == a[i][2]);

                // abb + a

                ok |= (f1[a[i][0] - 'a']);

                // abc + ba

                ok |= (f2[a[i][1] - 'a'][a[i][0] - 'a']);

                // abc + cba

                ok |= (f3[a[i][2] - 'a'][a[i][1] - 'a'][a[i][0] - 'a']);
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
    return 0;
}