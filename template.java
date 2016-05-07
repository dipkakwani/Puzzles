import java.io.*;
import java.util.*;

public class Main {
    private static BufferedReader br;
    private static PrintWriter out;
    private static StringTokenizer st;

    public static void main(String[] args) throws IOException {
        InputStream input = System.in;
        OutputStream output = System.out;
        br = new BufferedReader(new InputStreamReader(input));
        out = new PrintWriter(output);
        int t = nextInt();
        while (t-- > 0) {

        }
        out.close();
    }

    /* Fast I/O template code */
    public static int nextInt() throws IOException {
        return Integer.parseInt(nextToken());
    }

    public static long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    public static String nextToken() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            if (line == null)
                return null;
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }
}
