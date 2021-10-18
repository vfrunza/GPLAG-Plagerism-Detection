/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <cmath>
#include <deque>
#include <vector>
#include <type_traits>
#include <functional>

//.. FUNKCIJA ZA TESTIRANJE...

	int SumaCifara(int n){
		int suma(0);
		while(n != 0){
			suma += (n % 10);
			n /= 10;
		}
		return suma;
	}
//... POTREBNE FUNKCIJE ZA TESTIRANJE ....
int SumaDjelilaca (long long int n){
	 int  suma (0);
	for(int i = 1; i <= n; i++){
		if(n % i == 0) {
		//	std::cout<<"| "<<i;
			suma += i;
		}
	}
	
	return suma;
}
int BrojProstihFaktora(long long int n){ 
	int br(0);
	//...UKOLIKO JE DJELJIV SA 2

	while(n % 2 == 0){
		std::cout<<2<<" ";
		br++;
		n /= 2;
	}
	
	//...UKOLIKO JE DJELJIV SA 3,5,7,9....NEPARNI

	for(int i = 3; i < std::sqrt(n);i= i + 2){
		
		while(n % i == 0){
			std::cout<<i<<" ";
			n /= i;
			br++;
		}
		
	}

	//... ONO STO JE OSTALO...

	if(n > 2){ 
	std::cout<<n<<" ";
	br++;
	}
	
	return br;
}

bool SavrsenBroj(long long int n){
	int suma (0);
	
	int i = 1;
	while(n % i == 0){
		suma+= i;
		i++;
	}
	if(suma == n) return true;
	return false;
}


template<typename IterTip,typename t ,typename Tip,typename Tip2 >
auto UvrnutiPresjek(IterTip p1, IterTip p2 , t p3 , t p4 , Tip2 fun (Tip) ) -> typename std::remove_reference <decltype (*p1)**>
{
	
	int br (0);
	std::vector<std::vector<Tip>> mat = {};
	
	while(p1 != p2){
		
		if( fun (*p1) == fun(*p3)){
			//....SACUVATI (*p1, *p3);
			br++;
			
		
			//... NAPRAVI MATRICU I stavi elemente u matricu
			for(int i = 0; i < br; i++){
				mat.push_back(std::vector<Tip> ());
				for(int j (0); j < 3; j++){
					if(mat[i][0]) mat.push_back(*p1);
					if(mat[i][1]) mat.push_back(*p2);
					if(mat[i][2]) mat.push_back( f (*p1) );
				}
			}
		}
		
		p1++;
		p3++;
		
	}
	
	for(int i (0); i < mat.size(); i++){
		for(int j (0); j < mat[i].size();j++){
			std::cout<<mat[i][j]<< " ";
		}
		std::cout<<std::endl;
	}
	
	//...POTREBNO JE SORTIRATI REDOVE MATRICE PO VRIJEDNOSTI TRECE KOORDINATE
	//... UKOLIKO DVA REDA IMAJU ISTU VRIJEDNOST F,TADA SE SORTIRA PO X KOORDINATI 
	//..UKOLIKO SE I X POKLAPA,TADA SE SORTIRA PO Y 
	//...KORISTITI SORT IZ ALGORITHM UZ LAMBDA 
	
	for(int i (0); i < mat.size(); i++){
		std::
	}
	
	
	return mat;
}

int main ()
{
	std::cout<<"Unesite broj elemenata prvog kontejnera: ";
	int n;
	std::cin>> n;
	
	std::cout<<"\nUnesite elemenate prvog kontejnera: ";
	std::deque<int>d1;
	for(int i (0); i < n; i++){
		int br;
		std::cin >> br;
		d1.push_back(br);
	}
	
	std::cout<<"\nUnesite broj elemenata drugog kontejnera: ";
	int b;
	std::cin >> b;
	
	std::cout<<"\nUnesite elemente drugog kontejnera: ";
	std::deque<int>d2;
	for(int i (0); i < b; i++){
		int br;
		std::cin >> br;
		d2.push_back(br);
	}
	
	std::cout<<"Uvrnuti presjek kontejnera:\n";
	
	std::deque<std::deque<int>> presjek = UvrnutiPresjek(d1.begin(), d1.end(), d2.begin() , d2.end(), SumaCifara);
	


	std::cout<<"\nUvrnuta razlika kontejnera:\n";
	return 0;
}