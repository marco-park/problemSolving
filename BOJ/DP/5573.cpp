#include <iostream>

using namespace std;

int map[1001][1001], d[1001][1001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int h, w, n;
	cin >> h >> w >> n;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> map[i][j];
		}
	}
    n--;
	d[0][0] = n;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
				if (d[i][j] % 2) {
					if (map[i][j]) {
						d[i + 1][j] += d[i][j] / 2;
						d[i][j + 1] += d[i][j] / 2 + 1;
					}
					else {
						d[i + 1][j] += d[i][j] / 2 + 1;
						d[i][j + 1] += d[i][j] / 2;
					}
				}
				else {
					d[i + 1][j] += d[i][j] / 2;
					d[i][j + 1] += d[i][j] / 2;
				}
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (d[i][j] % 2) map[i][j] = 1-map[i][j];
		}
	}


	int x = 0;
	int y = 0;
	while (x<h && y<w) {
		if (map[x][y])y++;
		else x++;
	}
	cout << x+1 << ' ' << y+1 << '\n';
}