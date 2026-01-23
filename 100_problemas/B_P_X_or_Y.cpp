#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll ans=0;
    ll a,b;
    cin>>a>>b;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=6;j++){
            if(i+j>=a || abs(i-j)>=b){
                ans++;
            }
        }
    }
    long double res=(long double)ans/36;
    cout<<fixed<<setprecision(10)<<res;
}