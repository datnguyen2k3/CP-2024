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
