prices = [1, 2, 3, 2, 3]


def solution(prices):
    answer = []
    le = len(prices)
    result= 0
    for i in range(le):
        result += 1
        count = 0
        for j in range(result,le):
            count += 1 
            if prices[i] > prices[j]:
                break
        answer.append(count)
        

    return answer
