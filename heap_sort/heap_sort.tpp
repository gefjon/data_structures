namespace HeapSort {
  template<
    class T,
    class I,
    BTREE_COMPARATOR(T, LT),
    BTREE_COMPARATOR(T, EQ)
    >
  std::vector< T > Sort(I begin, I end) {
    BinaryTree::BTree< T, LT, EQ > heap;

    for (I iter = begin; iter != end; iter++) {
      heap.Insert(*iter);
    }

    std::vector< T > sorted;
    while (heap) {
      sorted.push_back(heap.RemoveLeast());
    }

    return sorted;
  }

  template< class I >
  std::vector< int > IntDecreasing(I begin, I end) {
    return Sort< int, I, IntDecreasingCmp, IntEq >(begin, end);
  }

  template< class I >
  std::vector< int > IntIncreasing(I begin, I end) {
    return Sort< int, I, IntIncreasingCmp, IntEq >(begin, end);
  }
}
