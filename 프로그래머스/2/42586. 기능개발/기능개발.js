function solution(progresses, speeds) {
    const complete = [];
    const result = [];
    for (let i = 0; i < progresses.length; i++) {
        complete.push(Math.ceil((100 - progresses[i]) / speeds[i]));
    }
    let cnt = 0,
        tmp = complete[0];
    for (let i = 0; i < progresses.length; i++) {
        if (tmp < complete[i]) {
            result.push(cnt);
            cnt = 1;
            tmp = complete[i];
        } else cnt++;
    }
    result.push(cnt);
    return result;
}