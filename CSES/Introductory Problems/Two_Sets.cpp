#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll n;
    cin>>n;
    long long xd=n*(n+1);
    if(xd%4==0){
        xd/=4;
        long long suma=0;
        vector<ll> ans1;
        vector<ll> ans2;
        cout<<"YES\n";
        for(int i=n;i>=1;i--){
            if(suma+i<=xd){
                ans1.push_back(i);
                suma+=i;
            }else{
                ans2.push_back(i);
            }
        }
        cout<<ans1.size()<<"\n";
            for(auto x:ans1){
                cout<<x<<" ";
            }
            cout<<"\n";
            cout<<ans2.size()<<"\n";
            for(auto x:ans2){
                cout<<x<<" ";
            }
    }else{
        cout<<"NO\n";
    }
}