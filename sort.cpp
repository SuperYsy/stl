#include<iostream>
using namespace std;


//÷±Ω”≤Â»Î≈≈–Ú
void InsertSort(int a[], int n)
{
	int i, j;
	for (i = 2;i <= n;i++)
	{
		a[0] = a[i];
		for (j = i - 1;a[0] < a[j];j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = a[0];
	}
}

//’€∞Î≤Â»Î≈≈–Ú
void BInsertSort(int a[], int n)
{
	int i, j;
	int low, high, mid;
	for (i = 2;i <= n;i++)
	{
		a[0] = a[i];
		int low = 1, high = i - 1;
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (a[mid] > a[0])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}

		for (j = i - 1;j >= high - 1;j--)
		{
			a[j + 1] = a[j];
		}
		a[high + 1] = a[0];
	}
}

//œ£∂˚≈≈–Ú
void shellSort(int a[], int n)
{
	for (int dk = n / 2; dk >= 1; dk = dk / 2)
	{
		for (int i = dk + 1;i <= n;i++)
		{
			if (a[i] < a[i - dk])
			{
				a[0] = a[i];
				for (int j = i - dk;j > 0 && a[0] < a[j];j -= dk)
				{
					a[j + dk] = a[j];
					a[j + dk] = a[0];
				}
			}
		}
	}
}

//√∞≈›≈≈–Ú
void BubbleSort(int a[], int n)
{
	for (int i = 0;i < n - 1;i++)
	{
		bool flag = false;
		for (int j = n - 1;j > 1;j--)
		{
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1],a[j]);
				flag = true;
			}
			if (flag == false)
			{
				return;
			}
		}
	}
}

//÷±Ω”—°‘Ò≈≈–Ú
void SelectSort(int a[], int n)
{
	for (int i = 0;i < n - 1;i++)
	{
		int min = i;
		for (int j = i + 1; j < n;j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
			if (min != i)
			{
				swap(a[i], a[min]);
			}
		}
	}
}

//øÏÀŸ≈≈–Ú
int Partition(int a[], int low, int high)
{
	int pivot = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= pivot)
		{
			high--;
		}
		a[low] = a[high];
		while (low < high && a[low] <= pivot)
		{
			low++;
		}
		a[high] = a[low];
	}
	a[low] = pivot;
	return low;
}
void QuickSort(int a[], int low, int high)
{
	if (low < high)
	{
		int pivotpos = Partition(a, low, high);
		QuickSort(a, low, pivotpos - 1);
		QuickSort(a, pivotpos + 1, high);
	}
}

//∂—≈≈–Ú
void BuildMaxHeap(int a[], int len)
{
	for (int i = len / 2;i > 0; i--)                                                                                                  
	{
		AdjustDown(a, i, len);
	}
}
void AdjustDown(int a[], int k, int len)
{
	a[0] = a[k];
	for (int i = 2 * k; i <= len; i *= 2)
	{
		if (i < len && a[i] < a[i + 1])
		{
			i++;
		}
		if (a[0] >= a[i])
		{
			break;
		}
		else
		{
			a[k] = a[i];
			k = i;
		}
	}
	a[k] = a[0];
}
void HeapSort(int a[], int len)
{
	BuildMaxHeap(a, len);
	for (int i = len;i > 1;i++)
	{
		Swap(a[i], a[1]);
		AdjustDown(a, 1, i - 1);
	}
}

//∂—µƒ≤Â»Î
void AdjustUp(int a[], int len,int k)
{
	a[0] = a[k];
	int i = k / 2;
	while (i > 0 && a[i] < a[0])
	{
		a[k] = a[i];
		k = i;
		i = k / 2;
	}
	a[k] = a[0];
}

//πÈ≤¢≈≈–Ú
int* b = new int[10];
void Merge(int a[], int low, int mid, int high)
{
	for (int k = low; k <= high;k++)
	{
		b[k] = a[k];
	}
		for (int i = low, int j = mid + 1, int k = i; i <= mid && j <= high;k++)
		{
			if (b[i] <= b[j])
			{
				a[k] = b[i++];
			}
			else
			{
				a[k] = b[j++];
			}
		}
		while (i <= mid)
		{
			a[k++] = b[i++];
		}
		while (j <= high)
		{
			a[k++] = b[j++];
		}
}
void MergeSort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);
		Merge(a, low, mid, high);
	}
}
int main()
{
	int a[100];
	for (int i = 1; i <= 10;i++)
	{
		cin >> a[i];
	}
	InsertSort(a,10);
	for (int i = 1;i <= 10;i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}

