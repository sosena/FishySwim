// FishTank.h : the FishTank interface :  class declaration
//
//by Sosena Bekele
// date : April 6th 2014


#ifndef FISHTANK_H
#define FISHTANK_H

#include <string>
using std::string;

#include "Fish.h"

class FishTank
{
public:
	FishTank();
	FishTank( int hgt , int wid);
	void simulate( bool singleStep , int fps);
	void showTank();
	void setHeight(int hgt);
	void setWidth(int wid);
	int getHeight();
	int getWidth();
	int getMaxFish();
	int getNumFish();
	bool addFish( Fish f);
	
	void clearTank();
	void updateAt( int row , int col , char newChar);
	
	
private:
	static const int MAX_FISH = 40;
	static const int MAX_HGT = 50;
	static const int MAX_WID = 200;	

	int width, height , amount_of_fish;
	int col_to_draw , row_to_draw; // new data members
	Fish fish[MAX_FISH];
	char tank_arr[MAX_HGT][MAX_WID];

	void home_cursor();
	void clear_screen();
	void wrap_around_hor( int col);
	void wrap_around_ver( int row);



};
#endif
