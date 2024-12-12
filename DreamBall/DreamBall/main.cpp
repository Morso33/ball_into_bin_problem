#include <vector>
#include <iostream>


int main()
{
	std::cout << "[simulation] start" << std::endl;

	int BALLS_COUNT = 100;
	int SLOTS_COUNT = 100;
	int ROUNDS = 1000 * 1000; // million

	int highest_result = 0;
	int lowest_result = BALLS_COUNT;

	std::vector <int> round_results(ROUNDS, 0);

	srand(time(NULL));

	//ROUNDS
	for (int r = 0; r < ROUNDS; r++)
	{
		std::vector <int> slots(SLOTS_COUNT, 0);
		//BALLS
		for (int i = 0; i < BALLS_COUNT; i++)
		{
			int slot = rand() % SLOTS_COUNT;
			slots[slot]++;
		}
		int count = 0;
		//SLOTS
		for (int i = 0; i < SLOTS_COUNT; i++)
		{
			if (slots[i] > 0)
			{
				count++;
			}
		}
		round_results[r] = count;
		if (count > highest_result)
		{
			highest_result = count;
		}
		if (count < lowest_result)
		{
			lowest_result = count;
		}

		if (r % (ROUNDS / 100) == 0)
		{
			std::cout << "[simulation] " << r / (ROUNDS / 100) << "%" << std::endl;
		}
	}
	int sum_average = 0;
	for (int i = 0; i < ROUNDS; i++)
	{
		sum_average += round_results[i];
	}
	sum_average /= ROUNDS;

	std::cout << "[simulation] result: " << sum_average << std::endl;
	std::cout << "[simulation] highest: " << highest_result << std::endl;
	std::cout << "[simulation] lowest: " << lowest_result << std::endl;

	return 0;
}