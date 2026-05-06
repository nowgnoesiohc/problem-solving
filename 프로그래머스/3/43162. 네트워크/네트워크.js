function solution(n, computers) {
    let cnt = 0;
    const visited = new Array(n).fill(false);
    function dfs(c) {
        visited[c] = true;
        for (let i = 0; i < n; i++) {
            if (i !== c && !visited[i] && computers[c][i]) dfs(i);
        }
    }
    for (let i = 0; i < n; i++) {
        if (!visited[i]) {
            cnt++;
            dfs(i);
        }
    }
    return cnt;
}