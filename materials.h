#pragma once
#include<string>
#include<map>
#include<iostream>
using namespace std;
class materials
{
public:
	//maps are lists of pairs of data , indexed by the first element and AUTOMATICALLY sorted by the second
	map<string, unsigned> materials_by_price;//full price , not pr kg
	map<string, unsigned> materials_by_weight;
	void add_material(string material_name,unsigned material_weight,unsigned material_price_per_kg);
	materials();
	~materials();
};

