
#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

int Ponavljanje (std::vector <int> v, int n){

	int br(0);
	for (int i=0; i<v.size(); i++){
		if(v[i]==n) br++;
		if (i==v.size()) break;
	}
	return br;
}

int Ternarni (int n){



	int c;

	
	if (n<0) n=abs(n);
	std::vector <int> v;

	while (n>0){
		c=n%3;
		v.push_back(c);
		n=n/3;
	}
int b(0);
int koef(pow(10, v.size()-1));


for(int i=v.size()-1; i>=0; i--){
    b=b+koef*v[i];
    koef=koef/10;
    if (koef<0) break;
    if(i==0) break;
}
	return b;
}

int Opaki_Odvratni (int n){

	int l=n;

	if (l<0) l=abs(l);
	int m=l;
	std::vector<int> vektor;
	int b;
	while (m>0){
		b=m%10;
		vektor.push_back(b);
		m=m/10;

	}


	bool opaki(0), odvratni(0);

	for (int i=0; i<10; i++){
            if ((Ponavljanje(vektor, i)==0)) continue;
			if ((Ponavljanje(vektor, i))%2==0){
				opaki=1;
			}
			else {
				opaki=0;
				break;
			}}


       if (opaki==1) return 1;

       	for(int i=0; i<10; i++){
            if (Ponavljanje(vektor, i)==0) continue;
			if (Ponavljanje(vektor, i)%2==1){
				odvratni=1;
			}
			else {
				odvratni=0;
				break;
			}

       }
       if(odvratni==1) return 0;

return 3;

}

std::vector <int>  IzdvojiGadne (std::vector <int> v, bool opaki_odvratni){
	std::vector <int> vektor_gadnih;

	if (opaki_odvratni==1){
		for (int i=0; i<v.size(); i++){
            int b=Ternarni(v[i]);
			if ((Opaki_Odvratni(b))==1){
				vektor_gadnih.push_back(v[i]);
			}
			if(i==v.size()) break;
		}
		
		for (int i=vektor_gadnih.size()-1; i>=0;i--){

		if ((Ponavljanje(vektor_gadnih, vektor_gadnih[i]))>1){
			vektor_gadnih.erase(vektor_gadnih.begin()+i);

		}


	}
	}

	else if (opaki_odvratni==0){
		for (int i=0; i<v.size(); i++){
                int b = Ternarni(v[i]);
			if (Opaki_Odvratni(b)==0){
				vektor_gadnih.push_back(v[i]);
			}
			if(i==v.size()) break;
		}
				for (int i=vektor_gadnih.size()-1; i>=0;i--){

		if ((Ponavljanje(vektor_gadnih, vektor_gadnih[i]))>1){
			vektor_gadnih.erase(vektor_gadnih.begin()+i);

		}


	}
	}

	return vektor_gadnih;
}

int main ()
{
	std::vector <int> v;
	int n;
	std::cout<< "Unesite brojeve (0 za prekid unosa): ";


	do {
		std::cin >>n;
		if(n==0) break;
		v.push_back(n);


	}
	while(n!=0);

	std::cout<< "Opaki: ";
	std::vector<int> opaki= std::move(IzdvojiGadne(v,1));



	for (int i=0; i<opaki.size();i++){

		std::cout<<opaki[i]<<" ";
		if(i==opaki.size()) break;

	}
	std::cout<<std::endl;
	std::cout<< "Odvratni: ";
	std::vector<int> odvratni = std::move(IzdvojiGadne(v,0));

	for (int i=0; i<odvratni.size();i++){

		std::cout<<odvratni[i]<<" ";
		if (i==odvratni.size()) break;
	}
	return 0;
}
