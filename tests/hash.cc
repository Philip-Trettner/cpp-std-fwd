#include <stdfwd.hh>

struct foo
{
    int a;

    bool operator==(foo const& r) const { return a == r.a; }
};
template <>
struct stdfwd::hash<foo>
{
    size_t operator()(foo const& f) const noexcept { return f.a; }
};

#include <unordered_map>

int hash_test(foo f)
{
    std::unordered_map<foo, int> m;
    return m[f];
}
