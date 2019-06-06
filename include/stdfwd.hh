#pragma once

// see https://stackoverflow.com/questions/31657499/how-to-detect-stdlib-libc-in-the-preprocessor
#include <ciso646>

#if defined(_LIBCPP_VERSION)
#define STDFWD_IS_LIBCPP
#elif defined(__GLIBCXX__)
#define STDFWD_IS_LIBSTDCPP
#else
#error "Unknown stdlib"
#endif

#if defined(STDFWD_IS_LIBSTDCPP)

#include <bits/memoryfwd.h> // allocator, uses_allocator

#include <bits/stringfwd.h> // char_traits, basic_string, string, wstring, u16string, u32string

namespace std _GLIBCXX_VISIBILITY(default)
{
    // <initializer_list>
    template <class _E>
    class initializer_list;

    _GLIBCXX_BEGIN_NAMESPACE_VERSION

    // <memory>
    template <typename _Tp>
    class shared_ptr;
    template <typename _Tp>
    struct default_delete;
    template <typename _Tp, typename _Dp>
    class unique_ptr;
    template <typename _Tp>
    class weak_ptr;

    // <functional>
    template <typename _Signature>
    class function;
    template <typename _Tp>
    struct hash;

    _GLIBCXX_BEGIN_NAMESPACE_CONTAINER

    // <vector>
    template <typename _Tp, typename _Alloc>
    class vector;

    _GLIBCXX_END_NAMESPACE_CONTAINER

    _GLIBCXX_END_NAMESPACE_VERSION

    _GLIBCXX_BEGIN_NAMESPACE_CONTAINER

    // <array>
    template <typename _Tp, std::size_t _Nm>
    struct array;

    _GLIBCXX_END_NAMESPACE_CONTAINER
} // namespace std_GLIBCXX_VISIBILITY(default)

namespace stdfwd
{
// <initializer_list>
using std::initializer_list;

// <memory>
using std::allocator;
using std::shared_ptr;
using std::uses_allocator;
using std::weak_ptr;
template <typename _Tp, typename _Dp = std::default_delete<_Tp>>
using unique_ptr = std::unique_ptr<_Tp, _Dp>;

// <functional>
using std::function;
using std::hash;

// <string>
template <typename Char, typename Traits = std::char_traits<Char>, typename Allocator = std::allocator<Char>>
using basic_string = std::basic_string<Char, Traits, Allocator>;
using std::string;
using std::u16string;
using std::u32string;
using std::wstring;

// <vector>
template <typename _Tp, typename _Alloc = std::allocator<_Tp>>
using vector = std::vector<_Tp, _Alloc>;

// <array>
using std::array;
}

#else

#error "not implemented"

#endif
