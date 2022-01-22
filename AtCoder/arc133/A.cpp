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
    int n; cin >> n;
    vector<int> a(n);
    get(a);
    vector<pair<int, int>> b;
    for(int i = 0; i < n; i++){
        int x = a[i];
        int j = i + 1;
        while(j < n && a[j] == x){
            j++;
        }
        b.push_back({x, j - i});
        i = j - 1;
    }
    b.push_back({-1, 0});
    int rm = -1;
    for(int i = 0; i + 1 < b.size(); i++){
        if(b[i + 1].first < b[i].first){
            rm = b[i].first;
            break;
        }   
    }
    for(int i = 0; i < n; i++){
        if(a[i] == rm) continue;
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}