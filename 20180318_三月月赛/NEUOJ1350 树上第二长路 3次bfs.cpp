#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))

const int maxn = 100005;

vector<int> e[maxn];
bool flag[maxn];
int depth[maxn], ans, n;

int bfs(int st) { //图的bfs
    //init
    memset(flag, 0, sizeof(flag));
    memset(depth, 0, sizeof(depth));
    queue<int> q;
    q.push(st);//起点
    flag[st] = true;//已访问过
    while(!q.empty()) { //处理直至队列为空
        int u = q.front();//取出一个点，处理一个点
        q.pop();
        for(int i = 0;i < e[u].size();i++) { //处理每个与u邻接的点
            if(!flag[e[u][i]]) { //该点未被访问过
                depth[e[u][i]] = depth[u]+1;
                flag[e[u][i]] = true;
                q.push(e[u][i]);
            }
        }
    }
    int point = -1;//距离最远的点的编号
    ans = -1;//最远距离
    for(int i = 1;i <= n;i++) {
        if(depth[i] > ans) {
            ans = depth[i];
            point = i;
        }

    }
    return point;//返回距离最远的点的编号
}

int main() {
    while(scanf("%d", &n) == 1) {
        memset(e, 0, sizeof(e));
        int x, y, res;
        for(int i = 1;i < n;i++) {
            scanf("%d %d", &x, &y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        // for(int i = 1;i <= n;i++) {
        //     cout << i << ": ";
        //     for(int j = 0;j < e[i].size();j++) cout << e[i][j] << ' ';
        //     cout << endl;
        // }
        int u1 = bfs(1);//以任意点为起点跑出的最长距离的终点，记u1
        // cout << "u1: " << u1 << endl;
        // cout << "ans: " << ans << endl;
        int u2 = bfs(u1);//以u1为起点，跑出最长距离，记u2
        // cout << "u2: " << u2 << endl;
        // cout << "ans: " << ans << endl;
        int cnt = 0;
        for(int i = 1;i <= n;i++)
            if(ans == depth[i]) cnt++;
        if(cnt == 1) {
            int u3 = bfs(u2);
            // cout << "u3: " << u3 << endl;
            // cout << "ans: " << ans << endl;
            int cnt1 = 0;
            for(int i = 1;i <= n;i++)
                if(ans == depth[i]) cnt1++;
            if(cnt1 == 1) res = ans-1;
            else res = ans;
        }
        else res = ans;
        cout << res << endl;
    }
    return 0;
}