/*B 2016/2017, Zadaća 1, Zadatak 1*/

#include <iostream>
#include <vector>
#include <cmath>


using std::cout;
using std::cin;
using std::endl;

std::vector<int> IzdvojiGadne(std::vector<int> brojevi, bool tf)

{
    std::vector<int> OpakiBrojevi;
    std::vector<int> OdvratniBrojevi;
    std::vector<int> v ;

    int p,broj,brojac0=0,brojac1=0,brojac2=0;
    for(int i: brojevi)
{
    
    broj=std::abs(i);

    do

{

            p=broj%3;


            if      (p==0)
            {
                brojac0++;
            }

            else if (p==1)
            {
                brojac1++;
            }


            else if (p==2)
            {
                brojac2++;
            }
            
            broj/=3;
            
            if(broj==0) break;

            }
        
    while(broj!=0);

        
        if(brojac0%2 == 0 &&brojac1%2==0 && brojac2%2==0)
            {
        
        OpakiBrojevi.push_back(i);
        for(int j=0;j<OpakiBrojevi.size()-1;j++)
        if(OpakiBrojevi[j]==i)
            {
                OpakiBrojevi.resize(OpakiBrojevi.size()-1);
            }
            }
            
        else if ((brojac0%2 != 0||brojac0==0) &&(brojac1%2!=0||brojac1==0) && (brojac2%2!=0||brojac2==0))
            {
        OdvratniBrojevi.push_back(i);
        for(int j=0;j<OdvratniBrojevi.size()-1;j++)
        if(OdvratniBrojevi[j]==i)
            {
            
               OdvratniBrojevi.resize(OdvratniBrojevi.size()-1);
            }
            }
       
        

    brojac0=0;
    brojac1=0;
    brojac2=0;
            }

    if(tf==true)
    return OpakiBrojevi;
    else if(tf==false)
    return OdvratniBrojevi;
            
    
             }


    int main ()
             {

    int broj;
    std::vector<int>brojevi;



    cout<<"Unesite brojeve (0 za prekid unosa): ";

    do

    {

        cin>> broj;
        if(broj==0) break;
        brojevi.push_back(broj);
    }

    while (broj !=0);


    bool tf(true);
    std::vector<int> b{(IzdvojiGadne(brojevi,tf))};
    
    tf=false;
    std::vector<int> c{IzdvojiGadne(brojevi,tf)};
    
    std::cout<<"Opaki: ";
    for(int i: b)
    std::cout<<i<<" ";
    std::cout<<std::endl;
    std::cout<<"Odvratni: ";
    for(int j: c)
    std::cout<<j<<" ";
    std::cout<<std::endl;

    return 0;
   }
