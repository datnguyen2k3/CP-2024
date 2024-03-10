def get_min_jumps(arr):
    min_jumps = [len(arr)] * len(arr)
    min_jumps[0] = 0
    
    for curr_index in range(len(arr) - 1):
        for jump in range(1, arr[curr_index] + 1):
            next_index = curr_index + jump
            if next_index < len(arr):
                min_jumps[next_index] = min(min_jumps[next_index], min_jumps[curr_index] + 1)
          
    return min_jumps[-1]

print(get_min_jumps([2, 3, 1, 1, 2, 4, 2, 0, 1, 1])) # 4