function solution(N, stages) {
    var answer = [];
    let dodal = Array(N+1).fill(0);
    let clear = Array(N+1).fill(0);
    let fail = [];
    let idx = [];
    
    for(let i=0;i<stages.length;i++){
        for(let j=1;j<=stages[i];j++){
            dodal[j]++;
            if(stages[i]!=j) clear[j]++;
        }
    }
    
    for(let i=1;i<=N;i++){
        fail.push((dodal[i]-clear[i])/(dodal[i]));
        idx.push(i);
    }
    console.log(fail);
    console.log(idx)
    for(let i=0;i<N;i++){
        for(let j=i;j<N;j++){
            var tmp;
            if(fail[i]<=fail[j]){
                if(fail[i]==fail[j] && idx[i]<idx[j]) continue;
                tmp = fail[i];
                fail[i] = fail[j];
                fail[j] = tmp;
                
                tmp = idx[i];
                idx[i] = idx[j];
                idx[j] = tmp;
            }
        }
    }
    
    return idx;
}