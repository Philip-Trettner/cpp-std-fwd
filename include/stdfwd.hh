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

/*
 * TODO: (secondary)
 *   <chrono>
 *   <random>
 *   <ratio>
 *   <regex>
 *   <atomic>
 *   <thread>
 *   <mutex>
 *   <shared_mutex>
 *   <future>
 *   <condition_variable>
 *
 * ??
 *  <scoped_allocator>
 *  <memory_resource>
 *  <exception>
 *  <stdexcept>
 *  <iterator>
 *  <locale>
 *
 *  <valarray> slices?
 *  <filesystem> more types?
 */

#include <iosfwd> // all of input/output

#if defined(STDFWD_IS_LIBSTDCPP)

#include <bits/memoryfwd.h> // allocator, uses_allocator

#include <bits/stringfwd.h> // char_traits, basic_string, string, wstring, u16string, u32string

// TODO: without the inline a number of warnings is generated
#define _GLIBCXX_BEGIN_NAMESPACE_CXX11_INLINE inline _GLIBCXX_BEGIN_NAMESPACE_CXX11

namespace std _GLIBCXX_VISIBILITY(default)
{
    // <initializer_list>
    template <class _E>
    class initializer_list;

    _GLIBCXX_BEGIN_NAMESPACE_VERSION

    // <utility>
    template <typename _T1, typename _T2>
    struct pair;

    // <tuple>
    template <typename... _Elements>
    class tuple;

    // <any>
    class any;

    // <optional>
    template <typename _Tp>
    class optional;
    struct nullopt_t;

    // <variant>
    template <typename... _Types>
    class variant;
    struct monostate;

    // <complex>
    template <typename _Tp>
    struct complex;

    // <valarray>
    template <class _Tp>
    class valarray;

    // <string_view>
    template <typename _CharT, typename _Traits>
    class basic_string_view;
    using string_view = basic_string_view<char, std::char_traits<char>>;
    using wstring_view = basic_string_view<wchar_t, std::char_traits<wchar_t>>;
    using u16string_view = basic_string_view<char16_t, std::char_traits<char16_t>>;
    using u32string_view = basic_string_view<char32_t, std::char_traits<char32_t>>;

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
    template <typename _Tp>
    struct equal_to;
    template <typename _Tp>
    struct not_equal_to;
    template <typename _Tp>
    struct greater;
    template <typename _Tp>
    struct less;
    template <typename _Tp>
    struct greater_equal;
    template <typename _Tp>
    struct less_equal;

    // <stack> - not in container for some reason
    template <typename _Tp, typename _Sequence>
    class stack;

    // <queue> - not in container for some reason
    template <typename _Tp, typename _Sequence>
    class queue;
    template <typename _Tp, typename _Sequence, typename _Compare>
    class priority_queue;

    _GLIBCXX_BEGIN_NAMESPACE_CONTAINER

    // <vector>
    template <typename _Tp, typename _Alloc>
    class vector;

    // <deque>
    template <typename _Tp, typename _Alloc>
    class deque;

    _GLIBCXX_BEGIN_NAMESPACE_CXX11_INLINE

    // <list>
    template <typename _Tp, typename _Alloc>
    class list;

    _GLIBCXX_END_NAMESPACE_CXX11

    // <forward_list>
    template <typename _Tp, typename _Alloc>
    class forward_list;

    // <map>
    template <typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    class map;
    template <typename _Key, typename _Tp, typename _Compare, typename _Alloc>
    class multimap;

    // <set>
    template <typename _Key, typename _Compare, typename _Alloc>
    class set;
    template <typename _Key, typename _Compare, typename _Alloc>
    class multiset;

    // <unordered_map>
    template <typename _Key, typename _Tp, typename _Hash, typename _Pred, typename _Alloc>
    class unordered_map;
    template <typename _Key, typename _Tp, typename _Hash, typename _Pred, typename _Alloc>
    class unordered_multimap;

    // <unordered_set>
    template <typename _Value, typename _Hash, typename _Pred, typename _Alloc>
    class unordered_set;
    template <typename _Value, typename _Hash, typename _Pred, typename _Alloc>
    class unordered_multiset;

    _GLIBCXX_END_NAMESPACE_CONTAINER

    namespace filesystem
    {
    _GLIBCXX_BEGIN_NAMESPACE_CXX11_INLINE

    // <filesystem>
    class path;

    _GLIBCXX_END_NAMESPACE_CXX11
    }

    _GLIBCXX_END_NAMESPACE_VERSION

    _GLIBCXX_BEGIN_NAMESPACE_CONTAINER

    // <bitset>
    template <size_t _Nb>
    class bitset;

    // <array>
    template <typename _Tp, std::size_t _Nm>
    struct array;

    _GLIBCXX_END_NAMESPACE_CONTAINER
} // namespace std_GLIBCXX_VISIBILITY(default)

#else

#error "not implemented"

#endif

// dedicated forward declaration namespace
// (provides proper default template arguments)
namespace stdfwd
{
// <initializer_list>
using std::initializer_list;

// <utility>
using std::pair;

// <tuple>
using std::tuple;

// <any>
using std::any;

// <optional>
using std::nullopt_t;
using std::optional;

// <variant>
using std::monostate;
using std::variant;

// <complex>
using std::complex;

// <valarray>
using std::valarray;

// <string_view>
template <typename _CharT, typename _Traits = std::char_traits<_CharT>>
using basic_string_view = std::basic_string_view<_CharT, _Traits>;
using std::string_view;
using std::u16string_view;
using std::u32string_view;
using std::wstring_view;

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
template <typename _Tp = void>
using equal_to = std::equal_to<_Tp>;
template <typename _Tp = void>
using not_equal_to = std::not_equal_to<_Tp>;
template <typename _Tp = void>
using greater = std::greater<_Tp>;
template <typename _Tp = void>
using less = std::less<_Tp>;
template <typename _Tp = void>
using greater_equal = std::greater_equal<_Tp>;
template <typename _Tp = void>
using less_equal = std::less_equal<_Tp>;

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

// <deque>
template <typename _Tp, typename _Alloc = std::allocator<_Tp>>
using deque = std::deque<_Tp, _Alloc>;

// <list>
template <typename _Tp, typename _Alloc = std::allocator<_Tp>>
using list = std::list<_Tp, _Alloc>;

// <forward_list>
template <typename _Tp, typename _Alloc = std::allocator<_Tp>>
using forward_list = std::forward_list<_Tp, _Alloc>;

// <map>
template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>, typename _Alloc = std::allocator<std::pair<const _Key, _Tp>>>
using map = std::map<_Key, _Tp, _Compare, _Alloc>;
template <typename _Key, typename _Tp, typename _Compare = std::less<_Key>, typename _Alloc = std::allocator<std::pair<const _Key, _Tp>>>
using multimap = std::multimap<_Key, _Tp, _Compare, _Alloc>;

// <set>
template <typename _Key, typename _Compare = std::less<_Key>, typename _Alloc = std::allocator<_Key>>
using set = std::set<_Key, _Compare, _Alloc>;
template <typename _Key, typename _Compare = std::less<_Key>, typename _Alloc = std::allocator<_Key>>
using multiset = std::multiset<_Key, _Compare, _Alloc>;

// <unordered_map>
template <typename _Key, typename _Tp, typename _Hash = std::hash<_Key>, typename _Pred = std::equal_to<_Key>, typename _Alloc = std::allocator<std::pair<const _Key, _Tp>>>
using unordered_map = std::unordered_map<_Key, _Tp, _Hash, _Pred, _Alloc>;
template <typename _Key, typename _Tp, typename _Hash = std::hash<_Key>, typename _Pred = std::equal_to<_Key>, typename _Alloc = std::allocator<std::pair<const _Key, _Tp>>>
using unordered_multimap = std::unordered_multimap<_Key, _Tp, _Hash, _Pred, _Alloc>;

// <unordered_set>
template <typename _Value, typename _Hash = std::hash<_Value>, typename _Pred = std::equal_to<_Value>, typename _Alloc = std::allocator<_Value>>
using unordered_set = std::unordered_set<_Value, _Hash, _Pred, _Alloc>;
template <typename _Value, typename _Hash = std::hash<_Value>, typename _Pred = std::equal_to<_Value>, typename _Alloc = std::allocator<_Value>>
using unordered_multiset = std::unordered_multiset<_Value, _Hash, _Pred, _Alloc>;

// <stack>
template <typename _Tp, typename _Sequence = deque<_Tp>>
using stack = std::stack<_Tp, _Sequence>;

// <queue>
template <typename _Tp, typename _Sequence = deque<_Tp>>
using queue = std::queue<_Tp, _Sequence>;
template <typename _Tp, typename _Sequence = vector<_Tp>, typename _Compare = less<typename _Sequence::value_type>>
using priority_queue = std::priority_queue<_Tp, _Sequence, _Compare>;

// <bitset>
using std::bitset;

// <array>
using std::array;

// <iosfwd>
using std::char_traits;
template <class charT, class traits = char_traits<charT>>
using basic_ios = std::basic_ios<charT, traits>;
template <class charT, class traits = char_traits<charT>>
using basic_streambuf = std::basic_streambuf<charT, traits>;
template <class charT, class traits = char_traits<charT>>
using basic_istream = std::basic_istream<charT, traits>;
template <class charT, class traits = char_traits<charT>>
using basic_ostream = std::basic_ostream<charT, traits>;
template <class charT, class traits = char_traits<charT>>
using basic_iostream = std::basic_iostream<charT, traits>;
template <class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
using basic_stringbuf = std::basic_stringbuf<charT, traits, Allocator>;

template <class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
using basic_istringstream = std::basic_istringstream<charT, traits, Allocator>;
template <class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
using basic_ostringstream = std::basic_ostringstream<charT, traits, Allocator>;
template <class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>>
using basic_stringstream = std::basic_stringstream<charT, traits, Allocator>;

template <class charT, class traits = char_traits<charT>>
using basic_filebuf = std::basic_filebuf<charT, traits>;
template <class charT, class traits = char_traits<charT>>
using basic_ifstream = std::basic_ifstream<charT, traits>;
template <class charT, class traits = char_traits<charT>>
using basic_ofstream = std::basic_ofstream<charT, traits>;
template <class charT, class traits = char_traits<charT>>
using basic_fstream = std::basic_fstream<charT, traits>;

template <class charT, class traits = char_traits<charT>>
using istreambuf_iterator = std::istreambuf_iterator<charT, traits>;
template <class charT, class traits = char_traits<charT>>
using ostreambuf_iterator = std::ostreambuf_iterator<charT, traits>;

using ios = basic_ios<char>;
using wios = basic_ios<wchar_t>;

using streambuf = basic_streambuf<char>;
using istream = basic_istream<char>;
using ostream = basic_ostream<char>;
using iostream = basic_iostream<char>;

using stringbuf = basic_stringbuf<char>;
using istringstream = basic_istringstream<char>;
using ostringstream = basic_ostringstream<char>;
using stringstream = basic_stringstream<char>;

using filebuf = basic_filebuf<char>;
using ifstream = basic_ifstream<char>;
using ofstream = basic_ofstream<char>;
using fstream = basic_fstream<char>;

using wstreambuf = basic_streambuf<wchar_t>;
using wistream = basic_istream<wchar_t>;
using wostream = basic_ostream<wchar_t>;
using wiostream = basic_iostream<wchar_t>;

using wstringbuf = basic_stringbuf<wchar_t>;
using wistringstream = basic_istringstream<wchar_t>;
using wostringstream = basic_ostringstream<wchar_t>;
using wstringstream = basic_stringstream<wchar_t>;

using wfilebuf = basic_filebuf<wchar_t>;
using wifstream = basic_ifstream<wchar_t>;
using wofstream = basic_ofstream<wchar_t>;
using wfstream = basic_fstream<wchar_t>;

namespace filesystem
{
// <filesystem>
using std::filesystem::path;
}
}
