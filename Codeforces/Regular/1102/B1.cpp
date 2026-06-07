#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll m=n%12;
        ll xd;
        if(m<=9){
            xd=m;
        }else if(m==10){
            xd=22;
        }else{
            xd=11;
        }
        if(n<xd){
            cout<<-1<<"\n";
        }else{
            cout<<xd<<" "<<n-xd<<"\n";
        }
    }
}