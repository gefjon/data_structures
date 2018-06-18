# Various data structures in C++

I'm starting at NYU in September, and I plan on testing out of their early
Computer Science courses. The only problem is that they require knowledge of
either C++ or Java, neither of which I have ever written. Their ["Intro to Data
Structures" placement test](https://cs.nyu.edu/home/undergrad/placement.html)
asks that students demonstrate knowledge and understanding of:

* [ ] recursion
* [x] [linked lists](linked_list)
* [x] [stacks](stack)
* [x] [queues](queue)
* [ ] binary trees
* [ ] merge sort

and specifies that "Students may use either C++ or Java to answer the
questions." As practice, I'm going down the list (skipping recursion, because
they're vague about what is required and because I learned to program in Scheme,
a language which uses recursion so extensively that it does not include loops)
and implementing each thing in C++. This is the first time I've ever written
C++, so don't expect perfect code, but I am doing my best to learn best
practices and use of the standard library (yes, I know that C++ has
`std::list`/`std::forward_list`, `std::stack`, `std::map`, `std::set`, and
`std::multiset`, and I'm sure some sorting utilities in `<algorithm>`; I mean
standard library components like `std::shared_ptr` and `<cstdint>`).

## Tests

I'm using [Catch2](https://github.com/catchorg/Catch2) for testing. Catch2 is
[included](catch.hpp) in the root.

To run tests, try `make` (the default target runs the tests).

## How modules are built

`sample_Makefile` is directly copied (it should be simlinked, but whatever) into
each module subdirectory. It assumes that:

* for a module `foo`, its subdirectory will be `/foo` and its code will be in
  `foo.cpp`, `foo.hpp` and `foo.tpp`.
  
* It contains a test file named `test.cpp` which defines `main`.

See any of the included modules for examples.

## My setup

I'm on macOS High Sierra (10.13.5 at the time of writing, but I do my best to
keep up to date). My compiler is `clang++`:

```
Apple LLVM version 10.0.0 (clang-1000.10.25.5)
Target: x86_64-apple-darwin17.6.0
Thread model: posix
```

and I use GNU Make 3.81.

## License

This code is licensed under the [MIT License](LICENSE).

[Catch2](https://github.com/catchorg/Catch2) is licensed under the [Boost
Standard License
1.0](https://github.com/catchorg/Catch2/blob/master/LICENSE.txt).
