#ifndef BRIGHTNESSEFFECT_HPP
#define BRIGHTNESSEFFECT_HPP
#include "effect.hpp"
class BrightnessEffect: public Effect {
private:
	static int const max_kernel_size = 200;

	static void Luminosite(int, void*);
public:
	BrightnessEffect(){}
	~BrightnessEffect(){}
	Mat doEffect(Mat source,String windowName);
	static int doEffectVideo(Mat source,String windowName);
	static Mat ReapplyEffect(Mat source,String windowName, int value);
};
#endif