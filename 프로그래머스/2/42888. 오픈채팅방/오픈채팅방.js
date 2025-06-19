function solution(record) {
    const res = [];
    const nickname = {};

    for(r of record){
        const tmp = r.split(' ');
        if(tmp[0] == 'Leave'){
            res.push(`0 ${tmp[1]}`);
        }
        else{
            nickname[tmp[1]] = tmp[2];
            if(tmp[0] == 'Enter') res.push(`1 ${tmp[1]}`);    
        }
    }
    
    const answer = [];
    for(r of res){
        const tmp = r.split(' ');
        if(tmp[0] == '1') answer.push(`${nickname[tmp[1]]}님이 들어왔습니다.`);
        else answer.push(`${nickname[tmp[1]]}님이 나갔습니다.`);
    }
    // console.log(answer);
    return answer;
}