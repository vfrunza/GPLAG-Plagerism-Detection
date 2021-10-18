/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <memory>
#include <iterator>
#include <queue>
#include <set>
#include <functional>

std::function<int(int)> f(std::function<int(int, int)> g, int n) {
 return [g, n](int x) { return g(g(x, n + 1), n - 1); };
}

template <typename T>
void g(T f, int &x, int y, int &z)
{
    f(x);
    f(y);
    f(z);
}
int main()
{
    int a(3), b(4), c(5), d(6);
    g([&c](int x) {
        x++;
        c++;
        return x + c;
    }, a, a, a);
    std::cout << a << " " << c << std::endl;
    
    g([&d](int &x) { x++; d++; return x + d; }, b, b, b);
 std::cout << b << " " << d << std::endl;
 
  std::unique_ptr<int> p(new int[5]{3, 4, 2, 7, 1});
 auto p1(p.get() + 3);
 for(int i = -2; i <= 1; i++) std::cout << p1[i] << " ";
 std::cout << std::endl;

std::priority_queue<int> q;
 q.push(3); q.push(5); q.push(2); q.push(8);
 while(!q.empty()) { std::cout << q.top() << " "; q.pop(); }
 std::cout << std::endl;


std::vector<int> v{3, 5, 2, 7, 6};
 std::set<int> s{4, 8, 1, 6, 3, 4, 2, 8};
 std::copy(s.rbegin(), s.rend(), std::inserter(v, v.begin() + 3));
 for(auto x : v) std::cout << x << " ";
 std::cout << std::endl;

std::cout << f([](double x, double y) { return 2 * x + 3 * y; }, 3)(2);


              return 0;
}

/*// Vraća produkt zadanih matrica, uz pretpostavku da se mogu množiti
Matrica PomnoziMatrice(Matrica m1, Matrica m2) {
 auto m3(KreirajMatricu(BrojRedova(m1), BrojKolona(m2)));
 for(int i = 0; i < BrojRedova(m1); i++)
 for(int j = 0; j < BrojKolona(m2); j++) {
 double suma(0);
 for(int k = 0; k < BrojRedova(m2); k++) suma += m1[i][k] * m2[k][j];
 m3[i][j] = suma;
 }
 return m3;
} */