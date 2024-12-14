def solution(answers):
    result = []
    
    s1 = [1, 2, 3, 4, 5]
    s2 = [2, 1, 2, 3, 2, 4, 2, 5]
    s3 = [3, 3, 1, 1, 2, 2, 4, 4 , 5, 5]
    
    s1_cnt = 0
    s2_cnt = 0
    s3_cnt = 0
    for i in range(len(answers)):
        if s1[i%len(s1)] == answers[i]:
            s1_cnt += 1
        if s2[i%len(s2)] == answers[i]:
            s2_cnt += 1
        if s3[i%len(s3)] == answers[i]:
            s3_cnt += 1
    
    cnt = [s1_cnt, s2_cnt, s3_cnt]
    for i in range(3):
        if cnt[i] == max(cnt):
            result.append(i+1)
    
    return result