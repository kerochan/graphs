#pragma once
//©ì‚Ì”ŠwŠÖ”‚Á‚Û‚¢‚à‚Ì
class MyMath {
public:
	static float NewtonsMethodForSqrt(const float d, float x, int n);
	static float LaughApproxSqrt(const float x);
	static float MySqrt(const float d, int n = 10);
	static float MyDist(const float x, const float y, int n = 10);
};