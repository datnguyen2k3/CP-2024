def get_jump_ways(n):
    if n <= 2:
        return n
    
    first_prev = 1
    second_prev = 2
    
    for i in range(3, n + 1):
        current = first_prev + second_prev
        second_prev = first_prev
        first_prev = current
        
    return current

print(get_jump_ways(4)) # 4