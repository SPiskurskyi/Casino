#ifndef BAR
#define BAR

#include "Guest.h"

void create_phrase();

class Bar
{
private:
	fstream BarFile;
	string Name;
	int Price;
	int id;
	char Quantity;
	string path = "../assortment";
public:
	bool MakeOrder(int id,Guest& obj);
	void ShowAsortement();
	static int drunkenness;
};

 /////////////////////////////////////////////////////////////////////////
 
#endif
