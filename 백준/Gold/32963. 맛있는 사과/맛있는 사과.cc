#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    // 1) 사과 정보 읽기
    vector<pair<ll,ll>> apples(N);
    for (int i = 0; i < N; i++) cin >> apples[i].first;   // t_i (맛)
    for (int i = 0; i < N; i++) cin >> apples[i].second;  // s_i (크기)

    // 2) 맛 기준 내림차순 정렬
    sort(apples.begin(), apples.end(),
         [](auto &a, auto &b){ return a.first > b.first; });

    // 3) 쿼리 읽고, 원래 순서를 기억
    vector<pair<ll,int>> queries(Q);
    vector<ll> pvals(Q);
    for (int i = 0; i < Q; i++) {
        cin >> pvals[i];
        queries[i] = { pvals[i], i };
    }
    // 맛 기준 내림차순으로 정렬
    sort(queries.begin(), queries.end(),
         [](auto &a, auto &b){ return a.first > b.first; });

    // 4) map을 이용해 현재까지 추가된 사과들의 크기 빈도 관리
    map<ll,int> freq;
    vector<ll> ans(Q);
    int idx = 0;  // apples에서 다음으로 추가할 인덱스

    // 5) 쿼리를 맛(p) 내림차순으로 처리
    for (auto &q : queries) {
        ll p = q.first;
        int qi = q.second;
        // 맛 >= p인 사과들을 모두 map에 추가
        while (idx < N && apples[idx].first >= p) {
            freq[ apples[idx].second ]++;
            idx++;
        }
        // map이 비어있으면 0, 아니면 rbegin()->second가 최대 크기의 개수
        if (freq.empty()) ans[qi] = 0;
        else              ans[qi] = freq.rbegin()->second;
    }

    // 6) 원래 쿼리 순서대로 출력
    for (int i = 0; i < Q; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
