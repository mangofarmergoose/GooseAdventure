#include "control.hpp"
#include <iostream>
//takes float y as arg, returns row 
int GetRow(float y){
	return ((int)y-VERTICAL_OFFSET) / (GRIDSIZE+5);
}

//takes float x as arg, returns col 
int GetColumn(float x){
	return (int)x / (GRIDSIZE+5);
}
