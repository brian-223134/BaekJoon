#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string name, temp;
	vector<string> team_name;
	vector<int> team_res;
	int team_num, e_func, L = 0, O = 0, V = 0, E = 0, max = 0;

	cin >> name;
	cin >> team_num;
	for (int num = 0; num < team_num; num++) {
		cin >> temp;
		team_name.push_back(temp);
		for (int i = 0; i < name.size(); i++) {
			if (name[i] == 'L') L++;
			else if (name[i] == 'O') O++;
			else if (name[i] == 'V') V++;
			else if (name[i] == 'E') E++;
		}
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 'L') L++;
			else if (temp[i] == 'O') O++;
			else if (temp[i] == 'V') V++;
			else if (temp[i] == 'E') E++;
		}
		e_func = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
		team_res.push_back(e_func);
		L = 0;
		O = 0;
		V = 0;
		E = 0;
	}

	for (int i = 0; i < team_num; i++) {
		if (max < team_res[i]) {
			max = team_res[i];
			temp = team_name[i];
		}
		else if (max == team_res[i]) {
			if (temp < team_name[i]);
			else temp = team_name[i];
		}
	}
	
	cout << temp;

	return 0;
}