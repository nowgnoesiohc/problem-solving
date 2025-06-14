function solution(cards1, cards2, goal) {
    var answer = '';
    let cnt = 0;
    for(let i=0;i<goal.length;i++){
        if(goal[i]==cards1[0]){
            cards1.shift();
            cnt++;
            continue;
        }
        if(goal[i]==cards2[0]){
            cards2.shift();
            cnt++;
            continue;
        }
    }
    answer = cnt==goal.length ? "Yes" : "No";
    return answer;
}