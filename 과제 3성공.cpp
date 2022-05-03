#include<iostream>
#include<string>
using namespace std;
int main()
{
	char arr[1000];
	char* head;
	char* tail;
	cin >> arr;
	head = arr;
	tail = &arr[strlen(arr) - 1];
	for (int i = 0; i < strlen(arr)/2; i++)
	{
		if (*(head + i) != *(tail - i))
		{
			cout << "회문이 아님\n";
			return 0;
		}

	}
	cout << "회문임\n";
	return 0;
}