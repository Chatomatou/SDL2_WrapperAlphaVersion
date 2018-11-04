// Inclusion de la bibliothèque du module d'entité
#include "entity.hpp"

using namespace sdl;

 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Permet de crée un vecteur2D a partir d'un angle et un "rayon"
@ Param : la taille du vecteur, et l'angle 
*/
Entity::Vector2f Entity::Vector2f::Vector2fCreateFromAngle(const double length, const double angle)
{
    return {cos((angle * M_PI) / 180.0) * length, sin((angle * M_PI) / 180.0) * length};
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Ajoute un vecteur a un vecteur
@ Param : Un vecteur2D
*/
Entity::Vector2f Entity::Vector2f::operator+(const Vector2f& vector2f)
{
    return {x + vector2f.x, y + vector2f.y};
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Soustrait un vecteur a un vecteur
@ Param : Un vecteur2D
*/
Entity::Vector2f Entity::Vector2f::operator-(const Vector2f& vector2f)
{
    return {x - vector2f.x, y - vector2f.y};
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Multiplie les projection par un coefficient 
@ Param : Un coefficient 
*/
Entity::Vector2f Entity::Vector2f::operator*(const double coef)
{
    return {x * coef, y * coef};
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Ajoute un vecteur a un vecteur
@ Param : Un vecteur2D
*/
void Entity::Vector2f::operator+=(const Vector2f& vector2f)
{
    x += vector2f.x;
    y += vector2f.y;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Soustrait un vecteur a un vecteur
@ Param : Un vecteur2D
*/
void Entity::Vector2f::operator-=(const Vector2f& vector2f)
{
    x -= vector2f.x; 
    y -= vector2f.y;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Multiplier les projection par un coefficient
@ Param : Le coefficient
*/
void Entity::Vector2f::operator*=(const double coef)
{
    x *= coef; 
    y *= coef;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Modifie la position de l'entité transformable par celle du composante du vecteur 
@ Param : Un vecteur2D
*/
void Entity::Transformable::setPosition(const Entity::Vector2f& vector2f)
{
    m_position = vector2f;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Modifie la position de l'entité transformable par coordonnées
@ Param : position en X et position en Y 
*/
void Entity::Transformable::setPosition(const double x, const double y)
{
    m_position.x = x;
    m_position.y = y;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Accesseur(getteur) qui recupere un vecteur2D qui est la position
@ Param : void
*/
Entity::Vector2f Entity::Transformable::getPosition() const
{
    return m_position;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Change le scale de l'entité transformable depuis un vecteur2D
@ Param : Un vecteur2D
*/
void Entity::Transformable::setScale(const Entity::Vector2f& vector2f)
{
    m_scale = vector2f;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Change le scale de l'entité transformable de puis une coordonnées 
@ Param : Un vecteur2D
*/
void Entity::Transformable::setScale(const double x, const double y)
{
    m_scale.x = x;
    m_scale.y = y;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Accesseur(getteur) recupere un vector2d qui correspond au scale
@ Param : void
*/
Entity::Vector2f Entity::Transformable::getScale() const
{
    return m_scale;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Muttateur(setter) change l'origine de l'image par un vector2D
@ Param : un vecteur2D
*/
void Entity::Transformable::setOrigin(const Entity::Vector2f& vector2f)
{
    m_origin = vector2f;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Muttateur(setter) change l'origine de l'image par une coordonnées
@ Param : l'axe x et l'axe y
*/
void Entity::Transformable::setOrigin(const double x, const double y)
{
    m_origin.x = x;
    m_origin.y = y;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Accesseur(getter) qui récupere le vecteur2D associé a l'origin de l'image
@ Param : void
*/
Entity::Vector2f Entity::Transformable::getOrigin() const
{
    return m_origin;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Muttateur(setter) qui change la rotation de l'image par un angle en degrée
@ Param : l'angle en degrée 
*/
void Entity::Transformable::setRotation(const double angle)
{
    m_rotation = angle;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Accesseur(getter) qui récupere la rotation de l'image en degrée
@ Param : l'angle en degrée 
*/
double Entity::Transformable::getRotation() const
{
    return m_rotation;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Déplace le sprite selon un vecteur 
@ Param : un vecteur2D
*/
void Entity::Transformable::move(const Entity::Vector2f& vector2f)
{
    m_position += vector2f;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Déplace le sprite selon un décalage en X et en Y
@ Param : coordonnées x et y
*/
void Entity::Transformable::move(const double offsetX, const double offsetY)
{
    m_position.x += offsetX;
    m_position.y += offsetY;
}
 /*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Charge en mémoire un sprite 
@ Param : Une référence Graphics et un chemin "repertoire" 
*/
Entity::Sprite::Sprite(Graphics& graphics, const std::string& path) : Entity::Transformable{}
{
    SDL_Surface* surface = IMG_Load(path.data());
    m_texture = std::shared_ptr<SDL_Texture>{SDL_CreateTextureFromSurface(graphics.getRenderer(), surface), &SDL_DestroyTexture};
    SDL_FreeSurface(surface);
    SDL_QueryTexture(m_texture.get(), nullptr, nullptr, &m_w, &m_h);
} 
/*
\ Author : Samuel BICZO 
\ Date : 03/11/2018
@ Description : Déssine le sprite a l'écran 
@ Param : Un référence Graphics 
*/
void Entity::Sprite::draw(Graphics& graphics)
{
    SDL_RendererFlip flip {static_cast<SDL_RendererFlip>(SDL_FLIP_VERTICAL | SDL_FLIP_HORIZONTAL)};
    
    SDL_Rect dstRect{static_cast<int>(m_position.x), static_cast<int>(m_position.y), static_cast<int>(m_w * m_scale.x), static_cast<int>(m_h * m_scale.y)};
    SDL_Point origin {static_cast<int>(m_origin.x), static_cast<int>(m_origin.y)};
    SDL_RenderCopyEx(graphics.getRenderer(), m_texture.get(), nullptr, &dstRect, m_rotation, &origin, flip);
}
int Entity::Sprite::getWidth() const
{
    return m_w;
}
int Entity::Sprite::getHeight() const
{
    return m_h;
}