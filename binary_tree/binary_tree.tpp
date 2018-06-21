namespace BinaryTree {
  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  BTree< T, LT, EQ >::Node::Node() {};

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  BTree< T, LT, EQ >::Node::Node(T elem)
    : elem_(elem)
  {}

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  BTree< T, LT, EQ >::Node::Node(
                            typename BTree< T, LT, EQ >::Node const& copy_from
                            ) = default;

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  BTree< T, LT, EQ >::Node::~Node() = default;

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  T& BTree< T, LT, EQ >::Node::Elem() {
    return this->elem_;
  }

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  std::shared_ptr< typename BTree< T, LT, EQ >::Node >&
  BTree< T, LT, EQ >::Node::Left() {
    return this->left_;
  }

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  std::shared_ptr< typename BTree< T, LT, EQ >::Node >&
  BTree< T, LT, EQ >::Node::Right() {
    return this->right_;
  }

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  bool BTree< T, LT, EQ >::Node::HasChild() {
    return this->Left() || this->Right();
  }

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  BTree< T, LT, EQ >::BTree() {};

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  BTree< T, LT, EQ >::~BTree() = default;

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  std::shared_ptr< typename BTree< T, LT, EQ >::Node >
  BTree< T, LT, EQ >::Search(T const& target)  {
    std::shared_ptr< BTree< T, LT, EQ >::Node > node = this->root_;
    while (node) {
      if (EQ(target, node->Elem())) {
        return node;
      } else if (LT(target, node->Elem())) {
        node = node->Left();
      } else {
        node = node->Right();
      }
    }
    throw new SearchFailureException();
  }

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  void BTree< T, LT, EQ >::Insert(T to_insert) {
    auto shared_to_ins = std::make_shared< BTree< T, LT, EQ >::Node >(std::move(to_insert));
    if (!this->root_) {
      this->root_ = std::move(shared_to_ins);
    } else {
      std::shared_ptr< BTree< T, LT, EQ >::Node > node = this->root_;
      while (node) {
        if (LT(to_insert, node->Elem())) {
          if (node->Left()) {
            node = node->Left();
          } else {
            node->Left() = std::move(shared_to_ins);
            return;
          }
        } else {
          if (node->Right()) {
            node = node->Right();
          } else {
            node->Right() = std::move(shared_to_ins);
            return;
          }
        }
      }
      assert( false );
    }
  }

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  T BTree< T, LT, EQ >::RemoveLeast() {
    if (!this->root_) {
      throw new EmptyBTreeException();
    }
    return this->RemoveLeast(this->root_);
  }

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  BTree< T, LT, EQ >::operator bool() const noexcept {
    return !!this->root_;
  }

  template< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ) >
  T BTree< T, LT, EQ >::RemoveLeast(std::shared_ptr< Node >& parent) {
    assert( !!parent );
    
    if (!parent->HasChild()) {
      auto copy = parent;
      parent = nullptr;
      return std::move(copy->Elem());
    } else if (parent->Left()) {
      return this->RemoveLeast(parent->Left());
    } else {
      auto copy = parent;
      auto right = parent->Right();
      parent = right;
      return std::move(copy->Elem());
    }
  }
}
