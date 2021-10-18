auto it=lista.begin();
while(it!=lista.end() && br_vracenih<n)
{
    if(NazivBoje(it->first) == red.front().first) {
        if(it->second < red.front().second) {
            while(it!=lista.end() && NazivBoje(it->first) == red.front().first && it->second < red.front().second) it++;
            it--; //jer smo otisli mjesto iza
        }
        lista.insert(it, {it->first, red.front().second} );
        red.pop();
        br_vracenih++;
    } else it++;
}