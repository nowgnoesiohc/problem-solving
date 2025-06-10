function solution(numbers) {
    var res = [];

    for(let i = 0; i < numbers.length; i++){
        for(let ii = i + 1; ii < numbers.length; ii++){
            res.push(numbers[i] + numbers[ii]);
        }
    }
    
    var answer = [...new Set(res)].sort((a, b) => a - b);
    return answer;
}