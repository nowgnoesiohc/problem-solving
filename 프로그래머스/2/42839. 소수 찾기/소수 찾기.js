function recur(i, numbers, result, make) {
    if (numbers.length === i) return;

    const tmp = numbers[i];
    make.add(Number(result + tmp));
    numbers[i] = -1;
    for (let ii = 0; ii < numbers.length; ii++) {
        if (i === ii || numbers[ii] === -1) continue;
        recur(ii, numbers, result + tmp, make);
    }
    numbers[i] = tmp;
    return;
}

function isPrime(number) {
    if (number < 2) return false;
    for (let i = 2; i * i <= number; i++) {
        if (number % i === 0) return false;
    }
    return true;
}

function solution(numbers) {
    const origin = numbers.split('');
    const make = new Set();
    let result = 0;
    for (let i = 0; i < numbers.length; i++) {
        recur(i, origin, '', make);
    }
    for (const x of make) {
        if (isPrime(x)) {
            result++;
            console.log(x);
        }
    }
    return result;
}