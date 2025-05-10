#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    // 논문 주제 한 줄 입력
    if (!getline(cin, line)) return 0;

    // 대소문자 구분 없이 찾기 위해 모두 소문자로 변환
    string s = line;
    for (char &c : s) {
        c = tolower(c);
    }

    // 디지털인문학 트랙 판단 키워드
    const vector<string> digital = {"social", "history", "language", "literacy"};
    // 공공빅데이터 트랙 판단 키워드
    const vector<string> publicbd = {"bigdata", "public", "society"};

    // 디지털인문학 키워드 검사
    for (const auto &kw : digital) {
        if (s.find(kw) != string::npos) {
            cout << "digital humanities";
            return 0;
        }
    }
    // 공공빅데이터 키워드 검사
    for (const auto &kw : publicbd) {
        if (s.find(kw) != string::npos) {
            cout << "public bigdata";
            return 0;
        }
    }

    return 0;
}
