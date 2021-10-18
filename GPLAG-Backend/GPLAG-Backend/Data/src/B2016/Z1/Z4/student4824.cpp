#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using std::vector;
using std::cin;
using std::cout;
using std::string;

string ObrniFraze(string ul_recenica,vector<string> fraze){
	string pomocni_str;
	
	//Prolazimo kroz fraze 
	for(int i=0;i<fraze.size();i++){
		pomocni_str=fraze[i];
		string rijec;
		
		//Trazimo fraze unutar recenice
		for(int j=0;j<ul_recenica.length();j++){
			int br(0),k(j),l(0);
			while(ul_recenica[k]==pomocni_str[l]){
				br++;
				k++;
				l++;
				if(k==ul_recenica.length()) break;
			}
			
			//Ako smo nasli frazu u recenici obrcemo je
			if(br==pomocni_str.size()){
			rijec=ul_recenica.substr(j,br);
			if(pomocni_str==rijec){
				char temp;
				int x(0);
				for(int l=j;l<(br/2+j);l++){
					temp=ul_recenica[l];
					ul_recenica[l]=ul_recenica[l+br-1-x];
					ul_recenica[l+br-1-x]=temp;
					x+=2;
			    	}
			    }
		    }
	    }
	}
	return ul_recenica;
}

string IzmijeniUPigLatin(string ul_recenica,vector<string> fraze){
	string pomocni;
	
	//Prolazimo kroz fraze i bacamo izuzetak ako slova nisu eng alfabet
	if(fraze.size()!=0){
	for(int i=0;i<fraze.size();i++){
		 pomocni=fraze[i];
		 for(int j=0;j<pomocni.length();j++){
		       if(pomocni[j]<'A' || pomocni[j]>'z')
		       throw std::domain_error("Izuzetak: Nekorektan izbor rijeci");
		 	}
    }    
    bool tacka(false);
    if(ul_recenica[ul_recenica.size()-1]=='.') tacka=true;
    
    //Prolazimo fraze
	string pomocni_str;
    for(int i=0;i<fraze.size();i++){
    	pomocni_str=fraze[i];
    	string rijec;
    	
    	//Trazimo ponavljanja fraza u recenici
    	for(int j=0;j<ul_recenica.length();j++){
    		int br(0),k(j);
    		
    		while(ul_recenica[k]!=' '){
    			br++;
    			k++;
    			if(k==ul_recenica.length()) break;
    		}
    		
    		//Ako smo nasli ponavljanje vrsimo upiglatin transformaciju
    		rijec=ul_recenica.substr(j,br);
    		if(pomocni_str==rijec){
    			ul_recenica.resize(ul_recenica.size()+2);
    			for(int l=ul_recenica.length()-1;l>br+j+2;l--){
    				ul_recenica[l]=ul_recenica[l-2];
    			}
    			char temp(ul_recenica[j]);
    			int br1;
    			for(int m=j;m<j+br;m++){
    				br1=m;
    				if(m==j+br-1) ul_recenica[m]=temp;
    				else ul_recenica[m]=ul_recenica[m+1];
    			}
    			ul_recenica[br1+1]='a';
    			ul_recenica[br1+2]='y';
    			ul_recenica[br1+3]=' ';
    		}
    	    j=j+br;
    	}
    }
    if(tacka) ul_recenica+".";
  }
  else{
     
  }
	return ul_recenica;
}

int main ()
{
	string ul_recenica,temp;
	cout<<"Unesite recenicu: ";
	getline(cin,ul_recenica);
	cout<<"Unesite fraze: ";
	vector<string> fraze;
	do{
		getline(cin,temp);
		if(temp.length()==0) break;
		fraze.push_back(temp);
	}while(temp.length()!=0);
	string pomocni;
	try{
		pomocni=IzmijeniUPigLatin(ul_recenica,fraze);
	cout<<"Recenica nakon PigLatin transformacije: ";
	cout<<pomocni<<std::endl;
	}catch(std::domain_error greska){
		cout<<greska.what();
	}
	cout<<std::endl<<"Recenica nakon obrtanja fraza: ";
	cout<<ObrniFraze(ul_recenica,fraze);

	return 0;
}