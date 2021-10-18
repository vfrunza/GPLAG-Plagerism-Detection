/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>
#include <limits>

std::vector<int> PretvoriBrojUBazuTri(int n){ // negativni brojevi nece radit pom s minus 1 pa radit pa ponovo na krauju pomnozit minus 1 da bude neg
	std::vector<int> PretvorenBroj;
	if(n<0) n*=-1;
	int broj=1, cifra=0, brojac=0;
	for(;;){
		if(broj*3>n || broj>std::numeric_limits<int>::max()/3)break;
		broj*=3;
		brojac++;
		
	}
	for (int i=0; i<=brojac; i++){
	    for(;;){
		    if(n-broj<0)break;
		    n-=broj;
		    cifra++;
	    }
	    PretvorenBroj.push_back(cifra);
	    broj/=3;
	    cifra=0;
	}
	//if (NegativanJe) PretvorenBroj[0]*=(-1); // prvi element vektora ce nositi znak broja
	return PretvorenBroj; // vraca vektor koji sadrzi cifre broja n u ternarnom brojnom sistemu
}
std::vector<int> IzdvojiGadne(std::vector<int> a, bool b){
	std::vector<int> c;
	std::vector<int> duplikati;
    for (int i=0; i<a.size(); i++){
    	std::vector<int> d(PretvoriBrojUBazuTri(a[i]));
    	int parno(0), neparno(0);
    	std::vector<int> VecTestiraneCifre(10, 0);
    	for (int j=0; j<d.size(); j++){
    	    if(VecTestiraneCifre[d[j]]==1)continue;
    		int brojac(1);
    		for(int z=j+1; z<d.size(); z++){
    			//std::cout << "Poredi d-j i d-z.. d[j]=" << d[j] << " i d[z]= " << d[z] << std::endl;
    			if(d[j]==d[z])brojac++;
    		}
    		//std::cout << "brojac= " << brojac << std::endl;
    		if(brojac%2==0 && brojac!=0)parno++;
    		else neparno++;
    		VecTestiraneCifre[d[j]]=1;
    	}
    	//std::cout << "parno= " << parno << " neparno= " << neparno << std::endl;
    	int VecImaTajBroj=0;
    	for (int x=0; x<duplikati.size(); x++){
    		if(a[i]==duplikati[x])VecImaTajBroj=1;
    	}
    	if(b==true && neparno==0 && VecImaTajBroj==0){
    		c.push_back(a[i]);
    		duplikati.push_back(a[i]);
    	}
    	if(b==false && parno==0 && VecImaTajBroj==0){
    		c.push_back(a[i]);
    		duplikati.push_back(a[i]);
    	}
    }

    return c;
} 

int main ()
{
	int n;
	std::vector<int> a;
	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	for(;;){
		std::cin >> n;
		if(n!=0) a.push_back(n);
		else break;
		 /*
		std::vector<int> d(PretvoriBrojUBazuTri(n));
		std::cout << n << " u bazi tri je ";
		for(int j=0; j<d.size(); j++)std::cout << d[j]; 
		std::cout << std::endl;
		 */
	}
	std::vector<int> b(IzdvojiGadne(a, true));// ovo true sam nasumicno jer nije definisano ovako da korisnik unosi
//	std::cout << "Velicina b.size je " << b.size() << std::endl;
    std::cout << "Opaki: ";
	for (int i=0; i<b.size(); i++){
		std::cout << b[i] << " ";
	}
	b=IzdvojiGadne(a, false);
	std::cout << std::endl << "Odvratni: ";
	for (int i=0; i<b.size(); i++){
		std::cout << b[i] << " ";
	}
	return 0;
}