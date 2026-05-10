#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll x=0;
        ll y=0;
        for(int i=0;i<n;i++){
            ll a;
            cin>>a;
            if(a==0){
                x++;
            }else if(a==-1){
                y++;
            }
        }
        if(y%2==1){
            x+=2;
        }
        cout<<x<<"\n";
    }
}