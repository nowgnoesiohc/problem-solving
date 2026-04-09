function solution(brown, yellow) {
    for (let sero = 3; ; sero++) {
        const garo = brown / 2 - sero + 2;
        if ((sero - 2) * (garo - 2) === yellow) return [garo, sero];
    }
}