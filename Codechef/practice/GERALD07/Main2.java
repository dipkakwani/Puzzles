import java.io.*;
import java.util.*;

/* Persistent Disjoint Set Union(DSU), which supports rollback to previous state
 * after a series of union operations are carried out. The main idea is to push
 * all the changes in a stack and to rollback by popping out from the stack, 
 * making necessary changes along the way. */
class DSU {
    int n, components;
    int[] parent, rank;
    class op {
    	boolean incRank;
    	int node, parent;
    	op(int n, int p, boolean inc) {
    		node = n;
    		parent = p;
    		incRank = inc;
    	}
    }
    Stack<op> history;

    DSU (int n) {
        this.n = n;
        parent = new int[n];
        rank = new int[n];
        history = new Stack<op>();
        components = n;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    
    int find(int i) {
        if (parent[i] == i)
            return i;
        return find(parent[i]);
    }

    void union(int i, int j) {
        int x = find(i);
        int y = find(j);
        if (x == y) {
        	history.push(null);
        }
        else {
        	//System.out.println("Union " + x + " " + y);
            components--;
            if (rank[x] > rank[y]) {
                parent[y] = x;
                history.push(new op(y, x, false));
            }
            else if (rank[x] < rank[y]) {
                parent[x] = y;
                history.push(new op(x, y, false));
            }
            else {
                rank[x]++;
                parent[y] = x;
                history.push(new op(y, x, true));
            }
        }
    }
    
    void rollback() {
        if (!history.isEmpty()) {
        	//System.out.println("Rolling back!");
        	op x = history.pop();
        	if (x == null)
        		return;
        	if (x.incRank)
        		rank[x.parent]--;
        	parent[x.node] = x.node;
        	components++;
        }
    }
    void reset() {
    	components = n;
    	history.removeAllElements();
    	for (int i = 0; i < n; i++) {
    		parent[i] = i;
    		rank[i] = 0;
    	}
    }
}

class Edge {
    int u, v;  
}

class Query {
    int start, end;
    int id;
}

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
        	int n = nextInt();
            int m = nextInt();
            int q = nextInt();
            Edge[] E = new Edge[m];
            Query[] Q = new Query[q];
            for (int i = 0; i < m; i++) {
            	E[i] = new Edge();
            	E[i].u = nextInt() - 1;
            	E[i].v = nextInt() - 1;
            }
            int sqrt;
            for (sqrt = 1; sqrt * sqrt <= m; sqrt++); 
            DSU dsu = new DSU(n);
            for (int i = 0; i < q; i++) {
            	Q[i] = new Query();
            	Q[i].start = nextInt() - 1;
            	Q[i].end = nextInt() - 1;
            	Q[i].id = i;
            }
            final int bucketSize = sqrt;
            /* Sqrt decomposition of the queries based on the total number of
             * edges. */
            Arrays.sort(Q, new Comparator<Query>() {
                public int compare(Query a, Query b) {
                    int idx1 = a.start/bucketSize, idx2 = b.start/bucketSize;
                    if (idx1 != idx2)
                    	return (idx1 < idx2) ? -1 : 1;
                    if (a.end != b.end)
                    	return (a.end < b.end) ? -1 : 1;
                    if (a.start != b.start)
                    	return (a.start < b.start) ? -1 : 1;
                    return 0;
                }
            });
            int[] res = new int[q];
            int curBucket = -1, r = -1;
            for (Query x : Q) {
            	//System.out.println("Query " + x.start + " " + x.end);
            	int bucket = x.start / bucketSize;
            	if (bucket != curBucket) {
            		dsu.reset();
            		r = bucketSize * (bucket + 1);
            		curBucket = bucket;
            	}
            	for (; r <= x.end; r++) {
            		dsu.union(E[r].u, E[r].v);
            	}
				int lastStart = Math.min(m - 1, bucketSize * (curBucket + 1) - 1);
				for (int i = x.start; i <= lastStart && i <= x.end; i++) {
					dsu.union(E[i].u, E[i].v);
				}

            	res[x.id] = dsu.components;
            	//System.out.println(res[x.id]);
            	
            	for (int i = x.start; i <= lastStart && i <= x.end; i++)
            		dsu.rollback();
            }
            for (int i = 0; i < q; i++)
            	System.out.println(res[i]);
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
