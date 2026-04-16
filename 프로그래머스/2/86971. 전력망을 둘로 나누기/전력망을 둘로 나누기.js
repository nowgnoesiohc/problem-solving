function solution(n, wires) {
    let visited = new Array(n + 1).fill(false);
    let excepted = [...visited];

    function dfs(current) {
        visited[current] = true;
        const filteredwires = excepted.filter((e) => e.includes(current));
        let cnt = 1;
        for (const x of filteredwires) {
            let target;
            if (x[0] === current) target = x[1];
            else target = x[0];
            if (!visited[target]) {
                // console.log(target);
                cnt = cnt + dfs(target);
            }
        }
        return cnt;
    }

    let min = 100;
    for (const x of wires) {
        excepted = wires.filter((e) => e !== x);
        // console.log(excepted);
        const tmp = Math.abs(dfs(x[0]) - dfs(x[1]));
        // console.log(x, dfs(x[0]), dfs(x[1]));
        visited = new Array(n + 1).fill(false);
        if (tmp < min) min = tmp;
    }

    return min;
}