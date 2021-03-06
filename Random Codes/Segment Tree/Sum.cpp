#include <bits/stdc++.h>

using namespace std;

// 1 indexed segment tree
struct SumSegTree
{
    vector < long long > tree, mainAr;
    int mainArSz, mxTreeIndx = 0; // size of the main arrray

    // function to print the tree level by level
    void printTree(){
        
        long long ln = 1, cnt = 1;
        // ln = for checking wether we have comepleted a level or not
        // cnt = for getting the number of nodes in next level

        cout << "Printing Segment Tree : \n";

        for(int i=1; i <= mxTreeIndx ; i++) {
            cout << tree[i] << " ";
            if(ln == i && i != mxTreeIndx){
                cout << endl;
                cnt *= 2;
                ln += cnt; 
            }
        }

        cout << endl; 
    }

    // claculates the value of "node" having range = [left,right]
    void init(int node, int left, int right){

        // saving the max Tree indx
        mxTreeIndx = max(mxTreeIndx, node);
        
        // base case of the recursion
        // when left and right child are same we are at the leaf
        if (left == right) {
            tree[node] = mainAr[left];
            return;
        }
        int leftChild = node * 2;
        int rightChild = node * 2 + 1;
        int midIndx = (left + right) / 2;
        init(leftChild, left, midIndx);
        init(rightChild, midIndx + 1, right);
        tree[node] = tree[leftChild] + tree[rightChild];
    }

    // constructor ~ takes the mother array and its size
    SumSegTree(long long ar[], int sz){

        mainArSz = sz; // initializing main array size

        // mainAr[0] = nothing as it starts from 1 index
        mainAr.assign(sz+2, 0);
        for(int j=0;j<sz;j++) mainAr[j+1]=ar[j];

        int size = 1;
        // calculation the upper closest two's power for ar[] size
        while(size < sz) size *= 2;

        // assigining the tree's nodes with 0
        tree.assign(3 * size, 0LL);
        // assuming tree size 3*n

        // creating the initial segment tree
        init(1, 1, sz);

    }

    void make_change(int node, int left, int right, int indx, int newvalue){

        // Case 1 : Out of range
        if (indx > right || indx < left)
            return;

        // Case 2 : left == right (Leaf node)
        if (left >= indx && right <= indx) {
            tree[node] = newvalue;
            return;
        }

        // Case 3: Need to breakout more
        int leftChild = node * 2;
        int rightChild = node * 2 + 1;
        int midIndx = (left + right) / 2;
        make_change(leftChild, left, midIndx, indx, newvalue);
        make_change(rightChild, midIndx + 1, right, indx, newvalue);

        tree[node] = tree[leftChild] + tree[rightChild];
    }

    // takes 1 based index and updates tree for ar[indx] = value
    void update(int indx, long long value){
        make_change(1, 1, mainArSz, indx, value);
        //printTree();
    }

    long long getsum(int node, int curLeft, int curRight, int reqLeft, int reqRight){

        // Case 1:  Out of bounds
        if (reqLeft > curRight || reqRight < curLeft)
            return 0;

        // Case 2: Fully in the range
        if (curLeft >= reqLeft && curRight <= reqRight)
            return tree[node];

        // Case 3: Need to breakout deeper
        int leftChild = node * 2;
        int rightChild = node * 2 + 1;
        int midIndx = (curLeft + curRight) / 2;

        long long leftSum = getsum(leftChild, curLeft, midIndx, reqLeft, reqRight);
        long long rightSum = getsum(rightChild, midIndx + 1, curRight, reqLeft, reqRight);

        return leftSum + rightSum;
    }

    long long sumQuery(int left, int right){
        return getsum(1, 1, mainArSz, left, right);
    }
};

int main()
{

    // n = size of the array
    // q = number of queries
    int n, q, Qtype;

    cin >> n >> q;
    long long ar[n];
    for(int i=0;i<n;i++) cin >> ar[i];

    // initiating the segment tree
    SumSegTree sTree(ar,n);
    sTree.printTree();

    // taking queries of two types
    while(q--){

        cin >> Qtype;

        if(Qtype == 1){
            // 1 i v (update query)
            // i = index of the element (indexed from 0)
            // v = value that will be replaced
            int i; long long v;
            cin >> i >> v;

            // it will update tree by ar[i] = v
            sTree.update(i+1, v); // making 1 based index
        }
        else if(Qtype == 2){
            // 2 l r (sum query)
            // l = start index (indexed from 0)
            // r = end index
            int l, r;
            cin >> l >> r;

            // it will return sum [l,r) ~ 0 indexed
            cout << sTree.sumQuery(l+1, r) << endl; // making 1 based index
        }
    }

    return 0;
}
