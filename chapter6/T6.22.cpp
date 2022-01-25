#include<iostream>
using namespace std;
// void swapPtr(int **n1, int **n2)
// {
//     int *temp = *n1;
//     *n1 = *n2;
//     *n2 = temp;
// }
// int main()
// {
//     int i1 = 1, i2 =2;
//     int *n1 = &i1, *n2 = &i2;
//     swapPtr(&n1, &n2);
//     cout << *n1 << ' '<< *n2 << endl;
// }
void swap(int*& lft, int*& rht)
{
	int* tmp = lft;
	lft = rht;
	rht = tmp;
}

int main()
{
	int i = 42, j = 99;
	auto lft = &i;
	auto rht = &j;
	swap(lft, rht);
	std::cout << *lft << " " << *rht << std::endl;

	return 0;
}