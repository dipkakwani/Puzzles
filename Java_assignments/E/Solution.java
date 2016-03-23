/* @author Diptanshu Kakwani */
import java.io.*;
import java.util.*;

/* To support fast traversal through the neighbouring vertices, an adjacency 
 * list implementation of graph would suffice. However, to support constant time
 * edge-existence query, we have to use hashing. Since the graph may contain
 * parallel edges, a multiset instead of a set, is required. So, a graph is
 * a list of multisets, where ith element represents ith vertex and it points
 * to a multiset which contains the neighbouring vertices and the count of 
 * number of edges between them. */

class MultiSet<T> {
    private HashMap<T, Integer> map;

    public MultiSet() {
        map = new HashMap<T, Integer>();
    }

    public Boolean contains(T i) {
        return map.containsKey(i);
    }

    public void add(T i) {
        if (contains(i)) 
            map.put(i, map.get(i) + 1);
        else
            map.put(i, 1);
    }

    public Set<T> keySet() {
        return map.keySet();
    }

    public int getCount(T i) {
        return map.get(i);
    }

    public int size() {
        return map.size();
    }
}

/* Represents an unweighted, undirected graph. */
class Graph {
    private ArrayList<MultiSet<Integer>> adjMultiSet;
    private int V;
    public int[] degree;

    public Graph(int V) {
        adjMultiSet = new ArrayList<MultiSet<Integer>>(V);
        for (int i = 0; i < V; i++)
            adjMultiSet.add(i, new MultiSet<Integer>());
        degree = new int[V];
        this.V = V;
    }
    
    public void addEdge(int u, int v) {
        adjMultiSet.get(u - 1).add(v - 1);
        adjMultiSet.get(v - 1).add(u - 1);
    }

    public void calculateDegrees() {
        for (int i = 0; i < V; i++) {
            degree[i] = adjMultiSet.get(i).size();
        }
    }

    public Boolean hasEdge(int u, int v) {
        return adjMultiSet.get(u - 1).contains(v - 1);
    }

    public int edgeCount(int u, int v) {
        return adjMultiSet.get(u - 1).getCount(v - 1);
    }

    public Set<Integer> adjVertices(int u) {
        return adjMultiSet.get(u - 1).keySet();
    }
}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        for (int t = 0; t < T; t++) {
            String tmp[] = br.readLine().split(" ");
            int V = Integer.parseInt(tmp[0]);
            int E = Integer.parseInt(tmp[1]);
            Graph g = new Graph(V);
            for (int i = 0; i < E; i++) {
                tmp = br.readLine().split(" ");
                int u = Integer.parseInt(tmp[0]);
                int v = Integer.parseInt(tmp[1]);
                g.addEdge(u, v);
            }
            g.calculateDegrees();
            long res = 0;
            for (int x = 1; x <= V; x++) {
                ArrayList<Integer> neighbours = new ArrayList<Integer>(g.adjVertices(x));
                for (int i = 0; i < neighbours.size(); i++){
                    Integer y = neighbours.get(i);
                    if (g.degree[y] < g.degree[x - 1] || (x - 1) == y ||
                        (g.degree[y] == g.degree[x - 1] && y < (x - 1)))
                        continue;
                    for (int j = i + 1; j < neighbours.size(); j++) {
                        Integer z = neighbours.get(j);
                        if (g.degree[z] < g.degree[x - 1] || (x - 1) == z ||
                            (g.degree[z] == g.degree[x - 1] && z < (x - 1)))
                            continue;
                        if (g.hasEdge(y + 1, z + 1)) {
                            res += g.edgeCount(x, y + 1) * 
                                   g.edgeCount(y + 1, z + 1) *
                                   g.edgeCount(x, z + 1);
                        }
                    }
                }
            }
            System.out.println(res);
        }
    }
}
