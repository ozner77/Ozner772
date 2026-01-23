#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    string ans;
    for(int i=0;i<s.size()-1;i++){
        ans+=s[i];
    }
    ans+="4";
    cout<<ans;
}