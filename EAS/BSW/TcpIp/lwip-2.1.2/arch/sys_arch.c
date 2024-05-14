

#include "arch/sys_arch.h"
#include "lwip/sys.h"
#include "SchM_TcpIp.h"

u32_t sys_now(void)
{
	return TcpIp_SystemTime;
}



sys_prot_t sys_arch_protect(void)
{
	SchM_Enter_TcpIp_TCPIP_EXCLUSIVE_AREA_0();
	return 1;
}

void sys_arch_unprotect(sys_prot_t pval)
{
    (void)pval;

    SchM_Exit_TcpIp_TCPIP_EXCLUSIVE_AREA_0();
	return ;
}
