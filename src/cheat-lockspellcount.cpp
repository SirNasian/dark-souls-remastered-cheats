#include <sys/ptrace.h>
#include <sys/wait.h>

#include "cheat-lockspellcount.hpp"

bool LockSpellCount::status(unsigned int pid)
{
	const void* addr = (void*)0x1407530e1;
	long long data;

	if (ptrace(PTRACE_ATTACH, pid, 0, 0) == -1) return false;
	waitpid(pid, (int*)(&data), 0);

	data = ptrace(PTRACE_PEEKDATA, pid, addr, 0);
	ptrace(PTRACE_DETACH, pid, 0, 0);

	unsigned char* ptr = (unsigned char*)(&data);
	return (ptr[0] != 0x03) ||
	       (ptr[1] != 0xcf);
}

void LockSpellCount::enable(unsigned int pid)
{
	const void* addr = (void*)0x1407530e1;
	long long data;

	if (ptrace(PTRACE_ATTACH, pid, 0, 0) == -1) return;
	waitpid(pid, (int*)(&data), 0);

	data = ptrace(PTRACE_PEEKDATA, pid, addr, 0);
	unsigned char* ptr = (unsigned char*)(&data);
	ptr[0] = 0x90;
	ptr[1] = 0x90;

	ptrace(PTRACE_POKEDATA, pid, addr, data);
	ptrace(PTRACE_DETACH, pid, 0, 0);
};

void LockSpellCount::disable(unsigned int pid)
{
	const void* addr = (void*)0x1407530e1;
	long long data;

	if (ptrace(PTRACE_ATTACH, pid, 0, 0) == -1) return;
	waitpid(pid, (int*)(&data), 0);

	data = ptrace(PTRACE_PEEKDATA, pid, addr, 0);
	unsigned char* ptr = (unsigned char*)(&data);
	ptr[0] = 0x03;
	ptr[1] = 0xcf;

	ptrace(PTRACE_POKEDATA, pid, addr, data);
	ptrace(PTRACE_DETACH, pid, 0, 0);
};
