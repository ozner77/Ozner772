#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        if(m>=a){
            m-=a;
            ans++;
        }else{
            m=0;
        }
    }
    cout<<ans;
}