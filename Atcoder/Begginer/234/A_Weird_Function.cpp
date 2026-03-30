#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll a){
    ll x=a*a;
    ll y=2*a;
    ll z=3;
    return x+y+z;
}
int main(){
    ll t;
    cin>>t;
    ll ans=f(f(f(t)+t)+f(f(t)));
    cout<<ans<<endl;
}
//f(f(f(t)+t)+f(f(t))).