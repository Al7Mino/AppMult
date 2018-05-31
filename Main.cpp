#include <iostream>
#include "canny.hpp"
#include "erodeDilate.hpp"
#include "resizing.hpp"
//#include "stitching.hpp"
//#include "britness.hpp"

using namespace std;

int main(int argc, char** argv)
{
	string functionName;
	cout << "Bienvenue sur le super logiciel Pimp my Gimp !  Veuillez choisir parmi les fonctions suivantes : canny, erodeDilate, resizing";
	cin >> functionName;
	
	string tab[] = {"canny", "erodeDilate", "resizing"};
	int select = -1;
	while(select==-1) {
		for(int i=0; i<3; i++) {
			if(functionName==tab[i]) {
				select = i;
			}
		}
		if(select==-1){
			cout << "Fonction non existante. Veuillez choisir parmi les fonctions suivantes : ";
			cin >> functionName;
		}
	}
	switch (select) {
		case 0:
			canny();
			break;
		case 1:
			erodeDilate();
			break;
		case 2:
			resize();
			break;
		default:
			break;
	}
    return 0;
}
