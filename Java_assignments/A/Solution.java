import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for (int T = 0; T < t; T++) {
            int n = s.nextInt();
            int sum = 0;
            for (int i = 0; i < n; i++) {
                int a = s.nextInt();
                if ((a % 2) != 0)
                    sum += a;
            }
            System.out.println(sum);
        }
    }
}
