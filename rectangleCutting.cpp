// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;


/*
// Top Down Dp
int rectangleCutting(int i, int j, vector<vector<int>> &dp){
	if(i == j)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	int hoz = 1e8, ver = 1e8;

	// Horizontal Cut
	for(int k=1;k<=j-1;k++){
		int x = 1 + rectangleCutting(i,k,dp) + rectangleCutting(i,j-k,dp);
		hoz = min(hoz, x);
	}

	// Vertical Cut
	for(int k=1;k<=i-1;k++){
		int x = 1 + rectangleCutting(k,j,dp) + rectangleCutting(i-k,j,dp);
		ver = min(ver, x);
	}

	return dp[i][j] = min(hoz,ver);
}
*/

// Bottom up
int rectangleCutting(int a, int b){
	vector<vector<int>> dp(a+1,vector<int>(b+1));
	for(int i = 0; i <= a; i++) {
		for(int j = 0; j <= b; j++) {
			if(i == j) dp[i][j] = 0;
			else {
				dp[i][j] = 1e9;
				for(int k = 1; k < i; k++) {
					dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1);
				}
				for (int k = 1; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1);
				}
			}
		}
	}

	return dp[a][b];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a,b; cin>>a>>b;
    cout<<rectangleCutting(a,b);
    return 0;
}

