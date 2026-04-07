function solution(genres, plays) {
  const result = [];
  const map1 = new Map();
  for (let i = 0; i < genres.length; i++) {
    map1.set(genres[i], (map1.get(genres[i]) || 0) + plays[i]);
  }
  const arr = [...map1].sort((a, b) => b[1] - a[1]);
  for (let i = 0; i < arr.length; i++) {
    let cnt = 0;
    let fst,
      fst_val = 0;
    let snd,
      snd_val = 0;
    for (let j = 0; j < genres.length; j++) {
      if (genres[j] == arr[i][0]) {
        if (plays[j] > fst_val) {
          snd = fst;
          snd_val = fst_val;
          fst = j;
          fst_val = plays[j];
        } else if (plays[j] > snd_val) {
          snd = j;
          snd_val = plays[j];
        }
      }
    }
    result.push(fst);
    if (snd_val) result.push(snd);
  }
  return result;
}
