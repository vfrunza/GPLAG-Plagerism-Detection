//TP 2017/2018: Tutorijal 1, Zadatak 4
#include <iostream>
#include <cstring>
int main ()
{
    double n(0);
    int suma(0);
    int i(0);
    
    std::cout << "Unesite prirodan broj ili 0 za kraj: ";
    std::cin >> n;
    
    int n1 = n;
    do {
        for(i = 1; i < n1; i++) {
            if(n1 % i == 0) {
                suma+=i;
            }
        }
        if(!std::cin) {
            std::cout << "Niste unijeli prirodan broj!" << std::endl;
            std::cout << "Unesite prirodan broj ili 0 za kraj: ";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
        else if(n != int(n)) {
            std::cout << "Niste unijeli prirodan broj!" << std::endl;
            std::cout << "Unesite prirodan broj ili 0 za kraj: ";
        }
        else if(n1 < 0) {
            std::cout << "Niste unijeli prirodan broj!" << std::endl;
            std::cout << "Unesite prirodan broj ili 0 za kraj: ";
        }
        else if(suma < n1) {
            std::cout << "Broj " << n << " je manjkav!" << std::endl;
            std::cout << "Unesite prirodan broj ili 0 za kraj: ";
        }
        else if(suma > n1) {
            std::cout << "Broj " << n << " je obilan!" << std::endl;
            std::cout << "Unesite prirodan broj ili 0 za kraj: ";
        }
        else if(suma == n1) {
            std::cout << "Broj " << n << " je savrsen!" << std::endl;
            std::cout << "Unesite prirodan broj ili 0 za kraj: ";
        }
        suma = 0;
        std::cin >> n;
        n1 = int(n);
    } while(n != 0);
    std::cout << "Dovidjenja!";
    
	return 0;
}
