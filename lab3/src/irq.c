#include "tools.h"
int is_local_timer ()
{
  return *LOCAL_TIMER_CONTROL_REG & 0x80000000; //31 Interrupt flag (Read-Only)
}

int is_core_timer ()
{
  int cntp_ctl_el0;
  asm volatile ("mrs %0, cntp_ctl_el0":"=r" (cntp_ctl_el0)); 
  return cntp_ctl_el0 & 4; //ISTATUS, bit [2] if Timer condition is met return 1
}	
void irq_router ()
{
    if (is_core_timer ())
    {
        uart_puts ("core timer\n");
        core_timer_handler ();
    }
    else if (is_local_timer ())
    {
        uart_puts ("local timer\n");
        local_timer_handler ();
    }
    else
    {
        uart_puts ("wtf? ghooooost IRQ\n");
    }
}