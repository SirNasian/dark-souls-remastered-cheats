#include <sys/ptrace.h>
#include <sys/wait.h>

#include "cheat-lockspellcount.hpp"
#include "procmemio/procmemio.h"

bool LockSpellCount::status(const unsigned int pid)
{
	unsigned char data[2];
	procmemio_read(pid, (void*)0x1407530e1, data, 2);
	return ((data[0] != 0x03) || (data[1] != 0xcf));
}

void LockSpellCount::enable(const unsigned int pid)
{
	const unsigned char data[2] = { 0x90, 0x90 };
	procmemio_write(pid, (void*)0x1407530e1, data, 2);
};

void LockSpellCount::disable(const unsigned int pid)
{
	const unsigned char data[2] = { 0x03, 0xcf };
	procmemio_write(pid, (void*)0x1407530e1, data, 2);
};
