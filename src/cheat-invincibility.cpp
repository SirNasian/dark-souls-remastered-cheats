#include <sys/ptrace.h>
#include <sys/user.h>
#include <sys/wait.h>

#include "cheat-invincibility.hpp"

bool Invincibility::status(unsigned int pid)
{
	if (this->base_address == 0) return false;
	long long data;

	if (ptrace(PTRACE_ATTACH, pid, 0, 0) == -1) return false;
	waitpid(pid, (int*)(&data), 0);

	data = ptrace(PTRACE_PEEKDATA, pid, this->base_address+0x524, 0);
	ptrace(PTRACE_DETACH, pid, 0, 0);

	unsigned char* ptr = (unsigned char*)(&data);
	return (ptr[0] == 0x40);
}

void Invincibility::enable(unsigned int pid)
{
	const void* addr = (void*)0x140314d70;
	long long data_original, data_breakpoint;
	unsigned char* ptr;

	if (ptrace(PTRACE_ATTACH, pid, 0, 0) == -1) return;
	waitpid(pid, (int*)(&data_original), 0);

	data_original   = ptrace(PTRACE_PEEKDATA, pid, addr, 0);
	data_breakpoint = data_original;

	ptr = (unsigned char*)(&data_breakpoint);
	ptr[0] = 0xCC;
	ptrace(PTRACE_POKEDATA, pid, addr, data_breakpoint);

	ptrace(PTRACE_CONT, pid, 0, 0);
	waitpid(pid, (int*)(&data_breakpoint), 0);

	struct user_regs_struct regs;
	ptrace(PTRACE_GETREGS, pid, 0, &regs);
	regs.rip--;
	ptrace(PTRACE_POKEDATA, pid, addr, data_original);
	ptrace(PTRACE_SETREGS, pid, addr, &regs);
	this->base_address = regs.rax;

	data_original = ptrace(PTRACE_PEEKDATA, pid, this->base_address+0x524, 0);
	ptr = (unsigned char*)(&data_original);
	ptr[0] = 0x40;

	ptrace(PTRACE_POKEDATA, pid, this->base_address+0x524, data_original);
	ptrace(PTRACE_DETACH, pid, 0, 0);
};

void Invincibility::disable(unsigned int pid)
{
	const void* addr = (void*)0x140314d70;
	long long data_original, data_breakpoint;
	unsigned char* ptr;

	if (ptrace(PTRACE_ATTACH, pid, 0, 0) == -1) return;
	waitpid(pid, (int*)(&data_original), 0);

	data_original   = ptrace(PTRACE_PEEKDATA, pid, addr, 0);
	data_breakpoint = data_original;

	ptr = (unsigned char*)(&data_breakpoint);
	ptr[0] = 0xCC;
	ptrace(PTRACE_POKEDATA, pid, addr, data_breakpoint);

	ptrace(PTRACE_CONT, pid, 0, 0);
	waitpid(pid, (int*)(&data_breakpoint), 0);

	struct user_regs_struct regs;
	ptrace(PTRACE_GETREGS, pid, 0, &regs);
	regs.rip--;
	ptrace(PTRACE_POKEDATA, pid, addr, data_original);
	ptrace(PTRACE_SETREGS, pid, addr, &regs);
	this->base_address = regs.rax;

	data_original = ptrace(PTRACE_PEEKDATA, pid, this->base_address+0x524, 0);
	ptr = (unsigned char*)(&data_original);
	ptr[0] = 0x00;

	ptrace(PTRACE_POKEDATA, pid, this->base_address+0x524, data_original);
	ptrace(PTRACE_DETACH, pid, 0, 0);
};
