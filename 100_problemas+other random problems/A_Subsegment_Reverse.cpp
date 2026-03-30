#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,l,r;
    cin>>n>>l>>r;
    vector<ll> R;
    vector<ll> ans;
    for(int i=l;i<=r;i++){
        R.push_back(i);
    }
    reverse(R.begin(),R.end());
    for(int i=1;i<l;i++){
        ans.push_back(i);
    }
    for(auto x:R){
        ans.push_back(x);
    }
    for(int i=r+1;i<=n;i++){
        ans.push_back(i);
    }
    for(auto x:ans){
        cout<<x<<" ";
    }
}