/*B 2016/2017, Zadaća 1, Zadatak 1*/
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
typedef std::vector<int> Vektor;
enum TipBroja{Opaki, Odvratni, Ostali};

bool JelOstali(int broj){
    Vektor brojaci(3);
    enum TipBroja tip(Ostali);
    
    if(broj<0)broj=-broj;
    if(broj==0)brojaci[0]++;
    while(broj!=0){
    			int cifra=broj%3;
    			if(cifra<0)cifra=-cifra;
				brojaci[cifra]++;
				broj/=3;
    }
    for(int i=0; i<brojaci.size(); i++){
        if(brojaci[i]!=0){
            if(brojaci[i]%2==0){
                    if(tip==Odvratni){
                        tip=Ostali;
                        return true;
					}
                    else tip=Opaki;
			}
            else if(brojaci[i]%2==1){
                    if(tip==Opaki){
                        tip=Ostali;
                        return true;
					}
                    else tip=Odvratni;
            }
        }
    }
    return false;
}

Vektor IzdvojiGadne(Vektor v, bool tacnost){
	Vektor NoviVektor, brojaci(3);
	enum TipBroja tip(Ostali);
	bool Isti_su(false);

	for(int i=0; i<v.size(); i++){
			tip=Ostali;
			int pomocni=v[i];
			if(pomocni<0)pomocni=-pomocni;
			if(pomocni==0)brojaci[0]++;
			while(pomocni!=0){
				int cifra=pomocni%3;
				if(cifra<0)cifra=-cifra;
				brojaci[cifra]++;
				pomocni/=3;
			}
			for(int k=0; k<brojaci.size(); k++){
				if(brojaci[k]!=0){
					if(brojaci[k]%2==0){
						if(tip==Odvratni){
							tip=Ostali;
							break;
						}
						else tip=Opaki;
					}
					else if(brojaci[k]%2==1){
							if(tip==Opaki){
								tip=Ostali;
								break;
							}
							else tip=Odvratni;
                    }
                }
            }
			if(tacnost && tip==Opaki){
                Isti_su=false;
				for(int j=0; j<NoviVektor.size(); j++){
					if(v[i]==NoviVektor[j])Isti_su=true;
                }
				if(NoviVektor.size()==0 || !Isti_su)NoviVektor.push_back(v[i]);
			}
			else if(!tacnost && tip==Odvratni){
				Isti_su=false;
				for(int j=0; j<NoviVektor.size(); j++){
					if(v[i]==NoviVektor[j])Isti_su=true;
				}
			if(NoviVektor.size()==0 || !Isti_su) NoviVektor.push_back(v[i]);
            }
		for(int i=0; i<brojaci.size(); i++)brojaci[i]=0;
	}
	return NoviVektor;
}

int main ()
{
	Vektor Pocetni;
	Vektor Pomocni;
	bool tacnost(true), Isti_su(false), Kraj(true);
	int element, brojac(0);
	
	cout << "Unesite brojeve (0 za prekid unosa): ";
	while(1){
		cin >> element;
		if(element==0)break;
		else Pocetni.push_back(element);
	}
	cin >> tacnost;
	Vektor Gadni=IzdvojiGadne(Pocetni, tacnost);

	if(tacnost){ // IzdvojiGadne vraca opake brojeve
	    for(int i=0; i<Pocetni.size(); i++){
            if(JelOstali(Pocetni[i]))continue;
            Isti_su=false;
            Kraj=true;
            int j;
        
            for(j=0; j<Gadni.size(); j++){
                if(Pocetni[i]==Gadni[j])Isti_su=true;
            }
            if(!Isti_su){
                int k;
                for(k=0; k<Pomocni.size(); k++){
                    if(Pomocni[k]==Pocetni[i])Kraj=false;
                }
                if(brojac==0 || Kraj){
                    Pomocni.push_back(Pocetni[i]);
                    brojac++;
                }
        }
    }
        cout << "Opaki: ";
        for(int i=0; i<Gadni.size(); i++)cout << Gadni[i] << " ";
        cout << std::endl;
        cout << "Odvratni: ";
        for(int i=0; i<Pomocni.size(); i++)cout << Pomocni[i] << " ";
    }
    
    else if(!tacnost){ // IzdvojiGadne vraca odvratne brojeve
	    for(int i=0; i<Pocetni.size(); i++){
            if(JelOstali(Pocetni[i]))continue;
            Isti_su=false;
            Kraj=true;
            int j;
            
            for(j=0; j<Gadni.size(); j++){
                if(Pocetni[i]==Gadni[j])Isti_su=true;
            }
            if(!Isti_su){
                int k;
                for(k=0; k<Pomocni.size(); k++){
                    if(Pomocni[k]==Pocetni[i])Kraj=false;
                }
                if(brojac==0 || Kraj){
                    Pomocni.push_back(Pocetni[i]);
                    brojac++;
                }
            }
        }
        cout << "Opaki: ";
        for(int i=0; i<Pomocni.size(); i++)cout << Pomocni[i] << " ";
        cout << std::endl;
        cout << "Odvratni: ";
        for(int i=0; i<Gadni.size(); i++)cout << Gadni[i] << " ";
    }
	return 0;
}

