#include <iostream>

using namespace std;

int RemainPongDang(int nN, int nR)
{
	int nSum = 0;

	for (int i = 1; i < nR; i++)
	{
		if (i > 2 * nN)
		{
			nSum += 4 * nN - i;
		}
		else
		{
			nSum += i;
		}
	}

	return nSum;
}

int PongDang(int nN, int nP, int nT)
{
	int nRotHand = 4 * nN * nN - 1;
	int nRotT = 4 * nN - 2;

	int nRRot = nRotHand % (2 * nN);
	int nR = nT % nRotT;

	int nHand_Pos = (nRRot * (nT / nRotT) + RemainPongDang(nN, nR)) % (2 * nN);
	int nHand_Remain = 0;

	if (nR > 2 * nN)
		nHand_Remain += 4 * nN - nR;
	else
		nHand_Remain += nR;

	for (int i = 0; i < nHand_Remain; i++)
	{
		nHand_Pos += 1;

		if (nHand_Pos > (2 * nN))
			nHand_Pos %= (2 * nN);

		if (nHand_Pos == (2 * nP - 1) || nHand_Pos == 2 * nP)
			return 1;
	}
	return 0;
}

int main(void)
{
	int nN = 0, nP = 0, nT = 0;

	cin >> nN >> nP >> nT;

	if (PongDang(nN, nP, nT))
		cout << "Dehet YeonJwaJe ^~^" << endl;
	else
		cout << "Hing...NoJam" << endl;

	return 0;
}