# Heap sort

The heap sort algorithm, considered one of the faster sorting algorithms,
involves constructing a binary heap (AKA a [binary tree](../binary_tree)) out of
the elements to be sorted and then repeatedly removing the least element from
that tree. Efficient implementations compete with Quicksort. This is not an
efficient implementation.

Easy improvements might be:

- not rewalking the entire tree in each call to `RemoveLeast`, as the removed
  elements will usually be near each other and will always be towards the
  bottom.
  
- pre-allocating space for the heap and for the sorted vector.

- building a heap of `T * const` or of `T const&` instead of a heap of `T`, to
  reduce copying.
  
Luckily, it is not my job to build the optimal heap sort, just a heap sort.
