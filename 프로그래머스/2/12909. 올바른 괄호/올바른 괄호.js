function solution(s){
    const stack = [];
    for (const x of s) {
        if (x === '(') stack.push(x);
        else if (x === ')') {
            const tmp = stack.pop();
            if (tmp === undefined) return false;
        }
    }
    return stack.length ? false : true;
}