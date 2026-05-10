#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
vector<char> V;
void fun(ll l,ll r){
    while(V[l]==V[r]){
        V[l]='*';
        V[r]='*';
        while(l>=0){
            if(V[l]!='*'){
                break;
            }
            l--;
        }
        while(r<=n-1){
            if(V[r]!='*'){
                break;
            }
            r++;
        }
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        cin>>n;
        V.clear();
        string s;
        cin>>s;
        for(int i=0;i<n;i++){
            V.push_back(s[i]);
        }
        for(int i=1;i<n;i++){
            if(V[i]==V[i-1]){
                fun(i-1,i);
            }
        }
        bool ok=true;
        for(auto x:V){
            if(x!='*'){
                ok=false;
            }
        }
        if(ok){
            cout<<"YES\n";
        }else{
            cout<<"NO\n";
        }
    }
}