def matrix_mult(A, B):
  C = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
  for i in range(3):
    for j in range(3):
      for k in range(3):
        C[i][k] = (C[i][k] + A[i][j] * B[j][k]) % 1000000007
  return C

def fast_exponentiation(A, n):
  if n == 1:
    return A
  else:
    if n % 2 == 0:
      A1 = fast_exponentiation(A, n/2)
      return matrix_mult(A1, A1)
    else:
      return matrix_mult(A, fast_exponentiation(A, n - 1))

def solve(n):
    A = [[1,1,1],[0,0,1],[0,1,0]]
    A_n = fast_exponentiation(A,n-3)
    return A_n[0][0] + A_n[0][1] + A_n[0][2]*2
# print solve(199073263955331)
# print solve(735920745626327)
# print solve(755385292636371)
#print solve(870655175447013)
# for i in range(10**5, 10**6):
#     print solve(i)
print solve(1000000000000)
print solve(1000000000001)
print solve(1000000000002)
