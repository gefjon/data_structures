# Linked lists

This module exposes the template `LinkedList::Node< class T >`, a node in a
singly-linked list.

`Node< T >` is a `struct`, which means that all of its members are public. There
is no particularly good reason for this, and users should limit their access to
member data to using `Node< T >.Car()` and `Node< T >.Cdr()`, which return a
`T&` and a `std::shared_ptr< Node< T > >`, respectively.
