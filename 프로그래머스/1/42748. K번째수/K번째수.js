function solution(array, commands) {
    const result = [];
    for (const cmd of commands) {
        const slicedArray = array.slice(cmd[0] - 1, cmd[1]);
        slicedArray.sort((a, b) => a - b);
        result.push(slicedArray[cmd[2] - 1]);
    }
    return result;
}