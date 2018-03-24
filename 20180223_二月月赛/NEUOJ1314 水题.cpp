#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100005;
const int mod = 100003;

int t;
ll a, b, c, d, e, f;

int main() {
    cin >> t;
    while(t--) {
        cin >> a >> b >> c >> d >> e >> f;
        ll rmin = min(a, min(c, e)), rmax = max(a, max(c, e));
        ll cmin = min(b, min(d, f)), cmax = max(b, max(d, f));
        cout << (rmax-rmin) * (cmax-cmin) << endl;
    }
    return 0;
}