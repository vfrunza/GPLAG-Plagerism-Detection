#include <iostream>
#include <typeinfo>
class Base {
public:
 void f() { std::cout << 2 << " "; }
 virtual void g() { std::cout << 7 << " "; }
};
class Derived : public Base {
public:
 void f() { std::cout << 1 << " "; }
 void g() { std::cout << 3 << " "; }
 virtual void h() { std::cout << 4 << " "; }
};
class Young : public Derived {
public:
 void h() { std::cout << 9 << " "; }
};
void p(Base x) { x.f(); x.g(); }
void q(Base &y) { y.f(); y.g(); }
int main() {
 Base a; Derived b;
 Base *c = new Base; Base *d = new Derived; Derived *e = new Derived;
 a.f(); a.g(); b.f(); b.g(); std::cout << std::endl;
 c->f(); c->g(); d->f(); d->g(); e->f(); e->g(); std::cout << std::endl;
 p(a); q(a); p(b); q(b); std::cout << std::endl;
 Base *u = new Young;
 std::cout << std::boolalpha;
 std::cout << (static_cast<Derived*>(c) == nullptr) << " ";
 std::cout << (dynamic_cast<Derived*>(c) == nullptr) << " ";
 std::cout << (static_cast<Derived*>(d) == nullptr) << " ";
 std::cout << (dynamic_cast<Derived*>(d) == nullptr) << " ";
 std::cout << (static_cast<Derived*>(u) == nullptr) << " ";
 std::cout << (dynamic_cast<Derived*>(u) == nullptr) << " " << std::endl;
 std::cout << (typeid(*u) == typeid(Base)) << " ";
 std::cout << (typeid(*u) == typeid(Derived)) << " ";
 std::cout << (typeid(*u) == typeid(Young)) << " " << std::endl;
 dynamic_cast<Derived*>(u)->h(); std::cout << std::endl;
return 0;
}