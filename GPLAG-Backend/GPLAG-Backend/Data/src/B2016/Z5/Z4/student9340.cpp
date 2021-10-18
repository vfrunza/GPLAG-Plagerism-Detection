#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>
#include <vector>
#include <initializer_list>

template <typename  Tip> 
class Gmatrica {
    bool Saglasne_Za_Sabiranje(const Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2) {
        return matrica.brojredova==matrica2.brojredova && matrica.brojkolona==matrica2.brojkolona;
    }
    bool Saglasne_Za_Mnozenje(const Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2) {
        return matrica.brojkolona==matrica2.brojredova;
    }
    Tip Matrica[4][4];
    int brojredova,brojkolona;
    public:
    Gmatrica() {
        brojkolona=0;
        brojredova=0;
    }
    Gmatrica(int red,int kolona,Tip element=Tip());
    Gmatrica(const Gmatrica<Tip> &matrica);
    Gmatrica(Tip(*pok)[4]);
    
    Gmatrica(std::vector<std::vector<Tip>> v);
    
    Gmatrica(std::initializer_list<Tip> lista);
    
    int DajBrojKolona() {
        return brojkolona;
    }
    int DajBrojRedova() {
        return brojredova;
    }
  friend  Gmatrica<Tip> operator+(const Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2);
  friend Gmatrica<Tip> operator-(const Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2);
  friend  Gmatrica<Tip> operator*(const Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2);
  friend Gmatrica<Tip> operator +=(Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2);
  friend Gmatrica<Tip> operator -=(Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2);
  friend Gmatrica<Tip> operator *=(Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2);
  friend bool operator ==(const Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2);
  friend bool operator !=(const Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2);
 friend std::ostream &operator<<(std::ostream &tok,const Gmatrica<Tip> &matrica);
 friend std::istream &operator >>(std::istream &tok,const Gmatrica<Tip> &matrica);
 Tip &operator()(int red,int kolona);
};
template <typename Tip5>
 Gmatrica<Tip5>::Gmatrica(int red,int kolona,Tip5 element) {
        if(red<0 || red>4 || kolona<0 || kolona>4)
        throw std::logic_error("Ilegalan format matrice");
        this->brojredova=red;
        this->brojkolona=kolona;
        for(int i=0;i<brojredova;i++) {
            for(int j=0;j<brojkolona;j++) {
                Gmatrica::Matrica[i][j]=element;
            }
        }
    }
    
     template <typename Tip>
    Gmatrica<Tip>::Gmatrica(const Gmatrica<Tip> &matrica) {
        for(int i=0;i<matrica.DajBrojRedova();i++) {
            for(int j=0;j<matrica.DajBrojKolona();j++) {
                Matrica[i][j]=matrica.Matrica[i][j];
            }
        }
    }

  template <typename Tip>
    Gmatrica<Tip>::Gmatrica(Tip(*pok)[4]) {
        for(int z=0;z<4;z++) {
            for(int k=0;k<4;k++) {
                Matrica[z]=pok[z];
            }
        }
    }
  template <typename Tip>
  
 Gmatrica<Tip>::Gmatrica(std::vector<std::vector<Tip>> v) {
        if(v.size()<=0 || v.size()>4) throw std::logic_error("Ilegalan format matrice");
        for(int i=0;i<v.size();i++) {
            if(v[i].size()<=0 || v[i].size()>4) 
            throw std::logic_error("Ilegalan format matrice");
        }
        for(int j=0;j<v.size();j++) {
            for(int k=0;k<v[j].size();k++) {
                this->Matrica[j][k]=v[j][k];
            }
        }
    }
    template <typename Tip10>
 Gmatrica<Tip10>::Gmatrica(std::initializer_list<Tip10> lista) {
    if(lista.size()<=0 || lista.size()>4) throw std::logic_error("Ilegalan format matrice");
    auto it2(lista.begin());
    for(int i=0;i<lista.size();i++) {
        if((*it2).size()<=0 || (*it2).size()>4)
        throw std::logic_error("Ilegalan format matrice");
    }
    auto it(lista.begin());
    for(int j=0;j<lista.size();j++) {
      this->Matrica[j]=*it;
      it++;
  }     
    }
    template <typename Tip11>
Gmatrica<Tip11> operator +(const Gmatrica<Tip11> &matrica,const Gmatrica<Tip11> &matrica2) {
    if(Saglasne_Za_Sabiranje(matrica,matrica2)) {
    Gmatrica<Tip11> rezultat(matrica.brojredova,matrica.brojkolona,0);
    for(int i=0;i<rezultat.DajBrojRedova();i++) {
        for(int j=0;j<rezultat.DajBrojKolona();j++) {
            rezultat.Matrica[i][j]=matrica.Matrica[i][j]+matrica2.Matrica[i][j];
        }
    }
    return rezultat;
}
else {
    throw std::domain_error("Nedozvoljena operacija");
}
}
template <typename Tip12>
Gmatrica<Tip12> operator -(const Gmatrica<Tip12> &matrica,const Gmatrica<Tip12> &matrica2) {
    if(Saglasne_Za_Sabiranje(matrica,matrica2)) {
        Gmatrica<Tip12> rezultat(matrica.brojredova,matrica.brojkolona,0);
        for(int i=0;i<rezultat.DajBrojRedova();i++) {
            for(int j=0;j<rezultat.DajBrojKolona();j++) {
                rezultat.Matrica[i][j]=matrica.Matrica[i][j]-matrica2.Matrica[i][j];
            }
        }
        return rezultat;
    }
    else {
        throw std::domain_error("Nedozvoljena operacija");
        }
}
template <typename Tip>

Gmatrica<Tip> operator *(const Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2){
    if(Saglasne_Za_Mnozenje(matrica,matrica2)) {
        Gmatrica<Tip> rezultat(matrica.brojredova,matrica2.brojkolona,0);
        double suma(0);
        for(int i=0;i<matrica.DajBrojRedova();i++) {
            for(int j=0;j<matrica2.DajBrojKolona();j++) {
            suma=0;
            for(int k=0;k<matrica.DajBrojKolona();k++) {
                suma+=matrica.Matrica[i][k]*matrica2.Matrica[k][j];
            }
            rezultat[i][j]=suma;
            }
        }
        return rezultat;
    }
    else 
    throw std::domain_error("Nedozvoljena operacija");
}
template <typename Tip1>
Gmatrica<Tip1> operator +=(Gmatrica<Tip1> &matrica,const Gmatrica<Tip1> &matrica2) {
    if(Saglasne_Za_Sabiranje(matrica,matrica2)) {
        for(int i=0;i<matrica.DajBrojRedova();i++) {
            for(int j=0;j<matrica.DajBrojKolona();j++) {
                matrica.Matrica[i][j]+=matrica2.Matrica[i][j];
            }
        }
    }
    else {
        throw std::domain_error("Nedozvoljena operacija");
    }
    return matrica;
}
template <typename Tip>
Gmatrica<Tip> operator -=(Gmatrica<Tip> &matrica,const Gmatrica<Tip> &matrica2) {
    if(Saglasne_Za_Sabiranje(matrica,matrica2)) {
        for(int i=0;i<matrica.DajBrojRedova();i++) {
            for(int j=0;j<matrica.DajBrojKolona();j++) {
                matrica.Matrica[i][j]-=matrica2.Matrica[i][j];
            }
        }
    }
    else 
    throw std::domain_error("Nedozvoljena operacija");
    return matrica;
}

template <typename Tip1>
Gmatrica<Tip1> operator *=(Gmatrica<Tip1> &matrica,const Gmatrica<Tip1> &matrica2) {
    if(Saglasne_Za_Mnozenje(matrica,matrica2))  {
        for(int i=0;i<matrica.DajBrojRedova();i++) {
            for(int j=0;j<matrica.DajBrojKolona();j++) {
                matrica.Matrica[i][j]*=matrica2.Matrica[i][j];
            }
        }
    }
    else {
        throw std::domain_error("Nedozvoljena operacija");
        }
        return matrica;
}
template <typename Tip2>
bool operator ==(const Gmatrica<Tip2> &matrica,const Gmatrica<Tip2> &matrica2) {
    if(Saglasne_Za_Sabiranje(matrica,matrica2)) {
        for(int i=0;i<matrica.DajBrojRedova();i++) {
            for(int j=0;j<matrica.DajBrojKolona();j++) {
                if(matrica.Matrica[i][j]!=matrica2.Matrica[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    else 
    return false;
}
template <typename Tip3>
bool operator !=(const Gmatrica<Tip3> &matrica,const Gmatrica<Tip3> &matrica2) {
    return !(matrica==matrica2);
}
template <typename Tip4>
Tip4 &Gmatrica<Tip4>::operator ()(int red,int kolona) {
    if(red<=0 || red>=this->brojredova || kolona<=0 || kolona>=this->brojkolona) {
        throw std::range_error("Nedozvoljen indeks");
    }
    return this->Matrica[red][kolona];
}

template <typename NekiTip>
std::ostream &operator<<(std::ostream &tok,const Gmatrica<NekiTip> &matrica) {
  for(int i=0;i<matrica.DajBrojRedova();i++) {
      for(int j=0;j<matrica.DajBrojKolona();j++) {
          tok<<std::setw(6)<<matrica.Matrica[i][j]<<" ";
      }
      tok<<std::endl;
  }
  return tok;
}
template <typename NekiDrugiTip>
std::istream &operator>>(std::istream &tok,Gmatrica<NekiDrugiTip> &matrica) {
    char znak;
    int broj(0),i(0),j(0);
    tok>>znak;
    if(znak!='[') tok.setstate(std::ios::failbit);
    while(tok.tellg()!=tok.eof()) {
    tok>>znak;
    while(znak!=';' && j<matrica.DajBrojKolona()) {
    tok>>broj>>znak;
    matrica[i][j]=broj;
    j++;
    }
    i++;
    j=0;
if(znak==']')
return tok;
else 
if(j==matrica.DajBrojKolona() && (znak!=';' || znak!=']')) {
tok.setstate(std::ios::failbit);
}
}
return tok;
}
int main ()
{
    std::cout<<"Budi lud,unesi nesto: ";
	return 0;
}