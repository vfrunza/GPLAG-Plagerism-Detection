#include <stdio.h>

char* zamjena_rijeci(char* tekst, char** rijeci,char** zamjene, int broj_rijeci)
{
    char* tmp=tekst;
    char* tmp1;
    char* tmp2;
    char* tmp3;
    char* kraj;
    int znak=0;
    int i=0;
    int logik=0,k,l,m,n=0,j;
    int prosliznak=0;
    int duzina_rijeci=0;
    while(*tmp!='\0')
    {
        tmp++;
    }
    kraj=tmp;
    tmp=tekst;
    while(*tmp!='\0')
    {
        i=0;
        
        prosliznak=znak;
        if(*tmp==' ')
        znak=0;
        else
        znak=1;
        
        if(znak==1 && prosliznak==0)
        {
            duzina_rijeci=0;
            duzina_rijeci++;
            if(*(tmp+1)=='\0')
            {
            while(i<broj_rijeci)
            {
                tmp1=rijeci[i];
                
                for(j=0;j<=duzina_rijeci-1;j++)
                {
                    if(*tmp1==*(tmp+1-duzina_rijeci+j))
                    {
                        logik=1;
                        tmp1++;
                    }
                    else
                    {
                        logik=0;
                        break;
                    }
                }
                
                if(logik==0)
                {i++;
                continue;
                }    
                else
                {
                    if(*tmp1=='\0' || *tmp1==' ')
                    {
                       k=0;
                       tmp2=zamjene[i];
                       while(*tmp2!='\0')
                       {
                           k++;
                           tmp2++;
                       }
                       
                       if(k==duzina_rijeci)
                       {
                           tmp2=zamjene[i];
                           for(j=0;j<=duzina_rijeci-1;j++)
                           {
                               *(tmp+1-duzina_rijeci+j)=*(tmp2+j);
                               
                               
                               
                               
                               
                           }
                           
                        i++;   
                       }
                       if(k<duzina_rijeci)
                       {
                          tmp2=zamjene[i];
                           for(j=0;j<=k-1;j++)
                           {
                               *(tmp+1-duzina_rijeci+j)=*(tmp2+j);
                               
                           } 
                           tmp2=tmp+1-duzina_rijeci+k;
                           tmp3=tmp2;
                           for(j=k;j<=duzina_rijeci-1;j++)
                           {
                               while(*tmp2!='\0')
                               {
                                   *tmp2=*(tmp2+1);
                                   tmp2++;
                               }
                               tmp2=tmp3;
                           }
                           tmp=tmp-duzina_rijeci+k;
                            kraj=kraj+duzina_rijeci-k;
                         i++;  
                       }
                      
                       
                       if(k>duzina_rijeci)
                       {
                          tmp2=kraj;
                          for(j=duzina_rijeci;j<=k-1;j++)
                           {
                                while(tmp2!=tmp)
                                {
                                    *(tmp2+1)=*tmp2;
                                    tmp2--;
                                }
                                *(tmp2+1)=*tmp2;
                                tmp2=++kraj;
                          
                           }
                         
                          tmp2=zamjene[i];
                           for(j=0;j<=k-1;j++)
                           {
                               *(tmp+1-duzina_rijeci+j)=*(tmp2+j);
                            
                           }
                          
                        tmp=tmp+duzina_rijeci-k;
                         i++;  
                           
                       }
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                    }
                    else 
                    {i++;
                    continue;
                    }
                    
                    
                    
                    
                    
                }
                    
                    
                                    
                
                
                
                
                
            }
            
            
            
            
        }
            tmp++;
            continue;
        }
        
        if(znak==1 && prosliznak==1)
        {
            duzina_rijeci++;
            
            if(*(tmp+1)=='\0')
            {
            while(i<broj_rijeci)
            {
                tmp1=rijeci[i];
                
                for(j=0;j<=duzina_rijeci-1;j++)
                {
                    if(*tmp1==*(tmp+1-duzina_rijeci+j))
                    {
                        logik=1;
                        tmp1++;
                    }
                    else
                    {
                        logik=0;
                        break;
                    }
                }
                
                if(logik==0)
                {i++;
                continue;
                }    
                else
                {
                    if(*tmp1=='\0' || *tmp1==' ')
                    {
                       k=0;
                       tmp2=zamjene[i];
                       while(*tmp2!='\0')
                       {
                           k++;
                           tmp2++;
                       }
                       
                       if(k==duzina_rijeci)
                       {
                           tmp2=zamjene[i];
                           for(j=0;j<=duzina_rijeci-1;j++)
                           {
                               *(tmp+1-duzina_rijeci+j)=*(tmp2+j);
                               
                               
                               
                               
                               
                           }
                           
                        i++;   
                       }
                       if(k<duzina_rijeci)
                       {
                          
                          tmp2=zamjene[i];
                           for(j=0;j<=k-1;j++)
                           {
                               *(tmp+1-duzina_rijeci+j)=*(tmp2+j);
                               
                           } 
                           tmp2=tmp+1-duzina_rijeci+k;
                           tmp3=tmp2;
                           for(j=k;j<=duzina_rijeci-1;j++)
                           {
                               while(*tmp2!='\0')
                               {
                                   *tmp2=*(tmp2+1);
                                   tmp2++;
                               }
                               tmp2=tmp3;
                           }
                           tmp=tmp-k+duzina_rijeci;
                            kraj=kraj+duzina_rijeci-k;
                         i++;  
                         
                       }
                      
                       
                       if(k>duzina_rijeci)
                       {
                          tmp2=kraj;
                          for(j=duzina_rijeci;j<=k-1;j++)
                           {
                                while(tmp2!=tmp)
                                {
                                    *(tmp2+1)=*tmp2;
                                    tmp2--;
                                }
                                *(tmp2+1)=*tmp2;
                                tmp2=++kraj;
                          
                           }
                         
                          tmp2=zamjene[i];
                           for(j=0;j<=k-1;j++)
                           {
                               *(tmp+1-duzina_rijeci+j)=*(tmp2+j);
                            
                           }
                         
                         tmp=tmp+k-duzina_rijeci;
                        
                      i++;  
                           
                       }
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                    }
                    else 
                    {i++;
                    continue;
                    }
                    
                    
                    
                    
                    
                }
                    
                    
                                    
                
                
                
                
                
            }
            
            
            
            
        }
            tmp++;
            continue;
        }
        
        if(znak==0 && prosliznak==1)
        {
            while(i<broj_rijeci)
            {
                tmp1=rijeci[i];
                
                for(j=0;j<=duzina_rijeci-1;j++)
                {
                    if(*tmp1==*(tmp-duzina_rijeci+j))
                    {
                        logik=1;
                        tmp1++;
                    }
                    else
                    {
                        logik=0;
                        break;
                    }
                }
                
                if(logik==0)
                {i++;
                continue;
                }    
                else
                {
                    if(*tmp1=='\0' || *tmp1==' ')
                    {
                       k=0;
                       tmp2=zamjene[i];
                       while(*tmp2!='\0')
                       {
                           k++;
                           tmp2++;
                       }
                       
                       if(k==duzina_rijeci)
                       {
                           tmp2=zamjene[i];
                           for(j=0;j<=duzina_rijeci-1;j++)
                           {
                               *(tmp-duzina_rijeci+j)=*(tmp2+j);
                               
                               
                               
                               
                               
                           }
                           
                        i++;   
                       }
                       if(k<duzina_rijeci)
                       {
                          tmp2=zamjene[i];
                           for(j=0;j<=k-1;j++)
                           {
                               *(tmp-duzina_rijeci+j)=*(tmp2+j);
                               
                           } 
                           tmp2=tmp-duzina_rijeci+k;
                           tmp3=tmp2;
                           for(j=k;j<=duzina_rijeci-1;j++)
                           {
                               while(*tmp2!='\0')
                               {
                                   *tmp2=*(tmp2+1);
                                   tmp2++;
                               }
                               tmp2=tmp3;
                           }
                           
                            kraj=kraj+duzina_rijeci-k;
                         i++;  
                         tmp=tmp-duzina_rijeci+k;
                       }
                      
                       
                       if(k>duzina_rijeci)
                       {
                          tmp2=kraj;
                          for(j=duzina_rijeci;j<=k-1;j++)
                           {
                                while(tmp2!=tmp)
                                {
                                    *(tmp2+1)=*tmp2;
                                    tmp2--;
                                }
                                *(tmp2+1)=*tmp2;
                                tmp2=++kraj;
                          
                           }
                         
                          tmp2=zamjene[i];
                           for(j=0;j<=k-1;j++)
                           {
                               *(tmp-duzina_rijeci+j)=*(tmp2+j);
                            
                           }
                         
                        
                         i++;  
                         tmp=tmp+duzina_rijeci-k;  
                       }
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                       
                    }
                    else 
                    {i++;
                    continue;
                    }
                    
                    
                    
                    
                    
                }
                    
                    
                                    
                
                
                
                
                
            }
            
            
            
            
        }
        
        
        
        
        
        
        
        
        
        
        
   tmp++; }
    
    
    
    
return tekst;
}















int main() {
char* rijeci[2] = { "test" };
char* zamjene[2] = { "zamjena" };
char tekst[100] = "test test";
printf("%s", zamjena_rijeci(tekst, rijeci, zamjene, 1));
	return 0;
}
