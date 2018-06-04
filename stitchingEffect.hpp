#ifndef STITCHINGEFFECT_HPP
#define STITCHINGEFFECT_HPP
#include "effect.hpp"
class StitchingEffect {
private:
	void printUsage();
public:
	StitchingEffect(){}
	~StitchingEffect(){}
	static Mat doStitch(int argc, char** argv, string windowName);
	int parseCmdArgs(int argc, char** argv);
};
#endif