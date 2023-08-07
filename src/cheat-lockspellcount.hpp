#include "cheat.hpp"

class LockSpellCount : public Cheat
{
	public:
		LockSpellCount() {};
		bool status(unsigned int pid) override;
		void enable(unsigned int pid) override;
		void disable(unsigned int pid) override;
};
