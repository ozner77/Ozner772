#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,a,b;
    cin>>n>>a>>b;
    ll ans=0;
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        if(x<=a && y>=b){
            ans++;
        }
    }
    cout<<ans<<"\n";
}