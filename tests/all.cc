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

#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <functional>
#include <iosfwd>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <iostream>

std::string get_string() { return ""; }
std::vector<int> get_vector() { return {1, 2, 3}; }
std::deque<int> get_deque() { return {1, 2, 3}; }
std::list<int> get_list() { return {1, 2, 3}; }
std::stack<int> get_stack() { return {}; }
std::forward_list<int> get_forward_list() { return {1, 2, 3}; }
std::shared_ptr<int> get_shared_ptr() { return std::make_shared<int>(0); }
std::unique_ptr<int> get_unique_ptr() { return std::make_unique<int>(0); }
std::array<int, 3> get_array() { return {{1, 2, 3}}; }
std::function<int()> get_function() { return nullptr; }
std::bitset<3> get_bitset() { return {}; }
std::pair<int, int> get_pair() { return {1, 2}; }
std::map<int, int> get_map() { return {{1, 2}}; }
std::set<int> get_set() { return {1, 2}; }
std::unordered_map<int, int> get_unordered_map() { return {{1, 2}}; }
std::unordered_set<int> get_unordered_set() { return {1, 2}; }

