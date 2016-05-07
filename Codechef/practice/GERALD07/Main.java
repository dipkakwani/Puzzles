import java.io.*;
import java.util.*;


class Edge {
    Node u, v;
    int id;  
}

class Query {
    int start, end;
    int id;
}

class Node {
    int id, value, minValue;
    boolean flip;
    Node left, right, parent, minNode;
    Node() {
        id = 0;
        left = right = parent = minNode = null;
        value = minValue = 999999999;
    }

    boolean isRoot() {
        return (parent == null || (parent.left != this && parent.right != this));
    }

    void pushDown() {
        if (this == null)
            return;
        if (flip) {
            Node temp = left;
            left = right;
            right = temp;
            if (right != null)
                right.flip = !right.flip;
            if (left != null)
                left.flip = !left.flip;
            flip = false;
        }
    }

    void update() {
        minValue = value;
        if(left != null && left.minValue < value) 
            minValue = left.minValue;
        if(right != null && right.minValue < minValue) 
            minValue = right.minValue;
    }

}

class LinkCutTree {
    Node[] tree;
    int n;
    Edge[] E;

    void connect(Node par, Node ch, Boolean isLeftChild) {
        ch.parent = par;
        if (isLeftChild)
            par.left = ch;
        else
            par.right = ch;
    }
    void rotate(Node x) {
        Node par = x.parent;
        Node gPar = par.parent;
        boolean isRootPar = par.isRoot();
        boolean leftChildX = (x == par.left);
    
        if (gPar == null) {
            /* x becomes root of the tree. */
            x.parent = null;
        }
        else {
            /* x becomes direct child of its grand parent. */
            connect(gPar, x, par == gPar.left);
        }

        /* Now rotate x and its _previous_ parent. */
        if (x == par.left) {
            connect(par, x.right, true);
            connect(x, par, false);
        }
        else {
            connect(par, x.left, false);
            connect(x, par, true);
        }
        x.update();
    }

    /* Makes Node x as the root of its splay tree. */
    void splay(Node x) {
        while (!x.isRoot()) {
            Node par = x.parent;
            Node gPar = par.parent;

            if (gPar != null)
                gPar.pushDown();
            par.pushDown();
            x.pushDown();

            /* zig case */
            if (gPar == null) {
                rotate(par);
            }
            /* zig-zag case; par and x are both either left or right child. */
            else if ((par == gPar.left) == (x == par.left)) {
                rotate(par);
                rotate(x);
            }
            /* zig-zig case. */
            else {
                rotate(par);
                rotate(par);
            }
        }
        x.pushDown();
        x.update();
    }
    
    /* Makes Node x as the root of the virtual tree. */
    void expose(Node x) {
        Node prev = null;
        for (Node y = x; y != null; y = y.parent) {
            splay(y);
            y.right = prev;
            y.update();
            prev = y;
        }
        splay(x);
    }

    void makeRoot(Node x) {
        expose(x);
        x.flip = !x.flip;
    }

    void link(Node x, Node y) {
        makeRoot(x);
        x.parent = y;
    }

    void cut(Node x, Node y) {
        makeRoot(x);
        expose(x);
        splay(y);
        y.parent = null;
        //y.right.parent = null;
        //y.right = null;
    }

    public Node path(Node u, Node v) {
        makeRoot(u);
        expose(v);
        splay(v);
        return v;
    }

    public int addEdge(Edge e) {
        /* If both the nodes lie in the same component, delete the minimum weight
         * edge from the path u to v and insert the edge between u and v. */
        int removeId = 0;
        if (rootId(e.u) == rootId(e.v)) {
            removeId = path(e.u, e.v).minValue;
            cut(tree[n + removeId], tree[n + E[removeId].u.id]);
            cut(tree[n + removeId], tree[n + E[removeId].v.id]);
        }
        link(tree[n + e.id], tree[n + e.u.id]);
        link(tree[n + e.id], tree[n + e.v.id]);
        return removeId;
    }

    int rootId(Node x) {
        expose(x);
        while(x.right != null)
            x = x.right;
        splay(x);
        return x.id;
    }

    LinkCutTree(int n, int m) {
        tree = new Node[n << 1];
        E = new Edge[m + 1];
        this.n = n;
        for (int i = 0; i < n; i++) {
            tree[i] = new Node();
            tree[i].id = i;
        }
        for (int i = 0; i <= m; i++)
            E[i] = new Edge();
    }
}

/**/
class FenwickTree {
    int[] t;
    int n;
    FenwickTree(int n) {
        t = new int[n + 1];
        this.n = n + 1;
    }
    
    void adjust(int k, int value) {
        for (int i = k; i < n; i += (i & -i))
            t[i] += value;
    }

    int query(int x) {
        int res = 0;
        for (int i = x; i > 0; i -= (i & -i))
            res += t[i];
        return res;
    }

    int query(int l, int r) {
        return query(r) - query(l - 1);
    }

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
            LinkCutTree lct = new LinkCutTree(n, m);
            for (int i = 1; i <= m; i++) {
                int from = nextInt();
                int to = nextInt();
                lct.E[i].u = lct.tree[from - 1];
                lct.E[i].v = lct.tree[to - 1];
                lct.E[i].id = i;
            }
            Query[] Q = new Query[q + 1];
            Q[0] = new Query();
            for (int i = 1; i <= q; i++) {
                Q[i] = new Query();
                Q[i].start = nextInt();
                Q[i].end = nextInt();
                Q[i].id = i;
            }
            Arrays.sort(Q, new Comparator<Query>() {
                public int compare(Query a, Query b) {
                    return (a.end < b.end) ? 1 : 0;
                }
            });
            int[] ans = new int[q + 1];
            FenwickTree ft = new FenwickTree(n);
            for (int i = 1; i <= q; i++) {
                for (int j = Q[i - 1].end; j <= Q[i].end; j++) {
                    if (lct.E[j].u != lct.E[j].v) {
                        int removeId = lct.addEdge(lct.E[j]);
                        ft.adjust(m - removeId + 1, -1);
                        ft.adjust(m - i + 1, 1);
                    }
               }
               ans[Q[i].id] = n - ft.query(m, Q[i].start);   
            }
            for (int i = 1; i <= q; i++)
                out.println(ans[i]);
            
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

