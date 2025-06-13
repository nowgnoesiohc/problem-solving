function solution(s)
{
    var answer = 0;
    const stack = [];
    
    for(const x of s){
        stack.push(x);
        const tmp = stack.length;
        // console.log(i, stack);

        if(stack[tmp-1]==stack[tmp-2]){
            stack.pop();
            stack.pop();
        }
        // console.log(i, stack);
    }
    if(!stack.length) answer=1;
    return answer;
}