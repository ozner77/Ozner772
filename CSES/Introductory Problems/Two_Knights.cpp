#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    vector<ll> ans;
    ans.push_back(0);
    ans.push_back(6);
    ans.push_back(28);
    ans.push_back(96);
    for(int i=5;i<=1e5;i++){
        ll res1=12*4;
        ll res2=(ll)(i-4)*(ll)40;
        ll res3=(ll)(i-4)*(ll)(i-4)*(ll)8;
        ll res=res1+res2+res3;
        res/=2;
        ll xd=(ll)(i*i)*(ll)((ll)((ll)i*(ll)i)-1);
        xd/=2;
        ans.push_back(xd-res);
    }
    ll n;
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<ans[i]<<"\n";
    }
}