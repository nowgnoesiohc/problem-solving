function solution(begin, target, words) {
    function is1Diff(a, b) {
        let cnt = 0;
        for (let i = 0; i < a.length; i++) {
            if (a[i] !== b[i]) cnt++;
        }
        return cnt === 1 ? true : false;
    }
    const n = words.length;
    const queue = new Array();
    const visited = new Array(n);
    queue.push([begin, 0]);
    let head = 0;
    while (queue.length > head) {
        const [tmp, cnt] = queue[head++];
        if (tmp === target) return cnt;
        for (let i = 0; i < n; i++) {
            if (!visited[i] && is1Diff(words[i], tmp)) {
                visited[i] = true;
                queue.push([words[i], cnt + 1]);
            }
        }
    }
    return 0;
}