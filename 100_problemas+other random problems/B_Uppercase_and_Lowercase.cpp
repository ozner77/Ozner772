#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    ll a=0;
    ll b=0;
    for(auto x:s){
        if(x>='A' && x<='Z'){
            a++;
        }else{
            b++;
        }
    }
    if(a>b){
        string ans="";
        for(auto x:s){
            if(x>='A' && x<='Z'){
                ans+=char(x);
            }else{
                ans+=char(x-32);
            }
        }
        cout<<ans;
    }else{
        string ans="";
        for(auto x:s){
            if(x>='A' && x<='Z'){
                ans+=char(x+32);
            }else{
                ans+=char(x);
            }
        }
        cout<<ans;
    }
}