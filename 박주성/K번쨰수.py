def solution(array, commands):
    answer = []
    ar = array 
    
    for i in commands:
        test = []
        for a in range(i[0]-1,i[1]):
            test.append(array[a])
        test.sort()
        answer.append(test[i[2]-1])
        print(answer)
        
    
    
    return answer