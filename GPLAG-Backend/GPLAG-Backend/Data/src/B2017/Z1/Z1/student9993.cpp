#include <vector> 
#include <iostream>
#include <cmath>

int ternary(int testbroj3){                 //konverzija dec.--->ter.
    int suma(0);
    for(int i(0);; i++){
        suma+=(testbroj3%3)*std::pow(10, i);
        testbroj3/=3;
        if(testbroj3==0) break;
    }
    return suma;
}
bool simetricnost(int testbroj2){
        int tempbroj;                                     
        tempbroj=ternary(testbroj2);
        int a(0);
        int temp(tempbroj); // temporalna varijabla ternarnog zapisa
        while(temp!=0){
            int zadnja_cifra(temp%10);
            a+=zadnja_cifra;
            a*=10;
            temp/=10;
        }
        a/=10;
        if(a==tempbroj) return true;
        else return false;
}

bool dalijeprost(int testbroj){
    int counter(0);
    if (testbroj==0) return false;
    for(int i(2); i<=std::sqrt(testbroj); i++){
        if(testbroj%i==0) counter++;
    }
    if(counter==0) return true;
    else return false;
}

std::vector<int> IzdvojiSimetricneTernarne(std::vector<int> final, bool logic){
    std::vector<int> privremeni (0);                                                // u privremenom se nalaze proste/slozene vrijednosti elemenata
    if(logic==true){
        for(int i(0); i<final.size(); i++){
            if(dalijeprost(final.at(i))==true) privremeni.push_back(final.at(i));
        }
    }
    else if(logic==false){
        for(int i(0); i<final.size(); i++){
            if(dalijeprost(final.at(i))==false) privremeni.push_back(final.at(i));
        }
    }
    std::vector<int> konacni (0);                                                     //vektor koji vracamo
    for(int i(0); i<privremeni.size(); i++){
        if(simetricnost(privremeni.at(i))==true) konacni.push_back(privremeni.at(i));
    }
    return konacni;
}
// ******************************************************************************************************************************************************
int main ()
{/*
	std::cout<<"Unesite elemente vektora (-1 za kraj): ";
	std::vector<int> digits(0);
	int number;
    for(int i(0);; i++){
        std::cin>>number;
        if(number==-1 && digits.size()==0){
            std::cout<<"Vektor je prazan!";
            return 0;
        } 
        if(number==-1){
            break;
        }
        else {
            digits.push_back(number);
        }
    }
    int tip;
    std::cout<<"Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    std::cin>>tip;
    while((tip!=0 && tip!=1)){
        std::cout<<"Neispravan unos! Unesite ponovo: ";
        std::cin>>tip;
        if(tip==0 || tip==1) break;
    }
    std::vector<int> novi;  
    novi=IzdvojiSimetricneTernarne(digits, tip);
    for(int i(0); i<novi.size(); i++){ //brisanje elementa koji se ponovio
        for(int j(i+1); j<novi.size(); j++){
            if(novi.at(i)==novi.at(j)){
                novi.erase(novi.begin()+j);
            }
        }
    }
    if(tip==0 && novi.size()==0) {
        std::cout<<"Nema slozenih simetricnih brojeva u vektoru.";
        return 1;
    }
    else if(tip==1 && novi.size()==0){
        std::cout<<"Nema prostih simetricnih brojeva u vektoru.";
        return 1;
    }
    if(tip==0) std::cout<<"Slozeni simetricni brojevi iz vektora su: ";
    else if(tip==1) std::cout<<"Prosti simetricni brojevi iz vektora su: ";
    for(int i(0); i<novi.size(); i++){
            if(novi.size()-i==1){
                std::cout<<novi.at(i)<<".";
                break;
            } 
            std::cout<<novi.at(i)<<", ";
        }*/
        std::vector<int> v{-3,-2,-1,0,1,2,3};
	
	std::vector<int> p(IzdvojiSimetricneTernarne(v,1));
	std::vector<int> s(IzdvojiSimetricneTernarne(v,0));
	
	std::cout<<"Prosti: ";
	for(int x : p) std::cout<<x<<" ";
	std::cout<<std::endl;
	
	std::cout<<"Slozeni: ";
	for(int x : s) std::cout<<x<<" ";
	std::cout<<std::endl;
	return 0;
}