#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string s;
    cin>>s;
    vector<char> ans;
    vector<ll> V;
    ll par;
    for(auto x:s){
        if(x=='('){
            par++;
        }else if(x==')'){
            par--;
        }
    }
}