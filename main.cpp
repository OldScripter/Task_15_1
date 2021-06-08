#include <iostream>
#include <vector>
#include <cassert>

void FindOptimalSumRange(std::vector<int> v)
{
	assert(v.size() > 2);

	int biggest_sum = v[0];
	int action_count = 0;
	int optimal_i = 0;
	int optimal_j = 1;

	for (int i = 0; i < v.size() - 1; i++)
	{
		int sum = v[i];

		for (int j = i + 1; j < v.size(); j++)
		{
			action_count++;
			sum += v[j];
			if (sum > biggest_sum)
			{
				biggest_sum = sum;
				optimal_i = i;
				optimal_j = j;
			}
		}
	}

	std::cout << "Biggest sum is : " << biggest_sum << "\n";
	std::cout << "i: " << optimal_i << "\n";
	std::cout << "j: " << optimal_j << "\n";
	std::cout << "Actions count is: " << action_count << "\n";
}

int main()
{
	std::vector<int> input = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	FindOptimalSumRange(input);
	return 0;
}
