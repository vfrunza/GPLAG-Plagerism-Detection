/*B 2017/2018, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<int> Vektor;

bool DaLiJeProst(int n)
{
	bool prost = 1;
	if (n == 2) return true;
	if (n < 2) return false;
	
	for (int i=2; i<= std::sqrt(n); i++)
	{
		if (n%i == 0)
		{
			prost = 1;
			break;
		}
	}
	if (prost) return true;
	else return false;
}

Vektor PrebaciUTernarni(Vektor v)
{
	Vektor prebacen;
	int decimalni(0), ternarni(0), potencija(1);
	for (int i = 0; i < v.size(); i++)
	{
		decimalni = v.at(i); std::cout << "decimalni: " << decimalni << " ";
		//ternarni = 0;
		
		while (decimalni != 0)
		{
			ternarni += (decimalni % 3) * potencija;
			potencija *= 10;
			decimalni /= 3;
		}
		std::cout << "ternarni: " << ternarni << " ";
		prebacen.push_back(ternarni);
		//std::cout << "decimalni: " << decimalni << " ";
	}
	//prebacen.push_back(ternarni);
	for (int i = prebacen.size() - 1; i>=0; i--)
	{
		prebacen.at(i);
	}
	
	return prebacen;
}
int PrebaciUTernarni (int n)
{
	int decimalni(n), ternarni(0), potencija(1);
	
	while (decimalni != 0)
		{
			ternarni += (decimalni % 3) * potencija;
			potencija *= 10;
			decimalni /= 3;
		}
		return ternarni;
}
Vektor Ternarni (Vektor v)
{
	Vektor prebacen;
	int nova;
	for (int i  = 0; i<v.size(); i++)
	{
		nova = PrebaciUTernarni(v.at(i));
		prebacen.push_back(nova);
	}
	return prebacen;
}
int ObrniBroj (int broj)
{
	int invert(0);
	while (broj != 0)
	{
		invert *= 10;
		invert += (broj % 10);
		broj /= 10;
	}
	return invert;
}

Vektor VektorSaObrnutimElementima (Vektor v)
{
	Vektor v1;
	int nova;
	for (int i = 0; i < v.size(); i++)
	{
		nova = ObrniBroj(v.at(i));
	}
	v1.push_back(nova);
	return v1;
}

int VratiUDekadni (int n)
{
	int decimalni(0), i(0), potencija;
	while (n != 0)
	{
		potencija = n % 10;
		n /= 10;
		decimalni += potencija * pow(3,i);
		++i;
	}
	return decimalni;
}

Vektor Back (Vektor v)
{
	Vektor nazad;
	for (int i = 0; i < v.size(); i++)
	{
		nazad.push_back(VratiUDekadni(v.at(i)));
	}
	return nazad;
}

Vektor Simetrican (Vektor v1, Vektor v2)
{
	Vektor simetrican;
	int sim1, sim2;
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			sim1 = v1.at(i); sim2 = v2.at(j);
			if (sim1 == sim2) simetrican.push_back(sim1);
		}
	}
	return simetrican;
}
bool Simetrican2 (Vektor v1, Vektor v2)
{
	Vektor simetrican;
	int sim1, sim2;
	bool sim(true);
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			sim1 = v1.at(i); sim2 = v2.at(j);
			if (sim1 == sim2) 
			{
				sim = true;
				simetrican.push_back(sim1);
			}
			else sim = false;
		}
	}
	if (sim) return true;
	else return false;
}

Vektor IzdvojiSimetricneTernarne (Vektor vekt_brojeva, bool t)
{
	Vektor ternarni, ternarni_obrnut, ternarni1, ternarni_obrnut1;
	Vektor vekt_prostih, sim_p, konacan;
	Vektor vekt_slozeni, sim_s, konacan1;
	bool kerim(true);
	int obrnut(0), kon(0), obrnut1(0), kon1(0);
	
	if (t == true) 
	{
		for (int i = 0; i<vekt_brojeva.size(); i++)
		{
			kerim = DaLiJeProst(vekt_brojeva.at(i));
			if (kerim) 
			{
				vekt_prostih.push_back(vekt_brojeva.at(i)); //prosti brojevi u vektoru
				ternarni = Ternarni(vekt_prostih);  //pretvaramo ih u ternarni
				
				for (int j = 0; j<ternarni.size(); j++)
				{
					obrnut = ObrniBroj(ternarni.at(j));
					//simetrcan = ternarni.at(j);
				}
				ternarni_obrnut.push_back(obrnut);
				//sim_p.push_back(simetrcan);
				
				/*for (int j = 0; j < sim_p.size(); j++)
				{
					if (obrnut != simetrcan)
					{
						sim_p.erase(sim_p.begin() );
					}
				}*/
			}
		}
				sim_p = Simetrican(ternarni, ternarni_obrnut);
				
				/*for (int j = 0; j < sim_p.size(); j++)
				{
					std::cout << "[" <<  j+1 << "] " << sim_p.at(j) << " ";
				} std::cout << std::endl;*/
				
				for (int j = 0; j < sim_p.size(); j++)
				{
					kon = VratiUDekadni(sim_p.at(j));
					konacan.push_back(kon);
				}
				//konacan.push_back(kon);
				
			
			//konacan.push_back(kon);
		
	}
	
	else
	{
		for (int i = 0; i<vekt_brojeva.size(); i++)
		{
			kerim = DaLiJeProst(vekt_brojeva.at(i));
			if (!kerim) 
			{
				vekt_slozeni.push_back(vekt_brojeva.at(i));
				ternarni1 = Ternarni(vekt_slozeni);
				
				 for (int j = 0; j<ternarni1.size(); j++)
                {
                    obrnut1 = ObrniBroj(ternarni1.at(j));
                    //simetrican1 = ternarni.at(j);
                }
                ternarni_obrnut1.push_back(obrnut1);
                //sim_s.push_back(simetrican1);

                /*for (int j = 0; j<sim_s.size(); j++)
                {
                    if (obrnut1 != simetrican1)
                    {
                            sim_s.erase(sim_s.begin());
                    }
                }*/
                
			}
		}
                
                sim_s = Simetrican(ternarni1, ternarni_obrnut1);
                for (int j = 0; j < sim_s.size(); j++)
				{
					std::cout << "[" <<  j+1 << "] " << sim_s.at(j) << " ";
				} std::cout << std::endl;
                
                for (int j = 0; j < sim_s.size(); j++)
                {
                    kon1 = VratiUDekadni(sim_s.at(j));
                    konacan1.push_back(kon1);
                }
			
		
	}
	
	if (t) return konacan;
	else return konacan1;
}

Vektor ProstIliSlozen (Vektor v)
{
	Vektor rez_p, rez_s; bool prost(true);
	for (int i = 0; i< v.size(); i++)
	{
	    if (DaLiJeProst(v.at(i))) { prost = true; rez_p.push_back(v.at(i));}
	    else {prost = false; rez_s.push_back(v.at(i));}
	    
	}
	if (prost) return rez_p;
	else return rez_s;
}

int main ()
{
	Vektor v, hana, mirela;
	std::cout << "Unesite elemente vektora (-1 za kraj): ";
	for (;;)
	{
		int n;
		std::cin >> n;
		if (n!=-1) v.push_back(n);
		else break;
	}
	
	int broj;
	std::cout << "Unesite: 1 - za proste brojeve, 0 - za slozene brojeve: ";
	std::cin >> broj;
	
	if (broj != 0 && broj != 1) 
	{
		std::cout << "Neispravan unos! Unesite ponovo: ";
		std::cin >> broj;
	}
	
	Vektor ter_ob, ter(Ternarni(v));
	int t_o;
	
	for (int i = 0; i < ter.size(); i++)
    {
        t_o = ObrniBroj(ter.at(i));
        ter_ob.push_back(t_o);
    }
    
    bool sim_brojevi(true);
    
    sim_brojevi = Simetrican2(ter, ter_ob);
   /* bool pro(true);
    for (int i = 0; i < v.size(); i++)
    {
    	pro = DaLiJeProst(v.at(i));
    }*/
    
    Vektor s_b = Simetrican(ter, ter_ob);
    
	if (broj == 1)
	{
		//for (int i = 0; i < v.size(); i++){
		//if (Ternarni(v) == VektorSaObrnutimElementima(v))
		//if (DaLiJeProst(v.at(i)))
		if (Simetrican2(ter, ter_ob))
		{
			//if (sim_brojevi){
			hana = IzdvojiSimetricneTernarne(v,true);
			std::cout << "Prosti simetricni brojevi iz vektora su: ";
			for (int i = 0; i < hana.size(); i++)
			{
				if (i == hana.size() - 1) std::cout << hana.at(i) << ".";
				else std::cout << hana.at(i) << ", ";
			}
		}  
		else
		{
			std::cout << "Nema prostih simetricnih brojeva u vektoru.";
			return 0;
		}
		//}
		//}
	}
	
	//Vektor s_T_t_d (Back(s_b)), p_i_s (ProstIliSlozen(v));
	
    if (broj == 0)
	{
		/*for (int i = 0; i < s_T_t_d.size(); i++)
			{
				std::cout << s_T_t_d.at(i) << " " << std::endl;;
			}*/
			//for(int i = 0; i < v.size(); i++){
		//if (Ternarni(v) == VektorSaObrnutimElementima(v))
		//if (DaLiJeProst(v.at(i)) == false)
		if (!Simetrican2(ter, ter_ob))
		{
			//if (Simetrican2(ter, ter_ob)){
			mirela = IzdvojiSimetricneTernarne(v,false);
			std::cout << "Slozeni simetricni brojevi iz vektora su: ";
			for (int i = 0; i < mirela.size(); i++)
			{
				if (i == mirela.size() - 1) std::cout << mirela.at(i) << ".";
				else std::cout << mirela.at(i) << ", ";
			}
		}
		else
		{
			std::cout << "Nema slozenih simetricnih brojeva u vektoru.";
			return 0;
		}
		//}
			//}
	}
	
	return 0;
}