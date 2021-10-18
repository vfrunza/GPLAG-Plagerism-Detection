/B2017/2018: Primjer ispita 1
#include <iostream>
#include <ios>
#include <fstream>
#include <complex>
#include <algorithm>

int main ()
{
    /*std::ofstream tok("KOMPLEKSNI.TXT");
    tok << 2 << "," << 3 << std::endl;
    tok << 1 << "," << 5 << std::endl;*/
    
    //Zadatak 8
    std::ifstream tok1 ("KOMPLEKSNI.TXT");
    std::fstream tok2("KOMPLEKSNI.DAT", std::ios::binary | std::ios::in | std::ios::out | std::ios::app);
   
   tok2.seekp(0,std::ios::beg);
   tok2.seekg(0,std::ios::beg);
    for (;;){
        if (!tok1 || !tok2) break;
        double realni, imaginarni;
        char  znak;
        tok1 >> realni >> znak >> imaginarni;
        std::complex<double> broj(realni,imaginarni);
        tok2.seekg(0, std::ios::cur);
        tok2.seekp(0, std::ios::cur);
        tok2.write(reinterpret_cast<char*>(&broj), sizeof (broj));
        if (!tok2) throw ("error");
        
    }
    
    tok2.seekp(0, std::ios::beg);
    tok2.seekg(0, std::ios::beg);
    for (;;){
        if (!tok2) break;
        if(tok2.eof()) break;
        tok2.seekg(0, std::ios::cur);
        std::complex<double> broj;
        tok2.read(reinterpret_cast<char*>(&broj), sizeof broj);
        std::complex<double> broj2(broj.imag(),broj.real());
        tok2.seekg(-sizeof(broj2), std::ios::cur);
        tok2.seekp(-sizeof(broj2), std::ios::cur);
        tok2.write(reinterpret_cast<char*>(&broj2), sizeof broj);
        if (!tok2) throw "error";
    }
    
    /*U tekstualnoj datoteci “KOMPLEKSNI.TXT” nalazi se skupina podataka o kompleksnim brojevima, pri
čemu svaki red sadrži realni i imaginarni dio nekog kompleksnog broja, koji su međusobno razdvojeni
zarezima. Napišite program koji od ove datoteke kreira novu binarnu datoteku “KOMPLEKSNI.DAT” koja
sadrži iste podatke, samo pohranjene kao slijed objekata tipa “std::complex<double>”. Nakon
kreiranja ove datoteke i smještanja traženog sadržaja u nju, program treba da modificira kreiranu
datoteku tako da se u svakom kompleksnom broju razmijene realni i imaginarni dio (bez učitavanja
kompletnog sadržaja datoteke u memoriju), i da na kraju ispiše sadržaj tako modificirane datoteke na
ekran (svaki kompleksni broj u posebnom redu). Pretpostavite da ulazna datoteka “KOMPLEKSNI.TXT”
sadrži isključivo ispravne podatke. U slučaju bilo kakvih problema prilikom čitanja datoteke, treba
prijaviti grešku*/
	return 0;
}
