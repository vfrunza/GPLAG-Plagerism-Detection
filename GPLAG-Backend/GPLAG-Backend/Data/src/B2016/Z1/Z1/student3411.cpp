/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
#include <iostream>
#include <vector>

std::vector<int> IzdvojiGadne(std::vector<int> v, bool istina){
	if(istina){
		std::vector<int>opaki;
		for(int i=0; i<v.size(); i++){
			std::vector<int>pozitivni(3);
			std::vector<int>negativni(3);
			int broj=v[i];
			if(broj!=0){
				//while-petlja za brojanje ponavljanja cifara ako je broj pozitivan
				while(broj>0){
					pozitivni[broj%3]++;
					broj=broj/3;
				}
				//while-petlja za brojanje ponavljanja cifara ako je broj negativan
				while(broj<0){
					negativni[-1*(broj%3)]++;
					broj=broj/3;
				}
			}
			else pozitivni[broj]++;
			//if-uslov koji ispituje da li za nenegativan broj njegove cifre zadovoljavaju uslov opakog broja
			if((pozitivni[0]!=0 || pozitivni[1]!=0 || pozitivni[2]!=0) && (pozitivni[0]%2==0 && pozitivni[1]%2==0 && pozitivni[2]%2==0)){
				//provjera da li se ovaj broj vec nalazi u nizu izdvojenih opakih brojeva
				bool ponavlja_se=false;
				for(int j=0; j<opaki.size(); j++){
					if(v[i]==opaki[j]) {
						ponavlja_se=true;
						break;
					}
				}
				//ako se ne nalazi, spremamo ga u niz, ako se vec nalazi nista se ne desava
				if(ponavlja_se==false) opaki.push_back(v[i]);
			}
			//blok naredbi koji ispituje iste stvari za negativne brojeve
			if((negativni[0]!=0 || negativni[1]!=0 || negativni[2]!=0) && (negativni[0]%2==0 && negativni[1]%2==0 && negativni[2]%2==0)){
				bool ponavlja_se=false;
				for(int j=0; j<opaki.size(); j++){
					if(v[i]==opaki[j]) {
						ponavlja_se=true;
						break;
					}
				}
				if(ponavlja_se==false) opaki.push_back(v[i]);
			}
			
		}
		return opaki;
	}
	//blok naredbi koji se izvrsava ukoliko je poslan parametar "false" tj. ako se traze odvratni brojevi
	//skoro pa identican bloku naredbi koji se izvrsava za parametar "true"
	//jedina razlika u if uslovu ispitivanja da li je broj ponavljanja neparan(a ne paran kao u prethodnom slucaju)
	else{
		std::vector<int> odvratni;
		for(int i=0; i<v.size(); i++){
			std::vector<int> pozitivni(3);
			std::vector<int> negativni(3);
			int broj=v[i];
			if(broj!=0){
				//while petlja za brojanje ponavljanja cifara ako je broj pozitivan
				while(broj>0){
					pozitivni[broj%3]++;
					broj=broj/3;
				}
				//while petlja za brojanje ponavljanja cifara ako je broj negativan
				while(broj<0){
					negativni[-1*(broj%3)]++;
					broj=broj/3;
				}
			}
			else pozitivni[broj]++;
			//if-uslov koji ispituje da li za nenegativan broj njegove cifre zadovoljavaju uslov odvratnog broja
			if(v[i]>=0 && (pozitivni[0]%2==1 || pozitivni[0]==0) && (pozitivni[1]%2==1 || pozitivni[1]==0) && (pozitivni[2]%2==1 || pozitivni[2]==0)){
				//provjera da li se ovaj broj vec nalazi u nizu izdvojenih odvratnih brojeva
				bool nalazi_se=false;
				for(int j=0; j<odvratni.size(); j++){
					if(v[i]==odvratni[j]) {
						nalazi_se=true;
						break;
					}
				}
				//ako se ne nalazi, spremamo ga u niz, ako se vec nalazi nista se ne desava
				if(nalazi_se==false) odvratni.push_back(v[i]);
			}
			//if uslov koji ispituje da li se za negativan broj njegove cifre zadovoljavaju uslov odvratnog broja
			if(v[i]<0 && (negativni[0]%2==1 || negativni[0]==0) && (negativni[1]%2==1 || negativni[1]==0) && (negativni[2]%2==1 || negativni[2]==0)){
				bool nalazi_se=false;
				for(int j=0; j<odvratni.size(); j++){
					if(v[i]==odvratni[j]){
						nalazi_se=true;
						break;
					}
				}
				if(nalazi_se==false) odvratni.push_back(v[i]);
			}
		}
		return odvratni;
	}
	
}
int main ()
{	int x;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	std::vector<int> v;
	do{	
		std::cin>>x;
		if(x!=0) v.push_back(x);
	}while(x!=0);
	std::vector<int>a(IzdvojiGadne(v,true));
	std::vector<int>b(IzdvojiGadne(v,false));
	std::cout<<"Opaki: ";
	for(int i=0; i<a.size(); i++)
		std::cout<<a[i]<<" ";
	std::cout<<std::endl<<"Odvratni: ";
	for(int i=0; i<b.size(); i++)
		std::cout<<b[i]<<" ";
	return 0;
}