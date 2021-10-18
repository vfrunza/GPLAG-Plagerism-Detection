/*B 16/17, Zadaća 2, Zadatak 3
	
	NAPOMENA: i javni ATo-vi su dio postavke
	
	Autotestovi by Berina Cocalic. Sva pitanja, sugestije
	i prijave gresaka saljite na mail: bcocalic1@etf.unsa.ba
	
*/
#include <iostream>
#include <algorithm>
#include <deque>
#include <type_traits>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::deque;
using std::remove_reference;
using std::sort;


int SumaDjelilaca(long long int elemenat){
    int suma=0;
    for(int i(1);i<=elemenat;i++){
        if(abs(elemenat%i)==0)suma+=i;
    }
    return suma;
}

int BrojProstihFaktora(long long int elemenat){
    int brojac=0;
    bool temp(true);
    for(int i(2);i<elemenat;i++){
        if(elemenat%i==0){
            for(int j(1);j<i;j++){
                if(i%j==0){
                temp=false;
                 break;
                }
            }
            if(temp)brojac++;
        }
    }
    return brojac;
}

    

int BrojSavrsenihDjelilaca(long long int elemenat){
    int brojac=0;
    elemenat = abs(elemenat);
    for(int i(2); i<=elemenat; i++){
        if(elemenat%i==0){
            long long int suma=0;
            for(int j(1); j<i; j++){
                if(i%j==0)suma+=j;
            }
            if(suma==i) brojac++;
        }
    }
    return brojac;
}

typedef deque<deque<double>> MATRICA;
template <typename tip1, typename tip2, typename tip3>
std::vector<std::vector<int>> UvrnutiPresjek(tip1 it1, tip1 it2, tip2 it3, tip2 it4, tip3 f){
            tip1 it1copy1=it1; //kopija it1
            tip1 it2copy1=it2;//kopija it2
            tip2 it3copy1=it3; //kopija it3
            tip2 it4copy1=it4;//kopija it4
            tip1 it1copy2=it1; //kopija it1
            tip1 it2copy2=it2;//kopija it2
            tip2 it3copy2=it3; //kopija it3
            tip2 it4copy2=it4;//kopija it4
            
            deque<int> zbir_skup1;
            while(it1copy1!=it2copy1){
                    zbir_skup1.push_back(f(*it1copy1));
                    it1copy1++;
            }
            
            deque<int> zbir_skup2;
            while(it3copy1!=it4copy1){
                    zbir_skup2.push_back(f(*it3copy1));
                    it3copy1++;
            }
            
            deque<int> unija;
            for(int i(0);i<it2-it1;i++){
                for(int j(0);j<it4-it3;j++){
                    if(zbir_skup1[i]==zbir_skup2[j]){
                        unija.push_back(i);
                        unija.push_back(j);
                        unija.push_back(zbir_skup1[i]);
                    }
                }
            }
            std::vector<std::vector<int>> finalna_matrica;
            finalna_matrica.resize(int(unija.size())/3);
            for(int i(0);i<int(unija.size())/3;i++){finalna_matrica[i].resize(3);}
            
            for(int i(0);i<int(unija.size())/3;i++){
                for(int j(0);j<3;j++){
                    it1copy2=it1;
                    if(j==0){finalna_matrica[i][j]=*(it1copy2+unija[i*3]);}
                    if(j==1){finalna_matrica[i][j]=*(it3copy2+unija[i*3+1]);}
                    if(j==2){finalna_matrica[i][j]=unija[i*3+2];}
                }
            }    
    std::sort(finalna_matrica.begin(), finalna_matrica.end(), [](const std::vector<int> &v1, const std::vector<int> &v2){if (v1[2]==v2[2] && v1[0]==v2[0]) return v1[1]<v2[1]; else if(v1[2]==v2[2] && v1[0]!=v2[0]) return v1[0]<v2[0];else return v1[2]<v2[2];});
            
            
return finalna_matrica;            
            
            
}
template <typename tip1, typename tip2, typename tip3>
std::vector<std::vector<int>> UvrnutaRazlika(tip1 it1, tip1 it2, tip2 it3, tip2 it4, tip3 f){
            tip1 it1copy1=it1; //kopija it1
            tip1 it2copy1=it2;//kopija it2
            tip2 it3copy1=it3; //kopija it3
            tip2 it4copy1=it4;//kopija it4
            tip1 it1copy2=it1; //kopija it1
            tip1 it2copy2=it2;//kopija it2
            tip2 it3copy2=it3; //kopija it3
            tip2 it4copy2=it4;//kopija it4
            
            deque<int> zbir_skup1;
            while(it1copy1!=it2copy1){
                    zbir_skup1.push_back(f(*it1copy1));
                    it1copy1++;
            }
            
            deque<int> zbir_skup2;
            while(it3copy1!=it4copy1){
                    zbir_skup2.push_back(f(*it3copy1));
                    it3copy1++;
            }
            
            deque<int> razlika;
            bool raz=true;
            for(int i(0);i<it2-it1;i++){
                for(int j(0);j<it4-it3;j++){
                    if(zbir_skup1[i]==zbir_skup2[j]){
                        raz=false;
                        continue;
                    }
                    
                }
                if(raz){
                    razlika.push_back(*(it1copy2+i));
                    razlika.push_back(zbir_skup1[i]);
                    it1copy2=it1;
                }
                    
                }
            
            for(int i(0);i<it4-it3;i++){
                for(int j(0);j<it2-it1;j++){
                    if(zbir_skup2[i]==zbir_skup1[j]){
                        raz=false;
                        continue;
                    }
                    
                }
                if(raz){
                    razlika.push_back(*(it3copy2+i));
                    razlika.push_back(zbir_skup2[i]);
                    it3copy2=it3;
                }
                    
                }
            
            std::vector<std::vector<int>> finalna_matrica;
            finalna_matrica.resize(int(razlika.size())/2);
            for(int i(0);i<int(razlika.size())/2;i++){finalna_matrica[i].resize(2);}
            for(int i(0);i<int(razlika.size())/2;i++){
                for(int j(0);j<2;j++){
                    if(j==0){finalna_matrica[i][j]=razlika[i*2];}
                    if(j==1){finalna_matrica[i][j]=razlika[i*2+1];}
                }
            }    
    std::sort(finalna_matrica.begin(), finalna_matrica.end(), [](const std::vector<int> &v1, const std::vector<int> &v2){if (v1[2]==v2[2] && v1[0]==v2[0]) return v1[1]<v2[1]; else if(v1[2]==v2[2] && v1[0]!=v2[0]) return v1[0]<v2[0];else return v1[2]<v2[2];});
            
            
    return finalna_matrica;            
}

int main(){
   cout<<"Unesite broj elemenata prvog kontenjera: ";
    int br_elem1;
    cin>>br_elem1;
    cout<<"Unesite elemente prvog kontenjera: ";
    deque<int> skup1;
    int temp;
    bool ponavljanje(false);
    bool upis(false);
    for(int i(0);i<br_elem1;i++){
        ponavljanje=false;
        upis=false;
        cin>>temp;
        for(int j(0);j<=i;j++){
            if(temp==skup1[j] && temp!=skup1[i]){
                ponavljanje=true;
                upis=true;
                break;
            }
        }
            if(ponavljanje)i--;
            if(upis)continue;
            else{
                skup1.push_back(temp);
            }
    }
    cout<<"Unesite broj elemenata drugog kontenjera: ";
    int br_elem2;
    cin>>br_elem2;
    cout<<"Unesite elemente drugog kontenjera: ";
    deque<int> skup2;
    for(int i(0);i<br_elem2;i++){
        ponavljanje=false;
        upis=false;
        cin>>temp;
        for(int j(0);j<=i;j++){
            if(temp==skup2[j] && temp!=skup2[i]){
                ponavljanje=true;
                upis=true;
                break;
            }
        }
            if(ponavljanje)i--;
            if(upis)continue;
            else{
                skup2.push_back(temp);
            }
    }
    auto finalna_matrica(UvrnutiPresjek(skup1.begin(), skup1.end(), skup2.begin(), skup2.end(), SumaDjelilaca));
    auto finalna_matrica1(UvrnutaRazlika(skup1.begin(), skup1.end(), skup2.begin(), skup2.end(), BrojProstihFaktora));
    
    cout<<"Uvrnuti presjek kontejnera:"<<endl;
    for(int i(0);i<finalna_matrica.size();i++){
        for(int j(0);j<finalna_matrica[i].size();j++){
            cout<<"    "<<finalna_matrica[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"Uvrnuta razlika kontejnera:"<<endl;
    for(int i(0);i<finalna_matrica1.size();i++){
        for(int j(0);j<finalna_matrica1[i].size();j++){
            cout<<"    "<<finalna_matrica1[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"Dovidjenja!";
    return 0;
}