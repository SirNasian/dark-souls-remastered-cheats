#include <sys/ptrace.h>
#include <sys/wait.h>

#include "cheat-lockitemcount.hpp"
#include "procmemio/procmemio.h"

bool LockItemCount::status(unsigned int pid)
{
	unsigned char data[2];
	procmemio_read(pid, (void*)0x14074f295, data, 2);
	return ((data[0] != 0x03) || (data[1] != 0xc5));
}

void LockItemCount::enable(unsigned int pid)
{
	const unsigned char data[2] = { 0x90, 0x90 };
	procmemio_write(pid, (void*)0x14074f295, data, 2);
};

void LockItemCount::disable(unsigned int pid)
{
	const unsigned char data[2] = { 0x03, 0xc5 };
	procmemio_write(pid, (void*)0x14074f295, data, 2);
};
