import java.io.*;
import java.util.*;

/* Represents a 3x3 matrix. */
class Matrix {
    public long matrix[][];

    public Matrix() {
        matrix = new long[3][3];
    }

    public Matrix(long m[][]) {
        matrix = new long[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                matrix[i][j] = m[i][j];
            }
        }
    }

    /* Multiplies two 3x3 Matrix. */
    public Matrix multiply(Matrix A, Matrix B) {
        Matrix C = new Matrix();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    C.matrix[i][j] = (C.matrix[i][j] + A.matrix[i][k] * B.matrix[k][j]) % 1000000007L;
                }
            }
        }
        return C;
    }

    /* Fast exponentiation. */
    public Matrix power(Matrix A, long n) {   
        if (n == 1)
            return A;
        if ((n % 2) == 0) {
            Matrix B = power(A, n / 2);
            return multiply(B, B);
        }
        else
            return multiply(A, power(A, n - 1));
    }
}

public class Solution {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long t = Long.parseLong(br.readLine());
        for (long T = 0; T < t; T++) {
            long m[][] = {{1, 1, 1}, {1, 0, 0}, {0, 1, 0}};
            Matrix A = new Matrix(m);
            long n = Long.parseLong(br.readLine());
            if (n <= 3) {
                if (n <= 2)
                    System.out.println(1);
                else
                    System.out.println(2);
            }
            else {
                Matrix A_n = A.power(A, n - 3);
                System.out.println((2 * A_n.matrix[0][0] + A_n.matrix[0][1] + A_n.matrix[0][2]) % 1000000007L);
            }
        }
    }
}
