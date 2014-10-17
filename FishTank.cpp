// FishTank.cpp : the code that implement
// the FishTank class 
//
//
//by Sosena Bekele
// date : April 6th 2014



#include <iostream>
#include <string>

#include <unistd.h>

#include <cmath>

#include "FishTank.h"
#include "Fish.h"
#include <stdlib.h>

using namespace std;

//FishTank::FishTank
// Purpose: constructor that sets the integer
//			values to 0 and fills the tank picture with blanks
// arguments : none
// returns   : none ( constructor doesn't have a type

FishTank::FishTank()
{
 	width = 0 ;
 	height = 0;
 	amount_of_fish = 0;	

 	for( int i = 0 ; i < MAX_HGT ; i++){
 		for ( int j = 0 ; j < MAX_WID ; j++){
 			tank_arr[i][j] = ' ';
 		}
 	}
}


//FishTank::FishTank
// Purpose: constructor that sets the integer
//			values to the given values and fills the 
//			tank picture with blanks
// arguments : the height and width of the tank array as ints
// returns   : none ( constructor doesn't have a type


FishTank::FishTank( int hgt , int wid)
{
	width = wid ;
 	height = hgt;
 	amount_of_fish = 0;	

 	for( int i = 0 ; i < MAX_HGT ; i++){
 		for ( int j = 0 ; j < MAX_WID ; j++){
 			tank_arr[i][j] = ' ';
 		}
 	}

}

//FishTank::clear_screen
// Purpose: it clears the screen
// arguments : none
// returns   : none ( void)
// note      : private function


void FishTank::clear_screen()
{
	cout << "\033[2J";
} 


//FishTank::showTank
// Purpose: prints the character map on cout
// arguments : none
// returns   : none ( void)
// note      : public function


void FishTank::showTank()
{

	clear_screen();
	home_cursor();

	for( int i = 0 ; i < height ; i++){
		for ( int j = 0 ; j < width ; j++){
			cout << tank_arr[i][j];
		}
		cout << endl;  
	}
}

//FishTank::setHeight
// Purpose: sets the height of the tank array with the given
//			value
// arguments : the height of the tank as an int
// returns   : none ( void)
// effects   : modfies the private data "height"
// note      : public function

void FishTank::setHeight(int hgt)
{
	height = hgt;
}

//FishTank::setWidth
// Purpose: sets the width of the tank array with the given
//			value
// arguments : the width of the tank as an int
// returns   : none ( void)
// effects   : modfies the private data "width"
// note      : public function
void FishTank::setWidth(int wid)
{
	width = wid;
}

//FishTank::getHeight
// Purpose: returns the height of the tank array 
// arguments : none
// returns   : the height of the tank as an int
// note      : public function
int FishTank::getHeight()
{
	return height;
}


//FishTank::getWidth
// Purpose: returns the width of the tank array 
// arguments : none
// returns   : the width of the tank as an int
// note      : public function
int FishTank::getWidth()
{
	return width;
}

//FishTank::getMaxFish
// Purpose: returns the Maximum number of fish that 
//			the tank can hold
// arguments : none
// returns   : the maximum amount of fish as n int
// note      : public function
int FishTank::getMaxFish()
{
	return MAX_FISH;
}

//FishTank::getNumFish
// Purpose: returns  number of fish in the tank
// arguments : none
// returns   : the amount of fish in the tank as an int
// note      : public function

int FishTank::getNumFish()
{
	return amount_of_fish;
}


//FishTank::addFish
// Purpose: adds the given fish to the tank if there is room in the tank
// 			and returns true. It returns false and doesn't modify the tank
//			if there is no more room for new fish
// arguments : an object fish
// returns   : returns true if there is room in the tank and false when
//				there isn't
// note      : public function


bool FishTank::addFish( Fish f)
{
	if ( ( amount_of_fish > MAX_FISH) && ( amount_of_fish <= 0) ){
		return false;
	} else{
		fish[ amount_of_fish ] = f;
		amount_of_fish++;
		return true;
	}
}

//FishTank::updataAt
// Purpose: updates the character map at the given row and column with 
// 			the new character 
// arguments : the row and col sent in from draw as an int
//				the character as a char
// returns   : void 
// note      : public  function
void FishTank::updateAt( int row , int col , char newChar)
{

	wrap_around_hor(col);
	wrap_around_ver(row);

	tank_arr[row_to_draw][col_to_draw] = newChar;

}

//FishTank::vrap_around_ver
// Purpose: asseses the value of row depending if it excedes the 
//			tankHeight
// arguments : the row sent in from draw as an int( via updateAt)
// returns   : void 
// note      : private function



void FishTank::wrap_around_ver( int row)
{
	int coef_row ;

	int r_abs = abs(row);

	if( row < 0 ){
		coef_row =  (r_abs / height) + 1; 
	}
	if ( row > 0){
		 coef_row = r_abs / height ;
	}

	if( row >= height){
		row_to_draw = row - ( coef_row * height);
	}
	if ( row < 0){
		row_to_draw = row + ( coef_row * height) ;
	}

	if( ( row < height) && (row >=0)){
		row_to_draw = row;
	}
}

//FishTank::vrap_around_hor
// Purpose: asseses the value of col depending if it excedes the 
//			tankWidth
// arguments : the col sent in from draw as an int( via updateAt)
// returns   : void 
// note      : private function
void FishTank::wrap_around_hor( int col)
{
	int coef_col;

	int c_abs = abs(col);

	if ( col < 0){
		 coef_col = (c_abs/ width )+ 1 ;
	}
	if ( col >= 0){
		 coef_col = c_abs/ width;
	}

	if( col >= width){
		col_to_draw= col - ( coef_col * width);
	}
	if ( col < 0){
		col_to_draw = col + ( coef_col * width);
	}

	if( ( col < width) && (col >= 0)){
		col_to_draw = col;
	}
}


//FishTank::simulate
// Purpose: runs the tank simulaton
// arguments : the number of frames per second as an int
//			  a bool singlestep
// returns   : void 
// note      : public  function
//			  if singlestep is true ,the simulation pauses
//			after displaying each frame until the user types a 
//			carriage return 
//			  if singlestep is false , it sleeps between frames
void FishTank::simulate( bool singleStep , int fps)
{
	

	float amount_of_time = float(1) / ( float( fps) ); 
	int converter = pow(10 , 6);

	
	while( true){

		for( int j = 0 ; j < amount_of_fish  ; j++){
			fish[j].draw(this);
			fish[j].move( height , width);
			
		}
		
		showTank();
		clearTank();
		if ( singleStep != false){
			if ( system("read x < /dev/tty") != 0){
			exit(0);
			}
		}else{
			
			usleep(amount_of_time * float(converter) );
		}		

	}
}

//FishTank::home_cursor
// Purpose: home's the cursor
// arguments : none
// returns   : void
// note      : private function



void FishTank::home_cursor()
{
	cout << "\33[H";
}

//FishTank::clearTank
// Purpose: clears the character map : fills with space		
// arguments : none
// returns   : void
// note      : public function


void FishTank::clearTank()
{
	for( int i = 0 ; i < MAX_HGT ; i++){
 		for ( int j = 0 ; j < MAX_WID ; j++){
 			tank_arr[i][j] = ' ';
 		}
 	}	
}








