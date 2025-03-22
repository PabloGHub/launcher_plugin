#include "ofxCore.h"  
#include "ofxProperty.h"  
#include "ofxImageEffect.h"  

#include <cmath>  
#include <iostream>

#define PLUGIN_NAME "l_shake"

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT
#endif

// Definición de la función OfxGetDoubleProperty
OfxStatus OfxGetDoubleProperty(OfxPropertySetHandle properties, const char* property, double* value)
{
    return OfxGetPropertySetDouble(properties, property, 0, value);
}

static OfxStatus PluginMain(OfxImageEffectHandle instance)
{
    return kOfxStatOK;
}

void renderEffect(OfxImageEffectHandle instance)
{
    // Obtener parámetros del plugin
    double time;
    OfxPropertySetHandle effectProps;
    OfxStatus status = OfxGetInstancePropertySet(instance, &effectProps);
    if (status != kOfxStatOK) return;

    // Obtener el frame actual
    status = OfxGetDoubleProperty(effectProps, kOfxPropTime, &time);
    if (status != kOfxStatOK) return;

    // Generar vibración (movimiento aleatorio en X y Y)
    double shakeAmount = 5.0; // Intensidad del efecto
    double offsetX = shakeAmount * (sin(time * 10) * 0.5);
    double offsetY = shakeAmount * (cos(time * 10) * 0.5);

    // Inicializar y aplicar el movimiento a los píxeles
    OfxRectD rect = { 0, 0, 0, 0 };
    rect.x1 += offsetX;
    rect.y1 += offsetY;
    rect.x2 += offsetX;
    rect.y2 += offsetY;
}

static OfxPlugin myPlugin =
{
   kOfxImageEffectPluginApi,
   1,
   PLUGIN_NAME,
   1, 0,
   NULL,
   PluginMain
};

extern "C"
{
    EXPORT OfxPlugin* OfxGetPlugin(int nth)
    {
        return &myPlugin;
    }
}