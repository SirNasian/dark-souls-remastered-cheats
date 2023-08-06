#include "cheat.hpp"

class Invincibility : public Cheat
{
	private:
		long long base_address = 0;
	public:
		Invincibility() {};
		bool status(unsigned int pid) override;
		void enable(unsigned int pid) override;
		void disable(unsigned int pid) override;
};
