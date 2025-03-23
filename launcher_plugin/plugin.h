#pragma once

#include "ofxCore.h"
#include "ofxProperty.h"
#include "ofxImageEffect.h"

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT
#endif

extern "C"
{
    EXPORT OfxPlugin* OfxGetPlugin(int nth);
}