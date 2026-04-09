function solution(n, lost, reserve) {
    const students = new Array(n + 1).fill(1);
    for (const x of lost) students[x]--;
    for (const x of reserve) students[x]++;
    for (let i = 1; i <= n; i++) {
        if (students[i] === 2) {
            if (students[i - 1] === 0 && i !== 1) {
                students[i]--;
                students[i - 1]++;
            } else if (students[i + 1] === 0 && i !== n) {
                students[i]--;
                students[i + 1]++;
            }
        }
    }
    let cnt = 0;
    for (let i = 1; i <= n; i++) if (students[i] !== 0) cnt++;
    return cnt;
}