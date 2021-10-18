#include<iostream>
#include<cmath>
#include<vector>
bool Da_li_je_opak(long long int a){
    a=fabs(a);
    int ternarna_cifra,baza(3);
    std::vector<int>ternarne_cifre;
    do{
        int n(0);
        ternarna_cifra=a%baza;
        a=a/baza;
        ternarne_cifre.push_back(ternarna_cifra);
        n++;
    }while(a!=0);
    for(int i : ternarne_cifre){
        int n(0);
        for(int j : ternarne_cifre){
            if(i==j)
            n++;
        }
        if(n%2!=0)
        return false;
    }
    return true;
}
bool Da_li_je_odvratan(long long int a){
     a=fabs(a);
    int ternarna_cifra,baza(3);
    std::vector<int>ternarne_cifre;
    do{
        int n(0);
        ternarna_cifra=a%baza;
        a=a/baza;
        ternarne_cifre.push_back(ternarna_cifra);
        n++;
    }while(a!=0);
    for(int i : ternarne_cifre){
        int n(0);
        for(int j : ternarne_cifre){
            if(i==j)
            n++;
        }
        if(n%2==0)
        return false;
    }
    return true;
}
std::vector<int> IzdvojiGadne(std::vector<int> v, bool l){
    std::vector<int>Gadni;
    if(l){
        int prethodni(-1),n(0);
        for(int i : v){
            for(int j=0;j<Gadni.size();j++){
                if(Gadni[j]==i)
                prethodni=i;
            }
           if(Da_li_je_opak(i)&&i!=prethodni) {
              Gadni.push_back(i);
              n++;
           }
        }
    }
    else{
        int prethodni(-1),n(0);
        for(int i : v){
             for(int j=0;j<Gadni.size();j++){
                if(Gadni[j]==i)
                prethodni=i;
            }
           if(Da_li_je_odvratan(i)&&i!=prethodni) {
              Gadni.push_back(i);
              n++;
           }
        }
    }
   return Gadni; 
}
int main ()
{
    std::vector<int>Brojevi;
    std::vector<int>Odvratni;
    std::vector<int>Opaki;
    int a(1);
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    while(a!=0){
        std::cin>>a;
        if(a==0)break;
        Brojevi.push_back(a);
    }
    Odvratni=IzdvojiGadne(Brojevi,0);
    Opaki=IzdvojiGadne(Brojevi,1);
    std::cout<<"Opaki: ";
    for(int i : Opaki)
    std::cout<<i<<" ";
    std::cout<<"\nOdvratni: ";
    for(int i : Odvratni)
    std::cout<<i<<" ";
	return 0;
}