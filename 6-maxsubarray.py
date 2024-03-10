def get_max_subarray(arr):
    max_sum = float('-inf')
    curr_sum = 0
    
    for num in arr:
        curr_sum += num
        max_sum = max(max_sum, curr_sum)
        if curr_sum < 0:
            curr_sum = 0
            
    return max_sum

print(get_max_subarray([-2, 1, -3, 4, -1, 2, 1, -5, 4])) # 6
    