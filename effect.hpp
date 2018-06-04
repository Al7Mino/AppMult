#ifndef EFFECT_HPP
#define EFFECT_HPP
class Effect {
public:
    virtual Mat doEffect(Mat source,String windowName) =0;
};
#endif