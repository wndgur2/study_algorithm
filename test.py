def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge_truck= []
    truck_wait_time=[]
    dd=[]
    
    while 1:
        
        answer += 1
        bridge_truck.append(truck_weights[0])
        
        
        if sum(bridge_truck) <= weight:
            truck_wait_time.append(bridge_length)
            truck_weights.pop(0)
        else:
            bridge_truck.pop()
            
        q=[-1]*len(truck_wait_time)
        truck_wait_time= [x + y for x, y in zip(truck_wait_time,q)]
        
        if truck_wait_time[0] == 0:
            truck_wait_time.pop(0)
            bridge_truck.pop(0)
            
        if len(truck_weights) == 0:
            break 
        
            
    return answer + bridge_length
            