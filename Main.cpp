#include <iostream>
#include "canny.hpp"
#include "erodeDilate.hpp"
#include "resizing.hpp"
#include "stitching.hpp"
//#include "britness.hpp"

using namespace std;

int main(int argc, char** argv)
{
	char* functionName =argv[0];
	bool flag = true;
	while(flag){
		switch (functionName)
		{
			case 'canny'
				//fct canny
				flag = false;
				break;
			case 'erodeDilate'
				//fct erodeDilate
				flag = false;
				break;
			case 'resizing'
				//fct resizing
				flag = false;
				break;
			case 'stitching'
				//fct stitching
				flag = false;
				break;
			case 'canny'
				//fct canny
				flag = false;
				break;
			default
				cout << "Fonction non existante. Veuillez choisir une nouvelle fonction !!!" ;
				cin >> functionName;
				break;
		}
	}

    return 0;
}
