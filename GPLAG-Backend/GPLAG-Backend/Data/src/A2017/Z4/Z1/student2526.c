\*Napisati funkciju sa prototipom

char* ubaci_broj (char* tekst, int broj)

koja prima string i neki cijeli broj tipa int, te u primljenom stringu ubacuje broj između svake dvije riječi. 
Radi lakšeg lančanog pozivanja, funkcija vraća pokazivač na početak primljenog stringa. Pretpostaviti da je primljeni string dovoljno velik da primi sve dodatne karaktere. Obratite pažnju da broj može biti i negativan. 

Riječ se definiše kao niz karaktera omeđenih znakom razmaka, početkom i krajem stringa, tako da se npr. string "auto-stop" smatra za jednu riječ. Prilikom ubacivanja broja razmak se treba nalaziti prije i poslije broja. Ako se između dvije riječi nalazi dva ili više razmaka, broj treba ubaciti nakon prvog razmaka a ostale razmake ostaviti između broja i sljedeće riječi

Primjer: Ako je primljen string:
Ovo   je neki     primjer   teksta
i broj -123, nakon poziva funkcije string treba da glasi:
Ovo -123  je -123 neki -123    primjer -123   teksta

U programu je zabranjeno koristiti funkcije iz biblioteka string.h i stdlib.h, te funkcije sprintf i sscanf iz biblioteke stdio.h. Također je strogo zabranjeno kreirati pomoćni niz/string u funkciji!
*\
#include<stdio.h>
char* ubaci_broj(char* teskt, int broj)
{
    
}