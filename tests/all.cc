#include <stdfwd.hh>

stdfwd::string get_string();
stdfwd::vector<int> get_vector();
stdfwd::shared_ptr<int> get_shared_ptr();
stdfwd::unique_ptr<int> get_unique_ptr();
stdfwd::array<int, 3> get_array();
stdfwd::function<int()> get_function();
stdfwd::bitset<3> get_bitset();
stdfwd::pair<int, int> get_pair();

#include <array>
#include <bitset>
#include <functional>
#include <memory>
#include <string>
#include <utility>
#include <vector>
#include <iosfwd>

std::string get_string() { return ""; }
std::vector<int> get_vector() { return {1, 2, 3}; }
std::shared_ptr<int> get_shared_ptr() { return std::make_shared<int>(0); }
std::unique_ptr<int> get_unique_ptr() { return std::make_unique<int>(0); }
std::array<int, 3> get_array() { return {{1, 2, 3}}; }
std::function<int()> get_function() { return nullptr; }
std::bitset<3> get_bitset() { return {}; }
std::pair<int, int> get_pair() { return {1, 2}; }

std::pair<int, int> a;
