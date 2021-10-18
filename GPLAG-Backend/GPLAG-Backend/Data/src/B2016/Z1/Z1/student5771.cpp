/*B 2016/2017, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.

*/
#include<iostream>
#include<cmath>
#include<vector>
std::vector<int> IzdvojiGadne(std::vector<int> niz, bool istinitost)
{
	std::vector<int> c;
	/*izbaci clanove duple*/
	int d=niz.size();
	for(int j=0; j<niz.size(); j++) {
		int b=niz[j];
		for(int i=j+1; i<niz.size(); i++) {
			if(niz[i]==b) {
				for(int k=i; k<niz.size()-1; k++)niz[k]=niz[k+1];
				i--;
				d--;
			}
			niz.resize(d);
		}

	}
	/*trazi terarni zapis*/
	for(int i=0; i<niz.size(); i++) {
		int zapis1=0, zapis2=0, zapis0=0;
		/*ukoliko se unese prevelik broj incijalizacija na long long*/
		long long int pomoc1= std::abs((long long int)(niz[i]));
		long long int pomoc=pomoc1%3;
		while(pomoc1>0) {
			if(pomoc==1)zapis1++;
			if(pomoc==2)zapis2++;
			if(pomoc==0)zapis0++;
			pomoc1=pomoc1/3;
			pomoc=pomoc1%3;
		}
		/*uslovi */
		if(zapis1!=0 && zapis2!=0 && zapis0!=0) {
			if(zapis1%2==0 && zapis2%2==0 && zapis0%2==0 && istinitost==true)c.push_back(niz[i]);
			if(zapis1%2==1 && zapis2%2==1 && zapis0%2==1 && istinitost==false)c.push_back(niz[i]);
		}

		if(zapis1==0 && zapis2!=0 && zapis0!=0) {
			if(zapis2%2==0 && zapis0%2==0 && istinitost==true)c.push_back(niz[i]);
			if(zapis2%2==1 && zapis0%2==1 && istinitost==false)c.push_back(niz[i]);
		}

		if(zapis1!=0 && zapis2==0 && zapis0!=0) {
			if(zapis1%2==0 && zapis0%2==0 && istinitost==true)c.push_back(niz[i]);
			if(zapis1%2==1 && zapis0%2==1 && istinitost==false)c.push_back(niz[i]);
		}

		if(zapis1!=0 && zapis2!=0 && zapis0==0) {
			if(zapis1%2==0 && zapis2%2==0 && istinitost==true)c.push_back(niz[i]);
			if(zapis1%2==1 && zapis2%2==1 && istinitost==false)c.push_back(niz[i]);
		}

		if(zapis1==0 && zapis2==0 && zapis0!=0) {
			if(zapis0%2==0 && istinitost==true)c.push_back(niz[i]);
			if(zapis0%2==1 && istinitost==false)c.push_back(niz[i]);
		}

		if(zapis1==0 && zapis2!=0 && zapis0==0) {
			if( zapis2%2==0 && istinitost==true)c.push_back(niz[i]);
			if( zapis2%2==1 && istinitost==false)c.push_back(niz[i]);
		}

		if(zapis1!=0 && zapis2==0 && zapis0==0) {
			if(zapis1%2==0 && istinitost==true)c.push_back(niz[i]);
			if(zapis1%2==1 && istinitost==false)c.push_back(niz[i]);
		}
/*uslov za nulu*/
		if(zapis1==0 && zapis2==0 && zapis0==0) {
			if(istinitost==false)c.push_back(niz[i]);
		}
	}
	return c;
}
int main ()
{
	std::vector<int> niz;
	int broj;
	/*unos brojeva u vektor*/
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	do {
		std::cin>>broj;
		if(broj!=0)niz.push_back(broj);
	} while(broj!=0);
	/*poziv fje*/
	std::vector <int> c=IzdvojiGadne(niz,true);
	std::cout<<"Opaki: ";
	int i=0;
	/*ispis opakih*/
	while(i<c.size()) {
		std::cout<<c[i]<<" ";
		i++;
	}
	std::vector<int> b=IzdvojiGadne(niz,false);
	std::cout<<std::endl;
	/*ispis odvratnih*/
	std::cout<<"Odvratni: ";
	i=0;
	while(i<b.size()) {
		std::cout<<b[i]<<" ";
		i++;
	}
	return 0;
}