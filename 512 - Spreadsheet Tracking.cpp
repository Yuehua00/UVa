// 來源 CPE 公布解答
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int r, c, n, m, r1, c1, r2, c2, flag, idx, count, rr, cc, temp;
	string s;

	idx = 0;
	scanf("%d%d", &r, &c);
	while (r != 0 || c != 0) {
		vector< vector<int> > data;
		vector<int> a;
		count = 0;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				a.push_back(count);
				++count;
			}
			data.push_back(a);
			a.clear();
		}

		scanf("%d", &n);
		for (int k = 0; k < n; ++k) {
			a.clear();
			cin >> s;
			if (s == "EX") //如果輸入exchange，則接下來輸入 (r1, c1) (r2, c2) 
				scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
			else { //如果輸入exchange之外，根據m決定輸入個數 
				scanf("%d", &m);
				for (int j = 0; j < m; ++j) {
					scanf("%d", &temp);
					a.push_back(temp - 1);
				}
				sort(a.begin(), a.end());
			}

			if (s == "EX") //exchange 
				swap(data[r1 - 1][c1 - 1], data[r2 - 1][c2 - 1]);
			else if (s == "DR") { //delete row
				for (int i = 0; i < m; ++i)
					data.erase(data.begin() + a[i] - i);
			}
			else if (s == "DC") { //delete column
				for (int i = 0; i < m; ++i)
					for (int j = 0; j < data.size(); ++j)
						data[j].erase(data[j].begin() + a[i] - i);
			}
			else if (s == "IR") { //insert row
				for (int i = 0; i < m; ++i)
					data.insert(data.begin() + a[i] + i, vector<int>(data[0].size(), -1));
			}
			else if (s == "IC") { //insert column
				for (int i = 0; i < m; ++i)
					for (int j = 0; j < data.size(); ++j)
						data[j].insert(data[j].begin() + a[i] + i, -1);
			}
		}

		++idx;
		printf("Spreadsheet #%d\n", idx);
		scanf("%d", &n); //n個查詢指令 
		for (int k = 0; k < n; ++k) {
			flag = 0;
			scanf("%d%d", &rr, &cc);
			for (int i = 0; i < data.size(); ++i) { //一個個找 
				for (int j = 0; j < data[0].size(); ++j) {
					if ( data[i][j] == (rr - 1) * c + (cc - 1) ) {
						printf("Cell data in (%d,%d) moved to (%d,%d)\n", rr, cc, i + 1, j + 1);
						flag = 1;
						break;
					}
				}
				if (flag == 1) break;
			}
			if (flag != 1) printf("Cell data in (%d,%d) GONE\n", rr, cc);
		}
		scanf("%d%d", &r, &c);
		if (r != 0 || c != 0) printf("\n");
	}

	return 0;
}
