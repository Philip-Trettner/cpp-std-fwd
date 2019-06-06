#include <stdfwd.hh>

stdfwd::string get_string();
stdfwd::vector<int> get_vector();
stdfwd::shared_ptr<int> get_shared_ptr();
stdfwd::unique_ptr<int> get_unique_ptr();
stdfwd::array<int, 3> get_array();
stdfwd::function<int()> get_function();

#include <array>
#include <functional>
#include <memory>
#include <string>
#include <vector>

std::string get_string() { return ""; }
std::vector<int> get_vector() { return {1, 2, 3}; }
stdfwd::shared_ptr<int> get_shared_ptr() { return std::make_shared<int>(0); }
stdfwd::unique_ptr<int> get_unique_ptr() { return std::make_unique<int>(0); }
std::array<int, 3> get_array() { return {{1, 2, 3}}; }
std::function<int()> get_function() { return nullptr; }

std::hash<int> a;
