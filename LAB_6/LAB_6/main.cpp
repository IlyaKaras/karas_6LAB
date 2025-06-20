#include <D:\program\LAB_6\LAB_6\FUNCTION.h>

int main()
{
	try {
		char input[100];
		EnterTheString(input);
		if (*input == '\n') {
			throw"Your string is empty";
		}
		SplitString(input);
	}
	catch (const char* msg) {
		cout << msg;
	}
	return 0;

}