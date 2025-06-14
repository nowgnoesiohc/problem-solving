function solution(progresses, speeds) {
    var answer = [];
    const num = progresses.length;
    let endTime = [];
    for(let i=0; i<num; i++){
        endTime.push(Math.ceil((100 - progresses[i]) / speeds[i]));
    }
    console.log(endTime)

    let tmp = endTime[0];
    let cnt = 0;
    for(let i=1;; i++){
        if(endTime[0]<=tmp){
            cnt++;
            endTime.shift();
        }
        else{
            tmp = endTime[0];
            answer.push(cnt);
            cnt = 0;
        }
        // console.log(tmp, cnt, answer)
        if(!endTime.length) {answer.push(cnt); break;}
    }   
    return answer;
}