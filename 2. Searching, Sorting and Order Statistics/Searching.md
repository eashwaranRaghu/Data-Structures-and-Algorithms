# Searching

### 1. Linear Search

Returns -1 when target not found otherwise index of the first occurence of the target element in array

```cpp
int linear(Vi v, int target){
    for(int i=0; i<v.size(); i++){ // loop till the end of array
        if(v[i] == target) return i;
    }
    return -1;
}
```

### 2. Binary Search

Splits sorted array into 2 and 

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

```cpp
int exponential(Vi &v, int target, int l, int r){
    int i = 1, n = v.size();
    if(target < v[0] || target > v[n-1]) return -1; // target out of array range
    while(i<n && target >= v[i]) i<<=1; // find a right bound >= target
    return binary(v, target, i/2, min(i, n-1)); // now binary search in the obtained range
}
```

### 5. Interpolation Search
```cpp
int interpolation(Vi &v, int target, int l, int h){
    int pos = l + ((h-l) * (target - v[l]) / (v[h] - v[l]));
    if(pos < 0 || pos >= v.size()) return -1;
    if( l == h){
        if(v[l] == target) return l;
        else return -1;
    }
    if(v[pos] == target) return pos;
    else if(v[pos] < target) return interpolation(v, target, pos+1, h);
    else return interpolation(v, target, l, pos-1); 
}
```

### 6. Jump Search
```cpp
int jump(Vi &v, int target, int blockSize){
    int i;
    for(i=0; i<v.size(); i+=blockSize){
        if(v[i] == target) return i;
        if(v[i] > target) break;
    }
    for (int j = i-blockSize; j < i; j++)
    {
        if(j < 0) j = 0;
        if(v[j] == target) return j;
    }
    return -1;
}
```

### 7. Fibonacci Search
```cpp

```
## Comparison
Algorithm | Time | Space | Comments
--------- | ---- | ----- | ---------
Linear Search | n | 1 |
Binary (recursive) | 2log(2n) | n | sorted array
Binary | 2log(2n) | 1 | sorted array
Ternary | 4log(3n) | 1 | sorted array
Exponential | log(n) | 1 | sorted array
Interpolation | loglog(n), n | 1 | sorted array, best case when elements are uniformly distributed
Jump | √n | 1 | sorted array
Fibonacci | | | sorted array
