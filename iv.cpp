#include <iostream>
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
using namespace std;

int main(int argc, char *argv[]){
    bool quit = false, port = false;
    string version;
    int width = 0, height = 0, max = 0, r = 0, g = 0, b = 0;

    if (argc == 2 && string(argv[1]) == "-p")
    {
        port = true;
    }
    

    cin >> version >> width >> height >> max;
    if (version != "P3")
    {
        cerr << "Only ppm version P3 files supported." << endl;
        exit(-1);
    }
    

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window;

    if (port)
    {
        window = SDL_CreateWindow("Image Viewer", height, width, SDL_WINDOW_OPENGL);
    }
    else{
        window = SDL_CreateWindow("Image Viewer", width, height, SDL_WINDOW_OPENGL);
    }

    if (window == nullptr)
    {
        printf("Could not create window : %s\n", SDL_GetError());
        exit(-1);
    }
    
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    const SDL_PixelFormatDetails* fmt = SDL_GetPixelFormatDetails(surface->format);

    SDL_Rect rect;

    if (port)
    {
        for (int x = 0; x < height; x++)
        {
            for (int y = width-1; y > -1; y--)
            {
                cin >> r >> g >> b;
                rect.y = y, rect.x = x, rect.h = rect.w = 1;
                SDL_FillSurfaceRect(surface, &rect, SDL_MapRGB(fmt, nullptr, r, g, b));
            }
            
        }
    }
    else{
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                cin >> r >> g >> b;
                rect.y = y, rect.x = x, rect.h = rect.w = 1;
                SDL_FillSurfaceRect(surface, &rect, SDL_MapRGB(fmt, nullptr, r, g, b));
            }
            
        }
    }
    
    while (!quit)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT)
        {
            quit = true;
        }
        SDL_UpdateWindowSurface(window);
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}