#ifndef VECTORS_H
#define VECTORS_H

#include <cmath>

struct vector2f;

struct point2f{
	float x, y;
    point2f();
    point2f(float px, float py);
	point2f& operator=(point2f p);
	point2f operator+(vector2f vec);
	point2f operator+=(vector2f vec);
	vector2f operator-(point2f p);
};

struct vector2f{
	float x, y;
    vector2f();
    vector2f(float vx, float vy);
	vector2f operator+(vector2f vec);
	vector2f operator-(vector2f vec);
	vector2f& operator=(vector2f vec);
	vector2f operator+=(vector2f vec);
	vector2f operator-=(vector2f vec);
	vector2f operator*(float m);
	vector2f operator/(float m);
	float operator*(vector2f vec);
	float operator&(vector2f vec);
	float length();
	vector2f normalize();
};

struct Line_t{
	point2f p1, p2;
	vector2f normal();
};

float distance(point2f p1, point2f p2);

#endif
