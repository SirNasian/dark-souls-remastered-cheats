#pragma once

class Cheat
{
	public:
		virtual ~Cheat() {};
		virtual bool status(unsigned int pid) { return false; };
		virtual void enable(unsigned int pid) {};
		virtual void disable(unsigned int pid) {};
};
