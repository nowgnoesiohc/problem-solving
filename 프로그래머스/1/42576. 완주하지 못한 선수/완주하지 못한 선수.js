function solution(participant, completion) {
    let answer = '';
    const hash = new Map();
    
    for(const x of participant) hash.set(x, (hash.get(x) || 0) + 1);
    for(const x of completion) hash.set(x, (hash.get(x) || 0) - 1);
    
    hash.forEach((value, key) => {
        if(value) answer = key;
    })
    return answer;
}