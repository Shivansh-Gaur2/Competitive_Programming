#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    int size;

    void build(vector<int> &a, int v, int tl, int tr)
    {
        if (tl == tr)
            tree[v] = a[tl];
        else
        {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    int sum(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return tree[v];
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, int new_val)
    {
        if (tl == tr)
            tree[v] = new_val;
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(2 * v, tl, tm, pos, new_val);
            else
                update(2 * v + 1, tm + 1, tr, pos, new_val);

            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

public:
    SegmentTree(vector<int> &a)
    {
        size = a.size();
        tree.resize(4 * size);
        build(a, 1, 0, size - 1);
    }

    int sum(int l, int r)
    {
        return sum(1, 0, size - 1, l, r);
    }

    void update(int pos, int new_val) { update(1, 0, size - 1, pos, new_val); }
};


int main(){
    vector<int> a = {1, 3, 5, 7, 9, 11};
    SegmentTree st(a);

    cout << "Sum of range [1, 3]: " << st.sum(1, 3) << endl;
    st.update(2, 6);
    cout << "Sum of range [1, 3] after update: " << st.sum(1, 3) << " " << endl;

    return 0;
}