import heapq

def solution(scoville, K):
    heap1 = scoville
    answer = 0
    heapq.heapify(heap1)
    
    while heap1[0] <= K and len(heap1)>=2:
        n1 = heapq.heappop(heap1)
        n2 = heapq.heappop(heap1)
        n3 = n1 + (n2 * 2)
        heapq.heappush(heap1 , n3)
        answer += 1
    
    if heap1[0] < K:
        return -1
    
    return answer