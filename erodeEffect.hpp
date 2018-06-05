#ifndef ERODEEFFECT_HPP
#define ERODEEFFECT_HPP
#include "effect.hpp"
class ErodeEffect: virtual public Effect {
private:
	static int const max_elem = 2;
	static int const max_kernel_size = 21;

	static void Erosion(int, void*);
public:
	ErodeEffect(){}
	~ErodeEffect(){}
	Mat doEffect(Mat source,String windowName);
	static vector<int> doEffectVideo(Mat source,String windowName);
	static Mat ReapplyEffect(Mat source,String windowName, vector<int> values);
};
#endif