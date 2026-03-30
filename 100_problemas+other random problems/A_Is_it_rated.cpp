#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll a,b;
    cin>>a>>b;
    if(b==1){
        if(a>=1600 && a<=2999){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
    }else{
        if(a>=1200 && a<=2399){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
    }
}