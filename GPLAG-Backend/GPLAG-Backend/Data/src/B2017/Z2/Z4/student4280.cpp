//B 2017/2018, Zadaća 2, Zadatak 4
#include <iostream>
#include <vector>


template <typename PokTip, typename Tip1, typename Tip2> 
Tip2 SortirajPodrucjeVrijednosti(PokTip poc, PokTip kraj, Tip1 p2, Tip2 p3,
		Tip2 fun(PokTip,Tip1), bool sort(PokTip,Tip1)){
	while(poc<kraj){
		auto tmp(poc);
		sort(*poc, *kraj);
	}
}


int main ()
{
	std::cout<<"Unesite broj elemenata: ";
	int vel;
	std::cin>>vel;
	std::vector<int> S1(vel), S2(vel), S3(vel);
	std::cout<<"Unesite elemnte prvog vektora: ";
	for(int i=0; i<vel; i++){
		int br;
		std::cin>>br;
		S1.at(i)=br;
	}
	std::cout<<"Unesite elemnte drugog vektora: ";
	for(int i=0; i<vel; i++){
		int br;
		std::cin>>br;
		S2.at(i)=br;
	}
	std::cout<<"Unesite elemnte treceg vektora: ";
	for(int i=0; i<vel; i++){
		int br;
		std::cin>>br;
		S3.at(i)=br;
	}
	int *poc(&S1.at(0));
	auto kraj(std::end(S1));
	int *p2(&S2.at(0));
	int *p3(&S3.at(0));
	
	std::cout<<"Nakon sortiranja podrucja vrijednosti imamo sljedece trojke: "<<std::endl;
	for(int i=0; i<vel; i++){
		std::cout<<"f("<<S1.at(i)<<", "<<S2.at(i)<<") = "<<S3.at(i)<<std::endl;
	}
	
	return 0;
}