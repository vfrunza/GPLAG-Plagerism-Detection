#include <iostream>
#include <vector>
#include <cmath>

template <typename Element>
void f(std::vector<std::vector<Element>> &m) {

	bool nula(false);

	

		for(int i=0; i<m.size(); i++) {
			for(int j=0; j<m[i].size(); j++) {

				if(m[i][j]==0) { nula=true;

					for(int k=m[i].size()-1; k>j; k--) {

						if(m[i][k]!=0) {
							m[i][j]=m[i][k];
							m[i][k]=0;
							break;
						}
					}
				}
			}
		}

	
	
	if(!nula)throw "Nema nula";
	

}

int main()
{

	std::vector<std::vector<int>> m = {{15,0,0,1,2}, {14,0,2,0,1}, {3,16,0,2,3}};

	try{ 
		f(m);
	}
	catch(...){
		std::cout << "Nema nula";
		return 0;
	}
	
	
	for(int i=0; i<m.size(); i++) {
		for(int j=0; j<m[i].size(); j++) {
			std::cout << m[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}




/*
int CijeliBrojManjka(std::set<int> Skup)
{
	std::set<int>::iterator it = Skup.begin();
	int nedostaje=*it;

	while(it!=Skup.end())
	{
		if(*it!=nedostaje)return nedostaje;
		nedostaje++;it++;
	}

	if(nedostaje==*Skup.end()) return -1;
	return nedostaje;
}

int main () {
	std::set<int> Skup {5,6,8,9,10};

	if(CijeliBrojManjka(Skup)==-1) std::cout << "Nijedan broj ne fali skupu";
	else std::cout << "Broj koji fali skupu je " << CijeliBrojManjka(Skup);

	return 0;
}*/
