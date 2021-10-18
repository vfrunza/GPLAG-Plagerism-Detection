#include <iostream>
#include <new>
#include <string>
#include <vector>
#include <stdexcept>


int PotencijalniKrivci (char **&lista,std::vector<std::string>imena)
{
	int brojac(0);
	int n(imena.size());
	int min=0;
// svaki m je drugaciji
	char **pokazivac(new char *[n]);
	int q(0);
	try {


		for (int i=0; i<n; i++) {
			q=imena[i].length()+1; // +1 je \0
			pokazivac[i]=new char[q];
			q=0;
			brojac++;
		}
		lista=pokazivac;

		for (int i=0; i<n; i++) {
			for (int j=0; j<imena[i].length(); j++) {
				lista[i][j]=imena[i][j];
			}
		}
	} catch(std::bad_alloc izuzetak) {
		for (int i=0; i<n; i++) {
			delete[] pokazivac[i];
		}
		delete [] pokazivac;

		throw;   // u mainu hvatamo
	}

	return brojac;
}
// za sad okic



int OdbaciOptuzbu (char **&lista_imena, int n, std::string imena)
{
	try {
		int	brojac(0);
		int red(0);
		int q(0);



		char**lista(new char*[n]);


		for (int i=0; i<=n; i++) {
			if (imena.compare(lista[i])==0) {
				q++;
				red=i;
			}

		}
		if (q==0) throw std::domain_error (" nije bila optuzena");

	
	// pretpostavimo da smo nasli red

	delete [] lista[red]; // obrisi red
	lista[red]=nullptr; // nije obrisan pokazivac

	for (int i=0; i<n; i++) {
		if (lista[i]==nullptr)
			brojac++;  // broji izbacene
	}
	int novi(0);

	if (brojac<10) return (n-brojac);

	if (brojac>10) {
		char **nova_lista (new char*[n-brojac]); // POPRAVITI !!
		for (int i=0; i<n; i++) {
			if (*lista[i]) {
				novi++;
				for(int j=0; j<n; j++) {
					nova_lista[i][j]=lista[i][j];
				}
			}
		}

		for (int i=0; i<n; i++) {
			delete[]lista[i];

		}
		delete [] lista;

		lista_imena=nova_lista;
		return novi;
	}
}
catch(std::domain_error izuzetak)
{
	std::cout << "Osoba sa imenom ";
	for (int i=0; i<imena.length(); i++) {
		std::cout << imena[i];
	}

	std::cout << izuzetak.what();
}
}

int DodajOptuzbu (char **&lista_imena, int n, std::string ime)
{
	int duzina (ime.length()+1); // + \0
	int brojac(0);

	lista_imena[n+1]=new char [duzina];
	for (int i=n+1; i<n+2; i++) {
		for (int j=0; j<duzina; j++) {
			lista_imena[i][j]=ime[j];
		}
	}
	int w(0);

	for (int i=0; i<n; i++) {
		if (lista_imena[i]==nullptr) {
			w++;
			lista_imena[i]=lista_imena[n+1];
		}

	}


	if (w==0) {
		char **pokazivac (new char* [n+1]);
		for (int i=0; i<n+1; i++) {
			pokazivac[i]=lista_imena[i];
			brojac++;

		}
		pokazivac[n+1]=lista_imena[n+1];


		for (int j=0; j<n; j++) {
			delete []lista_imena[j];
		}
		delete []lista_imena;
		lista_imena=pokazivac; // NIJE TACNO !!!!!! ISPRAVITI !!!!!!!!!!!!!!!!!!!!!!!!!
		return (brojac+1);
	}
	if (w!=0) return (n+1); // samo smo dodali jedno ime jer nije bilo nul pokazivača
}

void IzlistajOptuzbu (char **lista, int n)
{
	for (int i=0; i<n; i++) {
		if (lista[i]==nullptr) continue;
		else std::cout << lista[i] << std::endl;
	}
}
int main ()
{
	int broj;
	char ime[500];

	std::cout << "Koliko potencijalnih krivaca zelite unijeti ? ";
	std::cin >> broj;
	
	std::cout << "Unesite potencijalne krivce: ";
	char ** imena(new char *[broj]);
	
   
    for (int i=0;i<broj;i++)
    { std::string im;
      for (;;)
      {
      	std::getline(std::cin,im);
      	if (std::cin.peek()=='\n') break;
      }
    
    int m(4) ; // ispraviti
    
    	imena[i]=new char[m];
    
    
    // ubaciti im u imena
    
     for (int k=0;i<m;k++)
     {
     	*(imena[i][k])=im[k];
     }
    
    }

	int opcija;
	std::cout << "Odaberite opciju: 1 za unos novog optuzenog, 2 za brisanje nekog optuzenog 3 za izlistavanje optuzenih, 0 za kraj: ";
	std::cin >> opcija;

	if (opcija==1) {
		std::cout << "Unesite ime novog optuzenog: ";

   	std::cin.getline(ime,sizeof ime,'\n');

		DodajOptuzbu(imena,broj,ime);
	}
/*	if (opcija==2) {
		std::cout << "Unesite ime koje zelite izbaciti:";
		for (;;) {
			std::getline(std::cin,ime);
			if (std::cin.peek()=='\n') break;
		}
		OdbaciOptuzbu(imena,broj,ime);

	}
	if (opcija==3) {
		IzlistajOptuzbu(imena,broj);
	}

	if (opcija==0) return 0;


*/

	return 0;
}