//
// Created by mathd on 2026-07-21.
//

#include "NMJLog.h"

#include <iostream>

#include "SDL3/SDL_error.h"

namespace NMJLog
{
    void Log(std::string str)
    {
        std::cout << str + "\n";
    }

    void Log_SDLErr(std::string str)
    {
        Log(str + " (SDL Error: "+ SDL_GetError() +")");
    }
}
