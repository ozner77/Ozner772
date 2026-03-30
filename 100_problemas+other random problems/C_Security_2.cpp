#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string s;
    cin>>s;
    ll ans=0;
    for(int i=0;i<s.size()-1;i++){
        ans+=((s[i]-'0')-(s[i+1]-'0')+10)%10;
    }
    ans+=s[s.size()-1]-'0';
    ans+=s.size();
    cout<<ans;
}