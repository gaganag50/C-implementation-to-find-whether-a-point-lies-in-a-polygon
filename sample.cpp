#include<bits/stdc++.h>

using namespace std;
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

struct Point {
	int x{};
	int y{};

	Point() = default;

	Point(const int &x, const int &y) : x(x), y(y) {}

	Point &operator=(const Point &other) = default;

	bool operator!=(const Point &other) const {
		return x != other.x || (x == other.x && y != other.y);
	}

	bool operator==(const Point &other) const {
		return x == other.x && y == other.y;
	}

	bool operator<(const Point &rhs) const {
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}


};

bool collinear(Point p1, Point p2, Point p3) {
	int x1 = p1.x, y1 = p1.y, x2 = p2.x, y2 = p2.y, x3 = p3.x, y3 = p3.y;
	int a = x1 * (y2 - y3) +
	        x2 * (y3 - y1) +
	        x3 * (y1 - y2);

	return a == 0;
}

bool isInside(vector<Point> polygon, Point p) {
	int N = polygon.size();
	if (N <= 2)return false;
	int counter = 0;
	int i;
	double xinters;
	Point p1, p2;

	p1 = polygon[0];
	for (i = 1; i <= N; i++) {
		p2 = polygon[i % N];

		if (p.y > MIN(p1.y, p2.y)) {
			if (p.y <= MAX(p1.y, p2.y)) {
				if (p.x <= MAX(p1.x, p2.x)) {
					if (p1.y != p2.y) {
						if (collinear(p1, p2, p)) {
							return false;
						}
						xinters = double((p.y - p1.y)) * (p2.x - p1.x) / (double((p2.y - p1.y))) + p1.x;
						if (p1.x == p2.x || p.x < xinters) {
							// cout << xinters << '\n';
							counter++;
						}
					}
				}
			}
		}
		p1 = p2;
	}

	return counter % 2 != 0;
}

int main() {
	vector<Point> poly = {{1,  -1},
		{ -1, -2},
		{0,  0}
	};
	Point p = {0, -1};
	cout << isInside(poly, p);
}