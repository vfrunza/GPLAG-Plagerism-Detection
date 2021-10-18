//B 2017/2018, Zadaća 1, Zadatak 1
#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<int> Vektor;
//Funkcija koja pretvara broj sa dekadnom bazom u broj sa ternarnom bazom
int Ternarni (int x)
{
    int y;
	y=x;
//Ako je broj manji od nule mijenjamo predznak	
    if(y<0)y*=-1;
	int cif, ter(0), i(0);
//Cifre pri konverziji su ostaci pri dijeljenu sa brojem tri; daljim dijeljenjem sa tri raste stepen cifre za jedan	
	while(x>0)
	{
    	cif=x%3;
    	ter=ter+cif*pow(10,i++);
    	x=x/3;
    }
    return ter;
}
//Funkcija koja vraca logicku vrijednost istina ili neistina zavisno od toga da li je broj prost ili nije, respektivno
bool DaLiJeProst (int n)
{	
//Ako je broj manji od nule mijenjamo predznak
    if(n<=0)n*=-1;
//Ako je broj djeljiv i sa jednim brojem sem jedan i samim sobom nije prost; u suprotnom jeste    
	for(unsigned i=2; i<sqrt(n+1) ;i++)if(n%i==0)return false;
	return true;
}
//Funkcija koja vraca logicku vrijednost istina ili neistina zavisno od toga da li je broj simetrican
bool Simetrican (int x)
{
	int broj, y;
	y=x;
	broj=x;
//Ako je broj manji od nule mijenjamo predznak
    if(y<0)y*=-1;
	int br(0);
//Racunamo stepen broja	
	while(y>0)
	{
		br++;
		y=y/10;
	}br=br-1;
	int naop(0), i, cif;
//Izvrcemo broj tako sto cifre nmanjeg stepena pretvaramo u cifre nveceg stepena; cifru sa najmanjih stepenom pretvaramo u cifru sa najvecim stepenom te stepen raste i opada, respektivno	
	for(i=br;i>=0;i--)
	{
    	cif=x%10;
    	naop=naop+cif*pow(10,i);
    	x=x/10;
    }
//Ako je broj nakon izvrtanja jednak broju prije izvrtanja on je simetrican    
	if(naop==broj)return true;
	else return false;
}
//Funkcija koja prima vektor cijelih brojeva i logicku vrijednost, a vraca vektor cijelih brojeva koji su u ternarnom obliku simetricni i prosti za logicku vrijednost istina ili slozeni za logicku vrijednost neistina
Vektor IzdvojiSimetricneTernarne (Vektor v, bool prost)
{
    Vektor v1;
//Ako trazimo proste brojeve    
    if(prost)
    {
        for(int i=0; i<v.size(); i++)
//Ako je element vektora prost i simetrican u ternarnom obliku stavljamo ga na kraj novog vektora    
            if(DaLiJeProst(v.at(i)) && Simetrican((Ternarni(v.at(i)))) && v.at(i)!=1)v1.push_back(v.at(i));
    }
//Ako trazimo slozene brojeve    
    else if(!prost)
    {
        for(int i=0; i<v.size(); i++)
//Ako element vektora nije prost ali jeste simetrican u ternarnom obliku stavljamo ga na kraj novog vektora
            if(!DaLiJeProst(v.at(i)) && Simetrican((Ternarni(v.at(i)))) && v.at(i)!=1)v1.push_back(v.at(i));
    }
    return v1;  
}
//Funckija koja izbacuje ponavljajuce elemente iz finalnog vektora
Vektor IzbrisiPonavljajuce (Vektor v)
{  
    int n(v.size());
//U slucaju da primamo vektor nula    
    int nula(0);
    for(int i=0; i<n; i++)
    {
        if(v.at(i)==0)nula++;
    }
    if(nula==v.size()){
        v.resize(1);
        v.at(0)=0;
        return v;
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
//Ako se element ponavlja izbacujemo ga tako sto sve elemente poslije njega vracamo jedno mjesto unatrag i smanjujemo velicinu vektora za jedan element           
            if(v.at(i)==v.at(j))
            {
                for(int k=j; k<n-1; k++)
                    v.at(k)=v.at(k+1);
                n--;
//Da bi provjerili da li je element prepisan preko elementa koji se ponavlja takodjer element koji se ponavlja smanjujemo brojac za jedan                
                j--;
            }
        }
    }
    v.resize(n);
    return v;
}

int main ()
{
    std::cout << "Unesite elemente vektora (-1 za kraj): ";
    Vektor v;
    int n;
    do
    {
        std::cin >> n;
        if(n==-1)break;
        else v.push_back(n);
    }while(1);
    std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
    std::cin >> n;
    while(n!=1 && n!=0)
    {
            std::cout << "Neispravan unos! Unesite ponovo: ";
            std::cin >> n;
    }
    Vektor V(IzbrisiPonavljajuce(IzdvojiSimetricneTernarne(v,n)));
    if(n)
    {
    	if(V.size()==0)std::cout << "Nema prostih simetricnih brojeva u vektoru.";
    	else std::cout << "Prosti simetricni brojevi iz vektora su: ";
    }
    else 
    {
    	if(V.size()==0)std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
    	else std::cout << "Slozeni simetricni brojevi iz vektora su: ";
    }
    for(int i=0; i<V.size(); i++)
    {
        std::cout << V.at(i);
		if(i+1!=V.size())std::cout << ", ";
		else std::cout << "." << std::endl;
	}
    return 0;
}