#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 500005;

int t;

int dp[maxn];
char s[maxn];

int main() {
    cin >> t;
    for(int cas = 1;cas <= t;cas++) {
        memset(dp, 0, sizeof(dp));
        scanf("%s", s);
        int len = strlen(s);
        stack<int> st;
        for(int i = 0;i < len;i++) {
            if(s[i] == ')') {
                if(st.empty())
                    continue;
                int tmp = st.top();
                st.pop();
                if(tmp != 0)
                    dp[i] = dp[tmp-1] + 1;
                else
                    dp[i] = 1;
            }
            else
                st.push(i);
        }
        ll ans = 0;
        for(int i = 0;i < len;i++)
            ans += dp[i];
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}