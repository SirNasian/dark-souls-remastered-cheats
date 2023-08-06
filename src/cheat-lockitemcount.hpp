#include "cheat.hpp"

class LockItemCount : public Cheat
{
	public:
		LockItemCount() {};
		bool status(unsigned int pid) override;
		void enable(unsigned int pid) override;
		void disable(unsigned int pid) override;
};
