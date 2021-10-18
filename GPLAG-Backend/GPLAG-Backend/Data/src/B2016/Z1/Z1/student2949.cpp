//B 2016/2017, Zadaća 1, Zadatak 1

#include<iostream>
#include<vector> 

typedef std::vector<int> vektor;                         //Uz ovako naveden typedef, konstrukcija vektor je dostupna svakoj funkciji i olaksica se ogleda u tome sto nije nuzno svaki put pisati prepoznatljivu konstrukciju za vektor, dakle dovoljno je uporijebiti rijec, u ovom slucaju "vektor" da bi se znalo o kojoj konstrukciji je rijec
 
bool Ispitaj(vektor vektor_modul){                       //funkcija koja ima zadatak da primi vektor koji se sastoji od terarnih cifara odredjenog elementa naseg pocetnog vektora i da ispita da li se cifre u terarnom zapisu pojavljuju ili ne, paran broj puta, odnosno neparan.
     int brojac(0);
    
     for(int i=0; i<vektor_modul.size(); i++){
         for(int j=i+1; j<vektor_modul.size(); j++){
             if(vektor_modul[i]==vektor_modul[j]) brojac++;
             if(vektor_modul[i]==vektor_modul[j]){
             vektor_modul.erase(vektor_modul.begin()+j);
             j--;
             }
         }
         if(brojac==0 || ((brojac+1)%2!=0 && brojac>1)) return false; 
         brojac=0;
     }
     return true;
}

bool IspitajDaLiSuSviElementiParliIliNeparni(vektor vektor_modul){ 
    int prvibr(1), drugibr(1);                            //ova funkcija ima ulogu da pronadje onaj element koji nema SVE elemente parne ili neparne
    for(int i=0; i<vektor_modul.size(); i++){
        for(int j=i+1; j<vektor_modul.size(); j++){
        if(vektor_modul[i]==vektor_modul[j]) prvibr++;
        if(vektor_modul[i]==vektor_modul[j]) {
            vektor_modul.erase(vektor_modul.begin()+j);
            j--; 
        }
        }
        if(prvibr>=1) break;
    }
    for(int i=1; i<vektor_modul.size(); i++){
        for(int j=i+1; j<vektor_modul.size(); j++){
            if(vektor_modul[i]==vektor_modul[j]) drugibr++;
            if(vektor_modul[i]==vektor_modul[j]){
                vektor_modul.erase(vektor_modul.begin()+j);
                j--;
            }
        }
        
        if(prvibr%2!=0 && drugibr%2!=0) drugibr=1;
        else return false;
      
    }
    return true;
}

vektor IzdvojiGadne(vektor VEK, bool X){
    vektor OPAKI;
    vektor ODVRATNI;
    vektor vektor_modula;
    
    int n;
    int modul;
    
    for(int i=0; i<VEK.size(); i++){                     //brisanje istih elemenata u pocetnom vektoru
        for(int j=i+1; j<VEK.size(); j++){
            if(VEK.at(i)==VEK.at(j)){
                VEK.erase(VEK.begin()+j);
            }
        }
    }
    
    for(int i=0; i<VEK.size(); i++){
        for(int j=i+1; j<VEK.size(); j++){
            if(VEK.at(i)==VEK.at(j)){
                VEK.erase(VEK.begin()+j);
            }
        }
    }
    
   
    for(int i=0; i<VEK.size(); i++){
        n=VEK.at(i);
        while(n!=0){
            modul= n%3;
            vektor_modula.push_back(modul);
            n= n/3;
        }
       
        
        if(Ispitaj(vektor_modula)==true)
            OPAKI.push_back(VEK.at(i));
        
            
        if(Ispitaj(vektor_modula)==false)
        {
            if(IspitajDaLiSuSviElementiParliIliNeparni(vektor_modula)==true)
            ODVRATNI.push_back(VEK.at(i));
        }
        vektor_modula=vektor(0);
    }
    
    if(X==true)
      return OPAKI;
      
    if(X==false) 
      return ODVRATNI;
}


int main ()
{
    vektor VEKTOR;
    int elementi_VEKTORA;
    
    std::cout<<"Unesite brojeve (0 za prekid unosa): ";
    for(;;){                                               //beskonacna for petlja koja vrsi unos elemenata u vektor VEKTOR dok god je element koji unosimo s tastature nenultog karaktera
        std::cin>>elementi_VEKTORA;
        if(elementi_VEKTORA==0) break;
        VEKTOR.push_back(elementi_VEKTORA);
    }

    auto opaki = IzdvojiGadne(VEKTOR, true);
    auto odvratni = IzdvojiGadne(VEKTOR, false);
   
std::cout<<"Opaki: ";
    for(int x: opaki){                                     //TZV rangovska for petlja koja je prakticna kod ispisa elemenata vektora
        std::cout<<x<<" ";
    }
    std::cout<<std::endl;
    
std::cout<<"Odvratni: ";
    for(int x: odvratni){
        std::cout<<x<<" ";
    }
	return 0;
}