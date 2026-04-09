function solution(triangle) {
    const tmp = triangle.length;
    const dp = Array.from({ length: tmp }, () => new Array(tmp).fill(0));
    dp[0][0] = triangle[0][0];
    for (let i = 1; i < triangle.length; i++) {
        for (let j = 0; j < triangle[i].length; j++) {
            dp[i][j] = triangle[i][j] + Math.max(dp[i - 1][j - 1] || 0, dp[i - 1][j] || 0);
        }
    }
    return dp[tmp - 1].reduce((max, element) => (max < element ? element : max), 0);
}