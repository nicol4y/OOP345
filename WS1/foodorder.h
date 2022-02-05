#ifndef SDDS_FOODORDER_H_
#define SDDS_FOODORDER_H_
#include <iostream>
#include <iomanip>
#include <fstream>
extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {

	class FoodOrder {
		char name[10];
		char desc[25];
		double price = 0;
		bool day = true;
		int rael = 0;
	public:
		FoodOrder();
		
		void read(std::istream& istr);
		void display();
		FoodOrder& operator=(const FoodOrder& jj);
	};
	
}
	
#endif // SDDS_FOODORDER_H