def solution(triangle):
    results = [triangle[0][0]]
    for layer in triangle[1:]:
        temp = results
        results = []
        for t in range(len(temp)):
            results.append(temp[t] + layer[t])
            results.append(temp[t] + layer[t+1])
    return max(results)
print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]))