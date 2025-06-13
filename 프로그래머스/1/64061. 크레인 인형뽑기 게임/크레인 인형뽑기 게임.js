function solution(board, moves) {
    var answer = 0;
    const num = board.length;
    
    const arr = new Array(num);
    for(let i=0;i<num;i++) arr[i] = new Array(0);
    
    for(let j=0; j<num; j++){
        const tmp = board[num-j-1];
        for(let i=0; i<num; i++){
            if(tmp[i]==0) continue;
            arr[i].push(tmp[i]);
        }
    }
    
    const bkt = [];
    for(let i=0; i<moves.length; i++){
        const tmp = arr[moves[i]-1].pop();
        if(!tmp) continue;
        if(tmp==bkt[bkt.length-1]){
            bkt.pop(); 
            answer += 2;
        }
        else bkt.push(tmp);
    }
    
    return answer;
}