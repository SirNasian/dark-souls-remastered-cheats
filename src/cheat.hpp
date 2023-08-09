#pragma once

class Cheat
{
	public:
		virtual ~Cheat() {};
		virtual bool status(const unsigned int pid) { return false; };
		virtual void enable(const unsigned int pid) {};
		virtual void disable(const unsigned int pid) {};
};
