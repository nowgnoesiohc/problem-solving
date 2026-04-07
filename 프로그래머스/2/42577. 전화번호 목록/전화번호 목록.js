function solution(phone_book) {
  const map = new Map()
  for (const x of phone_book) {
    map.set(x, true)
  }
  for (const x of phone_book) {
    for (let i = 0; i < x.length; i++) {
      const tmp = x.slice(0, i);
      if(map.has(tmp)) return false;
    }
  }
  return true;
}