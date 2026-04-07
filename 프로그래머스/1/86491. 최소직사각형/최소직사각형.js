function solution(sizes) {
  let max1 = 0,
    max2 = 0;
  for (const size of sizes) {
    size.sort((a, b) => b - a);
    if (size[0] > max1) max1 = size[0];
    if (size[1] > max2) max2 = size[1];
  }
  return max1 * max2;
}