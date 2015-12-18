/* See COPYRIGHT for copyright information. */

#ifndef JOS_KERN_TRAP_H
#define JOS_KERN_TRAP_H
#ifndef JOS_KERNEL
# error "This is a JOS kernel header; user programs should not #include it"
#endif

#include <inc/trap.h>
#include <inc/mmu.h>

/* The kernel's interrupt descriptor table */
extern struct Gatedesc idt[];

void idt_init(void);
void print_regs(struct PushRegs *regs);
void print_trapframe(struct Trapframe *tf);
void page_fault_handler(struct Trapframe *);
void backtrace(struct Trapframe *);

void inthandle_divide(void);
void inthandle_debug(void);
void inthandle_nmi(void);
void inthandle_brkpt(void);
void inthandle_oflow(void);
void inthandle_bound(void);
void inthandle_illop(void);
void inthandle_device(void);
void inthandle_dblflt(void);

void inthandle_tss(void);
void inthandle_segnp(void);
void inthandle_stack(void);
void inthandle_gpflt(void);
void inthandle_pgflt(void);

void inthandle_fperr(void);
void inthandle_align(void);
void inthandle_mchk(void);
void inthandle_simderr(void);

void inthandle_syscall(void);
void inthandle_default(void);

#endif /* JOS_KERN_TRAP_H */
