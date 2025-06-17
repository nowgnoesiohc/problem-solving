function solution(want, number, discount) {
    const obj = {};
    for(let i=0; i<want.length; i++){
        obj[want[i]] = number[i];
    }
    
    let cnt = 0;
    for(let i=0; i<discount.length; i++){
        const tmp = {...obj};
        let f = 0;
        for(let j=i; j<i+10; j++){
            if(tmp[discount[j]]) tmp[discount[j]] -= 1;
        }
        for(const x in tmp){
            if(tmp[x] != 0) f = 1;
        }
        if(f == 0) cnt++;
    }
    
    return cnt;
}