#include "vectors.hpp"

using namespace std;

point2f::point2f()
{
    x = y = 0;
}

point2f::point2f(float px, float py)
{
    this->x = px;
    this->y = py;
}

point2f& point2f::operator=(point2f p){
	x = p.x;
	y = p.y;
	return *this;
}

point2f point2f::operator+(vector2f vec){
	point2f tmp;
	tmp.x = x + vec.x;
	tmp.y = y + vec.y;
	return tmp;
}

point2f point2f::operator+=(vector2f vec){
	x += vec.x;
	y += vec.y;
	return *this;
}

vector2f point2f::operator-(point2f p){
    vector2f tmp;
	tmp.x = x - p.x;
	tmp.y = y - p.y;
	return tmp;
}

vector2f::vector2f()
{
    x = 0;
    y = 1;
}

vector2f::vector2f(float vx, float vy)
{
    this->x = vx;
    this->y = vy;
}

vector2f vector2f::operator+(vector2f vec){
	vector2f tmp;
	tmp.x = x + vec.x;
	tmp.y = y + vec.y;
	return tmp;
}

vector2f vector2f::operator-(vector2f vec){
	vector2f tmp;
	tmp.x = x - vec.x;
	tmp.y = y - vec.y;
	return tmp;
}

vector2f& vector2f::operator=(vector2f vec){
	x = vec.x;
	y = vec.y;
	return *this;
}

vector2f vector2f::operator+=(vector2f vec){
	x += vec.x;
	y += vec.y;
	return *this;
}

vector2f vector2f::operator-=(vector2f vec){
	x -= vec.x;
	y -= vec.y;
	return *this;
}

vector2f vector2f::operator*(float m){
	vector2f tmp;
	tmp.x = x*m;
	tmp.y = y*m;
	return tmp;
}

vector2f vector2f::operator/(float m){
	vector2f tmp;
	tmp.x = x/m;
	tmp.y = y/m;
	return tmp;
}

float vector2f::operator*(vector2f vec){
	return x*vec.x + y*vec.y;
}

float vector2f::operator&(vector2f vec){
	return x*vec.y - y*vec.x;
}

float vector2f::length(){
	return sqrt(x*x + y*y);
}

vector2f vector2f::normalize(){
    if (length() < 0.000001) return vector2f(0, 0);
    return *this/length();
}

vector2f Line_t::normal(){
	vector2f tmp;
	tmp.x = p2.y - p1.y;
	tmp.y = p1.x - p2.x;
	return tmp.normalize();
}

float distance(point2f p1, point2f p2){
	return sqrt(pow(p1.x-p2.x, 2.f) + pow(p1.y-p2.y, 2.f));
}
