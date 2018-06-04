#ifndef STITCHINGEFFECT_HPP
#define STITCHINGEFFECT_HPP
#include "effect.hpp"
class StitchingEffect: virtual public Effect {
private:
	
public:
	StitchingEffect(){}
	~StitchingEffect(){}
	Mat doEffect(Mat source,String windowName);
};
#endif