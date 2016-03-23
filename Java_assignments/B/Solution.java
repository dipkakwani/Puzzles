import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String args[] ) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int i = 0; i < t; i++) {
            int n = Integer.parseInt(br.readLine());
            SortedSet<String> namesSet = new TreeSet<String>();
            for (int j = 0; j < n; j++) {
                namesSet.add(br.readLine());
            }
            for (String name : namesSet) {
                System.out.println(name);
            }
        }
    }
}
