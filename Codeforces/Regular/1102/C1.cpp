#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll potencia(ll k){
    ll init=1;
    for(int i=0;i<k;i++){
        init*=2;
    }
    return init;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        string a,b;
        cin>>a>>b;
        ll ans1=0;
        ll ans2=0;
        ll ans3=0;
        for(int i=0;i<n;i++){
            ans1+=a[i]-'0';
            ans2+=b[i]-'0';
            if(a[i]=='1' && b[i]=='1'){
                continue;
            }else if(a[i]=='1' || b[i]=='1'){
                ans3++;
            }
        }
        ans1=(n-ans1)*ans1;
        ans2=(n-ans2)*ans2;
        ans3=(n-ans3)*ans3;
        if(k%2==0){
            ll xd=potencia(k);
            xd--;
            xd/=3;
            ll ans=0;
            ans+=xd*ans1;
            ans+=xd*ans2;
            ans+=xd*ans3;
            ans+=ans1;
            ans+=ans2;
            cout<<ans<<"\n";
        }else{
            ll xd=potencia(k);
            xd++;
            xd/=3;
            ll ans=0;
            ans+=xd*ans1;
            ans+=xd*ans2;
            ans+=xd*ans3;
            cout<<ans<<"\n";
        }
    }
}