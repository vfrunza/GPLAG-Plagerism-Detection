/*B 2016/2017, Zadaća 1, Zadatak 1
	
	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!
	
	NAPOMENA: nece svi (javni) testovi sa zamgera biti 
	dostupni na c9.
	
*/
//DNEVNIK RADA: za sada imam jos dva problema za resiti! 1. Obicne mi tretira kao odvratne 2.ne smeju mi se ponavljati u vracenom vektoru
#include <iostream>
#include <vector>

//KojiGadni pomocna funkcija koja prima element vektora pretvoren u broj po bazi 3, koji je takodje pretvoren u
//vektor..npr. za element 56, vektora unetog sa tastature, funkcija prima vektor 2 0 0 2, ya koji treba utvrditi
//da se sve cifre ponavljaju paran (opaki, pa ce vratiti tacno) ili neparan (odvratnjikavi, pa ce vratiti
//netacno) broj puta..


//razimsliti sta da vrati ako broj nije ni opak ni odvratan


int DaLiJeOpaki(std::vector<int> element_po_b3){
	int bezimena1{0};
	int bezimena2{0};
	 for(int i=0; i<element_po_b3.size(); i++){
	 	 int pomocna = element_po_b3[i];
	 	 int brojac{0};
	 	 for(int j=0; j<element_po_b3.size(); j++){
	 	 	if (pomocna == element_po_b3[j])
	 	 	brojac++;
	 }
	
	 if(brojac % 2 ==0) bezimena1++;
	 else bezimena2++;
}
if (bezimena1 == element_po_b3.size()) return 1;
//else if(bezimena1 != element_po_b3.size() && bezimena2 != element_po_b3.size()) return 2;
else if(bezimena2 == element_po_b3.size()) return 0;
else return 2;

}


std::vector<int> IzdvojiGadne(std::vector<int> v, bool flag){
	std::vector<int> opaki;
	std::vector<int> odvratni;
	
	for( int i = 0; i<v.size(); i++){
		int pomocna = v[i];
		std::vector<int> element_po_b3;
			
		while( pomocna != 0){
			element_po_b3.push_back(pomocna%3);
			pomocna=pomocna/3;	
		}
	//ovde sada imam element vektora pretvoren u broj sa bazom 3..sada je potebno proveritt
	//da li je opak ili odvratan i pushbackti u vektor "opaki" ili "odvratni"
		
	if(DaLiJeOpaki(element_po_b3)==1) { 
		
	//for(int k=0; k<opaki.size(); k++){
 //   if ( v[i] == opaki[k]) break;
		opaki.push_back(v[i]);
	}
		
		else if(DaLiJeOpaki(element_po_b3) == 0) { odvratni.push_back(v[i]);}
	}
	
	//ovde prolazim kroz oba vektora "opaki" pa "odvratni" , i brisem iste clanove
	for(int l=0; l<opaki.size(); l++){
			for(int m=l+1; m<opaki.size(); m++){
				if(opaki[l] == opaki[m]) {
				for(int f=m; f<opaki.size()-1; f++)
				opaki[f]=opaki[f+1];
				m--;
		int b{0};		
		b=opaki.size();
        b--;
		opaki.resize(b);}
			}
		}
//	else if(DaLiJeOpaki(element_po_b3)==2)
	for(int l=0; l<odvratni.size(); l++){
			for(int m=l+1; m<odvratni.size(); m++){
				if(odvratni[l] == odvratni[m]) {
				for(int f=m; f<odvratni.size()-1; f++)
				odvratni[f]=odvratni[f+1];
				m--;
		int b{0};		
		b=odvratni.size();
        b--;
		odvratni.resize(b);}

			}
		}
		
if(flag) {
	return opaki;}
	else{
		return odvratni;}
		
}
//136 123 12 1212 10102 10012 1000 608 2613 -608 333
//	333 333 333 333 333 1000 0
int main(){
	
	int i{0};

	int element{0};
	std::vector<int> v;
	std::vector<int> opaki;
	std::vector<int> odvratni;

	

	std::cout << "Unesite brojeve (0 za prekid unosa): ";
	do{
		std::cin >> element;
		if(element == 0) break;
		v.push_back(element);
			
	}while( v[i] != 0); 
	

    std::cout << "Opaki: ";
	opaki=IzdvojiGadne(v,1);
	for(int x : opaki) std::cout << x << " ";
	std::cout<< std::endl;
	
	std::cout << "Odvratni: ";
	odvratni=IzdvojiGadne(v,0);
	for(int x : odvratni) std::cout << x << " "; 
/*	x
	std::vector<int> v = {
	136, 123, 12, 1212, 10102, 10012, 1000, 608, 2613, -608, 333,
	333, 333, 333, 333, 333, 1000, -15, 60, 61, 15, 151, 16, 715, 7222,
};
auto opaki = IzdvojiGadne(v, true), odvratni = IzdvojiGadne(v, false);
std::cout << "Opaki: ";
for (const auto &x : opaki) std::cout << x << " ";
std::cout << std::endl << "Odvratni: ";
for (const auto &x : odvratni) std::cout << x << " "; */
	return 0;
	
}




