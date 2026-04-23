class MinHeap{
    constructor(){
        this.heap = [];
    }
    push(val){
        this.heap.push(val);
        this.bubbleUp();
    }
    bubbleUp(){
        let index = this.heap.length - 1;
        while(index > 0){
            const parentIndex = Math.floor((index - 1)/2);
            if(this.heap[parentIndex] <= this.heap[index]) break;
            [this.heap[parentIndex], this.heap[index]] = [this.heap[index], this.heap[parentIndex]];
            index = parentIndex;
        }
    }
    pop(){
        if(this.heap.length === 0) return null
        if(this.heap.length === 1) return this.heap.pop();
        const min = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown()
        return min;
    }
    bubbleDown(){
        const length = this.heap.length;
        let index = 0;
        while(true){
            let smallest = index;
            const left = index * 2 + 1;
            const right = index * 2 + 2;
            if(left<length && this.heap[left]<this.heap[smallest]) smallest = left;
            if(right<length && this.heap[right]<this.heap[smallest]) smallest = right;
            if(index===smallest) break;
            [this.heap[smallest], this.heap[index]] = [this.heap[index], this.heap[smallest]];
            index = smallest;
        }
    }
    peek(){
        return this.heap[0];
    }
    length(){
        return this.heap.length;
    }
}
function solution(scoville, K) {
    const heap = new MinHeap();
    scoville.forEach(s => heap.push(s));
    let mixCount = 0;
    while(heap.peek() < K){
        if(heap.length()<2) return -1;
        const first = heap.pop();
        const second = heap.pop();
        const mixed = first + (second * 2);
        heap.push(mixed);
        mixCount++;
    }
    return mixCount;
}