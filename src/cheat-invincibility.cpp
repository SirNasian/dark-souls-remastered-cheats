#include <procmemio/procmemio.h>

#include "cheat-invincibility.hpp"

long long Invincibility::getBase(const unsigned int pid)
{
	PROCMEMIO_REGS regs;
	procmemio_readRegisters(pid, (void*)0x140314d70, &regs);
	return regs.rax;
}

bool Invincibility::status(const unsigned int pid)
{
	void* addr = (void*)(this->getBase(pid) + 0x524);
	unsigned char data;
	procmemio_read(pid, addr, &data, 1);
	return (data == 0x40);
}

void Invincibility::enable(const unsigned int pid)
{
	void* addr = (void*)(this->getBase(pid) + 0x524);
	unsigned char data = 0x40;
	procmemio_write(pid, addr, &data, 1);
};

void Invincibility::disable(const unsigned int pid)
{
	void* addr = (void*)(this->getBase(pid) + 0x524);
	unsigned char data = 0x00;
	procmemio_write(pid, addr, &data, 1);
};
