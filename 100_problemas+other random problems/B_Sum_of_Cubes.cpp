#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isPerfectCube(long long x) {
    if(x==0){
        return false;
    }
    long long r=llround(cbrt((long double)x));
    return r*r*r==x;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ok=true;
        for(int i=1;i<=100000;i++){
            if(i>n){
                break;
            }
            ll xd=(ll)i*i*i;
            ll uwu=n-xd;
            if(xd>n){
                break;
            }
            if(isPerfectCube(uwu)){
                cout<<"YES\n";
                ok=false;
                break;
            }
        }
        if(ok){
            cout<<"NO\n";
        }
    }
}