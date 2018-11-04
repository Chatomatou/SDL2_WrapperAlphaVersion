#ifndef ENTITY_HPP
#define ENTITY_HPP 


#include "graphics.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <memory>
#include <cmath>

  
namespace sdl 
{
    namespace Entity 
    {
        struct Vector2f 
        {
            static Vector2f Vector2fCreateFromAngle(const double length, const double angle);

            double x{};
            double y{};

            Vector2f operator+(const Vector2f& vector2f);
            Vector2f operator-(const Vector2f& vector2f);
            Vector2f operator*(const double coef);

            void operator+=(const Vector2f& vector2f);
            void operator-=(const Vector2f& vector2f);
            void operator*=(const double coef);
        };

        class Transformable 
        {
        public: 
            Transformable() = default;

            void setPosition(const Vector2f& vector2f);
            void setPosition(const double x, const double y);
            Vector2f getPosition() const;
            
            void setScale(const Vector2f& vector2f);
            void setScale(const double x, const double y);
            Vector2f getScale() const;

            void setOrigin(const Vector2f& vector2f);
            void setOrigin(const double x, const double y);
            Vector2f getOrigin() const;

            void setRotation(const double angle);
            double getRotation() const;

            void move(const Vector2f& vector2f);
            void move(const double offsetX, const double offsetY);
        protected:
            Vector2f m_position{};
            Vector2f m_scale{1, 1};
            Vector2f m_origin{};
            double m_rotation{180};
        };

        class Sprite : public Transformable
        {
        public:
            Sprite(Graphics& graphics, const std::string& path);

            int getWidth() const;
            int getHeight() const;
            void draw(Graphics& graphics);
        private:
            std::shared_ptr<SDL_Texture> m_texture{};
            int m_w{};
            int m_h{};
        };

      

    }
}
 

#endif 