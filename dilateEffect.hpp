#ifndef DILATEEFFECT_HPP
#define DILATEEFFECT_HPP
#include "effect.hpp"
class DilateEffect: virtual public Effect {
private:
	static int const max_elem = 2;
	static int const max_kernel_size = 21;

	static void Dilation(int, void*);
public:
	DilateEffect(){}
	~DilateEffect(){}
	Mat doEffect(Mat source,String windowName);
	static vector<int> doEffectVideo(Mat source,String windowName);
	static Mat ReapplyEffect(Mat source,String windowName, vector<int> values);
};
#endif