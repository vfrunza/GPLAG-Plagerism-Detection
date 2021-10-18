#include <iostream>
#include <complex>
using namespace std;
void f(int *&x, int *&y, char z) { cout << *x++ << z << *--y << " "; }
int g(double x, int y = 2) { return x * y + 1; }
double g(double x, double y, int z = 1) { return x + y * z; }
int &h(int f(double, int), int &x, int &y, int &z) {
 cout.width(7);
 cout << endl << x << y << z << endl;
 x = y + z; z = x + y;
 cout << x << y << z << endl;
 z = f(x, y);
 return x;
}
void t(complex<double> x, int *y) { cout << double(*y) + x << endl; }
int main() {
 enum x {y, z = 4, u, v = 9, w};
 int a[] = {6, 7, 4, 2, 8, 5, 9, 1, 4, 8};

 int *p(&a[4]), *q(p – 1), *r(a + 7);
 cout << y << z << u << v << w << endl;
 t(4, new int(1)); t(complex<double>(4, 4), new int(1));
 cout << g(5,8) << " " << g(5.8) << " " << g(5,8.) << " "
 << g(8,5,5.8) << " " << g(8.5,5.8) << " " << g(8,5.5,8) << endl;
 while(r >= q) f(q, r, '-');
 ++h(g, a[7], *a, p[-2]);
 cout << a[7] << " " << *a << " " << p[-2] << endl;
 return 0;
}