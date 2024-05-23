#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static int dig_num(string str)
{
	int cnt = 0;
	char dig[2] = { 'a', 'A' };

	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j < 2; j++) {
			if (str[i] == dig[j]) 
				cnt += 1;
		}
	}
	return cnt;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream in("F1.txt");
	ofstream out("F2.txt");

	string str, words[100], digits = "";
	int word_index = 0, max = -1, max_i = 0;

	while (getline(in, str)) {

		int word_count = 1;

		for (int i = 0; i < str.size() - 1; i++) {
			if (str[i] == 32 && str[i + 1] != 32) word_count++;
		}

		int c = 0, k = 0;

		for (int i = c; i < str.size(); i++) {
			if (str[i] != 32) {

				int ii = i;

				while (str[ii] != 32 && str[ii] != '\0') ii++;
				c = ii - i;

				words[k] = str.substr(i, c);
				word_index++;

				if (dig_num(words[k]) >= max) {
					max = dig_num(words[k]);
					max_i = word_index;
					digits = words[k];
				}
				k++;
				i = ii - 1;
			}
		}

		bool flag = false;
		for (int i = 0; i < word_count; i++) {
			for (int j = i + 1; j < word_count && !flag; j++) {
				if (words[j] == words[i]) flag = true;
			}
		}
		if (flag) out << str << "\n";
	}

	out << endl << "Номер слова с максимальным кол-вом букв a: " << max_i << ". Само слово: " << digits;

	in.close();
	out.close();
	return 0;
}