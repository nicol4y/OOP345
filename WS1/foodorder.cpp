#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstring>
#include "foodorder.h"
#include "foodorder.h"
using namespace std;
    double g_dailydiscount;
	double g_taxrate;
namespace sdds {
	FoodOrder::FoodOrder() {
		FoodOrder::name[0] = '\n';
		FoodOrder::desc[0] = '\n';
		FoodOrder::price = 0;
		FoodOrder::day = 0;
		FoodOrder::rael = 0;
	}

	void FoodOrder::read(std::istream& istr) {
	
		char ss[] = "Y";
		
		
		char ll[256];

if(istr.getline(ll,256)){
int nn = 0;
int know = 0;
char* cod = strtok(ll, ",");
 while(cod){
if(nn == 0){
strcpy(FoodOrder::name,cod);

}
if(nn == 1){
strcpy(FoodOrder::desc,cod);

}
if(nn == 2){
FoodOrder::price = atof(cod);

}
if(nn == 3){

if(strcmp(cod,ss) == 1){
know = 1;

}

}

cod = strtok(NULL, ",");
nn++;
}
FoodOrder::day = know;
FoodOrder::rael = 1;
}
else{
FoodOrder::rael = 0;
}


	
	}
	void FoodOrder::display() {
static int count = 0;
count++;		
cout << left << setw(2) << count;
if(FoodOrder::rael == 1){
		
		
cout << ". " << left << setw(10)<< FoodOrder::name << "|" << left << setw(25) << FoodOrder::desc << "|" << left << setw(12)<< fixed << showpoint<< setprecision(2)<<FoodOrder::price + (FoodOrder::price*g_taxrate) << "|";

if (FoodOrder::day == 1) {
		
cout  <<right <<showpoint<< setprecision(2) <<setw(13)<<(FoodOrder::price + (FoodOrder::price*g_taxrate))- g_dailydiscount;
		}
		
	
		
}
else{
cout << ". No Order";
}
cout <<"\n" ;
	}
	

FoodOrder& FoodOrder::operator=(const FoodOrder& D){
 strcpy(FoodOrder::name,D.name);
 strcpy(FoodOrder::desc,D.desc);
 FoodOrder::price = D.price;
FoodOrder::rael = 1;
FoodOrder::day = D.day;
return *this;
}
}	
