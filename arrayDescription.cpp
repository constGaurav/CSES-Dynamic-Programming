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
 
int arrayDescription(vector<int> &a){
    
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
GAURAV_CHAUDHARY
 
    int n,m; cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<arrayDescription(a);


    return 0;
}