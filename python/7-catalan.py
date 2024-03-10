def get_catalan(n):
    catalan = [0] * (n + 1)
    catalan[0] = 1
    
    for i in range(1, n + 1):
        for j in range(i):
            catalan[i] += catalan[j] * catalan[i - j - 1]
            
    return catalan[n]

print(get_catalan(3)) # 5