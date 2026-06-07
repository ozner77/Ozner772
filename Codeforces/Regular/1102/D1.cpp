#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> h(n);
        ll mx=0;
        for(int i=0;i<n;i++){
            cin >> h[i];
            if(h[i]>h[mx]){
                mx = i;
            }
        }
        vector<ll> v(n-1);
        for(int i=0;i<n-1;i++){
            v[i]=h[(mx+i+1)%n];
        }
        vector<ll> L(n), R(n);
        vector<vector<ll>> st;
        ll sum = 0;
        for(int i=0;i<n-1;i++){
            ll cnt=1;
            while(st.size() && st[st.size()-1][0]<=v[i]){
                sum-=st[st.size()-1][0]*st.back()[1];
                cnt+=st[st.size()-1][1];
                st.pop_back();
            }
            st.push_back({v[i],cnt});
            sum+=v[i]*cnt;
            L[i+1]=sum;
        }
        st.clear();
        sum=0;
        for(int i=n-2;i>=0;i--){
            ll cnt=1;
            while(st.size() && st.back()[0]<=v[i]){
                sum-=st.back()[0]*st.back()[1];
                cnt+=st.back()[1];
                st.pop_back();
            }
            st.push_back({v[i],cnt});
            sum+=v[i]*cnt;
            R[i]=sum;
        }
        vector<ll> ans(n);
        for(int i = 0; i < n; i++){
            ans[(mx+i+1)%n]=L[i]+R[i];
        }
        for(int i = 0; i < n; i++){
            cout<<ans[i]<< " ";
        }
        cout <<"\n";
    }
}