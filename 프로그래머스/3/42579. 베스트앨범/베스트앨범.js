function solution(genres, plays) {
    var answer = [];
    const gl = genres.length;
    const gp = {};
    for(let i=0; i<gl; i++){
        if(!gp[genres[i]]) gp[genres[i]] = 0;
        gp[genres[i]] += plays[i];
    }
    
    const gp_sorted = Object.entries(gp).sort((a, b)=>b[1]-a[1]);
    const keys = [];
    for(const a of gp_sorted) keys.push(a[0]);
    // console.log(keys)
    for(const k of keys){
        let stp=-1, ndp=-1;
        let stidx, ndidx;
        for(let i=0; i<gl; i++){
            if(k == genres[i]){
                if(stp < plays[i]){
                    ndidx = stidx;
                    stidx = i;
                    ndp = stp;
                    stp = plays[i];
                }
                else if(ndp < plays[i]){
                    ndidx = i;
                    ndp = plays[i]
                }
            }
        }
        answer.push(stidx);
        if(ndp != -1) answer.push(ndidx);
        // console.log(answer)
    }
    
    
    return answer;
}