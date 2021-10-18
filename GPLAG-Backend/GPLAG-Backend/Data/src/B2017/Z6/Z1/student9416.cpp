/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <iterator>
#include <iomanip>
#include <functional>
#include <queue>
#include <algorithm>
int main()
{
    int v(0);
    auto nr([]() {
        std::cout << std::endl;
    });
    std::function<int(int)> a[] {[](int x) { return x + 10; },
    [](int x) { return x * 2; }, [](int x) {
        return x - 5;
    }
                                };
    std::list<int> d1 {3, 5, 1, 2, 8, 3, 7, 2};
    std::set<int> d2;
    std::multiset<int> d3;
    std::stack<int> c1;
    std::queue<int> c2;
    std::priority_queue<int> c3;
    std::string s1("qwerty"), s2(12, s1[0]), s3(s2);
    std::ostream_iterator<int> it(std::cout, "!");
    std::copy(s1.begin(), s1.end(), s2.rbegin() + 3);
    std::copy(s1.rbegin(), s1.rend(), std::inserter(s3, s3.begin() + 3));
    std::cout << s2 << " " << s3 << std::endl;
    for(auto x : a) std::cout << (v = x(v)) << " ";
    nr();
    for(auto x : {
                3, 5, 1, 8, 2
            }) {
        c1.push(x);
        c2.push(x);
        c3.push(x);
    }
    while(!c1.empty()) {
        std::cout << c1.top();
        c1.pop();
    }
    nr();
    while(!c2.empty()) {
        std::cout << c2.front();
        c2.pop();
    }
    nr();
    while(!c3.empty()) {
        std::cout << c3.top();
        c3.pop();
    }
    nr();
    for(auto x : d1) {
        d2.insert(x);
        d3.insert(x);
    }
    std::copy_if(d1.begin(), d1.end(), it, [](int x) {
        return x > 4;
    });
    nr();
    std::copy_if(d2.begin(), d2.end(), it, [](int x) {
        return x > 2;
    });
    nr();
    std::copy_if(d3.rbegin(), d3.rend(), it, [](int x) {
        return x < 5;
    });
    nr();
    return 0;
}