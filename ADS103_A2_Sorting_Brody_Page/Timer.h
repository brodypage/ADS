#pragma once
#include <chrono>

//code used from https://www.learncpp.com/cpp-tutorial/timing-your-code/
//modified by me to use milliseconds rather than seconds

class Timer
{

private:
	// Type aliases to make accessing nested type easier
	using clock_t = std::chrono::steady_clock; //modified by me
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(clock_t::now() - m_beg).count(); //modified by me
	}
};


