#include "main.h"
#include "part.h"
#include "gpio.h"

extern void lcd_19264_draw_logo(void);

static void at91_macb_hw_init(void)
{
	sys_write(AT91C_PMC_PCER, 1 << AT91C_ID_EMAC);

	/*
	 * Disable pull-up on:
	 *	RXDV (PA17) => PHY normal mode (not Test mode)
	 *	ERX0 (PA14) => PHY ADDR0
	 *	ERX1 (PA15) => PHY ADDR1
	 *	ERX2 (PA25) => PHY ADDR2
	 *	ERX3 (PA26) => PHY ADDR3
	 *	ECRS (PA28) => PHY ADDR4  => PHYADDR = 0x0
	 *
	 * PHY has internal pull-down
	 */

	writel(AT91C_PIO_PA14 |
	       AT91C_PIO_PA15 |
	       AT91C_PIO_PA17 |
	       AT91C_PIO_PA25 |
	       AT91C_PIO_PA26 |
	       AT91C_PIO_PA28, AT91C_PIOA_PPUDR);


    /*
     * This is  for the users custom init routine
     * Overwrite this file with your own routine to init
     * your own H/W features.
     */
	/* Need to reset PHY -> 500ms reset */
	sys_write(AT91C_RSTC_RMR, AT91C_RSTC_KEY | (AT91C_RSTC_ERSTL & (0x0D << 8)) | AT91C_RSTC_URSTEN);

	sys_write(AT91C_RSTC_RCR, AT91C_RSTC_KEY | AT91C_RSTC_EXTRST);

	/* Wait for end hardware reset */
	while (!(readl(AT91C_RSTC_RSR) & AT91C_RSTC_NRSTL));

	/* Restore NRST value */
	sys_write(AT91C_RSTC_RMR, AT91C_RSTC_KEY | (AT91C_RSTC_ERSTL & (0x0 << 8)) |  AT91C_RSTC_URSTEN);

	writel(AT91C_PIO_PA14 |
	       AT91C_PIO_PA15 |
	       AT91C_PIO_PA17 |
	       AT91C_PIO_PA25 |
	       AT91C_PIO_PA26 |
	       AT91C_PIO_PA28, AT91C_PIOA_PPUER);

}


void user_hw_init(void)
{
	#if 0
	/* Draw bootlogo */
	lcd_19264_draw_logo();
	#endif

	/* Init at91 macb, do not do this will make at91 macb network is invalid */
	at91_macb_hw_init();
}
