
void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)//выбирает элемент
	{
		for (int j = i + 1; j < n; j++)//перебирает элемент
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
void Sort(double arr[], const int n)
{
	for (int i = 0; i < n; i++)//выбирает элемент
	{
		for (int j = i + 1; j < n; j++)//перебирает элемент
		{
			if (arr[j] < arr[i])
			{
				double buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}