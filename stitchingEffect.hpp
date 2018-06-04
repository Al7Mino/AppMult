#ifndef STITCHINGEFFECT_HPP
#define STITCHINGEFFECT_HPP
#include "effect.hpp"
class StitchingEffect {
public:
	StitchingEffect(){}
	~StitchingEffect(){}
	static Mat doStitch(vector<Mat> imgs, string windowName);
};
#endif