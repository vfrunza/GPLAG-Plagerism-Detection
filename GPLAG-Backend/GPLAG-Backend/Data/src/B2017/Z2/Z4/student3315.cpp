
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>




int razmijeni(int *pok1,int *pok2){
	int pomocna(*pok1);
	*pok1=*pok2;
	*pok2=pomocna;
	
}

int f(int a, int b){
	return (-2*a)+b;
}




template<typename tip1, typename tip3, typename tip4,typename tip_elemenata12,typename tip_elemenata3>

int SortirajPoVrijednosti(tip1 *p1,tip1 *p2, tip3 *p3,tip4 *p4,  tip_elemenata3 f(tip_elemenata12, tip_elemenata12),bool funkcija(tip_elemenata12,tip_elemenata12)){
	
	// p1-p2 iteratori na prvi blok    p3-na drugi blok  p4-na treci blok  f-prima parametre kao u prva dva bloka
	
	//brojac nam govori koliki je prvi blok, on izlazi iz pelje kad dodje do p2 a to je iza kraja prvog bloka 
	
	int brojac(0);
	while(p1<p2){
		brojac++;
		p1++;
	}
	
	auto *pomocni=p3+brojac;
	
	std::sort(p1,p2,funkcija);
	std::sort(p3,pomocni,funkcija);
	
	// pokusat cu sa auto deklaracijom ovdje da dodijelim brojevima broj1 i broj2 neke vrijednosti i da ih saljem u fju
	while(p1<p2){
		
    tip_elemenata12 broj1=*p1;
	tip_elemenata12 broj2=*p3;
	 
	
	tip_elemenata3 rezultat=f(broj1,broj2);
	tip4 pok=p4; // u poku cuvamo pocetak bloka 3
	
	
	//moramo provjeriti jel ovaj rezultat u bloku 3, ovaj broj provjeriti sa svim ostalim
	bool postoji(false);
	int pozicija;
	
	//izaci ce iz petlje kada je p4 na broju kojeg trazimo
	
	
	int i=0;
	int t=0;
	while(t<brojac){
		if(rezultat==(p4)){
			postoji=true;
			pozicija=t;
			t=0;
			break;
		}
		
		p4++;
		t++;
	}
	

	if(postoji==false){
		throw std::domain_error("Vrijednost koja odgovara nekom od parova nije nadjena");
	}
	
	// trebamo dovesti ovaj rezultat svesti u bloku 3-na poziciju na kojoj smo ga ovdje nasli
	else{
		return rezultat;
	int mjesto_u_bloku(0);
	
	if(pozicija==mjesto_u_bloku){
		mjesto_u_bloku++;
		pok+=1;
		continue;
		
	}
	razmijeni(&p4,&pok);
	mjesto_u_bloku++;
	
	pok+=1;
	p4=p4-pozicija+mjesto_u_bloku;
	
	}

	
	
	}
		
	//////////////////
		
	}
	
	
// c-pripada bloku 1 d-pripada bloku 2 pa te blokove trebamo sortirati
bool funkcija(int c,int d){
	int broj1=c;
	int broj2=d;
	int brojac_faktora1(0);
	int brojac_faktora2(0);
	
	int i=2;
	while(broj1!=1){
		if(broj1%i==0){
			brojac_faktora1++;
			broj1/=i;
		}
		else{
			i++;
		}
	}
	
	int j=2;
	while(broj2!=1){
		if(broj2%j==0){
			brojac_faktora2++;
			broj2/=j;
		}
		else{
			j++;
		}
	}
	
	if(brojac_faktora1>brojac_faktora2){
		return true;
	}
	if(brojac_faktora1<brojac_faktora2){
		return false;
	}
	
	if(brojac_faktora1==brojac_faktora2){
		
		if(c>d){
			return true;
		}
		else{
			return false;
		}
	}
	
	
}









int main ()
{
	//int n;
	//std::cout<<"Unesite broj elemenata: ";
	//std::cin>>n;
	
	std::vector<int> v1={1,2,3,4,5,6};
	std::vector<int> v2={6,5,4,3,2,1};
	std::vector<int> v3={-3,-5,-1,-4,-2,-6};
	


	
	std::cout<<SortirajPoVrijednosti<int>(v1,v1,v2,v3,f,funkcija);
	
	
	
	
/*	std::vector<int>::iterator t1(v1.begin());
	auto t2(v1.end());
	
	std:: sort(t1,t2,funkcija);
	
	
	
	for(int i=0;i<v1.size();i++){
		std::cout<<v1[i]<<" ";
	}
	
	int brojac(0);
	while(t1<t2){
		brojac++;
		t1++;
	}
	
	
	std::cout<<std::endl;
	std::vector<int>::iterator t3(v2.begin());
	auto pomocni(t3+brojac);
	
	std::sort(t3,pomocni,funkcija);
	
	
//	for(int t=0;t<6;t++){
//		auto pomocna=funkcija(t1,t3);
//		std::cout<<pomocna;
//	}
	
	for(int k=0;k<v2.size();k++){
		std::cout<<v2[k]<<" ";
	}
	

	*/
	
	
	
	
/*	
	int broj1,broj2;
	std::cout<<"Unesite elemente prvog vektora: ";

	for(int i=0;i<n;i++){
		std::cin>>broj1;
		v1.push_back(broj1);
	}
	
	for(int k=1;k<v1.size();k++){
		for(int t=0;t<k;t++){
			
			if(v1[k]==v1[t]){
				v1.erase(v1.begin()+k);
			}
		
		}
	}
		
	

	


	
	
	std::cout<<"Unesite elemente drugog vektora: ";
	for(int j=0;j<n;j++){
		std::cin>>broj2;
		v2.push_back(broj2);
	}
	

		
	for(int x: v1){
		std::cout<<"ide:"<<x<<" "<<std::endl;
	}

*/	
	return 0;

}