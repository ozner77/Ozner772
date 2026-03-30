#include <bits/stdc++.h>
using namespace std;
#define ll long long
string binary(ll n){
    string s="";
    while(n>0){
        if(n%2==0){
            s+='0';
        }else{
            s+='1';
        }
        n/=2;
    }
    return s;
}
int main(){
    ll n;
    cin>>n;
    string s=binary(n);
    string ans="";
    reverse(s.begin(),s.end());
    for(auto x:s){
        if(x=='1'){
            ans+='2';
        }else{
            ans+='0';
        }
    }
    cout<<ans<<endl;
}