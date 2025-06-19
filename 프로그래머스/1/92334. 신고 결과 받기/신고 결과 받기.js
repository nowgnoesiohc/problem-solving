function solution(id_list, report, k) {
    var answer = [];
    const er = {}; // 해당 유저가 신고한 ID
    const ee = {}; // 신고당한 횟수
    
    for(const i of id_list){
        er[i] = [];
        ee[i] = 0;
    }
    for(const r of report){
        const tmp = r.split(' ');
        if(er[tmp[0]].includes(tmp[1])) continue;
        er[tmp[0]].push(tmp[1]);
        ee[tmp[1]]++;
    }
    // console.log(ee, er);
    
    const blocked = [];
    for(const e in ee){
         if(ee[e] >= k) blocked.push(e)
    }
    for(const i in er){
        let cnt = 0;
        for(const j of er[i]){
            for(const k of blocked){
                if(j==k) cnt++;
                // console.log(j, k)
            }
        }
        answer.push(cnt);
    }
    return answer;
}