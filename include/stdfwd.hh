#pragma once

// see https://stackoverflow.com/questions/31657499/how-to-detect-stdlib-libc-in-the-preprocessor
#include <ciso646>

#include <cstdint>

#if defined(_LIBCPP_VERSION)
#define STDFWD_IS_LIBCPP
#elif defined(__GLIBCXX__)
#define STDFWD_IS_LIBSTDCPP
#else
#error "Unknown stdlib"
#endif

/*
 * TODO: are these useful at all?
 *
 *  <scoped_allocator>
 *  <memory_resource>
 *  <exception>
 *  <stdexcept>
 *  <iterator>
 *  <locale>
 *
 * TODO:
 *
 *  <valarray> slices?
 *  <filesystem> more types?
 *  <regex> iterators?
 *  <mutex> raii types?
 *  <random> what is useful here?
 *  <chrono> depends heavily on ratio
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

    // <random>
    class random_device;

    // <atomic>
    template <typename _Tp>
    struct atomic;
    struct atomic_flag;

    // <mutex>
    class mutex;
    class timed_mutex;
    class recursive_mutex;
    class recursive_timed_mutex;

    // <shared_mutex>
    class shared_mutex;
    class shared_timed_mutex;

    // <thread>
    class thread;

    // <future>
    template <typename _Res>
    class future;
    template <typename _Res>
    class shared_future;
    template <typename _Signature>
    class packaged_task;
    template <typename _Res>
    class promise;

    // <condition_variable>
    class condition_variable;
    inline namespace _V2
    {
    class condition_variable_any;
    }

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

    // <regex>
    template <typename _Ch_type>
    struct regex_traits;
    template <typename _Ch_type, typename _Rx_traits>
    class basic_regex;
    using regex = basic_regex<char, regex_traits<char>>;
    template <typename _BiIter>
    class sub_match;
    template <typename _Bi_iter, typename _Alloc>
    class match_results;

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

// shared typedefs
namespace std
{
// <atomic>
using atomic_bool = atomic<bool>;
using atomic_char = atomic<char>;
using atomic_schar = atomic<signed char>;
using atomic_uchar = atomic<unsigned char>;
using atomic_short = atomic<short>;
using atomic_ushort = atomic<unsigned short>;
using atomic_int = atomic<int>;
using atomic_uint = atomic<unsigned int>;
using atomic_long = atomic<long>;
using atomic_ulong = atomic<unsigned long>;
using atomic_llong = atomic<long long>;
using atomic_ullong = atomic<unsigned long long>;
using atomic_char16_t = atomic<char16_t>;
using atomic_char32_t = atomic<char32_t>;
using atomic_wchar_t = atomic<wchar_t>;

using atomic_int8_t = atomic<int8_t>;
using atomic_uint8_t = atomic<uint8_t>;
using atomic_int16_t = atomic<int16_t>;
using atomic_uint16_t = atomic<uint16_t>;
using atomic_int32_t = atomic<int32_t>;
using atomic_uint32_t = atomic<uint32_t>;
using atomic_int64_t = atomic<int64_t>;
using atomic_uint64_t = atomic<uint64_t>;

using atomic_int_least8_t = atomic<int_least8_t>;
using atomic_uint_least8_t = atomic<uint_least8_t>;
using atomic_int_least16_t = atomic<int_least16_t>;
using atomic_uint_least16_t = atomic<uint_least16_t>;
using atomic_int_least32_t = atomic<int_least32_t>;
using atomic_uint_least32_t = atomic<uint_least32_t>;
using atomic_int_least64_t = atomic<int_least64_t>;
using atomic_uint_least64_t = atomic<uint_least64_t>;

using atomic_int_fast8_t = atomic<int_fast8_t>;
using atomic_uint_fast8_t = atomic<uint_fast8_t>;
using atomic_int_fast16_t = atomic<int_fast16_t>;
using atomic_uint_fast16_t = atomic<uint_fast16_t>;
using atomic_int_fast32_t = atomic<int_fast32_t>;
using atomic_uint_fast32_t = atomic<uint_fast32_t>;
using atomic_int_fast64_t = atomic<int_fast64_t>;
using atomic_uint_fast64_t = atomic<uint_fast64_t>;

using atomic_intptr_t = atomic<intptr_t>;
using atomic_uintptr_t = atomic<uintptr_t>;
using atomic_size_t = atomic<size_t>;
using atomic_ptrdiff_t = atomic<ptrdiff_t>;
using atomic_intmax_t = atomic<intmax_t>;
using atomic_uintmax_t = atomic<uintmax_t>;
}

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

// <random>
using std::random_device;

// <atomic>
using std::atomic;
using std::atomic_flag;

// named typedefs
using std::atomic_bool;
using std::atomic_char;
using std::atomic_char16_t;
using std::atomic_char32_t;
using std::atomic_int;
using std::atomic_llong;
using std::atomic_long;
using std::atomic_schar;
using std::atomic_short;
using std::atomic_uchar;
using std::atomic_uint;
using std::atomic_ullong;
using std::atomic_ulong;
using std::atomic_ushort;
using std::atomic_wchar_t;

using std::atomic_int16_t;
using std::atomic_int32_t;
using std::atomic_int64_t;
using std::atomic_int8_t;
using std::atomic_uint16_t;
using std::atomic_uint32_t;
using std::atomic_uint64_t;
using std::atomic_uint8_t;

using std::atomic_int_least16_t;
using std::atomic_int_least32_t;
using std::atomic_int_least64_t;
using std::atomic_int_least8_t;
using std::atomic_uint_least16_t;
using std::atomic_uint_least32_t;
using std::atomic_uint_least64_t;
using std::atomic_uint_least8_t;

using std::atomic_int_fast16_t;
using std::atomic_int_fast32_t;
using std::atomic_int_fast64_t;
using std::atomic_int_fast8_t;
using std::atomic_uint_fast16_t;
using std::atomic_uint_fast32_t;
using std::atomic_uint_fast64_t;
using std::atomic_uint_fast8_t;

using std::atomic_intmax_t;
using std::atomic_intptr_t;
using std::atomic_ptrdiff_t;
using std::atomic_size_t;
using std::atomic_uintmax_t;
using std::atomic_uintptr_t;

// <mutex>
using std::mutex;
using std::recursive_mutex;
using std::recursive_timed_mutex;
using std::timed_mutex;

// <shared_mutex>
using std::shared_mutex;
using std::shared_timed_mutex;

// <thread>
using std::thread;

// <future>
using std::future;
using std::packaged_task;
using std::promise;
using std::shared_future;

// <condition_variable>
using std::condition_variable;
using std::condition_variable_any;

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

// <regex>
using std::regex_traits;
template <typename _Ch_type, typename _Rx_traits = regex_traits<_Ch_type>>
using basic_regex = std::basic_regex<_Ch_type, _Rx_traits>;
using std::regex;
using std::sub_match;
template <typename _Bi_iter, typename _Alloc = allocator<sub_match<_Bi_iter>>>
using match_results = std::match_results<_Bi_iter, _Alloc>;

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
