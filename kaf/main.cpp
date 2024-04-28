#include <iostream>


int MinSum(int* arr, int size, int low_bound = 0, int res_bound = 0, int inherit_sum = -1)	//первое задание
{
	int cur_sum = 0;
	if (low_bound >= size - 10)
	{
		return res_bound;
	}
	for (int i = low_bound; i < low_bound + 10; i++)
	{
		cur_sum += arr[i];
	}
	if (cur_sum > inherit_sum)
	{
		inherit_sum = cur_sum;
		res_bound = low_bound;
	}

	low_bound++;

	MinSum(arr, size, low_bound, res_bound, inherit_sum);
}



int MaxVal(int* arr, int size)		//второе задание
{
	int res = -1;
	for (int i = 0; i < size; i++)
	{
		if (res < arr[i])
		{
			res = arr[i];
		}
	}
	return res;
}
int MaxVal(int** arr, int size)
{
	int res = -1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (res < arr[i][j])
			{
				res = arr[i][j];
			}
		}
		
	}
	return res;
}
int MaxVal(int*** arr, int size)
{
	int res = -1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int v = 0; v < size; v++)
			{
				if (res < arr[i][j][v])
				{
					res = arr[i][j][v];
				}
			}
			
		}

	}
	return res;
}
int MaxVal(int num1, int num2)
{
	if (num1 > num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}
int MaxVal(int num1, int num2, int num3)
{
	if (num1 > num2)
	{
		if (num1 > num3)
		{
			return num1;
		}
		else
		{
			return num3;
		}
	}
	else
	{
		if (num2 > num3)
		{
			return num2;
		}
		else
		{
			return num3;
		}
	}
}


int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));


	const int size1 = 100;		//первое задание
	int rand_arr[size1];

	for (int i = 0; i < size1; i++)
	{
		rand_arr[i] = rand() % 100;
	}

	for (int i = 0; i < size1; i++)
	{
		std::cout << rand_arr[i] << ' ';
	}

	std::cout << '\n' << MinSum(rand_arr, size1) << "\n\n";



	const int size2 = 50;		//второе задание

	int arr_1d[size2];
	int* arr_2d[size2];
	int** arr_3d[size2];


	for (int i = 0; i < size2; i++)
	{
		arr_1d[i] = rand() % 50;
		arr_2d[i] = new int[size2];
		arr_3d[i] = new int*[size2];
		for (int j = 0; j < size2; j++)
		{
			arr_3d[i][j] = new int[size2];
			arr_2d[i][j] = arr_2d[i][j] = rand() % 34;
			for (int v = 0; v < size2; v++)
			{
				arr_3d[i][j][v] = rand() % 150;
			}
		}
	}

	int num1 = rand() % 23, num2 = rand() % 32, num3 = rand() % 159, num4 = rand() % 93, num5 = rand() % 200;


	std::cout << "1) " << MaxVal(arr_1d, size2) << "\n2) " << MaxVal(arr_2d, size2) << "\n3) " << MaxVal(arr_3d, size2) << "\n4) " << MaxVal(num1, num2) << "\n5) " << MaxVal(num3, num4, num5) << '\n';


	return 0;
}