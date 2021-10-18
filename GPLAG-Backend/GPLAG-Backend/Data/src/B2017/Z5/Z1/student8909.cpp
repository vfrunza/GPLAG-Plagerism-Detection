/B2017/2018: Zadaća 5, Zadatak 1
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <memory>
#include <cstring>

class Student
{
    int index;
    char godina_studija[];
    
    public:
    Student(int index, std::string godina_studija, std::string ime_i_prezime, std::string adresa, std::string broj_telefona);
    int DajIndex() const
    {
        return index;
    }
    DajGodinuStuddija() const;
    std::string DajImePrezime() const
    {
        return ime_i_prezime;
    }
    std::string DajAdresu() const
    {
        return adresa;
    }
    std::string DajTelefon() const
    {
        return broj_telefona;
    }
    
};

bool DaLiJePetocifreni(int index)
{
    int br(0);
    while(index > 0)
    {
        index /= 10;
        br++;
    }
    
    if(br == 5) return true;
    return false;
}

class Laptop
{
    
};

class Administracija
{
    
};

int main ()
{
	return 0;
}
