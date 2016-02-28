X = [[1, 1], [1, 0]]
mod = 10000000007

def matrix_mul(A, B):   
    return [[((A[i][0] * B[0][j]) % mod + (A[i][1] * B[1][j]) % mod) % mod for j in range(2)]\
            for i in range(2)]
    
def pow_matrix(A, n):
    if n <= 1:
        return A
    B = pow_matrix(A, n / 2)
    C = matrix_mul(B, B)        
    if n % 2:
        return matrix_mul(A, C)
    return C

t = input()
for _ in range(t):
    n, mod = [int(x) for x in raw_input().split(' ')]
    A = pow_matrix(X, n + 1)
    print (2 * (A[0][0] - 1) - (n % mod) + mod) % mod
