function solution(answers) {
    const a1 = [1, 2, 3, 4, 5];
    const a2 = [2, 1, 2, 3, 2, 4, 2, 5];
    const a3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    let c = [0, 0, 0, 0];
    
    var answer = [];
    
    for(let i = 0; i < answers.length; i++){
        console.log(a1[i % a1.length]);
        if(answers[i] == a1[i % a1.length]) c[1]++;
        if(answers[i] == a2[i % a2.length]) c[2]++;       
        if(answers[i] == a3[i % a3.length]) c[3]++;
    }
    
    for(let i = 1; i <= 3; i++){
        if(c[i] == Math.max(...c)) answer.push(i);
    }
    
    return answer;
}