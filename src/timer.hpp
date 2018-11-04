#ifndef TIMER_HPP 
#define TIMER_CPP 

#include <SDL2/SDL.h>
#include <string>

namespace sdl
{
    class Timer
    {
    public:
        Timer(const unsigned int frame_limitation = 60);
        void start_timer();
        float getElapsedTime();
        unsigned int getFPS() const;
        void limitFPS();
    private:
        unsigned int m_start{};
        unsigned int m_frameLimit{};
        unsigned int m_currentFps{};
    };
}

#endif 