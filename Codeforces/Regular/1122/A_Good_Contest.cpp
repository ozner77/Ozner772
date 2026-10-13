#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b,c,n;
        cin>>n;
        cin>>a>>b>>c;
        cout<<n-min(a,min(b,c))<<"\n";
    }
}