#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    ll cur=2;
    ll ans=0;
    for(int i=1;i<=62;i++){
        if(cur>n){
            break;
        }
        long double res=n/cur;
        res=sqrt(res);
        ll res2=res;
        ans+=(res2/2);
        if(res2%2!=0){
            ans++;
        }
        cur*=2;
    }
    cout<<ans;
}