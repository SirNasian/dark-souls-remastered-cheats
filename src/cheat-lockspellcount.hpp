#include "cheat.hpp"

class LockSpellCount : public Cheat
{
	public:
		LockSpellCount() {};
		bool status(const unsigned int pid) override;
		void enable(const unsigned int pid) override;
		void disable(const unsigned int pid) override;
};
