#include <iostream>

#include <SDL3/SDL.h>

#include "imgui.h"
#include "imgui_internal.h"
#include "NMJLog.h"
#include "backends/imgui_impl_sdl3.h"
#include "backends/imgui_impl_sdlrenderer3.h"

#define WINSIZE_W 300
#define WINSIZE_H 200

SDL_Window* sdlWin;
SDL_Renderer* sdlRenderer;
bool running = true;

using namespace NMJLog;

namespace NMJ
{
    bool SetupSdl()
    {
        printf("hello world");
    
        if (!SDL_Init(SDL_INIT_GAMEPAD | SDL_INIT_JOYSTICK | SDL_INIT_VIDEO))
        {
            Log_SDLErr("Failed to init SDL.");
            return true;
        }
    
        float pixelScale = SDL_GetDisplayContentScale(SDL_GetPrimaryDisplay());
        SDL_WindowFlags winFlags = SDL_WINDOW_HIGH_PIXEL_DENSITY;
        sdlWin = SDL_CreateWindow("NMouseJoy", WINSIZE_W * pixelScale, WINSIZE_H * pixelScale, winFlags);
        if (sdlWin == nullptr)
        {
            Log_SDLErr("Failed to create window.");
            return true;
        }
    
        sdlRenderer = SDL_CreateRenderer(sdlWin, nullptr);
        if (sdlRenderer == nullptr)
        {
            printf("Failed to create renderer.");
            return true;
        }
    
        SDL_SetRenderVSync(sdlRenderer, 1);
        SDL_SetWindowPosition(sdlWin,SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
        SDL_ShowWindow(sdlWin);
        return false;
    }
    
    void SetupImGui()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        
        ImGui::StyleColorsClassic();
         
        ImGui_ImplSDL3_InitForSDLRenderer(sdlWin, sdlRenderer);
        ImGui_ImplSDLRenderer3_Init(sdlRenderer);
        
    }
    
    void ProgramLoop()
    {
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent))
        {
            ImGui_ImplSDL3_ProcessEvent(&sdlEvent);
            
            if (sdlEvent.type == SDL_EVENT_QUIT || sdlEvent.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
                running = false;
        }
    }
}

int main() {
    
    if (NMJ::SetupSdl())
    {
        return 1;
    }
    NMJ::SetupImGui();
    
    while (running)
    {
        NMJ::ProgramLoop();
    }
    
    return 0;
}
