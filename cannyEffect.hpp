#ifndef CANNYEFFECT_HPP
#define CANNYEFFECT_HPP
#include "effect.hpp"
class CannyEffect: virtual public Effect {
private:
	static int const max_lowThreshold = 500;
	static int const kernel_size = 3;
	static int const ratio = 1;

	static void CannyThreshold(int, void*);
public:
	CannyEffect(){}
	~CannyEffect(){}
	Mat doEffect(Mat source,String windowName);
	static int doEffectVideo(Mat source2,String windowName);
	static Mat ReapplyEffect(Mat source2,String windowName, int value);

};
#endif
