#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    if(a>b){
        cout<<a-b;
        return 0;
    }
    ll ans=0;
    while(b!=a){
        if(b>a){
            if(b%2==0){
                b/=2;
            }else{
                b++;
            }
        }else{
            b++;
        }
        ans++;
    }
    cout<<ans;
}