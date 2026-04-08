function solution(priorities, location) {
    const queue = priorities.map((e, i) => [i, e]);
    let cnt = 0;
    while (queue.length !== 0) {
        const maxPriority = queue.reduce((max, q) => {
            return Math.max(max, q[1]);
        }, 0);
        const tmp = queue.shift();
        if (maxPriority > tmp[1]) queue.push(tmp);
        else {
            cnt++;
            if (location === tmp[0]) return cnt;
        }
    }
}