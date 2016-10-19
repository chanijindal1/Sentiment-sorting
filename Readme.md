##Description:##

Counting sort algorithm is used for sorting a collection of objects according to keys that are small integers. 

Counting sort is efficient in this case as the range of input data is not significantly greater than the number of objects to be sorted.

Counting sort uses partial hashing to count the occurrence of data object in O(1).

n = Number of elements.
k = Range of inputs.

Time complexity: O(n+k) 
Auxiliary Space: O(n+k)

##Usage:##

Use "-a" option to give the space seperated input array.
Use "-n" option to select the first N numbers from the given input.

##Assumptions:##

1.Input array size < 100.
2.Range of numbers: (-5,5).

##Example:##

1.N = 5.

./a.out -n 5 -a " 1 -2 5 -5 4 -1 1 -3 4 2 2 5 -5 -2 1 1  3 "


Input:
1	-2	5	-5	4	
Output:
-5	5	4	-2	1	



2.If N is not specified then all the elements of the input array will be considered.

./a.out  -a " 1 -2 5 -5 4 -1 1 -3 4 2 2 5 -5 -2 1 1  3 "


Input:
1	-2	5	-5	4	-1	1	-3	4	2	2	5	-5	-2	1	1	
Output:
-5	-5	5	5	4	4	-3	-2	-2	2	2	-1	1	1	1	1	



