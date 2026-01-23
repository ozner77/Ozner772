#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    long double a,b;
    cin>>a>>b;
    long double ans=a/b;
    ll xd=ans;
    if(ans-xd>0.5){
        cout<<xd+1;
    }else{
        cout<<xd;
    }
}