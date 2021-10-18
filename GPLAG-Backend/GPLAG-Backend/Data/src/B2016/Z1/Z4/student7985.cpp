/*B 2016/2017, Zadaća 1, Zadatak 4*/
#include <iostream>
#include <string>
#include <vector>

using std::string;
typedef std::vector<string> VektorStr;

/*string IzdvojiRijeci(string rec){
	string rijec;
	for(int i{}; i < rec.length() - 1; i++){
		if((rec[i] ==  ' ' && rec[i+1] != ' ') || (i == 0 && rec[i] != ' ')) { //našli smo riječ-ili bar jedno slovo
	
			if(i != 0 || (i == 0 && rec[i] == ' ')) i++; //<-- 2.uslov sumnjivo
			int br_slova{};	
			for(int j{i}; j < rec.length(); j++){
				br_slova++;
				
				if (br_slova > 1){
					rijec = rec.substr(i, br_slova -1):
				}
				//if-ovima tražimo kraj riječi-> ili je razmak ili je kraj rečenice
				if(rec[j] == ' '){
					rijec = rec.substr(i, br_slova -1);
					
					br_slova = 0;
				}	
				if(j == rec.length() -1){
					rijec = rec.substr(i, br_slova);
					br_slova = 0;
				}
			}
		}
	}
	return rijec;
}*/
	
string ObrniFraze (string rec, VektorStr fraze){
	
	for(int i{}; i < fraze.size(); i++){
		for(int j{1}; j < fraze[i].size; j++){
			bool iste;
			while (true) {
				for(int k{1}; k < rec.length(); k++){	
					if (rec[k-1] == fraze[j-1][i] && rec[k] == fraze[j][i]) iste == true;
				}	
					
			}
		}
	}
}



int main ()
{
	return 0;
}