function solution(numbers) {
    const nums = numbers.map((a) => a.toString());
    console.log(nums);
    const sortedNumbers = nums.sort((a, b) =>
        a[0] !== b[0] ? b[0] - a[0] : Number(b + a) - Number(a + b)
    );
    if (sortedNumbers[0] === '0') return '0';
    console.log(sortedNumbers);
    return sortedNumbers.join('').toString();
}