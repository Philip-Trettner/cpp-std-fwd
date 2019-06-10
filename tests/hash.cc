#include <stdfwd.hh>

struct my_hashable_type
{
    int a;

    bool operator==(my_hashable_type const& r) const { return a == r.a; }
};
template <>
struct stdfwd::hash<my_hashable_type>
{
    size_t operator()(my_hashable_type const& f) const noexcept { return f.a; }
};

struct my_hashable_type2
{
    int a;

    bool operator==(my_hashable_type2 const& r) const { return a == r.a; }
};
template <>
struct std::hash<my_hashable_type2>
{
    size_t operator()(my_hashable_type2 const& f) const noexcept { return f.a; }
};

#include <unordered_map>

int hash_test(my_hashable_type f)
{
    std::unordered_map<my_hashable_type, int> m;
    return m[f];
}
int hash_test(my_hashable_type2 f)
{
    std::unordered_map<my_hashable_type2, int> m;
    return m[f];
}
