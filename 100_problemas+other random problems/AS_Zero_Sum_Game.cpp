#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll ans=0;
    for(int i=0;i<n-1;i++){
        ll a;
        cin>>a;
        ans+=a;
    }
    cout<<0-ans;
}