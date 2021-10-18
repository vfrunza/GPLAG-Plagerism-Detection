/*B 2017/2018, Zadaća 1, Zadatak 2
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.

	Za sva ostala pitanja i nedoumice vezane za 
	autotestove javiti se na email: bcocalic1@etf.unsa.ba.	
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <stdexcept>

// ispitujem da li je to ta podmatrica
int saberi(std::vector<std::vector<double>> matrica,int a,int pom_i,int b,int pom_j,int duzina){
	int s(0);
	int najveci_clan(matrica.at(pom_i).at(pom_j));
	for(int i(a);i<a+duzina;i++){
		for(int j(b);j<b+duzina;j++){
			if(i!=pom_i && j!=pom_j) { s+=matrica.at(i).at(j);
		}
	}
	std::cout<<std::endl;
	}
	if(s<najveci_clan) return najveci_clan;
	return 0;
}

std::vector<std::vector<double>>NajvecaPlaninaMatrice(std::vector<std::vector<double>>m){
	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++){
			if(m.size()!=m[i].size()) throw std::domain_error ("Matrica nije korektna");
		}
	}

	for(int i=0;i<m.size();i++){
		for(int j=0;j<m[i].size();j++)
		if(m.size()==0 || m[i].size()==0)
		return std::vector<std::vector<double>>(0,std::vector<double>(0));
	}
	int suma(0),i,j,k,pom_j,pom_i,index_i,index_j,duzina(0);
	//Ove varijable cuvaju mi vrijednost ako je to planina koju sam trebala naci
	//pom_j -> cuva mi index "j" tj. kolonu odakle mi pocinje podmatrica u kojoj je suma clanova manja od srednjeg clana
	//pom_i -> cuva mi index "i" tj red odakle mi pocinje podmatrica u kojoj je suma clanova manja od srednjeg clana 
	//index_i -> cuva mi u kojem redu se nalazi srednji clan podmatrice 
	//index_j -> cuva mi u kojoj koloni se nalazi srednji clan podmatrice
	for(i=0;i<=m.size();i++){
		int index_i1,index_j1,pom_i1,pom_j1,suma_1(0);
		// a mi je pomocna varijabla da provjerim da li cu promijeniti duzinu podmatrice
		int a=(i%m.size());
		if(a%2==0){
			duzina=a;
			for(k=0;k<=m.size();k++){
				for(j=0;j<=m[0].size();j++){
					index_i1=(duzina/2)+k;
					index_j1=(duzina/2)+j;
					pom_i1=k;
					pom_j1=j;
				//	std::cout << index_i1 << " " << index_j1 << std::endl;
					// ove varijable su mi pomocne samo dok provjerim je li to ta podmatrica (da mogu sacuvati koja je to podmatrica)
					//m-> saljem citavu matricu
					//pom_i1-> saljem red odakle hocu da mi pocne provjeravanje podmatrice
					//index_i1-> saljem red u kojem ce se nalaziti sredisnji clan te podmatrice
					//pom_j1 -> saljem kolonu odakle hocu da mi pocne provjeravanje podmatrice
					//index_j1 -> saljem kolonu u kojoj se nalazi sredisnji clan te podmatrice
					//duzina-> saljem kolika mi je trenutna duzina i visina podmatrice
					if(duzina+pom_i1<m.size() && duzina+pom_j1<m.size()) suma_1=saberi(m,pom_i1,index_i1,pom_j1,index_j1,duzina);{
					if(suma_1>suma){
						suma=suma_1;
						index_i=index_i1;
						index_j=index_j1;
						pom_i=pom_i1;
						pom_j=pom_j1;
					}
					if(suma_1==suma){
						if(pom_i1<pom_i1) {
							suma=suma_1;
							index_i=index_i1;
							index_j=index_j1;
							pom_i=pom_i1;
							pom_j=pom_j1;
						}
						if(pom_i1==pom_i){
							if(pom_j1<pom_j){
								suma=suma_1;
								index_i=index_i1;
								index_j=index_j1;
								pom_i=pom_i1;
								pom_j=pom_j1;
							}
						}
					}
				
				}
			}
		}
		}
		else{
			for(j=0;j<m.size();j++){
				index_i1=(duzina/2)+i;
				index_j1=(duzina/2)+j;
				pom_i1=i;
				pom_j1=j;
			if(duzina+pom_i1<m.size() && duzina+pom_j1<m.size()) suma_1=saberi(m,pom_i1,index_i1,pom_j1,index_j1,duzina);{
				if(suma_1>suma){
					suma=suma_1;
					index_i=index_i1;
					index_j=index_j1;
					pom_i=pom_i1;
					pom_j=pom_j1;
				}
				if(suma_1==suma){
					if(pom_i1<pom_i){
						suma=suma_1;
						index_i=index_i1;
						index_j=index_j1;
						pom_i=pom_i1;
						pom_j=pom_j1;
					}
					if(pom_i1==pom_i){
						if(pom_j1<pom_j){
							suma=suma_1;
							index_i=index_i1;
							index_j=index_j1;
							pom_i=pom_i1;
							pom_j=pom_j1;
						}
					}
				}
			}
		}
			
	}
	}
//	std::cout<<duzina;
	// sacuvam od koje mi kolone pocinje, jer cu dok popunjavala kolone morat pomjerat j i onda bi bio problem kad predem u drugi red
	int pom_j1(pom_j);
	// formiram matricu koju cu vratiti kao rezultat
	std::vector<std::vector<double>>vrh_planine(duzina,std::vector<double>(duzina));
	for(int p(0);p<vrh_planine.size();p++){
		pom_j=pom_j1;
		for(int q(0);q<vrh_planine[p].size();q++){
			vrh_planine.at(p).at(q)=m.at(pom_i).at(pom_j);
			pom_j++;	
		}
		pom_i++;
	}
	return vrh_planine;
}

int main ()
{ 
	try{
	std::cout<<"Unesite dimenzije matrice (m i n): ";
	int m,n;
	std::cin>>m>>n;
	if(m<0 || n<0){
		std::cout<<"Dimenzije matrice moraju biti nenegativne!";
	return 0;
	}
	std::vector<std::vector<double>>mat(m,std::vector<double>(n));
	std::cout<<"Unesite elemente matrice:"<<std::endl;
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++) std::cin>>mat[i][j];
	}
	
	auto planina(NajvecaPlaninaMatrice(mat));
	std::cout<<"Najveca planina unesene matrice je: "<<std::endl;
	for(int i(0);i<planina.size();i++){
		for(int j(0);j<planina[i].size();j++){
			std::cout<<std::setw(6)<<planina[i][j];
		}
		std::cout<<std::endl;
	}
	
	}
	catch(std::domain_error izuzetak){
		std::cout<<izuzetak.what() <<std::endl;
	}
	return 0;
}  


