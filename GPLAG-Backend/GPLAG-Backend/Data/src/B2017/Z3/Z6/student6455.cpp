/B2017/2018: Zadaća 3, Zadatak 6
#include <iostream>
#include <complex>
#include <algorithm>
#include <functional>
#include <set>
#include <list>
#include <iterator>
void f(int &x, int y, int &z) {
 std::cout << x << " " << y << " " << z << " ";
 x = y + 1; y = z + 2; z = x + 3;
 std::cout << x << " " << y << " " << z << " ";
}
void f(int &x, int y, int &&z) {
 std::cout << x << " " << y << " " << z << " ";
 x = y + 3; y = z + 2; z = x + 1;
 std::cout << x << " " << y << " " << z << " ";
}
template <typename T>
 std::complex<double> g(T &u, T &v) { return {*u++, *--v}; }
int h(std::function<int(int)> u, int v) { return u(u(v)); }

int main() {
 int x(1);
 f(x, x + 1, x); std::cout << x << std::endl;
 x = 1;
 f(x, x, x + 1); std::cout << x << std::endl;
 std::set<int> s{3, 8, 4, 7, 0, 1, 1, 5, 7, 3, 6};
 std::set<int>::iterator v(s.begin()), w(s.end());
 while(v != w) std::cout << g(v, w) << " "; std::cout << std::endl;
 int p(4), q(1), r(h([&p](int q){ return q * --p; }, p));
 std::cout << p << " " << q << " " << r << std::endl;
 std::list<int> a{3, 5, 4, 2, 1, 6}, b{4, 1, 2, 7, 3, 9, 2}, c(b);
 std::copy(a.rbegin(), a.rend(), b.begin());
 std::copy(a.begin(), a.end(), std::inserter(c, c.begin()));
 for(auto e : a) std::cout << e << " "; std::cout << std::endl;
 for(auto e : b) std::cout << e << " "; std::cout << std::endl;
 for(auto e : c) std::cout << e << " "; std::cout << std::endl;
 return 0;
}