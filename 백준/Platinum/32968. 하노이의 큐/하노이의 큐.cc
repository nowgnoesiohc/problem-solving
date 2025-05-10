#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--){
        int N;
        long long L;
        cin >> N >> L;
        vector<deque<int>> q(3);
        for(int i = 0; i < N; i++){
            int a;
            cin >> a;
            q[0].push_back(a);  // A 큐에 초기값
        }

        vector<pair<int,int>> ops;
        ops.reserve((int)(1.5 * N * (int)log2(N) + 10));

        int current = 0, scratch1 = 1, scratch2 = 2;
        // bottom-up merge sort
        for(int width = 1; width < N; width <<= 1){
            // q[current] 에서 길이 width 러너 두 개씩 뽑아 합쳐서 q[scratch2]에 쌓는다
            while(!q[current].empty()){
                // 1) 첫 번째 러너(run1)를 scratch1로 이동
                int cnt1 = min(width, (int)q[current].size());
                for(int i = 0; i < cnt1; i++){
                    ops.emplace_back(current, scratch1);
                    q[scratch1].push_back(q[current].front());
                    q[current].pop_front();
                }
                // 2) 두 번째 러너(run2)는 q[current]에 남아있으므로 그 크기만 알면 된다
                int cnt2 = min(width, (int)q[current].size());
                int c1 = cnt1, c2 = cnt2;
                // 3) 두 러너를 merge하여 scratch2에
                while(c1 > 0 && c2 > 0){
                    if(q[scratch1].front() <= q[current].front()){
                        ops.emplace_back(scratch1, scratch2);
                        q[scratch2].push_back(q[scratch1].front());
                        q[scratch1].pop_front();
                        c1--;
                    } else {
                        ops.emplace_back(current, scratch2);
                        q[scratch2].push_back(q[current].front());
                        q[current].pop_front();
                        c2--;
                    }
                }
                while(c1 > 0){
                    ops.emplace_back(scratch1, scratch2);
                    q[scratch2].push_back(q[scratch1].front());
                    q[scratch1].pop_front();
                    c1--;
                }
                while(c2 > 0){
                    ops.emplace_back(current, scratch2);
                    q[scratch2].push_back(q[current].front());
                    q[current].pop_front();
                    c2--;
                }
            }
            // 역할(queues)을 rotate: scratch2 → current, current → scratch1, scratch1 → scratch2
            int oc = current, os1 = scratch1, os2 = scratch2;
            current   = os2;
            scratch1  = oc;
            scratch2  = os1;
        }

        // 결과는 q[current]에 정렬된 상태로, 나머지 두 큐는 비어 있음
        int k = ops.size();
        // k는 L 이하여야 함
        if(k > L) {
            // 보통 문제에서 보장되므로 여기서는 아무 처리 없이 잘못된 경우를 그대로 출력
        }
        // 출력
        cout << k << "\n";
        if(k > 0){
            // 'A'+from, 'A'+to
            for(int i = 0; i < k; i++){
                char f = 'A' + ops[i].first;
                char t = 'A' + ops[i].second;
                cout << f << t << (i + 1 < k ? ' ' : '\n');
            }
        }
    }

    return 0;
}
