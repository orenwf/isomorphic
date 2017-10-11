#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>
#include <utility>
#include <iostream>

std::unordered_map<std::string, unsigned> make_table(const std::string& s) {
    std::unordered_map<std::string, unsigned> u_map;
    for(size_t i = 0; i < s.size(); ++i) {
        auto x = u_map.emplace(std::make_pair(s.substr(i,1), 1));
        if(!x.second) ++x.first->second;
    }
    return u_map;
}

bool test_isomorphic(const std::string& a, const std::string& b) {
    if(b.size() != a.size()) return false;
    std::unordered_map<std::string, unsigned> map_a = make_table(a);
    return map_a == make_table(b);
}

int main() {

    std::string first;
    std::string second;

    std::cout << "Please enter two strings: ";
    std::cin >> first >> second;  

    std::string t_or_f = test_isomorphic(first, second) ? "isomorphic " : "not isomorphic ";
    std::cout << "String " << first << " is " << t_or_f << "with " << second << "." << std::endl;

    return 0;
}

