#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for(int i=0;i<=m;i++){
        ll xd=1;
        for(int j=0;j<i;j++){
            xd*=n;
        }
        ans+=xd;
        if(ans>1e9){
            cout<<"inf";
            return 0;
        }
    }
    cout<<ans;
}