#include "SharpenProcessor.h"

ps::SharpenProcessor::SharpenProcessor(double sharpenMultiplier)
    : _sharpenMultiplier(sharpenMultiplier)
{
    if(_sharpenMultiplier < 0.0 || _sharpenMultiplier > 100.0)
        throw std::invalid_argument("Multiplier can't be less than 0.0 and more than 100.0");
}

void ps::SharpenProcessor::Process(ps::Image& image) const
{
    //TODO: implement sharpen to improve scanning
}
