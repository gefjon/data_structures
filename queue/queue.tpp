namespace Queue {
  template< class T >
  bool Queue< T >::head_is_defined() {
    return (this->head_) ? true : false;
  }

  template< class T >
  bool Queue< T >::tail_is_defined() {
    return (this->tail_) ? true : false;
  }

  template< class T >
  void Queue< T >::assert_defined() {
    assert(this->head_is_defined());
    assert(this->tail_is_defined());
  }

  template< class T >
  Queue< T >::Queue() {};

  template< class T >
  Queue< T >::Queue(const Queue< T >& other) = default;

  template< class T >
  Queue< T >::~Queue() = default;

  template< class T >
  void Queue< T >::Enqueue(T to_enqueue) {
    auto node = std::make_shared< LinkedList::Node< T > >(std::move(to_enqueue));
    if (this->length_ == 0) {
      this->head_ = node;
      this->tail_ = node;
    } else {
      this->assert_defined();
      
      this->tail_->next_ = node;
      this->tail_ = node;
    }
    this->length_ += 1;
  }

  template< class T >
  T Queue< T >::Dequeue() {
    if (this->length_ == 0) {
      throw new UnderflowException();
    }

    this->assert_defined();
    
    this->length_ -= 1;
    auto new_head = this->head_->Cdr();
    T to_return = std::move(this->head_->Car());
    this->head_ = new_head;
    return to_return;
  }

  template< class T >
  T& Queue< T >::Peek() {
    if (this->length_ == 0) {
      throw new UnderflowException();
    }

    this->assert_defined();
    
    return this->head_->Car();
  }

  template< class T >
  unsigned int Queue< T >::Length() {
    return this->length_;
  }
}
