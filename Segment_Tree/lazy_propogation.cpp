#include <bits/stdc++.h>
using namespace std;

class SegmentTreeLazy {
private:
    vector<int> tree, lazy;
    int size;

    // Build the segment tree using the initial array values
    void build(vector<int>& a, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, 2*v, tl, tm);
            build(a, 2*v+1, tm+1, tr);
            tree[v] = tree[2*v] + tree[2*v+1];
        }
    }

    // Push lazy updates downward to child nodes
    void push(int v, int tl, int tr) {
        if (lazy[v] != 0) {
            // Apply the pending lazy update
            tree[v] += (tr - tl + 1) * lazy[v];

            // Propagate lazily if not a leaf node
            if (tl != tr) {
                lazy[2*v] += lazy[v];
                lazy[2*v+1] += lazy[v];
            }

            lazy[v] = 0;  // Clear the lazy value
        }
    }

    // Perform range addition updates
    void update(int v, int tl, int tr, int l, int r, int val) {
        push(v, tl, tr);  // Push pending updates
        if (l > r)
            return;
        if (l == tl && r == tr) {
            lazy[v] += val;  // Set lazy value
            push(v, tl, tr); // Apply immediately
        } else {
            int tm = (tl + tr) / 2;
            update(2*v, tl, tm, l, min(r, tm), val);
            update(2*v+1, tm+1, tr, max(l, tm+1), r, val);
            tree[v] = tree[2*v] + tree[2*v+1];  // Update node value
        }
    }

    // Range sum query
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        push(v, tl, tr);  // Ensure pending updates are applied
        if (l == tl && r == tr)
            return tree[v];
        int tm = (tl + tr) / 2;
        return query(2*v, tl, tm, l, min(r, tm))
             + query(2*v+1, tm+1, tr, max(l, tm+1), r);
    }

public:
    // Constructor initializing from given array
    SegmentTreeLazy(vector<int>& a) {
        size = a.size();
        tree.assign(4*size, 0);
        lazy.assign(4*size, 0);
        build(a, 1, 0, size - 1);
    }

    // Public method for range addition
    void range_add(int l, int r, int val) {
        update(1, 0, size - 1, l, r, val);
    }

    // Public method for range sum query
    int range_sum(int l, int r) {
        return query(1, 0, size - 1, l, r);
    }
};

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11};

    SegmentTreeLazy st(a);

    cout << "Initial array: [1, 3, 5, 7, 9, 11]\n";

    // Query initial sum [1,3]
    cout << "Sum [1,3]: " << st.range_sum(1, 3) << endl;  // 3+5+7 = 15

    // Add 10 to elements [1,4]
    st.range_add(1, 4, 10);
    cout << "Added 10 to range [1,4]\n";

    // Query again after update
    cout << "Sum [1,3] after update: " << st.range_sum(1, 3) << endl;  // (13+15+17)=45

    // Another range update
    st.range_add(2, 5, 5);
    cout << "Added 5 to range [2,5]\n";

    // Final queries
    cout << "Sum [0,5]: " << st.range_sum(0, 5) << endl;  // Full array sum
    cout << "Sum [3,5]: " << st.range_sum(3, 5) << endl;  // Partial range

    return 0;
}
