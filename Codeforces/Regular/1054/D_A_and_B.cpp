#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll falsen;
        cin>>falsen;
        string s;
        cin>>s;
        ll cura=0;
        ll curb=0;
        ll ans1=0;
        ll ans2=0;
        vector<char> v;
        bool inicio=true;
        for(auto x:s){
            if(inicio && x==s[0]){
                continue;
            }else{
                inicio=false;
                v.push_back(x);
            }
        }
        ll n=v.size();
        for(int i=0;i<=n/2;i++){
            if(v[i]=='a'){
                ans1+=(i-cura);
                cura++;
            }else{
                ans2+=(i-curb);
                curb++;
            }
        }
        cura=n-1;
        curb=n-1;
        for(int i=(n/2)+1;i<n;i++){
            if(v[i]=='a'){
                ans1+=(cura-i);
                cura--;
            }else{
                ans2+=(curb-i);
                curb--;
            }
        }
        cout<<min(ans1,ans2)<<"\n";
    }
}