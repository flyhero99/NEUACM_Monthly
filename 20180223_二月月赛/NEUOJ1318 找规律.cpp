#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
const int mod = 1000000007;

int t;
int n;
int cas;

ll mypow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) {
            ans = (ans*a) % mod;
        }
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

int main() {
    cin >> t;
    for(int cas = 1;cas <= t;cas++) {
        cin >> n;
        int ans = (int) (n/2);
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}