/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/

int main ()
{
	int broj1,broj2;
	std::cout<<"Unesite broj elemenata prvog vektora: ";
	std::cin>>broj1;
	std::cout<<"Unesite elemente prvog kontejnera: ";
	int a;
	std::deque<int> d1;
	for(int i=0;i<broj1;i++) {
		std::cin>>a;
		d1.push_back(a);
	}
	std::cout<<"Unesite broj elemenata drugog vektora: ";
	std::cin>>broj2;
	std::cout<<"Unesite elemente drugog kontejnera: ";
	int b;
	std::deque<int> d2;
	for(int i=0;i<broj2;i++) {
		std::cin>>b;
		d2.push_back(b);
	}
		
	return 0;
}