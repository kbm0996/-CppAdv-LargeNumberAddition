#include <conio.h>
#include <cstdio>
#include <Windows.h>
#define df_MAX_NUMBER_LEN 1000

void Reverse(char *pArray);
void ctoi(char *pArray, int iLength);
void itoc(char *pArray, int iLength);
void sum(char *pNumber1, char *pNumber2, char *pResult, int iLength);

void main()
{
	char szNumber1[df_MAX_NUMBER_LEN];
	char szNumber2[df_MAX_NUMBER_LEN];
	char szResult[df_MAX_NUMBER_LEN + 1];
	int iLonglength;

	while (1)
	{
		//-------------------------
		// Initialize
		//-------------------------
		system("cls");
		memset(szNumber1, 0, sizeof(szNumber1));
		memset(szNumber2, 0, sizeof(szNumber2));
		memset(szResult, 0, sizeof(szResult));

		//-------------------------
		// Input
		//-------------------------
		printf("A =   ");
		gets_s(szNumber1, sizeof(szNumber1));
		printf("B =   ");
		gets_s(szNumber2, sizeof(szNumber2));

		//-------------------------
		// Operation
		//-------------------------
		iLonglength = strlen(szNumber1) < strlen(szNumber2) ? strlen(szNumber2) : strlen(szNumber1); // 긴 숫자를 기준으로 반복문을 돌리기 위한 변수

		Reverse(szNumber1);
		Reverse(szNumber2);

		ctoi(szNumber1, strlen(szNumber1));
		ctoi(szNumber2, strlen(szNumber2));

		sum(szNumber1, szNumber2, szResult, iLonglength);
		itoc(szResult, iLonglength + 1);

		// 계산은 배열순으로 하지만 표시는 배열의 역순으로 해야하므로 반전시켜준다 (123 -> 321)
		Reverse(szResult);

		//-------------------------
		// Print Result
		//-------------------------
		for (int i = 0; i < iLonglength + 1; i++)	// 상위 자릿수에 0이 올 경우, 0을 출력하지 않기 위함
			if (szResult[i] != '0')
			{
				printf("A + B = %s\n", &szResult[i]);
				break;
			}

		_getch();
	}
}


void Reverse(char *pArray)
{
	char temp;

	for (int cnt = 0; cnt < strlen(pArray) / 2; ++cnt)
	{
		temp = pArray[cnt];
		pArray[cnt] = pArray[strlen(pArray) - cnt - 1];
		pArray[strlen(pArray) - cnt - 1] = temp;
	}
}

void ctoi(char *pArray, int iLength)
{
	for (int i = 0; i < iLength; i++)
		pArray[i] -= '0';
}

void itoc(char *pArray, int iLength)
{
	for (int i = 0; i < iLength; i++)
		pArray[i] += '0';
}

void sum(char *pNumber1, char *pNumber2, char *pResult, int iLength)
{
	int sum;
	int up = 0;

	for (int i = 0; i < iLength + 1; i++)
	{
		sum = pNumber1[i] + pNumber2[i] + up;

		if (sum >= 10)
			up = 1;
		else
			up = 0;

		pResult[i] = sum % 10;
	}
}