function solution(word) {
    const dictionary = new Set();
    const vowels = ['A', 'E', 'I', 'O', 'U'];
    function permutation(created) {
        if (created.length > 0) dictionary.add(created);
        for (let i = 0; i < 5; i++) {
            if (created.length < 5) permutation(created + vowels[i]);
        }
    }
    permutation('');
    const sortedDictionary = [...dictionary].sort();
    const location = sortedDictionary.findIndex((e) => e === word);
    return location + 1;
}