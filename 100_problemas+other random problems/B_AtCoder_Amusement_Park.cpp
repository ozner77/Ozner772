#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,k;
    cin>>n>>k;
    ll cur=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(cur+a<=k){
            cur+=a;
        }else{
            ans++;
            cur=a;
        }
    }
    cout<<ans+1;
}