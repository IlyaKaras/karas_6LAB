#include <D:\program\LAB_6\LAB_6\FUNCTION.h>

void EnterTheString(char* input)
{
	cout << "Please enter a string: ";
	cin.getline(input, 100);
}

void SplitString(char* input)
{
	char delim[] = " ,.;:-_";
	char* context = nullptr;
	char* pch = strtok_s(input, delim, &context);

	while (pch != nullptr) {
		if (IsItNumber(pch)) {
			ProcessNumber(pch);
		}
		else if (IsItLeter(pch)) {
			OutCharSymbol(pch);
		}
		pch = strtok_s(nullptr, delim, &context);
	}
	cout << '\n';
}

void ProcessNumber(char* pch)
{
	const int targetLength = 5;
	int currentLength = strlen(pch);

	if (currentLength < targetLength) {
		char temp[6] = { 0 };
		strcpy_s(temp, pch);

		for (int i = currentLength; i < targetLength; ++i) {
			temp[i] = '0';
		}
		temp[targetLength] = '\0';

		cout << temp << " ";
	}
	else {
		cout << pch << " ";
	}
}

bool IsItNumber(char* pch)
{
	for (size_t i = 0; i < strlen(pch); ++i) {
		if (!isdigit(pch[i])) {
			return false;
		}
	}
	return true;
}

bool IsItLeter(char* pch)
{
	for (int i = 0; pch[i] != '\0'; ++i) {
		if (!isalpha(pch[i])) {
			return false;
		}
	}
	return true;
}

void OutCharSymbol(char* pch)
{
	int32_t size = strlen(pch);
	for (int32_t i = size - 1; i >= 0; --i) {
		cout << pch[i];
	}
	cout << " ";
}