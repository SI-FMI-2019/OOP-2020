#include <iostream>

double get_sum(double arr[], int n, double q)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > q)
		{
			sum += arr[i];
		}
	}

	return sum;
}

int main()
{
	int n = 0;
	std::cin >> n;
	
	double* arr = new double[n];

	for (int i = 0; i < n; i++)
	{
		std::cin >> arr[i];
	}

	double res = get_sum(arr,n, 0);

	std::cout << res / n;

	delete[] arr;
	return 0;
}