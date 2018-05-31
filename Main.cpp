#include <iostream>
#include "canny.hpp"
#include "erodeDilate.hpp"
#include "resizing.hpp"
#include "stitching.hpp"
//#include "brightness.hpp"

using namespace std;

int main(int argc, char** argv)
{
	char* functionName =argv[0];
	bool flag = true;
	while(flag){
		switch (functionName)
		{
			case 'canny'
				//fct canny(argv[1])
				flag = false;
				break;
			case 'erodeDilate'
				//fct erodeDilate(argv[1])
				flag = false;
				break;
			case 'resizing'
				//fct resizing(argv[1])
				flag = false;
				break;
			case 'stitching'
				//fct stitching(argv[1])
				flag = false;
				break;
			case 'brightness'
				//bright(argv[1]);
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
