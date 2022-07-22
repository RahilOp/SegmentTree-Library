///author : kartik8800
#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H
#define left_child(i) (2*i + 1)
#define right_child(i) (2*i + 2)
#define parent(i) ((i-1)/2)
#include <vector>

template<class T>
class SegTree
{
    public:
        //Constructors to initialize the tree
        SegTree(std::vector<T> data, T value, T (*operate)(T obj1, T obj2));
        SegTree(T ar[], int n, T value, T (*operate)(T obj1, T obj2));

        //works for query (l,r) in O(log n) time complexity
        T query(int l, int r);
        //use to update the value at a given node
        void update(int idx, T val);
       
    private:
        //The actual segment tree which is to be constructed
        T *tree;
    
        //Function to build the segment tree
        void buildSegtree(std::vector<T> data);
        
        //The final size of the segment tree array because it must be a perfect power of 2.
        int TreeSize;
    
        //this is the value which we must add to the extra nodes of the tree to make the size perfect power of 2.
        T valueForExtraNodes;
    
        //specifies how to operate child node results to form parent node result, for e.g. add, min, max, gcd, etc.
        T (*operate)(T obj1, T obj2);
    
        //function which decides the size of the final tree.
        int findSize(int n);
    
        //function which solves a range query.
        T queryHelper(int l,int r, int st, int ed, int node);
};

template<class T> SegTree<T>::SegTree(std::vector<T> data,
                                                T value, T (*operate)(T obj1, T obj2))
{
   this->operate = operate;
   valueForExtraNodes = value = findSize(data.size());
   buildSegtree(data);
}

template<class T> SegTree<T>::SegTree(T ar[], int n,
                                            T value, T (*operate)(T obj1, T obj2))
{
   this->operate = operate;
   valueForExtraNodes = value = findSize(n);

   std::vector<T> data;
   for(int i = 0; i < n; i++)
         data.push_back(ar[i]);

   buildSegtree(data);
}


template<class T> int SegTree<T>::findSize(int n)
{
    int pow2 = 1;
    while( pow2 < n)
    {
        pow2 = pow2 << 1;
    }
    return 2*pow2 - 1;
}

template<class T> void SegTree<T>::buildSegtree(std::vector<T> data)
{
   int n = data.size();
   tree = new];
   int extraNodes /2 + 1) - n;
   for(int i - 1; i >= 0; i--)
   {
       if(extraNodes>0)
           {
               tree[i] = valueForExtraNodes;
               extraNodes--;
           }
       else if(n>0)
           {
               tree[i] = data[n-1];
               n--;
           }
       else
           tree[i] = operate(tree[left_child(i)], tree[right_child(i)]);
   }
}

template<class T> void SegTree<T>::update(int idx, T val)
{
    int segTreeIdx /2) + idx;
    tree[segTreeIdx] = val;
    while(parent(segTreeIdx) >= 0)
    {
        segTreeIdx = parent(segTreeIdx);
        if(right_child(segTreeIdx) )
          tree[segTreeIdx] = operate(tree[left_child(segTreeIdx)], tree[right_child(segTreeIdx)]);
        if(segTreeIdx == 0)
            break;
    }
}

template<class T> T SegTree<T>::query(int l, int r)
{
    int st = 0, ed/2;
    return queryHelper(l, r, st, ed, 0);
}

template<class T> T SegTree<T>::queryHelper(int l,int r, int st, int ed, int node)
{
    if( (r < st) || (l > ed) || (l > r) )
        return valueForExtraNodes;
    if(st >= l && ed <= r)
        return tree[node];
    int mid=(st+ed)/2;
    T left_childVal = queryHelper(l, r, st, mid, left_child(node));
    T right_childVal = queryHelper(l, r, mid+1, ed, right_child(node));
    return operate(left_childVal, right_childVal);
}


#endif // SEGMENTTREE_H