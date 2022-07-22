# SegmentTree-Library
This is a segment tree library which works for different data types and different operations on a vector for e.g. minimum, maximum in a given range or sum of values in a given range, etc.
In order to use this library in our C++ code, we must firstly include the segment tree library (i.e. #include segment tree library.h) in our file. We must specify the following things to work with the segment tree i.e."
-> data type
-> vector
-> value to be filled in the extra space of the tree.
-> operation function viz. minimum, maximum, sum, etc.
Below is an example on how to work with the library:
int large(int x, int y){ return max(x,y); }
segTree < int > MaxQuery( array, 0, large );

