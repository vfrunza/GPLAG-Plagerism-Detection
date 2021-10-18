/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
#include <string>
#include <vector>

class Spremnik
{
 
};

class Sanduk : public Spremnik
{
 double tezina;
 std::string naziv;
 std::vector<double> tezine_predmeta;
};

class Vreca : public Spremnik
{
 double tezina;
 std::string naziv;
 std::vector<double> tezine_materije;
};

class Bure : public Spremnik
{
 double tezina;
 std::string naziv_tecnosti;
 double gustina_tecnosti;
 double zapremina_tecnosti;
};

class Skldiste
{
 Sanduk sanduk;
 Vreca vreca;
 Bure bure;
};

int main ()
{
	return 0;
}
