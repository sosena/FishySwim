// FishTank.h : the Fish interface :  class declaration
//
//by Sosena Bekele
// date : April 6th 2014



#ifndef FISH_H
#define FISH_H

#include <string>
using std::string;

class FishTank;  // Can't include FishTank.h; it includes Fish.h

// place it in private?


class Fish
{
public:
	Fish();
	void print();
	bool readFish();

	string getName();
	void setName( string name);
	void setHSpeed(float new_speed);
	void setVSpeed(float new_speed);
	void setPos(int row , int col);
	int getHeight();
	int getWidth();

	void move(int tankHeight , int tankWidth);
	void draw(FishTank *tank);
	
	
private:
	static const int MAX_HGT = 30;
	static const int MAX_WID = 60;

// old data members
	float row_pos , col_pos , v_speed , h_speed; 
	int height , width ;
	string name_of_fish;
	char fish_arr[MAX_HGT][MAX_WID];

// new data members

	bool check_for_space( int row , int col);

	
	
};

#endif
