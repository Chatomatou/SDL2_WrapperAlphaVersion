#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <SDL2/SDL.h> // Bibliothèque SDL 
#include <string> // Bibliothèque std::string
#include <memory> // Bibliothèque std::unique_ptr std::shared_ptr std::weak_ptr 

// SDL Module graphiqueL
namespace sdl  
{
    using RGBA = SDL_Color;

    class Graphics 
    {
    public:
        Graphics(const std::string& title = "Untitled", unsigned int x = SDL_WINDOWPOS_CENTERED, unsigned int y = SDL_WINDOWPOS_CENTERED, unsigned int w = 800, unsigned int h = 600, unsigned int flags = SDL_WINDOW_SHOWN);
        ~Graphics();

        
        void setWindowTitle(const std::string& title);
        std::string getWindowTitle() const;
        unsigned int getWidth() const;
        unsigned getHeight() const;
        void setWindowSize(const unsigned int w, const unsigned int h);
        
        SDL_Renderer* getRenderer();
        void setRenderTarget(SDL_Texture* texture);
        
        void setBackgroundColor(const RGBA& color);
        void setBackgroundColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a);
        void clear();
        void update();
 

        void setCallback(void(*function)(Graphics& graphics));
        void loop();
    private:
        std::shared_ptr<SDL_Window> m_window{}; // La Fenêtre SDL 
        std::shared_ptr<SDL_Renderer> m_renderer{}; // Rendu pour la fenêtre SDL 
        void (*m_callback)(Graphics& graphics); // Pointeur de fonction sur la boucle principale

    };
}


#endif 