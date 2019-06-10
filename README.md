# cpp-std-fwd

Forward declarations for most useful runtime classes of the C++ 17 standard library.

## Benchmarks

TODO

## Usage

Use forward declarations where possible in the header:

```cpp
#include <stdfwd.hh>

stdfwd::string get_string();
stdfwd::vector<int> get_vector();
stdfwd::deque<int> get_deque();
stdfwd::list<int> get_list();
stdfwd::stack<int> get_stack();
stdfwd::forward_list<int> get_forward_list();
stdfwd::shared_ptr<int> get_shared_ptr();
stdfwd::unique_ptr<int> get_unique_ptr();
stdfwd::array<int, 3> get_array();
stdfwd::function<int()> get_function();
stdfwd::bitset<3> get_bitset();
stdfwd::pair<int, int> get_pair();
stdfwd::map<int, int> get_map();
stdfwd::set<int> get_set();
stdfwd::unordered_map<int, int> get_unordered_map();
stdfwd::unordered_set<int> get_unordered_set();
...
```

And in the `.cc` just `#include <header>` and define the functions using the normal `std` type (all declarations inside `stdfwd` are typedefs into `std`).

`std::` forward declarations can also be used but won't have default template arguments (e.g. `std::vector<int>` does not work and `std::vector<int, std::allocator<int>>` or `stdfwd::vector<int>` must be used).

Adding support for `map` and `unordered_map` for custom data types:

```cpp
#include <stdfwd.hh>

struct foo
{
    int v;

    bool operator==(foo const& r) const { return v == r.v; }
};

template <>
struct std::hash<foo>
{
    size_t operator()(foo const& f) const noexcept { return f.v; }
};

template <>
struct std::less<foo>
{
    bool operator()(foo const& a, foo const& b) const noexcept { return a.v < b.v; }
};
```

## CMake

If not the top-level `CMakeLists.txt`, this project adds as an interface library and can be used with:

```cmake
# if set, force-includes "stdfwd.hh" in every translation unit
# this is optional and low-cost (see benchmarks)
# set(STDFWD_FORCE_INCLUDE ON CACHE BOOL " " FORCE)

add_subdirectory(path/to/cpp-std-fwd)

target_link_libraries(${PROJECT_NAME} PUBLIC std-fwd)
```

## FAQ

* Why?

  Each non-trivial `std` header adds 50-200 ms compile time just by including them. 
  `#include <stdfwd.hh>` is virtually free.

* Isn't adding declarations to `std` undefined behavior?

  Yes. 
  This project is meant as a proof-of-concept for a proposal to standardize a forward declaration header for `std`.

* Why the namespace `stdfwd`?

  Some classes like `std::vector` have default template arguments which must only appear on a declaration once.
  If they appear on the definition then they cannot appear on the forward declaration.
  Thus, all forward declarations in `std` are without default arguments and `stdfwd` adds typedefs with the appropriate defaults.

* Why are some classes like `std::integer_sequence` missing?

  I omitted classes that are intended for compile-time programming because there seems to be little reason to forward declare them.

* What are the use cases?

  Many functions defined in a header but implemented elsewhere don't require complete definitions of their arguments or return types.
  `std::vector<int> foo();` can be defined without including `<vector>` given forward declarations.

  Furthermore, many data types might want to specialize `std::less` or `std::hash` so that their users can use them inside `std::map` or `std::unordered_map`.
  Currently this requires including `<functional>` (one of the most expensive `std` headers to include) even if the data type itself uses nothing from that header.
  With a forward declaration, `less` and `hash` can be specialized without including the full header.

* Won't this be obsolete with modules?

  Yes and no.
  In C++20, `std` itself is not yet modularized.
  Additionally, it is not clear if all code bases can be immediately migrated to modules.
  This `std` forward header is a small and easy-to-implement non-intrusive change with big payoffs for many code bases.

* Why is `iosfwd` not used internally?

  This header should be as fast as possible.
  `iosfwd` includes more than forward declaration.
  It also fully defines the `postypes` at least in libstdc++.

## TODO

* make versions `libc++`
* add benchmarks