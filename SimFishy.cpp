// SimFishy.cpp : main application file
//
//  Code by: Sosena Bekele
//     Date: April 6th 2014



#include <iostream>

#include "Fish.h"
#include "FishTank.h"

using namespace std;

int main()
{
	Fish joey;
	string type ;
	int height , width;
	bool singleStep = false;
// i is a counter that will tell me if the first 
// " fish input " is incorrect
	int i = 0 ;

	cin >> type >> height >> width;


	if ( ( type != "tank") || (height < 0) || ( width < 0 )){
		return -1;
	}else{
		FishTank tank( height , width);
		while( joey.readFish()!= false){
			tank.addFish(joey);
			i++;
		}
	// the program will stop if the first "fish " input is wrong
		if( (joey.readFish() != true) && (i == 0) ){
			cerr << "input for fish is incorrect" << endl;
			return 1 ;
		}

		tank.simulate( singleStep , 10);
	}

	return 0;
}
