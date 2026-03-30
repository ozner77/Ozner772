#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        vector<char> v,v2;
        ll ans1=0,ans2=0;
        for(auto x:s){
            v.push_back(x);
            v2.push_back(x);
            if(x=='1'){
                ans2++;
                ans1++;
            }
        }
        for(int i=1;i<n-1;i++){
            if(v2[i]=='0' && v2[i-1]=='1' && v2[i+1]=='1'){
                ans2++;
                v2[i]='1';
            }
        }
        ans1=ans2;
        for(int i=1;i<n-1;i++){
            if(v2[i]=='1' && v2[i-1]=='1' && v2[i+1]=='1'){
                ans1--;
                v2[i]='0';
            }
        }
        cout<<ans1<<" "<<ans2<<endl;
    }
}