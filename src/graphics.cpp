// Inclusion de la bibliothèque du module graphique 
#include "graphics.hpp"

using namespace sdl;

/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Constructeur de la class Graphics de mon wrapper SDL 
@ Param : titre de la fenetre, position x de la fenetre, position y de la fenetre, largeur de la fenetre, hauteur de la fenpetre, drapeau pour la configuration de la fenêtre 
*/
Graphics::Graphics(const std::string& title, unsigned int x, unsigned int y, unsigned int w, unsigned int h, unsigned int flags)
{
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    m_window = std::shared_ptr<SDL_Window>{SDL_CreateWindow(title.data(), x, y, w, h, flags), &SDL_DestroyWindow};
    m_renderer = std::shared_ptr<SDL_Renderer>{SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED), &SDL_DestroyRenderer};
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Destructeur de la class Graphics de mon wrapper SDL qui détruit les ressources alloué par le module vidéo de SDL  
@ Param : void
*/
Graphics::~Graphics()
{
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Muttateur(setteur) qui permet de changer le titre de la fenêtre  
@ Param : le titre de la fenetre 
*/
void Graphics::setWindowTitle(const std::string& title)
{
    SDL_SetWindowTitle(m_window.get(), title.data());
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Accesseur qui permet de récuperer le titre de la fenêtre  
@ Param : void
*/
std::string Graphics::getWindowTitle() const
{
    return SDL_GetWindowTitle(m_window.get());
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Accesseur qui permet de récuperer la largeur de la fenetre
@ Param : void
*/
unsigned int Graphics::getWidth() const
{
    int w {};
    SDL_GetWindowSize(m_window.get(), &w, nullptr);
    return w;
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Accesseur qui permet de récuperer la hauteur de la fenetre
@ Param : void
*/
unsigned int Graphics::getHeight() const
{
    int h {};
    SDL_GetWindowSize(m_window.get(), nullptr, &h);
    return h;
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Change la hauteur et la largeur de la fenetre 
@ Param : la largeur de la fenetre, la hauteur de la fenetre
*/
void Graphics::setWindowSize(const unsigned int w, const unsigned int h)
{
    SDL_SetWindowSize(m_window.get(), w, h);
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Recuperer le pointeur lié au rendue
@ Param : void
*/
SDL_Renderer* Graphics::getRenderer()
{
    return m_renderer.get();
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Permet de changer vers quoi ou l'on dessine 
@ Param : une texture
*/
void Graphics::setRenderTarget(SDL_Texture* texture)
{
    SDL_SetRenderTarget(m_renderer.get(), texture);
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Charge une couleur pour le rendue 
@ Param : Une structure de type RGBA ou SDL_Color
*/
void Graphics::setBackgroundColor(const RGBA& color)
{
    SDL_SetRenderDrawColor(m_renderer.get(), color.r, color.g, color.b, color.a);
}
void Graphics::setBackgroundColor(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a)
{
    SDL_SetRenderDrawColor(m_renderer.get(), r, g, b, a);
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Nettoie ma fenêtre de la précédente couleur attribuer au rendue 
@ Param : void
*/
void Graphics::clear()
{
    SDL_RenderClear(m_renderer.get());
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Met a jour l'affichage de la fenetre
@ Param : void
*/
void Graphics::update()
{
    SDL_RenderPresent(m_renderer.get());
}
 /*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Permet de changer la fonction loop du wrapper SDL 
@ Param : Pointeur de fonction qui retourne "void" avec un argument qui est un pointeur de la classe Graphics "Graphics*"" 
*/
void Graphics::setCallback(void(*function)(Graphics& graphics))
{
   m_callback = function;
}
/*
\ Author : Samuel BICZO 
\ Date : 02/11/2018
@ Description : Execute la fonction de rappelle 
@ Param : Execute la fonction de rappel
*/
void Graphics::loop()
{
    Graphics& ref = *this;
    m_callback(ref);
}
