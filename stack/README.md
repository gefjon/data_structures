# Stacks

This module exposes the template `Stack::Stack< class T, size_t SIZE >`, a
simple single-type stack. `SIZE` is the maximum contents before an overflow, in
units of `T`.

`Stack< T >` exposes the methods `T& Push(T)`, `T& Peek()` and `T Pop()`. `Push`
returns a reference to the newly pushed value on the stack, `Peek` returns a
reference to the topmost value on the stack, and `Pop` removes the topmost value
from the stack and returns it. It also exposes the indexing methods `T&
operator[](typename Stack< T, SIZE >::index)` and `T& at(typename Stack< T, SIZE
>::index)`, for unchecked and checked indexing, respectively.

`typename Stack< T, SIZE >::index` is currently an alias for `std::size_t`.
