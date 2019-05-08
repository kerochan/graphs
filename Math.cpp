#include"Math.hpp"

float MyMath::NewtonsMethodForSqrt(const float d, float x, int n) {
	if (n > 0)
		x = MyMath::NewtonsMethodForSqrt(d, (x * x + d) / (2 * x), n - 1);
	return x;
}

float MyMath::LaughApproxSqrt(const float x) {
	return 1 + (x / 4);
}

float MyMath::MySqrt(const float d, int n) {
	return MyMath::NewtonsMethodForSqrt(d, MyMath::LaughApproxSqrt(d), n);
}

float MyMath::MyDist(const float x, const float y, int n) {
	if (x == 0 && y == 0)
		return 0.0f;
	return MyMath::MySqrt(x * x + y * y, n);
}