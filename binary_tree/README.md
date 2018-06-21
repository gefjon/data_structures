# Binary trees

This module exposes the template
`BinaryTree::BTree< class T, BTREE_COMPARATOR(T, LT), BTREE_COMPARATOR(T, EQ)>`, 
(along with the macro `BTREE_COMPARATOR(T, name)`, which expands to
`bool(*name)(T const&, T const&)`.

`BTree`'s interesting methods are
`std::shared_ptr< BTree::Node > Search(T const&)`, which finds a node with an
element `EQ` to the argument and returns a `shared_ptr` to it; `void Insert(T)`,
which adds its argument to the tree; and `T RemoveLeast()`, which removes and
returns the least element (the one for which `LT` will return `true` when it is
compared with any other element in the tree).

[The tests](test.cpp) include a sample for how `BTree` can be used in
conjunction with `std::tuple` to create a map.
