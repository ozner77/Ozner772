#include <bits/stdc++.h>
using namespace std;
void solve(){
    int x, y;
    cin>>x>>y;
    if((x&y)==0){
        cout<<x<<" "<<y<<"\n";
        return;
    }
    int cx=x, cy=y;
    vector <int> br;
    while(cx>0 || cy>0){
        br.push_back((cx%2)+(cy%2));
        cx/=2;
        cy/=2;
    }
    int p=x, q=y;
    int n=br.size(), r;
    int aa, ab, ba, bb, ca, cb, da, db;
    for(int i=0; i<n; ++i){
        if(br[i]==2){
            r=i;
        }
    } 
    for(int i=0; i<=r; ++i){
        p/=2;
        q/=2;
    }
    p*=2;
    q*=2;
    ++p;
    ++q;
    for(int i=0; i<r; ++i){
        p*=2;
        q*=2;
    }
    --p;
    --q;
    aa=p+1;
    ab=q;
    bb=q+1;
    ba=p;
    ca=x;
    cb=q+1+(1<<r);
    da=p+1+(1<<r);
    db=y;
    int mn=(x-aa)+(y-ab);
    p=aa;
    q=ab;
    if((x-ba)+(y-bb)<mn){
        mn=(x-ba)+(y-bb);
        p=ba;
        q=bb;
    }
    if((ca-x)+(cb-y)<mn && (ca&cb)==0){
        mn=(ca-x)+(cb-y);
        p=ca;
        q=cb;
    }
    if((da-x)+(db-y)<mn && (da&db)==0){
        mn=(da-x)+(db-y);
        p=da;
        q=db;
    }
    cout<<p<<' '<<q<<"\n";
    return;
}
int main(){
    int T=1;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}