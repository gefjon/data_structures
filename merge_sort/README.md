# Merge sort

The merge sort algorithm, as I understand it, is sort of like a backwards
Quicksort:

1. split the collection into to unsorted collections
2. merge sort each subcollection individually
3. "merge" the two subcollections by repeatedly choosing the least item among
   them (which will always have the lowest remaining index, as they are sorted)

This is in contrast with Quicksort, does the comparing part first and the
sorting sublists later.

Unlike most of my code, I have opted not to go too far on templating heap
sort. It is generic over `class T` and `MERGE_SORT_COMPARATOR(T, name)`, where
`T` is the type of element to be sorted, but it always operates on a
`std::vector< T >&`, which it sorts in-place. This allows otherwise impossible
performance improvements which I have chosen not to make.
