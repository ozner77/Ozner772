#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> ans(n);
        ll cur=1;
        for(int i=0;i<n;i+=2){
            ans[i]=cur;
            cur++;
        }
        cur=n;
        for(int i=1;i<n;i+=2){
            ans[i]=cur;
            cur--;
        }
        reverse(ans.begin(),ans.end());
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}