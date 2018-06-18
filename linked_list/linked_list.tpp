namespace LinkedList {
  template< class T >
  Node< T >::Node() {};

  template< class T >
  Node< T >::Node(const Node< T >& node) = default;

  template< class T >
  Node< T >::Node(T elem)
    : elem_(elem)
  {}

  template< class T >
  Node< T >::Node(T elem, std::shared_ptr< Node< T > > next)
    : elem_(elem)
    , next_(next)
  {}

  template< class T >
  Node< T >::~Node() = default;

  template< class T >
  Node< T >& Node< T >::operator=(const Node< T >& other) = default;

  template< class T >
  T& Node< T >::Car() {
    return this->elem_;
  }

  template< class T >
  std::shared_ptr< Node< T > >& Node< T >::Cdr() {
    return this->next_;
  }

  template< class T >
  Node< T > Node< T >::Prepend(T new_head) {
    auto shared_to_this = std::make_shared< Node< T > >(*this);
    return Node(std::move(new_head), std::move(shared_to_this));
  }
}
