# Searching

### 1. Linear Search

```cpp
int linear(Vi v, int target){
    for(int i=0; i<v.size(); i++){ // loop till the end of array
        if(v[i] == target) return i;
    }
    return -1;
}
```

### 2. Binary Search

Splits sorted array into 2 and picks one

```cpp
int binary(Vi &v, int target, int l, int r){ // called with (0, n-1)
    int mid = (l+r)/2;
    if(v[mid] == target) return mid; // element found
    if( l == r) return -1; // search is complete and element not found
    else if(v[mid] < target) return binary(v, target, mid+1, r); // target is greater than mid element, looking in right half
    else return binary(v, target, l, mid-1); // target is lesser than mid element, looking in left half
}
```

### 3. Ternary Search

Similar to binary search, splits array at 2 mids at 1/3 and 2/3.
Slower than binary search as it makes more comparisons per call
Time Complexity for Binary search = 2clog2n + O(1)
Time Complexity for Ternary search = 4clog3n + O(1)
It is clear that ternary makes more comparisons hence its slower.

```cpp
int ternary(Vi &v, int target, int l, int r){
    int n = v.size(), mid1 = l+((r-l)/3), mid2 = r-((r-l)/3);
    if(l > r){
        return -1; // element not found
    }
    if(target == v[mid1]) return mid1;
    else if(target == v[mid2]) return mid2;
    else if(target < v[mid1]) return ternary(v, target, l, mid1-1); // search in left part
    else if(target > v[mid2]) return ternary(v, target, mid2+1, r); // search in right part
    else return ternary(v, target, mid1+1, mid2-1); // search in mid part
}
```

### 4. Exponential Search

Find range where element is present using exponentiation, then Binary search the target in that range.
Time Complexity : O(Log n)
Auxiliary Space : The above implementation of Binary Search is recursive
and requires O(Log n) space.
With iterative Binary Search, we need only O(1) space.

```cpp
int exponential(Vi &v, int target, int l, int r){
    int i = 1, n = v.size();
    if(target < v[0] || target > v[n-1]) return -1; // target out of array range
    while(i<n && target >= v[i]) i<<=1; // find a right bound >= target
    return binary(v, target, i/2, min(i, n-1)); // now binary search in the obtained range
}
```

### 5. Jump Search

The basic idea is to check fewer elements (than linear search)
by jumping ahead by fixed steps or skipping some elements in place of searching all elements.
    Time Complexity : O(√n)
    Auxiliary Space : O(1)
The optimal size of a block to be jumped is (√n). This makes the time complexity of Jump Search O(√n).
The time complexity of Jump Search is between Linear Search ( ( O(n) ) and Binary Search ( O (Log n) ).
Binary Search is better than Jump Search, but Jump search has an advantage that we traverse back only
once (Binary Search may require up to O(Log n) jumps, consider a situation where the element to be
search is the smallest element or smaller than the smallest). So in a systems where jumping back is
costly, we use Jump Search.

```cpp
int jump(Vi &v, int target, int blockSize){
    int i;
    for(i=0; i<v.size(); i+=blockSize){ // choose block in which target exist
        if(v[i] == target) return i;
        if(v[i] > target) break;
    }
    for (int j = i-blockSize; j < i; j++) // linear search in the chosen block
    {
        if(j < 0) j = 0;
        if(v[j] == target) return j;
    }
    return -1;
}
```

### 6. Interpolation Search

The Interpolation Search is an improvement over Binary Search for instances,
where the values in a sorted array are uniformly distributed.
Binary Search always goes to the middle element to check. On the other hand,
interpolation search may go to different locations according to the value of
the key being searched. For example, if the value of the key is closer to the
last element, interpolation search is likely to start search toward the end side.

pos = low + [ (target-arr[low])*(high-low) / (arr[high]-arr[Low]) ]
when arr[high] == target :: pos = high

Time Complexity: If elements are uniformly distributed, then O (log log(n)). In worst case it can take upto O(n).
Auxiliary Space: O(1)

```cpp
int interpolation(Vi &v, int target, int l, int h){
    int pos = l + ((h-l) * (target - v[l]) / (v[h] - v[l])); // pos chosen on each iteration.
    if(pos < 0 || pos >= v.size()) return -1; // check if pos is lied in array range
    if(v[pos] == target) return pos; // target found
    else if(l == h) return -1; // target not found
    else if(v[pos] < target) return interpolation(v, target, pos+1, h); // target lies on right part
    else return interpolation(v, target, l, pos-1); // target lies on left part
}
```

### Comparison

Algorithm | Time | Space
--------- | ---- | -----
Linear Search | n | 1
Binary (recursive) | 2log(2n) | n
Binary | 2log(2n) | 1
Ternary | 4log(3n) | 1
Exponential | log(n) | 1
Interpolation | loglog(n), n | 1
Jump | √n | 1


# Sorting

### 1. Insertion Sort

Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there. It repeats until no input elements remain.
More efficient in practice than most other simple quadratic (i.e., O(n2)) algorithms such as selection sort or bubble sort
Insertion sort is one of the fastest algorithms for sorting very small arrays, even faster than quicksort; indeed, good quicksort implementations use insertion sort for arrays smaller than a certain threshold.
![insertion sort gif](https://upload.wikimedia.org/wikipedia/commons/4/42/Insertion_sort.gif)

```cpp
void insertion(Vi &v){
    int n = v.size();
    for (int i = 1; i < n; i++)
    {
        if(v[i-1] > v[i]){ // if an element is smaller than previous one
            for (int j = i; j > 0; j--)
            {
                if(v[j] < v[j-1]){
                    swap(v[j], v[j-1]); // swap it backwards till it reaches appropriate position.
                }
                else break;
            }
        }
    }
}
```

### 2. Selection Sort

Loop the array and each time find the minimum element and swap it with arr[pos] and incerement pos thereby growing the size of sorted array.

![selection gif](https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif)

```cpp
void selection(Vi &v){
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        int mn = n-1;
        for (int j = i+1; j < n; j++) // find minimum element
        {
            if(v[mn]>v[j]){
                mn = j;
            }
        }
        if(v[mn] < v[i]){
            swap(v[mn], v[i]); // swap i with minimum element
        }
    }
}
```

### 3. Bubble Sort

Repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.
Optimization: Operation could be stopped if inner loop didnt cause any swap, making best case complexity O(n).

![Bubble static](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)

```cpp
void bubble(Vi &v){
    for (int i = v.size()-1; i >= 0; i--) // expand sorted array from right to left
    {
        for (int j = 0; j < i; j++) // the largest number bubbles to the roof i
        {
            if(v[j] > v[j+1]){
                swap(v[j], v[j+1]);
            }
        }
    }
}
```

### 4. Bucket Sort

Bucket sort, or bin sort, is a sorting algorithm that works by distributing the elements of an array into a number of buckets. Each bucket is then sorted individually, either using a different sorting algorithm, or by recursively applying the bucket sorting algorithm. It is a distribution sort, a generalization of pigeonhole sort, and is a cousin of radix sort in the most-to-least significant digit flavor. Bucket sort can be implemented with comparisons and therefore can also be considered a comparison sort algorithm. The computational complexity depends on the algorithm used to sort each bucket, the number of buckets to use, and whether the input is uniformly distributed.

Bucket sort works as follows:
1. Set up an array of initially empty "buckets".
2. Scatter: Go over the original array, putting each object in its 3. bucket.
3. Sort each non-empty bucket.
4. Gather: Visit the buckets in order and put all elements back into the original array.

![Elements are distributed among bins](https://upload.wikimedia.org/wikipedia/commons/thumb/6/61/Bucket_sort_1.svg/311px-Bucket_sort_1.svg.png) ![Then, elements are sorted within each bin](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e3/Bucket_sort_2.svg/311px-Bucket_sort_2.svg.png) 

### 5. Merge Sort

Conceptually, a merge sort works as follows:
1. Divide the unsorted list into n sublists, each containing one element (a list of one element is considered sorted).
2. Repeatedly merge sublists to produce new sorted sublists until there is only one sublist remaining. This will be the sorted list.

![merge](https://upload.wikimedia.org/wikipedia/commons/thumb/c/cc/Merge-sort-example-300px.gif/220px-Merge-sort-example-300px.gif)

```cpp
void merge(Vi &v, int l, int r){ // splits array into 2 recursively and then merge them.
    if(l == r) return; // when no division is possible return.
    int mid = (l+r)/2; // divide at mid
    merge(v, l, mid);
    merge(v, mid+1, r);
    // inplace_merge(v.begin()+l, v.begin()+mid+1, v.begin()+r+1);
    merge(v, l, mid+1, r); // merges 2 sorted array
}
void merge(Vi &v, int l, int mid, int r) { // merges 2 sorted array using auxiliary space
    Vi u; // auxiliary array to store sorted array
    int i=l, j=mid;
    while(i<mid && j<=r) { // push the smaller values first
        if(v[i] <= v[j]) {
            u.push_back(v[i]);
            i++;
        }
        else {
            u.push_back(v[j]);
            j++;
        }
    }
    // now empty the remaining array
    while(i<mid) {
        u.push_back(v[i]);
            i++;
    }
    while(j <= r) {
        u.push_back(v[j]);
        j++;
    }
    for (int idx = l, idy=0; idx <= r; idx++, idy++) {
        v[idx] = u[idy]; // copy elements from auxiliary array to original array
    }
}
```

### 6. Quick Sort
When implemented well, it can be about two or three times faster than its main competitors, merge sort and heapsort.
Partition the array into 2 parts then recursively call on both subarrays.
Inplace but effecient implementations are not stable sort.
Partition Principle:
All elements [l,i) are strictly less than pivot
All elements [i,r] are greater than equal to pivot
Steps:
1. Keep i=l
2. start loop using j and (if A[j] < pivot swap A[j] with A[i] and advance i)
3. At the end of loop swap A[i] with A[r] cuz A[r] was the pivot used.

![quick](https://upload.wikimedia.org/wikipedia/commons/thumb/6/6a/Sorting_quicksort_anim.gif/220px-Sorting_quicksort_anim.gif) *Animated visualization of the quicksort algorithm. The horizontal lines are pivot values.*

```cpp
void quick(int l, int r) { // calls partition and then split the array into two.
  if(l>=r) return;
  int p = partition(l, r);
  quick(l, p-1);
  quick(p+1, r);
}
int partition(int l, int r) { // Lomuto partition
  int pivot = r; // last element is picked as pivot
  int i = l; // all elements smaller than pivot will go behind i
  for (int j = l+1; j+1 <= r; j++) // for every element in (l, r)
  {
    // if less than pivot then swap it with the ith element and increment i
    if(v[j] < v[pivot]) { 
      swap(v[j], v[i]);
      i++;
    }
  }
  swap(v[i], v[r]); // because pivot at r we need to swap the ith element with rth
  return i; // index of pivot
}
```

### 7. Heap Sort

Heapsort can be thought of as an improved selection sort: like selection sort, heapsort divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element from it and inserting it into the sorted region. Unlike selection sort, heapsort does not waste time with a linear-time scan of the unsorted region; rather, heap sort maintains the unsorted region in a heap data structure to more quickly find the largest element in each step.
Inplace but no stable
Algorithm:
1. Call the buildMaxHeap() function on the list. Also referred to as heapify(), this builds a heap from a list in O(n) operations.
2. Swap the first element of the list with the final element. Decrease the considered range of the list by one.
3. Call the siftDown() function on the list to sift the new first element to its appropriate index in the heap.
4. Go to step (2) unless the considered range of the list is one element.

![heap](https://upload.wikimedia.org/wikipedia/commons/1/1b/Sorting_heapsort_anim.gif) ![anim](https://upload.wikimedia.org/wikipedia/commons/4/4d/Heapsort-example.gif)
*A run of heapsort sorting an array of randomly permuted values. In the first stage of the algorithm the array elements are reordered to satisfy the heap property. Before the actual sorting takes place, the heap tree structure is shown briefly for illustration.*

### 8. Counting Sort

An algorithm for sorting a collection of objects according to keys that are small integers.
Algorithm:
For each element a[i] in array increment hash[a[i]].
For each element in hash with non zero value print the elements times their occurence.

### 9. Radix Sort

It avoids comparison by creating and distributing elements into buckets according to their radix. For elements with more than one significant digit, this bucketing process is repeated for each digit, while preserving the ordering of the prior step, until all digits have been considered. For this reason, radix sort has also been called bucket sort and digital sort.

Radix sort can be applied to data that can be sorted lexicographically, be they integers, words, punch cards, playing cards, or the mail. 

[GFG](https://www.geeksforgeeks.org/radix-sort/)

### Comparison


Things to leep in mind
1. Number of comparisons
2. Number of swaps
3. Auxiliary space used

Algorithm | Time (best) | Time (avg) | Time (worst) | Space (auxiliary) | Comment
--------- | ----------- | ---------- | ------------ | ----------------- | -------
Insertion Sort | n | n<sup>2</sup> | n<sup>2</sup> | 1
Selection Sort | n<sup>2</sup> | n<sup>2</sup> | n<sup>2</sup> | 1
Bubble Sort (opt) | n | n<sup>2</sup> | n<sup>2</sup> | 1
Bucket Sort | n<sup>2</sup>/k | n<sup>2</sup>/k | n<sup>2</sup> | nk | k = size of bucket
Merge Sort | n log n | n log n | n log n | n (array), 1 (linkedlist)
Quick Sort | n log n | n log n | n<sup>2</sup> | 1
Heap Sort | n log n | n log n | n log n | 1
Counting Sort | | | n+k | n+k | k is the range of the non-negative key values.
Radix Sort | n | | w.n | w+n | where w is the number of bits required to store each key.

# Order Statistics

The ith order statistic of a set of n elements is the ith smallest element. Together with rank statistics, order statistics are among the most fundamental tools in non-parametric statistics and inference.

1. **Quick Sort:** Selection in O(n log n)
Can be achieved by simple sorting and then picking the ith element.

2. **Randomized-Select:** Selection in Avg(n).
As in quicksort, we partition the input array
recursively. But unlike quicksort, which recursively processes both sides of the
partition, R ANDOMIZED -S ELECT works on only one side of the partition. This
difference shows up in the analysis: whereas quicksort has an expected running
time of (n lg n), the expected running time of RANDOMIZED SELECT is (n)
assuming that the elements are distinct.

3. **Randomized-Select optimized:** Selection in O(n).
Like RANDOMIZED SELECT , the algorithm SELECT finds the desired ele-
ment by recursively partitioning the input array. Here, however, we guarantee a
good split upon partitioning the array. SELECT uses the deterministic partitioning
algorithm PARTITION from quicksort, but modified to take the
element to partition around as an input parameter.

```cpp
// reusing the quick sort code and making modifications to follow one path when array is partitioned
int partition(int l, int r, Vi &v) {
  int pivot = r; // Lomuto
  // int pivot = rand() % (r-l+1)+l; // random
  int i = l;
  for (int j = l+1; j+1 <= r; j++)
  {
    if(v[j] < v[pivot]) {
      swap(v[j], v[i]);
      i++;
    }
  }
  swap(v[i], v[r]);
  return i;
}

int quick(int l, int r, int k, Vi &v) { // the kth order is passed in
  if(l==r) return v[l]; // when only 1 element is obtained it is the kth order number.
  int p = partition(l, r, v); // obtain pivot from partition
  if(k==p) return v[p]; // when the pivot index equals k, return element
  if(p > k) return quick(l, p-1, k, v); // pivot index greater than k, look on the left partition
  else return quick(p+1, r, k, v); // otherwise look on the right partition
}
```