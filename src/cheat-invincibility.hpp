#include "cheat.hpp"

class Invincibility : public Cheat
{
	private:
		long long getBase(const unsigned int pid);
	public:
		Invincibility() {};
		bool status(unsigned int pid) override;
		void enable(unsigned int pid) override;
		void disable(unsigned int pid) override;
};
