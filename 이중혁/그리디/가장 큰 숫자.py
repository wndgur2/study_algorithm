'''
    하나씩 제거해보고 그 중 최댓값을 구한다.
    위 과정을 k번 반복.
    O(k*n)
'''

def solution(number, k):
    answer = ''
    for i in range(k):
        nums = []
        for j in range(len(number)):
            nums.append(int(number[:j] + number[j-1:]))
        number = str(max(nums))
    
    return answer

