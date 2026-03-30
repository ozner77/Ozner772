#include <bits/stdc++.h>
#define s second
#define f first
using namespace std;
void solve(){
    int n, m, l, cmd=0, cld=0;
    l++;
    vector <int> t;
    vector <pair <int, pair <int, int> > > dl;
    cin>>n>>m>>l;
    if(m>n+1){
        m=n+1;
    }
    dl.assign(l+1, {0, {0, l}});
    t.resize(n);
    for(int i=0; i<n; ++i){
        cin>>t[i];
    }
    t.push_back(l+1);
    dl[0]={m, {0, l}};
    int ci=0;
    for(int i=1; i<=l; ++i){
        --dl[cld].f;
        ++dl[cld+1].f;
        if(cld+1>cmd){
            cmd=cld+1;
        }
        if(dl[cld+1].f==1){
            dl[cld+1].s.f=cld;
            dl[cld+1].s.s=dl[cld].s.s;
            dl[cld].s.s=cld+1;
            dl[dl[cld+1].s.s].s.f=cld+1;
        }
        if(dl[cld].f==0){
            dl[cld+1].s.f=dl[cld].s.f;
            dl[dl[cld+1].s.f].s.s=cld+1;
            ++cld;
        }
        if(i==t[ci]){
            --dl[cmd].f;
            if(dl[cmd].f==0){
                dl[dl[cmd].s.f].s.s=l;
                dl[l].s.f=dl[cmd].s.f;
                cmd=dl[cmd].s.f;
            }
            if(n-ci>=m){
                ++dl[0].f;
                cld=0;
            }
            ++ci;
        }
    }
    cout<<cmd<<"\n";
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