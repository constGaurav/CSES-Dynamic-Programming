// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;


ll dp[1000001][3];
const ll mod = 1e9+7;


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    dp[1][1] = dp[1][2] = 1;
    for(ll i=2;i<1000001;i++) {
        dp[i][1] = ((dp[i-1][1]*4)%mod + dp[i-1][2])%mod;
        dp[i][2] = (dp[i-1][1] + (dp[i-1][2]*2)%mod)%mod;
    }

    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        cout<<(dp[n][1] + dp[n][2])%mod<<endl;
    }

    return 0;
}

