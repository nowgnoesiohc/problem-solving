#include <bits/stdc++.h>
using namespace std;

int N, a;
vector<vector<int>> adj;
vector<int> state;    // 0=off, 1=on
vector<int> ans;

// v에서 p를 부모로 삼아 DFS
void dfs(int v, int p) {
    for (int u : adj[v]) {
        if (u == p) continue;
        // 1) 내려가기: v -> u
        ans.push_back(u);
        state[v] ^= 1;          // departure at v toggles v

        dfs(u, v);

        // 2) 올라오기: u -> v
        ans.push_back(v);
        state[u] ^= 1;          // departure at u toggles u

        // 3) 자식 u가 여전히 켜져 있으면, 한 번 더 왕복
        if (state[u] == 1) {
            // v -> u
            ans.push_back(u);
            state[v] ^= 1;
            // u -> v
            ans.push_back(v);
            state[u] ^= 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> a;
    adj.assign(N+1, {});
    state.assign(N+1, 0);

    string S;
    cin >> S;
    for (int i = 1; i <= N; i++) {
        state[i] = (S[i-1] == '1');
    }

    for (int i = 0; i < N-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(a, 0);

    // 루트 a에서의 마지막 상태 보정
    if (state[a] == 1) {
        // a의 이웃이 무조건 하나 이상 있으므로 adj[a][0] 사용
        int u = adj[a][0];
        ans.push_back(u);
        // departure at a toggles a
        // (도착한 u는 토글되지 않음)
        state[a] ^= 1;
        // 이후 멈추므로 u의 상태 변화는 없음
    }

    // 출력
    cout << ans.size() << "\n";
    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << (i+1 < (int)ans.size() ? ' ' : '\n');
    }
    return 0;
}
