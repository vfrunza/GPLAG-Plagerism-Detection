#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <new>


int PotencijalniKrivci(char **&a, std::vector<std::string> b){
	char **pok {new char*[int( b.size() ) ] };
	a=pok;
	for(int i=0; i<int(b.size()) ;i++) pok[i]=nullptr;
	int broj_krivaca(0);
	try{
		for(int i=0; i<int(b.size()) ;i++){
			if(b[i].length() == 0) continue;
			pok[i]=new char[int(b[i].size()) + 1];
			broj_krivaca++;
		}
		for(int i=0; i< int(b.size()) ; i++){
			if(b[i].length() == 0) continue;
			for(int j=0; j< int(b[i].size()) ; j++){
				pok[i][j]=b[i][j];
			}
			pok[i][int(b[i].size())]='\0';
		}
		a=pok;
		return broj_krivaca;
	}
	catch(std::bad_alloc){
		for(int i=0; i<broj_krivaca;i++) delete [] pok[i];
		delete []pok;
		throw;
	}
}
int OdbaciOptuzbu(char **&a, int n, std::string c){
	char **x(a);
	for(int i = 0; i < n; i++){
		int j = 0;
		while(*x[i]!='\0'){
			if(x[i][j]!=c[j])break;
			j++;
			if(j == int(c.size())){
				delete [] a[i];
				a[i] = nullptr;
				int brojac(0);
				for(int k = 0;k<n;k++){
					if(a[k]==nullptr)brojac++;
				}
				if(brojac > 10){
					char **novi{ new char *[n-brojac]};
					for(int b=0; b<n - brojac;b++) novi[b]=nullptr;
					try{
						int z(0);
						for(int k = 0; k < n; k++){
							if(a[k]!=nullptr){
								novi[z++]=a[k];
							}
						}
						delete [] a;
						a = novi;
						return n - brojac;
					}
					catch(std::bad_alloc){
						for(int b=0; b<n - brojac;b++) delete[] novi[b];
						delete []novi;
					}
				}else{
					return n;
				}
			}
		}
	}
	throw std::domain_error("Osoba sa imenom " + c + " nije bila optuzena");
}

int DodajOptuzbu(char **&a, int n, std::string c){
	if(c.length() == 0) return n;
	char **x = a;
	for(int i = 0; i < n; i++){
		if(x[i] == nullptr){
		  try{
			a[i] = new char [int(c.size())+1];
			for(int j = 0; j < int(c.size());j++){
				a[i][j] = c[j];
			}
			a[i][int(c.size())] = '\0';
		  }catch(std::bad_alloc){
		  	return n;	
		  }
		  return n;
		}
	}
	char **novi{new char *[n+1]};
	for(int b=0; b < n+1;b++) novi[b]=nullptr;
	//try{
		try{
			novi[n] = new char [int(c.size())+1];
			for(int j = 0; j < int(c.size());j++){
				novi[n][j] = c[j];
			}
			novi[n][int(c.size())] = '\0';
		  }catch(std::bad_alloc){
		  	delete [] novi;
		  	return n;	
		  }
		for(int k = 0; k < n; k++){
			novi[k]=a[k];
		}		  
		delete [] a;
		a = novi;
		return n + 1;
//	}
//		catch(std::bad_alloc){
	//	delete [] novi;
	//}
	// return n;
}

void IzlistajOptuzbu(char **a, int n){
	for(int i = 0; i < n; i++){
		if(a[i]!=nullptr){
			int neko_ko_broji(0);
			while(*a[i]!='\0'){
				std::cout << char(*a[i]);
				a[i]++;
				neko_ko_broji++;
			}
			std::cout << std::endl;
			for(int w = 0; w<neko_ko_broji ; w++) a[i]--;
		}
	}
}

int main ()
{
	int n;
	std::cout << "Koliko potencijalnih krivaca zelite unijeti? " << std::endl;
	std::cin >> n;
	std::cin.ignore(10000,'\n');
	std::cin.clear();
	std::cout << "Unesite potencijalne krivce: "<< std::endl;
	std::vector<std::string> b;
	for(int i=0; i<n; i++){
		std::string a;
		std::getline(std::cin, a);
		b.push_back(a);
	}
	int y ;
	char** x;
	try{
	y = PotencijalniKrivci(x, b);
	int a;
	std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<< std::endl;
	while(std::cin>>a , a!=0){
		if(a==3) IzlistajOptuzbu(x,y);
		else if(a==2 || a==1){
			std::string u;
			if(a==2){
				std::cin.ignore(10000,'\n');
				std::cout << "Unesite ime koje zelite izbaciti: " << std::endl;
				std::getline(std::cin, u);
				try{
				y=OdbaciOptuzbu(x,y,u);	
				}catch(std::domain_error izuzetak){std::cout<< izuzetak.what() << std::endl;}
				
			}
			else{
				std::cin.ignore(10000,'\n');
				std::cout << "Unesite ime novog optuzenog: " << std::endl;
				std::getline(std::cin, u);
				try{
				y=DodajOptuzbu(x,y,u);	
				}catch(std::bad_alloc){};
				
				
			}
			
		}
		std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: "<< std::endl;
	}
	for(int i=0; i<y ; i++) delete [] x[i];
	delete [] x;
	}
	catch(std::bad_alloc){
		return 0;
	}
	
	return 0;
}
