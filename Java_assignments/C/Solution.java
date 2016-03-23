import java.io.*;
import java.util.*;

/* Represents a request with start and finish time. */
class Pair<L, R> {
    public L start;
    public R finish;

    public Pair (L start, R finish) {
        this.start = start;
        this.finish = finish;
    }
}

/* Compare pair with their finish times. */
class ComparePairs implements Comparator<Pair<Integer, Integer>> {
    @Override
    public int compare(Pair<Integer, Integer> p1, Pair<Integer, Integer> p2) {
        return p1.finish.compareTo(p2.finish);
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int T = 0; T < t; T++) {
            int n = Integer.parseInt(br.readLine());
            ArrayList<Pair<Integer, Integer>> requests = new ArrayList<Pair<Integer, Integer>>(n);
            for (int i = 0; i < n; i++) {
                String temp[] = br.readLine().split(" ");
        		int a = Integer.parseInt(temp[0]);
        		int b = Integer.parseInt(temp[1]);
                requests.add(new Pair<Integer, Integer>(a, b));
            }
            /* Sort requests based on their finishing time. */
            Collections.sort(requests, new ComparePairs());
            Pair<Integer, Integer> prev = new Pair<Integer, Integer>(-1, -1);
            int ans = 0;
            for (Pair<Integer, Integer> p : requests) {
                /* If the current request doesn't overlap with the previously
                 * selected request, then greedily grant the current request too. */
                if (p.start >= prev.finish) {
                    ans++;
                    prev = p;
                }
            }
            System.out.println(ans);
        }
    }
}

