#include <iostream>
#include <memory>
std::unique_ptr<double> Funkcija(double x)
{
    return std::unique_ptr<double> p(new double(x));
}
int main()
{
    std::shared_ptr<double> p2(Funkcija(3.5)); // Legalno...
    std::cout<<*p2<<"\n";
    p2 = Funkcija(2.13);
    std::cout<<*p2;
}