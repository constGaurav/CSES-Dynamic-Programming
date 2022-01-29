// @MrGaurav
#include <bits/stdc++.h>
#include <cstring>
#include <cmath>
#include <cstring>
#define endl "\n"
#define ll int
#define ull unsigned long long;
#define ld long double;
#define vi vector<int>
#define vll vector<ll>
#define vvi vector <vi>
#define pii pair<int,int>
#define pll pair<long long, long long>
#define maxHeap priority_queue<ll>
#define minHeap priority_queue<ll,vector<ll>,greater<ll>>
#define mod 1000000007
#define inf 1000000000000000001;
#define be(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define debug(a) cout<<a<<" ";
#define eb emplace_back
#define pb push_back
#define pf push_front
#define f first
#define s second
#define GAURAV_CHAUDHARY ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;
// Pragmas
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
void prllArray(ll a[], ll n){for(ll i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;}
string decToBinary(ll n){string s="";ll i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;ll base = 1;ll len = num.length();for(ll i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
void debugVector(vector<ll> &v){cout<<endl<<" Debug vector: ";for(auto x: v) cout<<x<<" "; cout<<endl;}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(ll i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(ll n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
 
// This problem is exactly similar to 0-1 Kanpsack
ll bookShop(ll i, vector<ll> &price, vector<ll> &pages, ll x, vector<vector<ll>> &dp){
	if(i < 0 or x == 0)
		return 0;
	if(dp[i][x] != -1) 
		return dp[i][x];
	ll take = 0, notTake = 0;
	if(x >= price[i])
		take = pages[i] + bookShop(i-1, price, pages, x-price[i],dp);
	notTake = 0 + bookShop(i-1, price, pages, x, dp);
	return dp[i][x] = max(take, notTake);
}
 
// Bottom Up
ll bookShopBU(vector<ll> &price, vector<ll> &pages, ll x){
	ll n = price.size();
	vector<vector<ll>> dp(n+1, vector<ll>(x+1,0));
 
	for(int i=0;i<n+1;i++){
        for(int j=0;j<x+1;j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }
 
    for(int i=1;i<n+1;i++){
        for(int j=1;j<x+1;j++){
            if(price[i-1] <= j){
                int op1 = pages[i-1] + dp[i-1][j-price[i-1]];
                int op2 = dp[i-1][j];
                dp[i][j] = max(op1,op2);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][x];
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
GAURAV_CHAUDHARY
 
    ll n,x; cin>>n>>x; // x - capacity
    vector<ll> price(n); // similar to weight
    vector<ll> pages(n); // similar to value
    // vector<vector<ll>> dp(n+1, vector<ll>(x+1,-1));
    for(ll i=0;i<n;i++) cin>>price[i];
    for(ll i=0;i<n;i++) cin>>pages[i];
    // cout<<bookShop(n-1, price, pages, x, dp)<<endl; // this is giving Run Time error
 
    cout<<bookShopBU(price, pages, x);
 
    return 0;
}