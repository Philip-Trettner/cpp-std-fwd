// #include <stdfwd.hh>

#include <filesystem>
#include <iostream>

void test_filesystem()
{
    // TODO: this crashes once the include is added
    std::cout << "std::filesystem::current_path() = " << std::filesystem::current_path() << std::endl;
}
