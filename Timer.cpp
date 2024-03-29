
#include "Timer.h"

double Timer::elapsed() const {
    return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
}

void Timer::reset() {
    m_beg = clock_t::now();
}