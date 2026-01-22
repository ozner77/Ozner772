#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ans="";
    for(auto x:s){
        if(x<='Z'){
            ans+=x;
        }
    }
    cout<<ans;
}