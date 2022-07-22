# SegmentTree-Library
This is a segment tree library which works for different data types and different operations on a vector for e.g. minimum, maximum in a given range or sum of values in a given range, etc.
<br/>
In order to use this library in our C++ code, we must firstly include the segment tree library (i.e. #include segment tree library.h) in our file. We must specify the following things to work with the segment tree i.e."
<br/>
-> data type
<br/>
-> vector
<br/>
-> value to be filled in the extra space of the tree.
<br/>
-> operation function viz. minimum, maximum, sum, etc.
<br/>
Below is an example on how to work with the library:
<br/>
int large(int x, int y){ return max(x,y); }
<br/>
segTree < int > MaxQuery( array, 0, large );
<br/>

