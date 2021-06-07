#include <iostream>
#include <vector>
#include <cassert>

void findOptimalSumRange(std::vector<int> v)
{
	assert(v.size() > 2);

	int biggestSum = v[0] + v[1];
	int actionCount = 0;
	int optimal_i = 0;
	int optimal_j = 1;

	for (int i = 1; i < v.size() - 1; i++)
	{
		int sum = v[i];
		//Оптимизация: если следующий элемент i меньше предыдущего, то бОльшую сумму получить гарантированно не удастся.
		//Поэтому в таком случае внутренний цикл игнорируется и переходим к следующему i.
		if (v[i] > v[i - 1])
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				actionCount++;
				sum += v[j];
				if (sum > biggestSum)
				{
					biggestSum = sum;
					optimal_i = i;
					optimal_j = j;
				}
			}
		}	
	}
	std::cout << "Biggest sum is : " << biggestSum << "\n";
	std::cout << "i: " << optimal_i << "\n";
	std::cout << "j: " << optimal_j << "\n";
	std::cout << "Actions count is: " << actionCount << "\n";
}

int main()
{
	std::vector<int> input = { -2,1,-3,4,-1,2,1,-5,4 };

	findOptimalSumRange(input);

	return 0;
}
