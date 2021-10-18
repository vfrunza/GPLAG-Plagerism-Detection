/B16/17 (Zadaća 5, Zadatak 4)
//Autotestovi by Ivona Ivkovic (mail: iivkovic2@etf.unsa.ba)
//Za autotestove se obracati *iskljucivo* osobi koja ih pise
#include <iostream>
#include <stdexcept>
#include <vector>
#include <initializer_list>
#include <iomanip>
using std::vector;

template <typename tip>
class GMatrica{
    tip matrica[4][4];
    int broj_redova, broj_kolona;
    public:
    GMatrica(): broj_redova(0), broj_kolona(0){ };
    GMatrica(int br_redova, int  br_kolona, tip postavi=tip()): broj_redova(br_redova), broj_kolona(br_kolona){
        if (br_kolona>4 || br_kolona<0 || br_redova>4 || br_redova<0) throw std::logic_error ("Ilegalan format matrice");
        for (int i=0; i<broj_kolona; i++){
            for (int j=0; j<broj_redova; j++){
                matrica[i][j]=postavi;
            }
        }
    }
    template <typename tip2>
    GMatrica(GMatrica<tip2> m){
        for (int i=0; i<m.broj_redova; i++){
            for (int j=0; j<m.broj_kolona; j++){
                matrica[i][j]=m[i][j];
            }
        }
        broj_redova=m.broj_redova;
        broj_kolona=m.broj_kolona;
    }
    template <typename tip3>
    GMatrica(tip3 mat[4][4]): broj_kolona(4), broj_redova(4){
        for (int i=0; i<4; i++){
            for (int j=0; j<4; j++){
                matrica[i][j]=mat[i][j];
            }
        }
    }
    GMatrica(vector<vector<tip>> v){
        if (v.size()>4 || v[0].size())throw std::logic_error("Ilegalan format matrice!");
        int a=v[0].size();
        for (int i=0; i<v.size(); i++){
            if (v[i].size()!=a){throw std::logic_error("Ilegalan format matrice!");}
        }
        broj_kolona=v[0].size(); broj_redova=v.size();
        for (int i=0; i<broj_redova; i++){
            for (int j=0; j<broj_kolona; j++){
                matrica[i][j]=v[i][j];
            }
        }
    }
    GMatrica(std::initializer_list<std::initializer_list<tip>>l){
        auto it(l.begin());
        if (l.size()<0 || l.size()>4|| it->size()<0 || it->size()>4) throw std::logic_error("Ilegalan format matrice!");
        //napravi for petlju;
        
        broj_kolona=it->size();
        broj_redova=l.size();
        for (int i=0; i<broj_redova; i++){
            auto it2=it->begin();
            for (int j=0; j<broj_kolona; j++){
                matrica[i][j]=*it2++;
            }
            it++;
        }
    }
    tip *operator[](int redovi) {
        return matrica[redovi];
    }
    auto operator ()(int redovi,int kolone)-> decltype(matrica[0][0]);
    auto operator ()(int redovi,int kolone)const-> decltype(matrica[0][0]+matrica[0][0]);
    int DajBrojKolona() const{ return broj_kolona;}
    int DajBrojRedova() const{return broj_redova;}
    template <typename TipEl>
    friend GMatrica<TipEl> operator +(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2);
    template <typename TipEl>
    friend GMatrica<TipEl> operator -(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2);
    template <typename TipEl>
	friend std::ostream &operator <<(std::ostream &tok, GMatrica<TipEl> &m);
	
	template <typename TipEl>
	friend GMatrica<TipEl> operator *(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2);
	template <typename TipEl, typename tip2>
	friend GMatrica<TipEl> operator *(tip2 n, const GMatrica<TipEl> &m2);
	template <typename TipEl, typename tip2>
	friend GMatrica<TipEl> operator *(const GMatrica<TipEl> &m1,tip2 n );
	
	template <typename TipEl>
	    friend GMatrica<TipEl> &operator +=(GMatrica<TipEl> &m1, GMatrica<TipEl> &m2);
	template <typename TipEl, typename tip2>
	    friend GMatrica<TipEl> &operator +=(GMatrica<TipEl> &m1, tip2 n );
	
	template <typename TipEl>
	    friend GMatrica<TipEl> &operator -=(GMatrica<TipEl> &m1,GMatrica<TipEl> &m2);
	template <typename TipEl, typename tip2>
    	friend GMatrica<TipEl> &operator -=(GMatrica<TipEl> &m1, tip2 n );
	
	template <typename TipEl>
    	friend GMatrica<TipEl> &operator *=(GMatrica<TipEl> &m1, GMatrica<TipEl> &m2);
	template <typename TipEl, typename tip2>
	    friend GMatrica<TipEl> &operator *=(GMatrica<TipEl> &m1,tip2 n);
	    
	    template <typename TipEl>
    	friend bool operator ==(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2);
	template <typename TipEl>
	    friend bool operator !=(const GMatrica<TipEl> &m1,const GMatrica<TipEl> &m2);
};
template <typename Tip11>
auto GMatrica<Tip11>::operator ()(int redovi,int kolone)->decltype(matrica[0][0]){
    if(redovi<0 || redovi>4 || kolone<0 || kolone>4) throw std::logic_error("Ilegalan format matrice");
    return matrica[redovi-1][kolone-1];
}
template <typename Tip11>
auto GMatrica<Tip11>::operator ()(int redovi,int kolone)const ->decltype(matrica[0][0]+matrica[0][0]){
    if(redovi<0 || redovi>4 || kolone<0 || kolone>4) throw std::logic_error("Ilegalan format matrice");
    return matrica[redovi-1][redovi-1];
}
template <typename TipEl>
    	bool operator ==(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2){
    	    if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) return false;
    	    for (int i=0; i<m1.broj_redova; i++){
    	        for (int j=0; j<m1.broj_kolona; j++){
    	            if (m1.matrica[i][j]!=m2.matrica[i][j]) return false;
    	        }
    	    }
    	return true;
    	}
	template <typename TipEl>
	    bool operator !=(const GMatrica<TipEl> &m1,const GMatrica<TipEl> &m2){
	        if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) return true;
    	    for (int i=0; i<m1.broj_redova; i++){
    	        for (int j=0; j<m1.broj_kolona; j++){
    	            if (m1.matrica[i][j]!=m2.matrica[i][j]) return true;
    	        }
    	    }
    	return false;
	    }
template <typename TipEl>
	GMatrica<TipEl> &operator +=(GMatrica<TipEl> &m1,GMatrica<TipEl> &m2){
	    if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    		for(int i = 0; i < m1.broj_redova; i++){
    			for(int j = 0; j < m1.broj_kolona; j++){
    			m1.matrica[i][j] += m2.matrica[i][j];
    			}
    		}
    		return m1;
	}
	template <typename TipEl, typename tip2>
	GMatrica<TipEl> &operator +=(GMatrica<TipEl> &m1,tip2 n ){
	    //if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    		for(int i = 0; i < m1.broj_redova; i++){
    			for(int j = 0; j < m1.broj_kolona; j++){
    			m1.matrica[i][j] += n;
    			}
    		}
    		return m1;
	}
	
	template <typename TipEl>
	GMatrica<TipEl> &operator -=(GMatrica<TipEl> &m1, GMatrica<TipEl> &m2){
	     if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    		for(int i = 0; i < m1.broj_redova; i++){
    			for(int j = 0; j < m1.broj_kolona; j++){
    			m1.matrica[i][j] -= m2.matrica[i][j];
    			}
    		}
    		return m1;
	}
	template <typename TipEl, typename tip2>
	GMatrica<TipEl> &operator -=(GMatrica<TipEl> &m1,tip2 n){
    		for(int i = 0; i < m1.broj_redova; i++){
    			for(int j = 0; j < m1.broj_kolona; j++){
    			m1.matrica[i][j] -= n;
    			}
    		}
    		return m1;
	}
    template <typename TipEl>
	GMatrica<TipEl> &operator *=(GMatrica<TipEl> &m1, GMatrica<TipEl> &m2){
	    if(m1.broj_kolona != m2.broj_redova) throw std::domain_error("Nedozvoljena operacija");
		GMatrica<TipEl> m3(m1.broj_redova, m2.broj_kolona);
		for(int i = 0; i < m1.broj_redova; i++){
			for(int j = 0; j < m2.broj_kolona; j++){
				for (int k=0; k<m1.broj_kolona; k++){
					m3.matrica[i][j] += m1.matrica[i][k] * m2.matrica[k][j];
				}
			}
		}
		for(int i = 0; i < m1.broj_redova; i++){
			for(int j = 0; j < m2.broj_kolona; j++){
			    m1.matrica[i][j]=m3.matrica[i][j];
			}
		}
		m1.broj_redova=m2.broj_kolona;
	return m1;
	    
	}
	template <typename TipEl, typename tip2>
	GMatrica<TipEl> &operator *=(GMatrica<TipEl> &m1, tip2 n ){
	    //if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    		for(int i = 0; i < m1.broj_redova; i++){
    			for(int j = 0; j < m1.broj_kolona; j++){
    			m1.matrica[i][j] *= n;
    			}
    		}
    		return m1;
	}

    template <typename TipEl>
    GMatrica<TipEl> operator +(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2){
    		if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    		GMatrica<TipEl> m3(m1.broj_redova, m1.broj_kolona);
    		for(int i = 0; i < m1.broj_redova; i++){
    			for(int j = 0; j < m1.broj_kolona; j++){
    				m3.matrica[i][j] = m1.matrica[i][j] + m2.matrica[i][j];
    			}
    		}
    		m3.broj_kolona=m1.broj_kolona; m3.broj_redova=m1.broj_redova;
    	return m3;
    }
    template <typename TipEl>
	std::ostream &operator <<(std::ostream &tok, GMatrica<TipEl> &m){
	    int n=tok.width();
	    if (n<6) n=6;
		for(int i = 0; i < m.broj_redova; i++) {
			for(int j = 0; j < m.broj_kolona; j++){
				tok<< std::setw(n)<<m.matrica[i][j];
			}
		tok << std::endl;
		}
		return tok;
	}
	template <typename TipEl, typename tip2>
	GMatrica<TipEl> operator *(tip2 n, const GMatrica<TipEl> &m2){
	    GMatrica<TipEl> m3(m2.broj_redova, m2.broj_kolona);
	    for (int i=0; i<m2.broj_redova; i++){
	        for (int j=0; j<m2.broj_kolona; j++){
	            m3.matrica[i][j]=n*m2.matrica[i][j];
	        }
	    }
	    m3.broj_kolona=m2.broj_kolona;
	    m3.broj_redova=m2.broj_redova;
	    return m3;
	}
	template <typename TipEl, typename tip2>
	 GMatrica<TipEl> operator *(const GMatrica<TipEl> &m1,tip2 n ){
	     GMatrica<TipEl> m3(n*m1);
	     return m3;
	 }
    template <typename TipEl>
    GMatrica<TipEl> operator -(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2){
    		if(m1.broj_redova != m2.broj_redova || m1.broj_kolona != m2.broj_kolona) throw std::domain_error("Matrice nemaju jednake dimenzije!");
    		GMatrica<TipEl> m3(m1.broj_redova, m1.broj_kolona);
    		for(int i = 0; i < m1.broj_redova; i++){
    			for(int j = 0; j < m1.broj_kolona; j++){
    				m3.matrica[i][j] = m1.matrica[i][j] - m2.matrica[i][j];
    			}
    		}
    	return m3;
    }
    template <typename TipEl>
	GMatrica<TipEl> operator *(const GMatrica<TipEl> &m1, const GMatrica<TipEl> &m2){
		if(m1.broj_kolona != m2.broj_redova) throw std::domain_error("Nedozvoljena operacija");
		GMatrica<TipEl> m3(m1.broj_redova, m2.broj_kolona);
		for(int i = 0; i < m1.broj_redova; i++){
			for(int j = 0; j < m2.broj_kolona; j++){
				for (int k=0; k<m1.broj_kolona; k++){
					m3.matrica[i][j] += m1.matrica[i][k] * m2.matrica[k][j];
				}
			}
		}
		m3.broj_kolona=m1.broj_redova; 
		m3.broj_redova=m2.broj_kolona;
	return m3;
	}
		
	 
int main ()
{  
	return 0;
}