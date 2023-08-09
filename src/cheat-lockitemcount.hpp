#include "cheat.hpp"

class LockItemCount : public Cheat
{
	public:
		LockItemCount() {};
		bool status(const unsigned int pid) override;
		void enable(const unsigned int pid) override;
		void disable(const unsigned int pid) override;
};
