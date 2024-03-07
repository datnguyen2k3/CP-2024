def find_fib(n):
    if n <= 1:
        return n

    first_prev = 1
    second_prev = 0
    curr = 0
    for i in range(2, n + 1):
        curr = first_prev + second_prev
        second_prev = first_prev
        first_prev = curr
        
    return curr

print(find_fib(10)) # 55