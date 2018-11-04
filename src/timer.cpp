#include "timer.hpp"

using namespace sdl;

Timer::Timer(const unsigned int frame_limitation) : m_start{0}, m_frameLimit{frame_limitation}, m_currentFps{0}
{
    
}

void Timer::start_timer()
{
    m_start = SDL_GetTicks();
}

float Timer::getElapsedTime()
{
    return SDL_GetTicks() - m_start;
}
unsigned int Timer::getFPS() const
{
    return m_currentFps;
}
void Timer::limitFPS()
{
    if(1000 / m_frameLimit > getElapsedTime())
    {
        SDL_Delay( (1000 / m_frameLimit) - getElapsedTime());
        m_currentFps = 1000 / getElapsedTime();
    }
}