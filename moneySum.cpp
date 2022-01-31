// @MrGaurav
#include <bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;


// Top Down Dp
int moneySum(int i, vector<int> &a, vector<int> &ans){
	if(i == a.size())
		return 0;

	int x = a[i] + moneySum(i+1, a, ans);
	int y = 0 + moneySum(i+1, a, ans);
	ans.push_back(x);
	ans.push_back(y);
	return 0;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n; cin>>n;
    vector<int> a(n);
    for(ll i=0;i<n;i++) 
    	cin>>a[i];

    vector<int> ans;
    moneySum(0, a, ans);
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<endl;
    for(int x: ans) cout<<x<<" ";
    return 0;
}

