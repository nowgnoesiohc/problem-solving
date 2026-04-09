function solution(bridge_length, weight, truck_weights) {
    const ing = [{ w: truck_weights[0], t: 1 }];
    let ingsum = truck_weights[0],
        next = 1,
        time;
    for (time = 1; ; time++) {
        if (time - ing[0].t >= bridge_length) {
            const tmp = ing.shift();
            ingsum -= tmp.w;
        }
        if (weight >= ingsum + truck_weights[next] && bridge_length >= ing.length + 1) {
            ingsum += truck_weights[next];
            ing.push({ w: truck_weights[next], t: time });
            next++;
        }
        // console.log(time, ing, truck_weights[next], ingsum);
        if (truck_weights.length <= next && ingsum === 0) break;
    }
    return time;
}