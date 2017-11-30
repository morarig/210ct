#include<iostream>
#include<fstream>
using namespace std;

void main()
{
	//opening input file
	ifstream input ("data.in");
	unsigned int n,m;
	//reading the integer couples couples 
	while (input>>n>>m)
	{
		if (m <= n && m != 0 || m == 1 || (m == 1 && n == 0)) printf("%d devides %d!\n", m, n);//special cases
		else
		{
			bool factorial_vals[250], found = 0;
			int index, auxiliary = m;
			for (index = 1;index <= int(n);index++)
				factorial_vals[index] = 1;
			index = 2;
			//take all prime divisors of m and search for them or their multiples in factorial_vals
			while (auxiliary > 1)
			{
				if (auxiliary % index == 0)
				{
					auxiliary /= index;
					int searched_val = index;
					int k = 2;
					found = 0;
					while (searched_val <= int(n))
					{
						if (factorial_vals[searched_val])
						{
							factorial_vals[searched_val] = 0;
							found = 1;
							break;
						}
						else
						{
							searched_val = index * k;
							k++;
						}
					}
					if (!found)
						break;
				}
				else index++;
			}
			if (!found)
				printf("%d does not devide %d!\n", m, n);
			else printf("%d devides %d!\n", m, n);
		}
	}
}