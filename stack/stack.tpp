namespace Stack {
  template< class T, size_t SIZE >
  Stack< T, SIZE >::Stack() {};

  template< class T, size_t SIZE >
  Stack< T, SIZE >::Stack(const Stack< T, SIZE >& stack) = default;

  template< class T, size_t SIZE >
  Stack< T, SIZE >::~Stack() = default;

  template< class T, size_t SIZE >
  std::size_t Stack< T, SIZE >::Size() {
    return this->backing_array_.size();
  }

  template< class T, size_t SIZE >
  typename Stack< T, SIZE >::index Stack< T, SIZE>::MaxSize() {
    return this->backing_array_.max_size();
  }

  template< class T, size_t SIZE >
  T& Stack< T, SIZE >::Push(T to_push) {
    auto idx = this->length_++;
    this->backing_array_.at(idx) = std::move(to_push);
    return this->backing_array_.at(idx);
  }

  template< class T, size_t SIZE >
  typename Stack< T, SIZE >::index Stack< T, SIZE >::Length() {
    return this->length_;
  }

  template< class T, size_t SIZE >
  typename Stack< T, SIZE >::index Stack< T, SIZE >::HighestLegalIndex() {
    return this->Length() - 1;
  }

  template< class T, size_t SIZE >
  T& Stack< T, SIZE >::Peek() {
    return this->backing_array_.at(this->HighestLegalIndex());
  }

  template< class T, size_t SIZE >
  T Stack< T, SIZE >::Pop() {
    return std::move(this->Peek());
  }

  template< class T, size_t SIZE >
  T& Stack< T, SIZE >::operator[](typename Stack< T, SIZE >::index idx) {
    return this->backing_array_[idx];
  }

  template< class T, size_t SIZE >
  T& Stack< T, SIZE >::at(typename Stack< T, SIZE >::index idx) {
    if (idx > this->HighestLegalIndex()) {
      throw new IndexOutOfRangeException(
                                         idx,
                                         this->HighestLegalIndex(),
                                         this->MaxSize()
                                         );
    }
    return this->backing_array_.at(idx);
  }
}
