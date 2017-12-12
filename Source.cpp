#include<iostream>
#include"materials.h"
using namespace std;

void display(map<string,unsigned> materials)//just to see display maps
{
	for (auto index = materials.begin(); index != materials.end(); index++)
	{
		cout << (*index).first << " ";
		cout << (*index).second << endl;
	}
}
void main()
{
	materials my_materaials;
	my_materaials.add_material("cocaina", 2, 99999);
	my_materaials.add_material("lapte", 20, 5);
	my_materaials.add_material("iphonee", 5, 10000);
	map<string, unsigned> cargo;
	unsigned lorry_capacity = 10, value = 0;
	bool finished_materials = 0;
	auto material = my_materaials.materials_by_price.begin();
	while (lorry_capacity >= my_materaials.materials_by_weight[material->first])
	{
		value += material->second;
		lorry_capacity -= my_materaials.materials_by_weight[material->first];
		cargo.insert(pair<string, unsigned>(material->first, my_materaials.materials_by_weight[material->first]));
		if (++material == my_materaials.materials_by_price.end())
		{
			finished_materials = 1;
			break;
		}
	}
	if (!finished_materials)
	{
		value += (material->second / my_materaials.materials_by_weight[material->first]) * lorry_capacity;
		cargo.insert(pair<string, unsigned>(material->first, lorry_capacity));
	}
	cout << "Max cargo value : " << value << endl;
	display(cargo);
}