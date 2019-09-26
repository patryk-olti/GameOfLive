#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

struct Osobnik
{
    int x;
    int y;
};

void rysujMape(int wys, int szer)
{
    char tab[wys][szer];        // - ramka

    for(int i=0; i<wys; i++){
        for(int j=0; j<szer; j++){
            tab[i][j] = ' ';
        }
    }

    for(int i=0; i<wys; i++){
        for(int j=0; j<szer; j++){

            if(i==0 && j>0 && j<szer){  tab[i][j] = 205;    }
            if(i==wys-1 && j>0 && j<szer){  tab[i][j] = 205;    }
            if(i>0 && i<wys && j == 0){ tab[i][j] = 186;    }
            if(i>0 && i<wys && j == szer-1){ tab[i][j] = 186;    }

            if(i==0 && j==0){       tab[i][j] = 201;    }
            if(i==0 && j==szer-1){    tab[i][j] = 187;    }
            if(i==wys-1 && j==0){     tab[i][j] = 200;    }
            if(i==wys-1 && j==szer-1){  tab[i][j] = 188;    }
        }
    }

    for(int i=0; i<wys; i++){
        cout<<endl;
        for(int j=0; j<szer; j++){
            cout<<tab[i][j];
        }
    }
    cout<<endl<<endl;
}


Osobnik losuj(int wys, int szer)
{
    int x, y;
    srand(time(NULL));

    x = rand()%(wys-1)+1;
    y = rand()%(szer-1)+1;

    Osobnik osoba;
    osoba.x = x;
    osoba.y = y;

    return osoba;
}

void aktualizujMape(vector <Osobnik> tab, int liczebnosc)
{
    for(int i=0; i<liczebnosc; i++){

    }
}


int main()
{
    int wys = 20;
    int szer = 40;
    int liczebnosc = 10;
    int time = 10;

    // GENEROWANIE NOWYCH OSOBNIKOW
    vector <Osobnik> tab;
    Osobnik o;
    bool petla_dziala = true;
    cout<<tab.size()<<endl;
    tab.push_back(losuj(wys,szer));
    cout<<tab.size()<<endl;

    for(int k=0; k<liczebnosc; k++){
        petla_dziala = true;
        while(petla_dziala){
            o = losuj(wys, szer);
            for(int i=0; i<tab.size(); i++){
                if(!((tab[i].x != o.x) && (tab[i].y != o.y))){
                    i = tab.size();
                }
                else{
                    if(i+1 == tab.size()){
                        tab.push_back(o);
                        petla_dziala = false;
                    }
                }
            }
        }
        cout<<"Osobnik nr. "<<k<<" x = "<<tab[k].x<<" y = "<<tab[k].y<<" size: "<<tab.size()<<endl;
    }

    // KONIEC GENEROWANIA

    rysujMape(wys, szer);



    system("pause");
    return 0;
}
