#ifndef VECTORS_H
#define VECTORS_H

#include <cmath>

struct vector2f;

struct point2f{
	float x, y;
    point2f();
    point2f(float px, float py);
    point2f& operator=(const point2f& right);
    point2f& operator+=(const vector2f& right);
};

const point2f operator+(const point2f& left, const vector2f& right);
const point2f operator+(const vector2f& left, const point2f& right);
const vector2f operator-(const point2f& left, const point2f& right);

struct vector2f{
	float x, y;
    vector2f();
    vector2f(float vx, float vy);
    vector2f& operator=(const vector2f& right);
    vector2f& operator+=(const vector2f& right);
    vector2f& operator-=(const vector2f& right);
};

const vector2f operator+(const vector2f& left, const vector2f& right);
const vector2f operator-(const vector2f& left, const vector2f& right);
const vector2f operator*(const vector2f& left, const float& right);
const vector2f operator*(const float& left, const vector2f& right);
const vector2f operator/(const vector2f& left, const float& right);
const float operator*(const vector2f& left, const vector2f& right);
const float operator&(const vector2f& left, const vector2f& right);
const vector2f normalize(const vector2f& vector);
const float length(const vector2f& vector);

struct Line_t{
    point2f p1, p2;
    Line_t();
    Line_t(point2f first, point2f second);
    Line_t(float first_x, float first_y, float second_x, float second_y);
};

const vector2f normal(const Line_t& line);

const float distance(const point2f& left, const point2f& right);

#endif
