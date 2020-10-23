#ifndef _VEC3_H_
#define _VEC3_H_

#include <iostream>
using namespace std; //For Copy debug


template<typename T>
class Vec3
{

public:
	T x;
	T y;
	T z;

	// - CONSTRUCTORS - //
	Vec3() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Vec3(T a, T b, T c) {
		x = a;
		y = b;
		z = c;
	}

	Vec3(const Vec3<T>& vect) {
		this->x = vect.x;
		this->y = vect.y;
		this->z = vect.z;
		cout << "Copy constructor" << endl;
	}

	// CLASS FUNC
	static float Magnitude(T a, T b, T c) {
		T aX = a * a;
		T bX = b * b;
		T cX = c * c;
		return sqrt(aX + bX + cX);
	}

	// -- FUNCTIONS --- //
	void Normalize() {
		float magnitude = Magnitude(this->x, this->y, this->z);

		this->x /= magnitude;
		this->y /= magnitude;
		this->z /= magnitude;
	}

	// We use U so we can work with vectors of different type. (Distance between (1,2,3) and (1.0f,2.0f,3.0f) )
	template<typename U> float DistanceTo(const Vec3<U>& vect) const {
		return Magnitude(this->x - vect.x, this->y - vect.y, this->z - vect.z);
	}

	template<typename U> T DotProduct(const Vec3<U>& vect) const {
		return (this->x * vect.x + this->y * vect.y + this->z * vect.z);
	}

	template<typename U> Vec3<T> CrossProduct(const Vec3<U>& vect) const {
		return Vec3(this->y * vect.z - this->z * vect.y, -(this->x * vect.z - this->z * vect.x), this->x * vect.y - this->y * vect.x);
	}

	template<typename U> float AngleBetween(const Vec3<U>& vect) const {
		double dotProd = this->DotProduct(vect);
		double magnitudeA = Magnitude(this->x, this->y, this->z);
		double magnitudeB = Magnitude(vect.x, vect.y, vect.z);
		double cosine = dotProd / (magnitudeA * magnitudeB);
		double angle = acos(cosine);
		return angle;
	}

	Vec3<T> operator+(Vec3& vect) {
		return Vec3<T>(this->x + vect.x, this->y + vect.y, this->z + vect.z);
	}

};

#endif