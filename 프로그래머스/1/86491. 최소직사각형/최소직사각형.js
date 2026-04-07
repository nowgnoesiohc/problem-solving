function solution(sizes) {
    let width = 0, height = 0;
    for (const [w, h] of sizes) {
        const [left, right] = w > h ? [w, h] : [h, w];

        width = Math.max(width, left);
        height = Math.max(height, right);
    }
    return width * height;
}