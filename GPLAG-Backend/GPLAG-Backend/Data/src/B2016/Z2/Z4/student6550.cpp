/*B 16/17, Zadaća 2, Zadatak 4
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Ivona Ivkovic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: iivkovic2@etf.unsa.ba
*/
#include <iostream>
#include <vector>
#include <string>
#include <new>
#include <stdexcept>


int PotencijalniKrivci(char **&mat, std::vector<std::string> v){
	try{
	mat = new char*[v.size()];
	for(int i=0 ; i<v.size() ; i++) mat[i] = nullptr;
	try{
		for(int i=0 ; i<v.size() ; i++) {
			std::string pom = v[i];
		    mat[i] = new char[pom.length()+1];
		}
			for(int i=0 ; i<v.size() ; i++){
				std::string temp = v[i];
				for(int j=0 ; j<temp.size() ; j++ ){
					mat[i][j] = v[i][j];
				}
			}
			
			return v.size();
	}
		catch(...){
			for(int i=0 ; i<v.size() ; i++) delete [] mat;
			delete [] mat;
			throw;
		}
}
	catch(...){
		throw std::bad_alloc();
	}
}

OdbaciOptuzbu(char **&mat, int vel, std::string s){
	
}

int main ()
{
	return 0;
}