#ifndef RESIZINGEFFECT_HPP
#define RESIZINGEFFECT_HPP
#include "effect.hpp"
class ResizeEffect: virtual public Effect {
private:
	static void MyCallbackForAxeY(int iY, void *userData);
	static void MyCallbackForAxeX(int iX, void *userData);
public:
	ResizeEffect(){}
	~ResizeEffect(){}
	Mat doEffect(Mat source,String windowName);
};
#endif