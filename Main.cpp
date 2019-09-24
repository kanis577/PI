#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <sstream>

/*
DIGI_CONSTANT 設定 2800 print the first 800 digits of pi
2800 / 14 = 200(次), 1次輸出4 digi

需求為10000 digi, 10000 / 4 = 2500, 2500 * 14 = 35000

*/

#define DIGI_CONSTANT		35000		// 35000
#define OUTPUT_ALL_DIGI		false

enum
{
	L = 0,
	R = 1
};

int main() 
{
	std::stringstream stmData;
	std::vector<std::vector<int>> vInputPos;
	std::string strData;

	int nLines = 0;
	std::cin >> nLines;
	for (int i = 0; i < nLines; i++)
	{
		std::vector<int> vTemp(2);
		std::cin >> vTemp[L];
		std::cin >> vTemp[R];
		vInputPos.push_back(vTemp);
	}
  
	int r[DIGI_CONSTANT + 1];
	int i, k, b, d;
	for (i = 0; i < DIGI_CONSTANT; i++)
	{
		r[i] = 2000;
	}

	for (k = DIGI_CONSTANT; k > 0; k -= 14)
	{
		d = 0;
		i = k;
		for (;;) {
			d += r[i] * 10000;
			b = 2 * i - 1;
			r[i] = d % b;
			d /= b;
			i--;
			if (i == 0) break;
			d *= i;
		}
	}
	// 輸出特定位置字串
	std::cout << "OUTPUT:" << std::endl;
	for (int i = 0; i < vInputPos.size(); i++)
	{
		int nLength = vInputPos[i][R] - vInputPos[i][L] + 1;

		for (int j = vInputPos[i][L]; j < vInputPos[i][L] + nLength; j++)
		{
			std::cout << strData[j];
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}
