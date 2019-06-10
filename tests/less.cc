#include <stdfwd.hh>

struct my_comparable_type
{
    int a;

    bool operator==(my_comparable_type const& r) const { return a == r.a; }
};
template <>
struct std::less<my_comparable_type>
{
    bool operator()(my_comparable_type const& a, my_comparable_type const& b) const noexcept { return a.a < b.a; }
};

#include <map>

int less_test(my_comparable_type f)
{
    std::map<my_comparable_type, int> m;
    return m[f];
}
