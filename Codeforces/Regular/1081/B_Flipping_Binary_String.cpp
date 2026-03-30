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
        vector<ll> ans1;
        vector<ll> ans2;
        ll con=0;
        ll res=0;
        ll res2=0;
        for(auto x:s){
            if(x=='1'){
                res++;
                ans1.push_back(con+1);
            }else{
                res2++;
                ans2.push_back(con+1);
            }
            con++;
        }
        if(res%2==0){
            cout<<ans1.size()<<"\n";
            for(auto x:ans1){
                cout<<x<<" ";
            }
            cout<<"\n";
        }else if(res2%2!=0){
            cout<<ans2.size()<<"\n";
            for(auto x:ans2){
                cout<<x<<" ";
            }
            cout<<"\n";
        }else{
            cout<<-1;
            cout<<"\n";
        }
    }
}