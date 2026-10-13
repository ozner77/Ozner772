#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<int> ans;
        for(int i=2;i<=n;i+=2){
            ans.push_back(i);
            ans.push_back(i-1);
        }
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}