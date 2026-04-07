function solution(clothes) {
    const map = new Map();
    for(const x of clothes){
        map.set(x[1], (map.get(x[1])||0)+1);
    }
    let result = 1;
    for(const [key, value] of map){
        result *= (value+1);
    }
    return result-1;
}