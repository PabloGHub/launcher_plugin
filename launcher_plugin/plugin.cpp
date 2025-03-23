#include "plugin.h"

#include <cmath>
#include <iostream>

#define PLUGIN_NAME "launcher_plugin"

// Variable global para almacenar el host
static const OfxHost* gHost = nullptr;

static OfxStatus PluginMain(const char* action, const void* handle, OfxPropertySetHandle inArgs, OfxPropertySetHandle outArgs)
{
    if (strcmp(action, kOfxActionLoad) == 0)
    {
        gHost = (const OfxHost*)handle;
        return kOfxStatOK;
    }

    if (strcmp(action, kOfxActionDescribe) == 0)
    {
        return kOfxStatOK;
    }

    if (strcmp(action, kOfxActionCreateInstance) == 0)
    {
        return kOfxStatOK;
    }

    return kOfxStatReplyDefault;
}

// Definición correcta de OfxPlugin
static OfxPlugin myPlugin =
{
   kOfxImageEffectPluginApi,
   1,
   PLUGIN_NAME,
   1, 0,
   NULL,
   PluginMain
};

// Implementación ÚNICA de OfxGetPlugin
extern "C"
{
    EXPORT OfxPlugin* OfxGetPlugin(int nth)
    {
        if (nth == 0)
            return &myPlugin;
        return NULL;
    }
}
