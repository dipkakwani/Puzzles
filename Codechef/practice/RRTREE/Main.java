import java.io.*;
import java.util.*;

class Tree {
    public int n;
    public int[] par, level;

    public Tree(int n) {
        this.n = n;
        par = new int [n];
        level = new int [n];
    }
}

class LCA {
    private int[][] dp;

    public LCA (Tree t) {
        dp = new int[t.n][18];
        for (int i = 0; i < t.n; i++) {
            for (int j = 0; (1 << j) < t.n; j++) {
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 0;
        t.level[0] = 0;
    }

    public void update(int i, Tree t) {
        dp[i][0] = t.par[i];
        for (int j = 1; (1 << j) < t.n; j++) {
            if (dp[i][j - 1] != -1)
                dp[i][j] = dp[dp[i][j - 1]][j - 1];
        }
        t.level[i] = t.level[t.par[i]] + 1;
    }

    public int distance(int u, int v, Tree t) {
        return t.level[u] + t.level[v] - (t.level[query(t, u, v)] << 1);
    }

    public int query(Tree t, int p, int q) {
        int tmp, log, i;
        if (t.level[p] < t.level[q]) {
            tmp = q;
            q = p;
            p = tmp;
        }
        for (log = 1; (1 << log) <= t.level[p]; log++);

        log--;
        for (i = log; i >= 0; i--) {
            if (t.level[p] - (1 << i) >= t.level[q]) {
                p = dp[p][i];
            }
        }

        if (p == q)
            return q;
        for (i = log; i >= 0; i--) {
            if (dp[p][i] != -1 && dp[p][i] != dp[q][i]) {
                p = dp[p][i];
                q = dp[q][i];
            }
        }
        return t.par[p];
    }
}

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int testCases = Integer.parseInt(br.readLine());
        for (int test = 0; test < testCases; test++) {
            int n = Integer.parseInt(br.readLine());
            Tree t = new Tree(n);
            LCA l = new LCA(t);
            int diameterStart = 0, diameterEnd = 0, diameter = 0;
            t.par[0] = 0;
            for (int i = 0; i < n - 1; i++) {
                int v = Integer.parseInt(br.readLine());
                t.par[i + 1] = v - 1;
                l.update(i + 1, t);
                int dist1 = l.distance(diameterStart, i + 1, t); 
                int dist2 = l.distance(diameterEnd, i + 1, t); 
                if (dist1 > diameter && dist1 >= dist2) {
                    diameterEnd = i + 1;
                    diameter++;
                }
                else if (dist2 > diameter) {
                    diameterStart = i + 1;
                    diameter++;
                }
                System.out.println(diameter);
            }
        }
    }
}
