#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll ans=0;
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        if(b>a){
            ans++;
        }
    }
    cout<<ans;
}