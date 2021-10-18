/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>


std::vector<int> IzdvojiGadne(std::vector<int> br, bool a) {
//	if (a);
	//izbaci duple
	for (int i=0; i<br.size()-1; i++) {
      for (int j=i+1; j<br.size(); j++) {
         if (br[i] == br[j]) {
            for (int z=j; z<br.size()-1; z++) {
               br[z] = br[z+1];
            }
            br.resize(br.size()-1);
            i--;
            j--;
         }
       }
   }
   
   std::vector<int> c(br);
   //pretvori u brojevni sa bazom tri
   std::vector<std::vector<int>> bin(br.size());
   for (int i=0; i<br.size(); i++) {
   	//	std::vector<int> tmp;
   		do {
   			bin[i].push_back(br[i]%3);
   			br[i]/=3;
   		} while(br[i]!=0);
   	
   }
   
   //obrtanje elemenata
   for (int i=0; i<bin.size(); i++) {
   	for (int j=0; j<bin[i].size()/2; j++) {
   		int temp(bin[i][j]);
   		bin[i][j]= bin[i][bin[i].size()-j-1];
   		bin[i][bin[i].size()-j-1]=temp;
   	}
   }
   
   //analiza
   int s(0);
   for (int i=0; i<bin.size(); i++) {
   	int z0=0;
   	int z1=0;
   	int z2(0);
   	for (int j=0; j<bin[i].size(); j++) {
   		if (bin[i][j]==0) z0++;
   		else if (bin[i][j]==1) z1++;
   		else if (bin[i][j]==2) z2++;
   	}
   	//parni opaki ... izbacivanje
   	if (z0%2==0 && z1%2==0 && z2%2==0) {
   		if (a==false) {
   			for (int z=i-s; z<c.size()-1; z++) {
   				c[z]=c[z+1];
   			}
   			s++;
	   		c.resize(c.size()-1);
	   		z0=0;
	   		z1=0;
	   		z2=0;
   		}
   		
   	}
   	//neparni odvratni ... izbacivanje
   	else if ( (z0%2==1 && z1%2==1 && z2%2==1) || //svi su neparni
   				
   				(z0==0 && z1%2==1 && z2%2==1) ||	//jedan je nula, a ostali su neparni
   				(z1 == 0 && z0%2==1 && z2%2==1) ||
   				(z2 == 0 && z0%2==1 && z1%2==1) ||
   				
   				(z0 == 0 && z1 == 0 && z2%2==1) || //dva su nula jedan neparan
   				(z0 == 0 && z2 == 0 && z1%2==1) ||
   				(z1 == 0 && z2 == 0 && z0%2==1) ) {
   					if (a) {
   						for (int z=i-s; z<c.size(); z++) {
		   				c[z]=c[z+1];
			   			}
			   			s++;
				   		c.resize(c.size()-1);
				   		z0=0;
				   		z1=0;
				   		z2=0;
	   					}
   				}
   	else {
   		for (int z=i-s; z<c.size()-1; z++) {
		   				c[z]=c[z+1];
			   			}
			   			s++;
				   		c.resize(c.size()-1);
				   		z0=0;
				   		z1=0;
				   		z2=0;
   	}
   }
   
   return c;
}

int main ()
{	
	//std::cout<< "Unesi br elemenata: ";
//	int n;
//	std::cin>>n;					
	std::cout<< "Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> e;
/*	for (int i=0; i<n; i++) {
		int c;
		std::cin>> c;
		e.push_back(c);
	}*/
	int c;
	std::cin >> c;
	while (c!=0){
	//	int c;
		e.push_back(c);
		std::cin >> c;
	
	}
	std::vector<int> o;
	std::cout<< "Opaki: ";
	o=IzdvojiGadne(e, true);
	for (int i=0; i<o.size(); i++) {
		std::cout << o[i] << " ";
	}
	
	std::cout<< std::endl<<"Odvratni: ";
	o=IzdvojiGadne(e, false);
	for (int i=0; i<o.size(); i++) {
		std::cout << o[i] << " ";
	}
	return 0;
}