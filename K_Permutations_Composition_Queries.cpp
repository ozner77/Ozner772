#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll N,M;
        cin>>N>>M;
        vector<vector<ll>> A(N,vector<ll>(M));
        for(ll i=0;i<N;i++)
        {
            for(ll j=0;j<M;j++)
            {
                cin>>A[i][j];
                A[i][j]--;
            }
        }
        ll Q;
        cin>>Q;
        for(ll q=0;q<Q;q++)
        {
            ll L,R;
            cin>>L>>R;
            L--;
            vector<ll> B = A[L];
            for(ll i=L+1;i<R;i++)
            {
                vector<ll> C(M);
                for(ll j=0;j<M;j++)
                {
                    C[j] = A[i][B[j]];
                }
                B = C;
            }
            ll ans=0;
            for(ll i=0;i<M;i++)
            {
                ans += (i+1)*(B[i]+1);
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}