#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    string ans;
    bool ok=true;
    for(auto x:s){
        if(x=='#'){
            ok=true;
            ans+="#";
        }else if(x=='.'){
            if(ok){
                ans+='o';
                ok=false;
            }else{
                ans+=".";
            }
        }
    }
    cout<<ans;
}