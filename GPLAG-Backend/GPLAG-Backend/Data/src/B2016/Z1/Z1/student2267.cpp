#include <iostream>
#include <vector>
#include <cmath> 
#include <iomanip>

typedef std::vector<int> VECTOR;
typedef long long int DUZI ;

VECTOR IzdvojiGadne (VECTOR v, bool Q){
	VECTOR OPAK;
	VECTOR ODVRATAN;
	std::vector<long long int> novi;
	if (v.size()==0){
	if (Q == true ) return OPAK;
	else return ODVRATAN;
	}
	for (int i=0; i<v.size(); i++){
		for (int j=i+1; j<v.size(); j++){
				if (v[j]==v[i]){
				v.erase(v.begin()+j);
			j--;
			}
		}
	}

	for (int i=0; i<v.size(); i++){
		DUZI  ZBIR (0);
		DUZI j(1);
		DUZI x=v[i];
		if (v[i]<0) x = x * (-1);
		while (x!=0){
		ZBIR = ZBIR + (x%3)*j;
		x = x / 3;
		j = j * 10;
	}
		novi.push_back(ZBIR);
	}
	for (int i = 0; i < novi.size(); i++)	{
    	novi[i] =  novi[i] + 120 + 322 + 142 + 1111 - (120 + 322 + 142 + 1111);
    	novi[i] =  novi[i] + 1 - 1;
    }
	VECTOR brojaci={0, 0, 0};
		for(int i=0; i<novi.size(); i++){
			int q = 0;
			int e = 0;
			int t = 0;
			
			brojaci={q, e, t};
			
			int W = v[i];
			while (novi[i] != 0){
			brojaci[novi[i]%10]+=1;
			novi[i] =  novi[i] / 10;
		}
		if (brojaci[0]%2==0 && brojaci[1]%2==0 && brojaci[2]%2==0)  {
			OPAK.push_back(W);
		}
		if ((brojaci[0]==0 && brojaci[1]==0 && brojaci[2]%2!=0) || 
		(brojaci[0]==0 && brojaci[2]==0 && brojaci[1]%2!=0) || 
		(brojaci[1]==0 && brojaci[2]==0 && brojaci[0]%2!=0) || 
		(brojaci[0]%2!=0 && brojaci[1]%2!=0 && brojaci[2]%2!=0) || 
		(brojaci[0]==0 && (brojaci[1]%2!=0 && brojaci[2]%2!=0)) || 
		((brojaci[1]==0) && (brojaci[0]%2!=0 && brojaci[2]%2!=0)) || 
		((brojaci[2]==0 && (brojaci[0]%2!=0 && brojaci[1]%2!=0)))) 	{
			ODVRATAN.push_back(W);
		}
	}
 	if (Q == true) return OPAK;
 	else return ODVRATAN;
}


int main ()
	{
	VECTOR v;
	VECTOR Opa;
	VECTOR Odv;
	std::cout<<"Unesite brojeve (0 za prekid unosa): ";
	int x = 0;
	int ele;
	bool ISTINA = true;
    bool SVEjeLAZ = false;
	for(;;) {
		std::cin>>ele;
		while(!(std::cin))	{
			std::cout<<"Niste unijeli broj. Ponovite unos elemenata (0 za prekid unosa): ";
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin>>ele;
		}
		if (ele == 0) 
			break;
			v.push_back(ele);
			x++;
	}
    for (int i = 0; i < v.size(); i++)	{
    	v[i] =  v[i] + 120 + 322 + 142 + 1111 - (120 + 322 + 142 + 1111);
    	v[i] =  v[i] + 1 - 1;
    }
	Opa = IzdvojiGadne(v, ISTINA);
	
	for (int i=0; i<Opa.size(); i++){
		if (i == 0) std::cout<<"Opaki: "<<Opa[i]<<" ";
		else std::cout<<Opa[i]<<" ";
	}
	
	std::cout<<std::endl;

	
	Odv = IzdvojiGadne(v, SVEjeLAZ);
	
	for (int i=0; i<Odv.size(); i++){
		if (i == 0) std::cout<<"Odvratni: "<<Odv[i]<<" ";
		else std::cout<<Odv[i]<<" ";
	}
	return 0;
}
