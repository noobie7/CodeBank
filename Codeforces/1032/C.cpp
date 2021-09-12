/*
"An anomaly, I'm Muhammad Ali
  Cause I know one day I'm gonna be the"
                - Greatest, Eminem
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const ll INF = 2e18;
const int inf = 2e9;
const int mod1 = 1e9 + 7;



int main(){
    Shazam;
    int n; cin >> n;
    vector<int> a(n); 
    get(a);
    vector<int> inc(n), dec(n);
    vector<int> incr(n), decr(n);
    for(int i = 0; i < n; i++){
        int j = i + 1;
        while(j < n && a[j - 1] < a[j]){
            j++;
        }
        for(int k = i; k < j; k++){
            inc[k] = (j - k);
        }
        i = j - 1;
    }
    for(int i = 0; i < n; i++){
        int j = i + 1;
        while(j < n && a[j - 1] > a[j]){
            j++;
        }
        for(int k = i; k < j; k++){
            dec[k] = (j - k);
        }
        i = j - 1;
    }
    for(int i = n-1; i>=0; i--){
        int j = i - 1;
        while( j >= 0 && a[j] > a[j+1]){
            j--;
        }
        for(int k = j + 1; k <= i; k++){
            incr[k] = (k - j);
        }
        i = j + 1;
    }
    for(int i = n-1; i >= 0; i--){
        int j = i - 1;
        while(j >= 0 && a[j] < a[j + 1]){
            j--;
        }
        for(int k = j + 1; k <= i; k++){
            decr[k] = (k - j);
        }
    }
    // pra(inc);
    // pra(incr);
    // pra(dec);
    // pra(decr);
    bool cant = 0;
    cant |= (*max_element(all(inc)) > 5);
    cant |= (*max_element(all(dec)) > 5);
    cant |= (*max_element(all(incr)) > 5);
    cant |= (*max_element(all(decr)) > 5);

    if(cant){
        cout << -1 << endl;
        return 0;
    }

    vector<int> ans(n);
    int prev = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] > prev){
            ans[i] = ans[i-1];
            ans[i]+=1;
        }
        if(a[i] < prev){
            ans[i] = ans[i-1];
            ans[i]-=1;
        }
        if(a[i] == prev){
            if(i-2>=0 && a[i-1] == a[i-2]){
                ans[i] = ans[i-2];
            }
            else{
                if(i == 0){
                    ans[i] = dec[i];
                }
                else{
                    int hi = (5 - inc[i] + 1);
                    int lo = dec[i];
                    if(lo > hi){
                        cout << -1 << endl;
                        return 0;
                    }
                    if(lo == hi && hi == ans[i-1]){
                        cout << -1 << endl;
                        return 0;
                    }
                    if(lo != ans[i-1])
                        ans[i] = lo;
                    else
                        ans[i] = hi;
                }
            }
        }
        prev = a[i];
    }
    pra(ans);
    return 0;
}