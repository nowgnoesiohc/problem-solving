def solution(brown, yellow):
    answer = []
    
    for x in range(brown):
        for y in range(brown):
            if brown == 2 * ((x-1) + (y-1)) and yellow == (x-2) * (y-2):
                if x>=y : 
                    answer = [x, y]
            
    return answer