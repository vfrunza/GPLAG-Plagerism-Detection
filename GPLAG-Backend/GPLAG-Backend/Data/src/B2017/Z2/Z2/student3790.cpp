#include <iostream>
#include<vector>
#include<stdexcept>
#include<deque>
#include<iomanip>
enum SmjerKretanja {NaprijedNazad,NazadNaprijed,GoreDolje,DoljeGore,LijevoDesno,DesnoLijevo};
template<typename kont>
kont PjescaniSat(kont k,enum SmjerKretanja s)
{
	kont p;

	for(int b=0; b<k.size(); b++) {
		for(int g=0; g<k.at(b).size(); g++) {
			if(k.at(b).at(g).size()!=k.at(b).size() or k.size()!=k.at(b).size()) throw std::domain_error("3D matrica nema oblik kocke");
		}
	}
	for(int b=0; b<k.size(); b++) {
		if(k.at(b).size()%2==0) throw std::length_error("3D kontejner ne zadovoljava uvjet neparnosti");
	}
	p.resize(k.size());
	for(int z=0; z<p.size(); z++) {
		p.at(z).resize(p.size());


	}

	switch (s) {

	case GoreDolje:

		for(int i=0; i<k.size(); i++) {

		
			int f=0;
			for(int j=0; j<k.size()/2+1; j++) {

				for(int l=0+f; l<k.size()-f; l++) {

					p.at(i).at(j).push_back(k.at(i).at(j).at(l));
				}
				f++;

			}
			
			for(int j=k.size()/2; j<k.size(); j++) {

				f--;
				for(int l=0+f; l<k.size()-f; l++) {
				if(j!=k.size()/2){
					p.at(i).at(j).push_back(k.at(i).at(j).at(l));}
					
					
				}
				
			}

		}
		break;
		case DoljeGore:
		for(int i=0; i<k.size(); i++) {

		
			int f=0;
			int r=0;
			for(int j=k.size()-1; j>k.size()/2-1; j--) {

				for(int l=0+f; l<k.size()-f; l++) {

					p.at(i).at(r).push_back(k.at(i).at(j).at(l));
				}
				f++;
                r++;
			}
			r--;
			
			for(int j=k.size()/2; j>=0; j--) {

				f--;
				for(int l=0+f; l<k.size()-f; l++) {
				if(j!=k.size()/2){
					p.at(i).at(r).push_back(k.at(i).at(j).at(l));}
					
					
				}
				r++;
				
			}

		}
		break;
		case LijevoDesno:
		for(int i=0; i<k.size(); i++) {

		
			int f=0;
			for(int j=0; j<k.size()/2+1; j++) {

				for(int l=0+f; l<k.size()-f; l++) {

					p.at(i).at(j).push_back(k.at(i).at(l).at(j));
				}
				f++;

			}
			
			for(int j=k.size()/2; j<k.size(); j++) {

				f--;
				for(int l=0+f; l<k.size()-f; l++) {
				if(j!=k.size()/2){
					p.at(i).at(j).push_back(k.at(i).at(l).at(j));}
					
					
				}
				
			}

		}
		break;
		case DesnoLijevo:
		for(int i=0; i<k.size(); i++) {

		
			int f=0;
			int r=0;
			for(int j=k.size()-1; j>k.size()/2-1; j--) {

				for(int l=0+f; l<k.size()-f; l++) {

					p.at(i).at(r).push_back(k.at(i).at(l).at(j));
				}
				f++;
                r++;
			}
			r--;
			
			for(int j=k.size()/2; j>=0; j--) {

				f--;
				for(int l=0+f; l<k.size()-f; l++) {
				if(j!=k.size()/2){
					p.at(i).at(r).push_back(k.at(i).at(l).at(j));}
					
					
				}
				r++;
				
			}

		}
		break;
		case NaprijedNazad:
		
       for(int i=0;i<k.size();i++)
       {
       	int f=0;
       	for(int m=0; m<k.size()/2+1; m++) {
       	for(int j=0+f;j<k.size()-f;j++)
       	{
       		
       		p.at(i).at(m).push_back(k.at(m).at(i).at(j));
       	}
       	f++;
       	}
       	for(int m=k.size()/2;m<k.size();m++)
       	{
       		f--;
       		for(int j=0+f;j<k.size()-f;j++)
       	{
       		if(m!=k.size()/2) p.at(i).at(m).push_back(k.at(m).at(i).at(j));
       	}
       	}
       }
       break;
       case NazadNaprijed:
       
        for(int i=k.size()-1;i>=0;i--)
       {
       	int e=k.size()-1;
       	int f=0;
       	for(int m=0; m<k.size()/2+1; m++) {
       	for(int j=0+f;j<k.size()-f;j++)
       	{
       		
       		p.at(i).at(e).push_back(k.at(m).at(i).at(j));
       	}
       	f++;
       	e--;
       	}
       	e++;
       	for(int m=k.size()/2;m<k.size();m++)
       	{
       		f--;
       		for(int j=0+f;j<k.size()-f;j++)
       	{
       		if(m!=k.size()/2) p.at(i).at(e).push_back(k.at(m).at(i).at(j));
       	}
       	e--;
       	}
       	
       	
       }
       break;
		

	}

	return p;
}
int main ()
{

	std::cout<<"Unesite dimenziju (x/y/z): ";
	int u=0;
	int x;
	do {
		if(u!=0) std::cout<<"Dimenzija nije ispravna, unesite opet: ";
		std::cin>>x;
		u++;
	} while(x<0);

	std::vector<std::deque<std::deque<int>>> k(x,std::deque<std::deque<int>> (x,std::deque<int>(x))),p;
	std::cout<<"Unesite elemente kontejnera: ";
	for(int i=0; i<x; i++) {

		for(int j=0; j<x; j++) {

			for(int r=0; r<x; r++) {
				int c=0;
				std::cin>>c;
				k.at(i).at(j).at(r)=c;
			}
		}
	}
	std::cout<<"Unesite smjer kretanja [0 - 5]:";
	int s=0,o=0;
	do {
		if(o!=0) std::cout<<" Smjer nije ispravan, unesite opet: ";
		std::cin>>s;
		o++;
	} while(s>5 or s<0);
	try {
		switch (s) {
		case 0:
			p=PjescaniSat(k,SmjerKretanja::NaprijedNazad);
			break;
		case 1:
			p=PjescaniSat(k,SmjerKretanja::NazadNaprijed);
			break;
		case 2:
			p=PjescaniSat(k,SmjerKretanja::GoreDolje);
			break;
		case 3:
			p=PjescaniSat(k,SmjerKretanja::DoljeGore);
			break;
		case 4:
			p=PjescaniSat(k,LijevoDesno);
			break;
		case 5:
			p=PjescaniSat(k,DesnoLijevo);
			break;


		}
		std::cout<<"\nPjescani sat unesene matrice je:\n\n";

		for(int a=0; a<p.size(); a++) {
			for(int b=0; b<p.at(a).size()/2+1; b++) {
				for(int d=0; d<b; d++) std::cout<<std::setw(4)<<" ";
				for(int c=0; c<p.at(a).at(b).size(); c++) {
					std::cout<<std::setw(4)<<p.at(a).at(b).at(c);
				}
				//for(int d=0; d<b; d++) std::cout<<std::setw(4)<<" ";
				std::cout<<std::endl;
			}
			for(int b=p.at(a).size()/2+1; b<p.at(a).size(); b++) {
				for(int d=0; d<p.at(a).size()-b-1; d++) std::cout<<std::setw(4)<<" ";
				for(int c=0; c<p.at(a).at(b).size(); c++) {
					std::cout<<std::setw(4)<<p.at(a).at(b).at(c);
				}
				//for(int d=0; d<p.at(a).size()-b-1; d++) std::cout<<std::setw(4)<<" ";
				std::cout<<std::endl;
			}
			std::cout<<std::endl;

		}
	} catch(const std::exception& a) {
		std::cout<<"\nIzuzetak: "<<a.what();
	}
	return 0;
}