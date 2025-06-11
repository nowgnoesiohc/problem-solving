function isRight(str){
    const stack = [];
    for(let i=0; i<str.length; i++){
        if(str[i]=='[' || str[i]=='{' || str[i]=='('){
            stack.push(str[i]);
        }
        else{
            const tmp = stack.pop();
            if(str[i]==')' && tmp=='(') continue;
            else if(str[i]=='}' && tmp=='{') continue;
            else if(str[i]==']' && tmp=='[') continue;
            return false;
        }
    }
    return stack.length === 0;
}

function solution([...s]) {
    var answer = 0;
    for(let i = 0; i < s.length; i++){
        const tmp = s.shift();
        s.push(tmp);
        if(isRight(s.join(''))) answer++;
    }
    return answer;
}