#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;

#define FOR(i, x, y) for(auto i = x; i < y; i++)
#define TESTCASE(T) cout << "Case #" << T << ": "
#define print(x) cout << x << endl
#define iterate(i, x) for (auto i = x.begin(); i != x.end(); i++)
#define max_ele(x) max_element(x.begin(), x.end())

class segmentTree
{
    vi arr, tree;
    int size;
    inline int left(int pos)
    {
        return (pos << 1) + 1;
    }
    inline int right(int pos)
    {
        return (pos << 1) + 2;
    }
    void buildTree(int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = l;
            return;
        }

        buildTree(left(node), l, (l + r) / 2);

        buildTree(right(node), (l + r) / 2 + 1, r);

        int leftChild = tree[left(node)], rightChild = tree[right(node)];
        tree[node] = (arr[leftChild] <= arr[rightChild])? leftChild : rightChild;
    }

    int rmq_query(int node, int l, int r, int i, int j)
    {
        cout << "Range  " << l << "  " << r << endl;
        if (i > r || j < l)      //Outside the range
            return -1;
        if (l >= i && r <= j)       //Inside the range
        {
            cout << "return  " << node << endl;
            return tree[node];
        }
        int leftChild = rmq_query(left(node), l, (l + r) / 2, i , j);
        int rightChild = rmq_query(right(node), (l + r) / 2 + 1, r, i , j);
        if (leftChild == -1)
            return rightChild;
        if (rightChild == -1)
            return leftChild;
        return (arr[leftChild] <= arr[rightChild])? leftChild : rightChild;
    }   
    
    /*
     * Updates the corresponding tree nodes which are affected by updating the array value.
     */
    void update_query(int node, int l, int r, int idx)
    {
        if (l == r)
        {
            tree[node] = l;
            return;
        }
        
        if (idx <= (l + r) / 2)         //Go to left subtree 
            buildTree(left(node), l, (l + r) / 2);
        else                //Go to right subtree
            buildTree(right(node), (l + r) / 2 + 1, r);

        int leftChild = tree[left(node)], rightChild = tree[right(node)];
        tree[node] = (arr[leftChild] <= arr[rightChild])? leftChild : rightChild;
    }
 public:

    segmentTree(vi& a)
    {
        arr = a;
        size = a.size();
        tree.assign(4 * size, 0);
        buildTree(0, 0, size - 1);
        iterate(i, tree)
            cout << *i << "  ";
        cout << endl;
    }
    int rmq(int i, int j)
    {
        return arr[rmq_query(0, 0, size - 1, i, j)];
    }
    void update(int idx, int newValue)
    {
        arr[idx] = newValue;       
        update_query(0, 0, size - 1, idx);
    }
    void array_iter()
    {
        iterate(i, arr)
            cout << *i << "  ";
        cout << endl;
    }
    void tree_iter()
    {
        iterate(i, tree)
            cout << *i << "  ";
        cout << endl;
    }
};
int main()
{
    int n;
    cin >> n;
    vi a(n);
    FOR(i, 0, n)
        cin >> a[i];
    segmentTree Tree(a);
    while (1)
    {
        cout <<"Update (idx, value)\n";
        int i, j;
        cin >> i >> j;
        if (!i && !j)
            break;
        Tree.update(i, j);
        Tree.array_iter();
        Tree.tree_iter();
    }
    return 0;
}

