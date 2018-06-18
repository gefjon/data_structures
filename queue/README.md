# Queues

This module exposes the template `Queue::Queue< class T >`, a FIFO
queue. `Queue< T >` is backed by a [linked list](../linked_list), though it does
its best not to expose that in its public interface.

It exposes the methods `void Enqueue(T)`, `T Dequeue()`, `T& Peek()` and
`unsigned int Length()`. Indexing operations are not exposed, as indexing into a
linked list is O(n).
