// Fish.cpp : the code that implements the 
// Fish class
//
//by Sosena Bekele
// date : April 6th 2014

#include <iostream>
#include <string>
#include <cmath> 

#include "Fish.h"
#include "FishTank.h"

using namespace std;


//Fish::Fish
// 	purpose : constructor that initializes a fish's
//  		 bitmap to all spaces,
//          its size and speed numbers to 0, 
//			its name to an empty string.
// 	arguments : none 
// 	returns : nothing (constructor doesn't have a type)
// 	effects : doesn't modify any array
//			 sets some of the private datas
Fish::Fish()
{
    // initializes a fish's bitmap to all spaces
    for (int row = 0 ; row < MAX_HGT ; row++){
    	for ( int col = 0 ; col < MAX_WID ; col++){
    		fish_arr[row][col] = ' ';
    	}
   	}
 
    // initialize fish's speed to 0
   	v_speed = 0.0;
   	h_speed = 0.0;
    // initialize fish's size to 0
   	height = 0;
   	width = 0;
    // initialize fish's name to empty string
    name_of_fish = " ";
    }

// Fish::print
// 	purpose : prints out the array that of fish bitmaps
// 	arguments : none 
// 	returns : nothing (void)
// 	effects : doesn't modify any array
// 	note    : public function

void Fish::print()
{
	
	 for (int row = 0 ; row < height ; row++){
    	for ( int col = 0 ; col < width + 1; col++){
    		cout << fish_arr[row][col] ;
    	}
   	cout << endl;
   	}

}

// Fish::readFish
// 	purpose : reads a fish specification from cin  
//			 if the first word is "fish", it sets the fish's state
//			according to the values and picture map read in and 
//			returns true
//			if the function cannot read a fish specification , 
//			it returns false
// 	arguments : none 
//	returns : returs false if the first input is invalid and true 
//			when it is a a fish specification
// 	effects : "modifies" the privata datas
// 	note    : public function

bool Fish::readFish()
{
	string line , type ;
	cin >> type >> height >> width >> row_pos >> col_pos
		>> v_speed >> h_speed >> name_of_fish;

	if (  (type != "fish") || (height < 0) || (height > MAX_HGT) ||
		(width < 0 ) || ( width > MAX_WID)) {
		return false;
	}else {
		for( int  row  = 0  ; row < height + 1; row++){
			getline(cin , line);
			for ( int col = 0 ; col < width  ; col++ ){
					if( row!= 0){ // first line that "getline" reads is 
								 // an empty line
						fish_arr[row - 1][col] = line[col];
					}
				}
			}
	
		return true;	
	}
	
}
// Fish:: getName
// 	purpose : returns the fish's name
// 	arguments : none 
// 	returns : returns the fish's name as a string
// 	effects : doesn't modify anything
// 	note    : public function

string Fish::getName()
{
	return name_of_fish;
}

//Fish::getHeight
// purpose : returns the height of the fish 
// arguments : none 
// returns : returns the height of the fish as an int
// effects : doesn't modify anything
// 	note    : public function


int Fish::getHeight()
{
	return height;
}
// Fish::getWidth
// 	purpose : returns the height of the fish 
// 	arguments : none 
// 	returns : nothing (void)
// 	effects : doesn't modify anything
// 	note    : public function


int Fish::getWidth()
{
	return width;
}

// Fish::setName
// 	purpose : set the fish's name to name 
// 	arguments : the fish's name as a string 
// 	returns : nothing (void)
// 	effects : modfies the privata data "name_of_fish"
// 	note    : public function

void Fish::setName( string name)
{
	name_of_fish = name;
}

// Fish::setHSpeed
// 	purpose : set the fish's horizontal speed to new_speed 
// 	arguments : the fish's new_speed as a float 
// 	returns : nothing (void)
// 	effects : modfies the privata data "h_speed"
// 	note    : public function

void Fish::setHSpeed(float new_speed)
{
	h_speed = new_speed ;
}

// Fish::setVSpeed
// 	purpose : set the fish's vertical speed to new_speed 
// 	arguments : the fish's new_speed as a float 
// 	returns : nothing (void)
// 	effects : modfies the privata data "v_speed"
// 	note    : public function


void Fish::setVSpeed(float new_speed)
{
	v_speed = new_speed ;	
}

// Fish::setPos
// 	purpose : set the fish's row and col position
// 	arguments : the fish's row and col as ints
// 	returns : nothing (void)
// 	effects : modfies the privata data "row_pos" and "col_pos"
// 	note: the privata datas are stored as floats
// 		  thus the ints values have to be casted
//		  public function


void Fish::setPos(int row , int col)
{

	 row_pos = (float) row ;
	 col_pos = (float) col ;
}

// Fish::check_for_space
// 	purpose : checks if a specifc element of the fish array
//			  is a empty space
// 	arguments : the row and col position of the element as ints
// 	returns : returns true if there is a space and false when there isn't
// 	effects : modfies the privata data "h_speed"
//  note     : private function( helper function)
//			   doesn't draw in the tank when there is a "hole" in the fish



bool Fish::check_for_space( int row , int col)
{
	if ( fish_arr[row][col] == ' ')
		return true;
	else
		return false; 
}

// Fish::move
// 	purpose : updates the fish's position according to its current
//			 position and horizontal and vertical speeds
// 	arguments : the tank's height and width
// 	returns : nothing (void)
// 	effects : modfies the privata data "row_pos" and "col_pos"
// 	note: the parameters are not used in this function 
//		  public function

void Fish::move(int tankHeight , int tankWidth)
{
	// not using the parameters
	(void) tankHeight;
	(void) tankWidth;

	row_pos = row_pos + v_speed;
	col_pos = col_pos + h_speed;
}


// Fish::draw
// 	purpose : draws the fish;s character map into the tank
// 	arguments : a pointer to a variable of type FishTank
// 	returns : nothing (void)
// 	effects : eventually modifies the tank ( via pointer)
// 	note: -the privata datas are stored as floats
//		    to draw a fish , they need to be converted into integers 		  
//          thus the float values have to be casted
//		 - public function
//		 - calls a public function in the FishTank class
	


void Fish::draw( FishTank *tank)
{


// casting ( "converting" the floats into ints)
	int col_as_int = (int) col_pos; 
	int row_as_int = (int) row_pos;

// the fish will be drawn until max_col of the tank array
	int max_col = width + col_as_int; 
// the fish will be draw on the tank until max_row of the tank array
 	int max_row = height + row_as_int;


 	for ( int row_f = 0 , row_t = row_as_int;
		  row_t < max_row ;
		  row_f++ , row_t++){

		for ( int col_f = 0 ,  col_t = col_as_int ;
		 	 col_t < max_col;
		  	col_f++ , col_t++){
			if ( check_for_space( row_f , col_f) != true){
				(*tank).updateAt( row_t , col_t , fish_arr[row_f][col_f]);
			}
		}	
	}
}
