#include <iostream>
#include <vector>
#include <new>
#include <stdexcept>
#include <iomanip>

template <typename tip>
tip **AlocirajFragmentirano (std::vector<tip> &v, int koliko_puta){
	
	
	tip **p(nullptr);
	
	
	try{
		p=new tip*[koliko_puta*v.size()];
		for (int i=0; i<(v.size()*koliko_puta); i++) p[i]=nullptr;
		try{
			tip max(v[0]);
			for (int i=0; i<v.size(); i++) if(max<v[i]) max=v[i];
			for (int=k(0); k<koliko_puta; k++){
				for (int k=)
			}
		}
	}
	
	
	catch{
		
	}
	
	
}








int main ()
{
	return 0;
}