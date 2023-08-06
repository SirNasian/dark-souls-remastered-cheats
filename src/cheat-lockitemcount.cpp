#include <sys/ptrace.h>
#include <sys/wait.h>

#include "cheat-lockitemcount.hpp"

bool LockItemCount::status(unsigned int pid)
{
	long long data;

	if (ptrace(PTRACE_ATTACH, pid, 0, 0) == -1) return false;
	waitpid(pid, (int*)(&data), 0);

	data = ptrace(PTRACE_PEEKDATA, pid, (void*)0x14074f295, 0);
	ptrace(PTRACE_DETACH, pid);

	unsigned char* ptr = (unsigned char*)(&data);
	return (ptr[0] != 0x03) ||
	       (ptr[1] != 0xc5);
}

void LockItemCount::enable(unsigned int pid) {};
void LockItemCount::disable(unsigned int pid) {};
