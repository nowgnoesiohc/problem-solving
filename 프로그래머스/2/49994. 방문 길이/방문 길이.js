function solution(dirs) {

    const hx = [0];
    const hy = [0];
    const hd = [];
    let x = 0, y = 0;
    
    for(let i = 0; i < dirs.length; i++){
        if(dirs[i] == 'D' && y-1 >= -5) {
            y--;
            hx.push(x);
            hy.push(y);
            hd.push(dirs[i]);
        }
        else if(dirs[i] == 'U' && y+1 <= 5) {
            y++;
            hx.push(x);
            hy.push(y);
            hd.push(dirs[i]);
        }
        else if(dirs[i] == 'L' && x-1 >= -5) {
            x--;
            hx.push(x);
            hy.push(y);
            hd.push(dirs[i]);
        }
        else if(dirs[i] == 'R' && x+1 <= 5){
            x++;
            hx.push(x);
            hy.push(y);
            hd.push(dirs[i]);
        }
    }
    console.log(hx, hy, hd);
    
    var answer = 0;
    for(let i = 0; i < hd.length; i++){
        let isRe = 0;
        for(let j = 0; j < i; j++){
            if(hx[i]==hx[j] && hy[i]==hy[j] && hd[i]==hd[j]) isRe = 1;
        }
                    
        let tmp;
        if(hd[i]=='D') tmp = 'U';
        else if(hd[i]=='U') tmp = 'D';
        else if(hd[i]=='L') tmp = 'R';
        else if(hd[i]=='R') tmp = 'L';
        
        for(let j = 0; j < i; j++){
            if(hx[i]==hx[j+1] && hy[i]==hy[j+1] && tmp==hd[j]) isRe = 1;
        }
        if(isRe == 0) answer++;
    }
    return answer;
}