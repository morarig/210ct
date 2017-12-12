#include "materials.h"

void materials::add_material(string name, unsigned weight, unsigned price_per_kg)
{
	materials_by_price.insert(pair<string, unsigned>(name, weight * price_per_kg));
	materials_by_weight.insert(pair<string, unsigned>(name, weight));
}


materials::materials()
{
}


materials::~materials()
{
}
