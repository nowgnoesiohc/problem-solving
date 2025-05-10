#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF64 = LLONG_MAX/4;

// 세그먼트 트리: 구간 add, 구간 max
struct SegTree {
    int n;
    vector<ll> mx, lz;
    SegTree(int _n): n(_n), mx(4*n+4), lz(4*n+4, 0) {}

    // 초기값: seg[i] = K * i
    void build(int idx, int l, int r, ll K) {
        if (l == r) {
            mx[idx] = K * l;
        } else {
            int m = (l + r) >> 1;
            build(idx<<1,   l, m, K);
            build(idx<<1|1, m+1, r, K);
            mx[idx] = max(mx[idx<<1], mx[idx<<1|1]);
        }
    }

    void apply(int idx, ll v) {
        mx[idx] += v;
        lz[idx] += v;
    }

    void push(int idx) {
        if (lz[idx] != 0) {
            apply(idx<<1,   lz[idx]);
            apply(idx<<1|1, lz[idx]);
            lz[idx] = 0;
        }
    }

    // [ql..qr] 에 v를 더함
    void update(int idx, int l, int r, int ql, int qr, ll v) {
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            apply(idx, v);
            return;
        }
        push(idx);
        int m = (l + r) >> 1;
        update(idx<<1,   l,   m, ql, qr, v);
        update(idx<<1|1, m+1, r, ql, qr, v);
        mx[idx] = max(mx[idx<<1], mx[idx<<1|1]);
    }

    // [ql..qr] 구간의 max 조회
    ll query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return -INF64;
        if (ql <= l && r <= qr) return mx[idx];
        push(idx);
        int m = (l + r) >> 1;
        return max(
            query(idx<<1,   l,   m, ql, qr),
            query(idx<<1|1, m+1, r, ql, qr)
        );
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    ll K, X, Y;
    cin >> N >> M >> K >> X >> Y;
    vector<int> A(M+1);
    for (int i = 1; i <= M; i++) {
        cin >> A[i];
    }
    vector<ll> B(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> B[i];
    }

    // (1) 기본 시간: 모든 요청을 메인 메모리에서 처리했을 때
    ll baseTime = 0;
    for (int i = 1; i <= N; i++) {
        baseTime += B[i] * Y;
    }

    // 캐시 이득 단위: Y - X
    ll D = Y - X;

    // (2) dp 를 위한 세그 트 초기화 (크기 M)
    SegTree st(M);
    st.build(1, 1, M, K);

    // 마지막 등장 위치 기록
    vector<int> last(N+1, 0);
    ll bestProfit = 0;

    // (3) i번째 위치까지 고려했을 때의 최대 profit 계산
    for (int i = 1; i <= M; i++) {
        int v = A[i];
        ll bonus = B[v] * D;
        int p = last[v];
        // p+1..i 구간 시작점들은 v를 '첫 등장'으로 추가
        st.update(1, 1, M, p+1, i, bonus);
        last[v] = i;

        // F(i) = max_{1<=j<=i} [ K*j + S(j,i) ]
        ll Fi = st.query(1, 1, M, 1, i);
        // dp[i] = F(i) - K*(i+1)
        ll dpi = Fi - K * (i + 1LL);
        bestProfit = max(bestProfit, dpi);
    }

    // (4) 답: baseTime - bestProfit
    cout << baseTime - bestProfit << "\n";
    return 0;
}
