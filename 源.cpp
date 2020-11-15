#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<sstream>
#include<array>
#include<ctime>
#include<cstdlib>
using namespace std;

/*
int moveCards(int cards[], int heap)
{
	int sum = 0;
	int avg;
	int length = heap;
	for (int i = 0;i < length ;i++)
	{
		sum += cards[i];
	}
	avg = sum / length;
	int count = 0;
	for (int j = 0;j < length;j++)
	{
		if (cards[j] != avg)
		{
			int movecard = cards[j] - avg;
			cards[j] -= movecard;
			cards[j + 1] += movecard;
			count++;
		}
	}
	return count;
}

int main()
{
	int heap = 4;
	int cards[] = {9,8,17,6};
	int count = moveCards(cards,heap);
	cout <<"移动次数："<< count << endl;
	int length = sizeof(cards) / sizeof(cards[0]);
	for (int i = 0;i < length;i++)
	{
		cout << "第" << i + 1 << "牌堆数：" << cards[i] << endl;
	}
	return 0;
}
*/
/*
int * maxNum(int nums[])
{

	for (int i = 0;i < 3;i++)
	{
		stringstream ss1;
		string num1;
		ss1 << nums[i];
		ss1 >> num1;
		for (int j = i + 1;j < 3;j++)
		{
			stringstream ss2;
			string num2;
			ss2 << nums[j];
			ss2 >> num2;
			if ((num1 + num2).compare(num2 + num1) < 0)
			{
				int temp = nums[j];
				nums[j] = nums[i];
				nums[i] = temp;
			}
		}
	}
	return nums;
}
int main()
{
	int nums[3] = { 13,312,343 };
	//cout << nums.size();
	int * p = maxNum(nums);
	cout << "最大整数：";
	for (int i = 0;i < 3;i++)
	{
		cout << *(p+i);
	}
	return 0;
}
*/

/*
int main()
{
	int a[5] = { 5,3,2,4,1 };
	for (int i = 0;i <= 3;i++)
	{
		for (int j = 4;j>=i+1;j--)
		{
			if (a[j] < a[j - 1])
			{
				int temp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0;i < 5;i++)
	{
		cout << a[i] << " ";
	}
	return 0;
}
*/


/* 最大子数组
void find1(int a[],int& left_sum, int& max_left, int& max_right, int& right_sum,int length)
{
	//int left_sum = 0;
	int sum = 0;
	int low = 0, hight = length;
	int mid = length / 2;
	//int max_left = 0;
	for (int i = mid;i > low;i--)
	{
		sum += a[i];
		if (sum > left_sum)
		{
			left_sum = sum;
			max_left = i;
		}
	}
	//int right_sum = 0;
	//int max_right = 0;
	int sum1 = 0;
	for (int j = mid + 1;j < hight;j++)
	{
		sum1 += a[j];
		if (sum1 > right_sum)
		{
			right_sum = sum1;
			max_right = j;
		}
	}
}

void find2(int& low, int& hight, int a[],int &sum,int length)
{
	int left_sum = 0;
	int right_sum = 0;
	int max_right = 0;
	int max_left = 0;
	int sum1 = 0;
	int sum2 = 0;
	int mid = (low + hight) / 2;
	int mid2 = mid + 1;
	int total = 0;
	if (low == hight)
	{

	}
	else
	{
		find2(low, mid, a,sum1,length);
		find2(mid2, hight, a, sum2,length);
		find1(a, left_sum, max_left, max_right, right_sum, length);
		total = left_sum + right_sum;
	}
	if (sum1 >= sum2 && sum1 >= total)
	{
		low = low;
		hight = mid;
		sum = sum1;
	}
	else if (sum2 >= sum1 && sum2 >= total)
	{
		low = mid2;
		hight = hight;
		sum = sum2;
	}
	else
	{
		low = max_left;
		hight = max_right;
		sum = total;
	}
}
int main()
{
	int a[] = { 13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7 };
	int left_sum = 0;
	int length = sizeof(a) / sizeof(a[0]);
	int right_sum = 0;
	int max_right = 0;
	int max_left = 0;
	int low = 0;
	int hight = length;
	int sum = 0;
	//find1(a,left_sum,max_left, max_right, right_sum,length);
	find2(low, hight, a,sum,length);
	cout << low << " " << hight << " " << sum << endl;
	//cout << left_sum << " " << max_left << endl;
	//cout << right_sum << " " << max_right << endl;
	return 0;
}
*/

/*
int main()
{
	int la[6] = { 48,32,10,80,103,110 };
	vector<int> li(la, la + 6);
	cout << count_if(li.begin(), li.end(), not1(bind2nd(less<int>(), 40)));
	return 0;
}
*/
/*
#include<iostream>
#include<array>
#include<ctime>
#include<cstdlib> //qsort bsearch NULL
using namespace std;
constexpr auto ASIZE = 50000;
const long max1 = 1000;


int main()
{
	string buf;
	int ret;
	buf = get_a_target_string(ret);
	cout << ret << endl;
	cout << buf << endl;
	return 0;
}



int main()
{
	cout << max1 << endl;
	cout << "\ntest_array().......\n";
array<long,ASIZE> c;
	srand((unsigned)time(NULL));
	for (long i = 0;i < ASIZE;i++)
	{
		c[i] = rand()%500 + 1;
	}
	cout << "milli_seconds: " << (clock()) << endl;
	cout << c.size() << endl;
	cout << c.front() << endl;
	cout << c.back() << endl;
	cout << c.data() << endl; //传回array在内存起点的地址

long target = get_a_target_long();
	qsort(c.data(),ASIZE,sizeof(long), compareLongs);
long* pIterm = (long*)bsearch(&target, (c.data()),ASIZE, sizeof(long), compareLongs);
	if (pIterm != NULL)
	{
		cout << "fount, " << *pIterm << endl;
	}
	else
	{
		cout << "not found! " << endl;
	}
	return 0;
}
*/

#include<vector>
#include<stdexcept>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<iostream>
#include<ctime>
#include<set>
#include<algorithm>
#include<map>
#include<unordered_set>
#include<unordered_map>
using namespace std;

long get_a_target_long()
{
	long target = 0;
	cout << "target (0~" << RAND_MAX << "):";
	cin >> target;
	return target;
}

long get_a_target_long(long& ret)
{
	long target = 0;
	cout << "target (0~" << ret << "):";
	cin >> target;
	return target;
}

string get_a_target_string(int& ret)
{
	long target = 0;
	char buf[10];
	cout << "target (0~" << RAND_MAX << "):";
	cin >> target;
	ret = snprintf(buf, 10, "%d", target);
	return string(buf);
}

int compareLongs(const void* a, const void* b)
{
	return (*(long*)a - *(long*)b);
}

int comperStrings(const void* a, const void* b)
{
	if (*(string*)a > *(string*)b)
	{
		return 1;
	}
	else if (*(string*)a < *(string*)b)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//容器vector
/*
void test_vector(long& value)
{
	cout << "\ntest_vector()....... \n";

vector<string> c;
char buf[10];

clock_t timeStart = clock();
	for (long i = 0;i < value;i++)
	{
		try {
			snprintf(buf, 10, "%d", rand());
			c.push_back(string(buf));
		}
		catch (exception& p) {
			cout << "i = " << i << " " << p.what() << endl;
				//曾经最高 i=58389486 then std::bad_alloc
			abort();
		}
	}
	cout << "milli-seconds=" << (clock() - timeStart) << endl;
	cout << "vector.size()=" << c.size() << endl;
	cout << "vector.front()=" << c.front() << endl;
	cout << "vector.back()=" << c.back() << endl;
	cout << "vector.data()=" << c.data() << endl;
	cout << "vector.capacity()=" << c.capacity() << endl;
	cout << c.max_size() << endl;
int ret = 0;
string target = get_a_target_string(ret);
	{
	timeStart = clock();
auto pItem = ::find(c.begin(), c.end(), target);
	cout << "::find(),milli-seconds: " << (clock() - timeStart) << endl;
	if (pItem != c.end())
	{
		cout << "found, " << *pItem << endl;
	}
	else
	{
		cout << "not found! " << endl;
	}

	}

	{
	timeStart = clock();
	sort(c.begin(), c.end());
string* pItem = (string*)bsearch(&target, (c.data()), c.size(), sizeof(string), comperStrings);
	cout << "::find(),milli-seconds: " << (clock() - timeStart) << endl;
	if (pItem != NULL)
	{
		cout << "found, " << *pItem << endl;
	}
	else
	{
		cout << "not found! " << endl;
	}
	}
}
*/


// 容器multiset
/*
void test_multiset(long& value)
{
	cout << "\ntest_multiset()....... \n";

	multiset<string> c;
	char buf[10];

	clock_t timeStart = clock();
	for (long i = 0;i < value;i++)
	{
		try {
			snprintf(buf, 10, "%d", rand());
			c.insert(string(buf));
		}
		catch (exception& p) {
			cout << "i = " << i << " " << p.what() << endl;
			//曾经最高 i=58389486 then std::bad_alloc
			abort();
		}
	}
	cout << "milli-seconds=" << (clock() - timeStart) << endl;
	cout << "multiset.size()=" << c.size() << endl;
	cout << "multiset.max_size()" << c.max_size() << endl;
	int ret = 0;
	string target = get_a_target_string(ret);
	{
		timeStart = clock();
		auto pItem = ::find(c.begin(), c.end(), target);
		cout << "::find(),milli-seconds: " << (clock() - timeStart) << endl;
		if (pItem != c.end())
		{
			cout << "found, " << *pItem << endl;
		}
		else
		{
			cout << "not found! " << endl;
		}

	}

	{
		timeStart = clock();
		auto pItem = c.find(target);
		cout << "::find(),milli-seconds: " << (clock() - timeStart) << endl;
		if (pItem != c.end())
		{
			cout << "found, " << *pItem << endl;
		}
		else
		{
			cout << "not found! " << endl;
		}
	}


}
*/

//容器multimap
//void test_multimap(long& value)
//{
//	cout << "\ntest_multimap()....... \n";
//
//	multimap<long,string> c;
//	char buf[10];
//
//	clock_t timeStart = clock();
//	for (long i = 0;i < value;i++)
//	{
//		try {
//			snprintf(buf, 10, "%d", rand());
//			//multimap 不可使用[]做insert
//			c.insert(pair<long,string>(i,buf));
//		}
//		catch (exception& p) {
//			cout << "i = " << i << " " << p.what() << endl;
//			//曾经最高 i=58389486 then std::bad_alloc
//			abort();
//		}
//	}
//	cout << "milli-seconds=" << (clock() - timeStart) << endl;
//	cout << "multiset.size()=" << c.size() << endl;
//	cout << "multiset.max_size()" << c.max_size() << endl;
//	//long& ret = value;
//	long target = get_a_target_long(value);
//		timeStart = clock();
//		auto pItem = c.find(target);
//		cout << "c.find(),milli-seconds:" << (clock() - timeStart) << endl;
//		if (pItem != c.end())
//		{
//			//取出pair中第二个元素，第一个first，第二个second
//			cout << "found, key = " << (*pItem).first << endl;
//			cout << "found, value = " << (*pItem).second << endl;
//		}
//		else
//		{
//			cout << "not found! " << endl;
//		}
//}

//容器unordered_multiset
//void test_unordered_multiset(long& value)
//{
//	cout << "\ntest_unordered_multiset()....... \n";
//	
//unordered_multiset<string> c;
//char buf[10];
//
//clock_t timeStart = clock();
//		for (long i = 0;i < value;i++)
//		{
//			try {
//				snprintf(buf, 10, "%d", rand());
//				//multimap 不可使用[]做insert
//				c.insert(string(buf));
//			}
//			catch (exception& p) {
//				cout << "i = " << i << " " << p.what() << endl;
//				//曾经最高 i=58389486 then std::bad_alloc
//				abort();
//			}
//		}
//		cout << "milli-seconds=" << (clock() - timeStart) << endl;
//		cout << "unordered_multiset.size()=" << c.size() << endl;
//		cout << "unordered_multiset.max_size()=" << c.max_size() << endl;
//		cout << "unordered_multiset.bucket_count()=" << c.bucket_count() << endl;
//		cout << "unordered_multiset.load_f actor()=" << c.load_factor() << endl;
//		cout << "unordered_multiset.max_load_f actor()" << c.max_load_factor() << endl;
//		cout << "unordered_multiset.max_bucket_count()" << c.max_bucket_count() << endl;
//		for (unsigned i = 0;i < 20;i++)
//		{
//			cout << "bucket #" << i << " has " << c.bucket_size(i) <<" elements"<< endl;
//		}
//		int ret = 0;
//string target = get_a_target_string(ret);
//		{
//			timeStart = clock();
//auto pItem = ::find(c.begin(), c.end(), target);
//			cout << "::find(),milli-seconds : " << (clock() - timeStart) << endl;
//			if (pItem != c.end())
//			{
//				cout << "found, " << *pItem << endl;
//			}
//			else
//			{
//				cout << "not found! " << endl;
//			}
//		}
//		{
//		timeStart = clock();
//		auto pItem = c.find(target);
//		cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
//		if (pItem != c.end())
//		{
//			cout << "found, " << *pItem << endl;
//		}
//		else
//		{ 
//			cout << "not found! " << endl;
//		}
//		}
//}

//容器unordered_multimap
//void test_unordered_multimap(long& value)
//{
//	cout << "\ntest_unordered_multimap()....... \n";
//		
//	unordered_multimap<long,string> c;
//	char buf[10];
//	
//	clock_t timeStart = clock();
//			for (long i = 0;i < value;i++)
//			{
//				try {
//					snprintf(buf, 10, "%d", rand());
//					//multimap 不可使用[]做insert
//			c.insert(pair<long,string>(i,buf));
//				}
//				catch (exception& p) {
//					cout << "i = " << i << " " << p.what() << endl;
//					//曾经最高 i=58389486 then std::bad_alloc
//					abort();
//				}
//			}
//			cout << "milli-seconds=" << (clock() - timeStart) << endl;
//			cout << "unordered_multiset.size()=" << c.size() << endl;
//			cout << "unordered_multiset.max_size()=" << c.max_size() << endl;
//			long& ret = value;
//	long target = get_a_target_long(ret);
//			{
//				timeStart = clock();
//	auto pItem = c.find(target);
//				cout << "c.find(), milli-seconds : " << (clock() - timeStart) << endl;
//				if (pItem != c.end())
//				{
//					cout << "found, " << (*pItem).second << endl;
//				}
//				else
//				{
//					cout << "not found! " << endl;
//				}
//			}
//}

//容器set
//void test_set(long& value)
//{
//	cout << "\ntest_set()....... \n";
//
//set<string> c;
//char buf[10];
//
//clock_t timeStart = clock();
//	for (long i = 0;i < value;i++)
//	{
//		try {
//			snprintf(buf, 10, "%d", rand());
//			c.insert(string(buf));
//		}
//		catch(exception& p){
//			cout << "i=" << i << " " << p.what() << endl;
//			abort();
//		}
//	}
//	cout << "milli-seconds : " << (clock() - timeStart) << endl;
//	cout << "set.size()=" << c.size() << endl;
//	cout << "set.max_size()" << c.max_size() << endl;
//	
//	int ret = 0;
//string target = get_a_target_string(ret);
//	{
//		timeStart = clock();
//auto pItem = ::find(c.begin(), c.end(), target);
//		cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;
//		if (pItem != c.end())
//		{
//			cout << "found, " << *pItem << endl;
//		}
//		else
//		{
//			cout << "not found! " << endl;
//		}
//	}
//
//	{
//		timeStart = clock();
//auto pItem = c.find(target);
//		cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;
//		if (pItem != c.end())
//		{
//			cout << "found, " << *pItem << endl;
//		}
//		else
//		{
//			cout << "not found! " << endl;
//		}
//	}
//}

//容器map
void test_map(long& value)
{
	cout << "\ntest_map()....... \n";

map<long,string> c;
char buf[10];

clock_t timeStart = clock();
	for (long i = 0;i < value;i++)
	{
		try {
			snprintf(buf, 10, "%d", rand());
			c[i] = string(buf);
		}
		catch (exception& p) {
			cout << "i=" << i << " " << p.what() << endl;
			abort();
		}
	}
	cout << "milli-seconds : " << (clock() - timeStart) << endl;
	cout << "set.size()=" << c.size() << endl; //map的虽然拒绝重复，但key可以重复，所以还是1000000个
	cout << "set.max_size()" << c.max_size() << endl;

long& ret = value;
long target = get_a_target_long(ret);
	{
		timeStart = clock();
auto pItem = c.find(target);
		cout << "::find(), milli-seconds : " << (clock() - timeStart) << endl;
		if (pItem != c.end())
		{
			cout << "found, " << (*pItem).second << endl;
		}
		else
		{
			cout << "not found! " << endl;
		}
	}
}
int main()
{
	long value = 1000000;
	//test_vector(value);
	//test_multiset(value);
	//test_multimap(value);
	//test_unordered_multiset(value);
	//test_unordered_multimap(value);
	//test_set(value);
	test_map(value);
	return 0;
}
