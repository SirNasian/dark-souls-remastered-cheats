#include "cheat.hpp"

class Invincibility : public Cheat
{
	private:
		long long getBase(const unsigned int pid);
	public:
		Invincibility() {};
		bool status(const unsigned int pid) override;
		void enable(const unsigned int pid) override;
		void disable(const unsigned int pid) override;
};
