#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    string a,b;
    cin>>a>>b;
    ll as=a.size();
    ll bs=b.size();
    bool ok=false;
    for(int i=0;i<=as-bs;i++){
        bool ok2=true;
        for(int j=0;j<bs;j++){
            if(a[i+j]==b[j] || a[i+j]=='?'){
                continue;
            }else{
                ok2=false;
                break;
            }
        }
        if(ok2){
            ok=true;
            break;
        }
    }
    if(ok){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
}