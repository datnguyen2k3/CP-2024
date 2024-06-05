<<<<<<< HEAD
# # matrix 2x2

# """
# 1 2
# 3 4

# + operation reverse 1 row
# + operation reverse 1 col

# matrix 2n x 2n -> Find max sum of sub matrix top-left n x n

# n = 10


# 1 5 4 9 3 1
# 3 2 7 8 6 7
# 2 9 6 4 9 7
# 5 1 2 1 1 4
# 1 2 3 4 5 6
# 3 2 5 1 9 1

# 9 + 5 + 8 + 9 = 31

# row, col -> row, 2*n - col - 1

# |
# v

# 2*n - row - 1, col -> 2*n - row - 1, 2*n - col - 1

# """

# def get_max_top_left_sub_matrix(matrix):
#     n = len(matrix) // 2
#     sub_matrix_sum = 0

#     for row in range(n):
#         for col in range(n):
#             max_value = max(
#                 matrix[row][col],
#                 matrix[2 * n - row - 1][col],
#                 matrix[row][2 * n - col - 1],
#                 matrix[2 * n - row - 1][2 * n - col - 1],
#             )

#             sub_matrix_sum + max_value

#     return sub_matrix_sum


# array [1, 11, 2, 9] sort-> [1, 2, 9, 11] -> max distance adj elements

# n = 1000
# 0 <= arr[i] <= 100

# arr[i] -> arr[i] += 1 -> find 2 adj element

# input array ->

# [1, 2, 11, 8, 9, 14, 13]


# [1, 2, 1, 4] -> power is start 0, if next element > max curr element -> power + 1
# n -> length
# m -> 1 <= element <= m
# t -> power == t

# n = 2, m = 3, t = 1 -> (1, 2), (2, 3) (1, 3)

# n**m
# n <= 50, t <= n, m <= 200

# ways[i][j][k] -> i is max element from 0 -> j while power is k
# ways[i][j][k] = sum(ways[0 -> i-1][j - 1][k - 1]) (case i is max)  + ways[i][j - 1][k] (i is equal previous max element) + 


def countSmaller(nums):
        
    enum = list(enumerate(nums))                              
    return mergeSort(enum, 0, len(nums) - 1)

def mergeSort(enum, start, end):
    if start >= end: 
        return 0
    
    res = 0
    mid = start + (end - start) // 2
    res += mergeSort(enum, start, mid)
    res += mergeSort(enum, mid + 1, end)
    return res + merge(enum, start, mid, end)

def merge(enum, start, mid, end):
    p, q = start, mid + 1
    inversion_count = 0                                     
    temp = []
    
    res = 0
        
    while p <= mid and q <= end:
        if enum[p][1] <= enum[q][1]:
            temp.append(enum[p])
            res += inversion_count              
            p += 1
        else:
            temp.append(enum[q])
            inversion_count += 1                           
            q += 1
        
    while p <= mid:
        temp.append(enum[p])
        res += inversion_count               
        p += 1
        
    while q <= end:         
        temp.append(enum[q])
        q += 1
        
    enum[start:end+1] = temp   
    return res

n = int(input())
nums = list(map(int, input().split()))

print(countSmaller(nums))
