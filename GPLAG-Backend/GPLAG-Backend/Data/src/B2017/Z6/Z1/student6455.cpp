/B2017/2018: Zadaća 6, Zadatak 1
#include <iostream>
//tut 5 zadatak 1
/*Napišite program koji od korisnika traži da sa tastature unese rečenicu, ne dužu od 1000 znakova, a
koji će zatim ispisati unesenu rečenicu bez prve riječi te rečenice, pri čemu ispis započinje od prvog
znaka druge riječi (u slučaju da rečenica ima samo jednu riječ, ili da je “prazna” bez riječi, ne
ispisuje se ništa). Pod riječi se ovdje smatra svaki niz znakova koji nisu razmaci a koji je s obje
strane omeđen razmacima, osim na početku ili kraju kada ne mora biti razmaka lijevo odnodno
desno od riječi. Vodite računa da može biti više razmaka između dvije riječi, kao i razmaka na
početku ili kraju rečenice. Unesena rečenica se smješta u klasični niz znakova (dakle, ne u
promjenljivu tipa “string”). Za realizaciju zadatka koristiti isključivo pokazivačku aritmetiku. Nije
dozvoljena upotreba funkcija iz biblioteka “cstring” niti “string”, kao ni upotreba indeksiranja
(što uključuje i njegovu trivijalnu simulaciju koja podrazumijeva pisanje “*(a + n)” umjesto
“a[n]”). */
int main ()
{
    std::cout<<"Unesite recenicu: \n";
     char recenica[1000];
     char niz;
     while(std::cin.peek()!=' '){
     niz=std::cin.get();}
     std::cin>>std::ws;
     std::cin.getline(recenica, sizeof recenica, '\n');
     std::cout<<recenica;
     
	return 0;
}
