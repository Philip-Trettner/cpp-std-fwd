# cpp-std-fwd

Forward declarations for most useful runtime classes of the C++ 17 standard library.

## Benchmarks

TL;DR: adding `#include <stdfwd.hh>` adds about 3 ms per translation unit.

| file | clang-6 | clang-7 | gcc-7 | gcc-8 |
| --- | ---: | ---: | ---: | ---: |
| empty | 12.6 ms | 13.9 ms | 5.5 ms | 5.5 ms |
| **`<stdfwd.hh>`** | **15.6 ms** | **17.2 ms** | **8.3 ms** | **7.7 ms** |
| `<type_traits>` | 22.5 ms | 24.5 ms | 13.9 ms | 12.7 ms |
| `<utility>` | 26.7 ms | 28.4 ms | 17.1 ms | 15.4 ms |
| `<string_view>` | 52.0 ms | 56.0 ms | 41.9 ms | 36.4 ms |
| `<vector>` | 56.7 ms | 61.3 ms | 46.5 ms | 40.8 ms |
| `<string>` | 105.7 ms | 113.1 ms | 95.8 ms | 85.3 ms |
| `<array>` | 108.5 ms | 116.3 ms | 99.3 ms | 88.6 ms |
| `<optional>` | 112.7 ms | 121.0 ms | 103.1 ms | 92.9 ms |
| `<map>` | 139.8 ms | 149.9 ms | 128.8 ms | 114.9 ms |
| `<memory>` | 140.1 ms | 149.2 ms | 130.3 ms | 115.4 ms |
| `<iostream>` | 150.0 ms | 158.7 ms | 145.1 ms | 127.4 ms |
| `<unordered_map>` | 155.0 ms | 162.9 ms | 141.1 ms | 131.5 ms |
| `<functional>` | 192.7 ms | 205.2 ms | 178.2 ms | 162.3 ms |
| `<regex>` | 310.4 ms | 326.0 ms | 308.6 ms | 268.4 ms |

Just compiling a single source including the specified file (`compiler -std=c++17 -O0 -c /tmp/file.cc -o /tmp/file.o`), best out of 10 compilations.

(system: intel i9-9900k 5 GHz, samsung 970 1TB pro nvme ssd, linux mint 19.1 tessa, kernel 4.15.0)

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

If the `CMakeLists.txt` is included, an interface library `std-fwd` is created:

```cmake
# if set, force-includes "stdfwd.hh" in every translation unit
# this is optional and low-cost (see benchmarks)
# set(STDFWD_FORCE_INCLUDE ON CACHE BOOL "" FORCE)

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

## Related Work

* https://blog.magnum.graphics/backstage/forward-declaring-stl-container-types/

## TODO

* add support for `libc++`
* make `msvc` benchmark
