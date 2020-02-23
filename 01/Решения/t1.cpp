#include <iostream>

int main()
{
	int n = 0, m = 0, a = 0;
	std::cin >> n >> m >> a;

	int** arr = new int*  [n];
	for(int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(i == j)
			{
				arr[i][j] = a;
			}
			else
			{
				arr[i][j] = 0;
			}
		}
	}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			std::cout << arr[i][j] << " ";
		}
		std::cout << std::endl;
	}

    for(int i = 0; i < n; i++)
    {
         delete[] arr[i];
    }
    delete[] arr;
	return 0;
}
