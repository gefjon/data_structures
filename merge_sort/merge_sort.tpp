namespace MergeSort {
  template< class T >
  bool Lt(T const& left, T const& right) {
    return left < right;
  }

  template< class T, MERGE_SORT_COMPARATOR(T, LT) >
  void sort(std::vector< T >& arr) {
    if (arr.size() == 0) {
      return;
    }

    sort(arr, 0, arr.size() - 1);
  }

  template< class T, MERGE_SORT_COMPARATOR(T, LT) >
  void sort(
            std::vector< T >& arr,
            typename std::vector< T >::size_type low,
            typename std::vector< T >::size_type high
            ) {
    typedef typename std::vector< T >::size_type idx_t;
    if (high > low) {
      idx_t middle = (low + high
                      ) / 2;
      sort(arr, low, middle);
      sort(arr, middle + 1, high);
      merge(arr, low, middle, high);
    }
  }

  template< class T, MERGE_SORT_COMPARATOR(T, LT) >
  
  void merge(
              std::vector< T >& arr,
              typename std::vector< T >::size_type low,
              typename std::vector< T >::size_type middle,
              typename std::vector< T >::size_type high
             ) {
     typedef typename std::vector< T >::size_type idx_t;

     idx_t lower_size = middle - low + 1;
     idx_t higher_size = high - middle;
     
     std::vector< T > tmp_left;
     std::vector< T > tmp_right;

     tmp_left.reserve(lower_size);
     tmp_right.reserve(higher_size);

     for (idx_t i = low; i <= middle; i++) {
       tmp_left.push_back(std::move(arr.at(i)));
     }

     for (idx_t i = middle + 1; i <= high; i++) {
       tmp_right.push_back(std::move(arr.at(i)));
     }

     idx_t right_idx = 0;
     idx_t left_idx = 0;
     idx_t main_idx = low;

     while ((left_idx < lower_size) && (right_idx < higher_size)) {
       auto& left = tmp_left.at(left_idx);
       auto& right = tmp_right.at(right_idx);

       if (LT(left, right)) {
         arr.at(main_idx) = std::move(left);
         left_idx += 1;
       } else {
         arr.at(main_idx) = std::move(right);
         right_idx += 1;
       }
       main_idx += 1;
     }

     while (left_idx < lower_size) {
       arr.at(main_idx) = std::move(tmp_left.at(left_idx));
       main_idx += 1;
       left_idx += 1;
     }

     while (right_idx < higher_size) {
       arr.at(main_idx) = std::move(tmp_right.at(right_idx));
       main_idx += 1;
       right_idx += 1;
     }

     #ifndef NASSERT
     for (idx_t i = low; i < high; i++) {
       assert( LT(arr.at(i), arr.at(i + 1)) );
     }
     #endif
   }
}
