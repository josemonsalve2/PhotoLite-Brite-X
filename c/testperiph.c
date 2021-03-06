/*
 *
 * Xilinx, Inc.
 * XILINX IS PROVIDING THIS DESIGN, CODE, OR INFORMATION "AS IS" AS A 
 * COURTESY TO YOU.  BY PROVIDING THIS DESIGN, CODE, OR INFORMATION AS
 * ONE POSSIBLE   IMPLEMENTATION OF THIS FEATURE, APPLICATION OR 
 * STANDARD, XILINX IS MAKING NO REPRESENTATION THAT THIS IMPLEMENTATION 
 * IS FREE FROM ANY CLAIMS OF INFRINGEMENT, AND YOU ARE RESPONSIBLE 
 * FOR OBTAINING ANY RIGHTS YOU MAY REQUIRE FOR YOUR IMPLEMENTATION
 * XILINX EXPRESSLY DISCLAIMS ANY WARRANTY WHATSOEVER WITH RESPECT TO 
 * THE ADEQUACY OF THE IMPLEMENTATION, INCLUDING BUT NOT LIMITED TO 
 * ANY WARRANTIES OR REPRESENTATIONS THAT THIS IMPLEMENTATION IS FREE 
 * FROM CLAIMS OF INFRINGEMENT, IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE.
 */

/*
 * 
 *
 * This file is a generated sample test application.
 *
 * This application is intended to test and/or illustrate some 
 * functionality of your system.  The contents of this file may
 * vary depending on the IP in your system and may use existing
 * IP driver functions.  These drivers will be generated in your
 * SDK application project when you run the "Generate Libraries" menu item.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "xparameters.h"
#include "xil_cache.h"
#include "xtmrctr.h"
#include "tmrctr_header.h"
#include "uartlite_header.h"
#include "xbasic_types.h"
#include "xuartlite.h"
#include "xuartlite.h"
#include "xuartlite_l.h"

///////////////////////////DO NOT CHANGE /////////////////////////////////

u8 byte_received[256];
//u8 byte_received[80];	// need enough bytes for 32-value marching grid sweep packet

XUartLite UartLite;		 /* Instance of the UartLite device */

union _two_bytes_to_16bit{
	u16 two_bytes;
	struct { u8 bytes [2];
	};
} two_bytes_to_16bit;

union _crc_c{
	u16 crc_u16;
	struct { u8 crc_u8[2];
	};
}crc_c;

int table[] = {
        0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
        0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
        0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
        0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
        0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
        0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
        0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
        0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
        0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
        0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
        0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
        0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
        0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
        0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
        0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
        0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
        0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
        0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
        0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
        0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
        0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
        0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
        0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
        0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
        0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
        0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
        0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
        0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
        0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
        0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
        0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
        0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0,
        };

XTmrCtr TimerCounter; /* The instance of the timer counter */
XTmrCtr *TmrCtrInstancePtr = &TimerCounter;
u8 TmrCtrNumber = 0x0;
int counter = 0;
////////////////////////////////////////////////////////////////////////////////////////////

XStatus Initialize_TIMER(void);
void sleep_in_s(u32 time);
void sleep_in_ms(u32 time);
void sleep_in_us(u32 time);


typedef struct {
	u8 size;	// 10 + 2*n_dacvals + 2.
	u8 cmd;		// should be 19
	u8 time_HSB	,time_LSB;
	u8 DAC_HSB	,DAC_LSB;
	u8 x_space, y_space ,x_offset, y_offset;
	u8 Aticks, Eticks, Pticks;
	u8 reset_at_HSB,reset_at_LSB, cutoff_at_HSB,cutoff_at_LSB;

} __attribute__((packed)) * const Grid_header; // 16/4/2/1 Channel



void set_bit(u8 bit, u8 index, int *number) {
	*number ^= (-bit ^ *number) & (1 << index);
}

u8 reverse_bits(u8 b) {
   b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
   b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
   b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
   return b;
}


volatile u32 * const slv_regs 	= (volatile u32 *) XPAR_LED_STRIP_CONTROLLER_0_BASEADDR;


// CONSTANTS
#define PIXELS 143
#define NULL_ADDR 255


// Pixel Buffer
typedef struct pixel {
	u8 red;
	u8 green;
	u8 blue;
} pixel;
pixel pixel_buffer[PIXELS];
void inline reset_pixel_buffer()
{
	int i;
	for (i = 0; i < PIXELS; i++)
	{
		pixel_buffer[i].red   = 0x00;
		pixel_buffer[i].green = 0x00;
		pixel_buffer[i].blue  = 0x00;
		if (i == 15)
		{
			pixel_buffer[i].red   = 0x00;
			pixel_buffer[i].green = 0x00;
			pixel_buffer[i].blue  = 0x00;
		}
	}
}


typedef struct led_driver {
	volatile u32  *pixel_addr;  // output
	volatile u32  *pixel_data;  // output
	volatile u32  *print_leds;  // output
	volatile u32  *busy;        // input
} led_driver;
led_driver *my_driver;


void inline setup_slv_regs()
{
	my_driver->pixel_addr  = &slv_regs[0];
	my_driver->pixel_data  = &slv_regs[1];
	my_driver->print_leds  = &slv_regs[2];
	my_driver->busy        = &slv_regs[3];
}
void inline reset_slv_regs(u8 initial)
{
	*(my_driver->pixel_addr)  = 0;
	*(my_driver->pixel_data)  = 0;
	*(my_driver->print_leds)  = 0;

	int i,j;

//	*(my_driver->print_leds) = 1;
//	for (j = 0; j < 2; j++);
//	*(my_driver->print_leds) = 0;

//	for (j = 0; j < 2; j++);

	for (i = 0; i < PIXELS; i++)
	{
		*(my_driver->pixel_addr) = i;
		for (j = 0; j < 2; j++);
		*(my_driver->pixel_data) = ((pixel_buffer[i].green & 0xF0) << 16)
								 + ((pixel_buffer[i].red & 0xF0)  << 8)
								 + ((pixel_buffer[i].blue & 0xF0));
		for (j = 0; j < 2; j++);
	}
	if (initial == 0) while (*(my_driver->busy) == 1);
	//while (*(my_driver->busy) == 1);
	*(my_driver->print_leds) = 1;
	for (j = 0; j < 2; j++);
	*(my_driver->print_leds) = 0;
}


void receive_bytes_of_data(void);

int main()
{
	Xil_ICacheEnable();
	Xil_DCacheEnable();
	Initialize_TIMER();



	//XUartLite_Initialize(&UartLite, XPAR_RS232_UART_1_DEVICE_ID);

	my_driver = malloc(sizeof(led_driver));
	setup_slv_regs();
	reset_pixel_buffer();
	reset_slv_regs(1);

	u32 cmd;

	int i, j;

/*	while (1)
	{
		int j;
		for (i = 0; i < 143; i++)
		{
			*(my_driver->pixel_addr) = i;
			//for (j = 0; j > 5; j++);
			if (i == 0)
				*(my_driver->pixel_data) = 0xFF0000;
			else if (i == 1)
				*(my_driver->pixel_data) = 0xFF00FF;
			else
				*(my_driver->pixel_data) = 0x00FF00;
			for (j = 0; j > 5; j++);
		}
		while (*(my_driver->busy) == 1);
		*(my_driver->print_leds) = 1;
		//for (j = 0; j > 5; j++);
		*(my_driver->print_leds) = 0;
		//sleep_in_ms(100);
	}*/
	u32 Register;

	while(1)
	{
		// receive bytes of data
		receive_bytes_of_data();

		// command is first byte received
		cmd = byte_received[1];

		switch( cmd )
		{

			// RESET (Batch #1 is next)
			case 0:
				reset_pixel_buffer();
				reset_slv_regs(0);
				break;

			// RECEIVE Batch #1 (Batch #2 is next)
			case 1:
				for (i = 0; i < 80; i++)    // 0 to 79 (80 pixels)
				{
					pixel_buffer[i].red   = byte_received[i*3+2];
					pixel_buffer[i].green = byte_received[i*3+3];
					pixel_buffer[i].blue  = byte_received[i*3+4];
//					pixel_buffer[i].red   = byte_received[i*3+2];
//					pixel_buffer[i].green = byte_received[i*3+3];
//					pixel_buffer[i].blue  = byte_received[i*3+4];
				}


				/*
				 * Read the status register 1st such that the next write to the control
				 * register won't destroy the state of the interrupt enable bit
				 */
				Register = XUartLite_ReadReg(XPAR_RS232_UART_1_BASEADDR,
							XUL_STATUS_REG_OFFSET);

				/*
				 * Write to the control register to reset both FIFOs, these bits are
				 * self-clearing such that there's no need to clear them
				 */
//				XUartLite_WriteReg(XPAR_RS232_UART_1_BASEADDR, XUL_CONTROL_REG_OFFSET,
//							Register | XUL_CR_FIFO_RX_RESET);

				break;

			// RECEIVE Batch #2 (Batch #1 is next)
			case 2:
				for (i = 0; i < 63; i++)  // 80 to 142 (63 pixels)
				{
					pixel_buffer[i+80].red   = byte_received[i*3+2];
					pixel_buffer[i+80].green = byte_received[i*3+3];
					pixel_buffer[i+80].blue  = byte_received[i*3+4];
//					pixel_buffer[i].red   = byte_received[i*3+2];
//					pixel_buffer[i].green = byte_received[i*3+3];
//					pixel_buffer[i].blue  = byte_received[i*3+4];
				}

				/*
				 * Read the status register 1st such that the next write to the control
				 * register won't destroy the state of the interrupt enable bit
				 */
				Register = XUartLite_ReadReg(XPAR_RS232_UART_1_BASEADDR,
							XUL_STATUS_REG_OFFSET);

				/*
				 * Write to the control register to reset both FIFOs, these bits are
				 * self-clearing such that there's no need to clear them
				 */
//				XUartLite_WriteReg(XPAR_RS232_UART_1_BASEADDR, XUL_CONTROL_REG_OFFSET,
//							Register | XUL_CR_FIFO_RX_RESET);


				// update fpga's buffer
				//for (i = PIXELS-1; i >= 0; i--)
				for (i = 0; i < PIXELS-1; i++)
				{
					*(my_driver->pixel_addr) = PIXELS-1 - i;
					for (j = 0; j<2; j++);
					*(my_driver->pixel_data) = ((pixel_buffer[i].green & 0xF0) << 12)
											 + ((pixel_buffer[i].red & 0xF0)  << 4)
											 + ((pixel_buffer[i].blue & 0xF0) >> 4);
//					*(my_driver->pixel_data) = ((pixel_buffer[i].green & 0xF0) << 16)
//											 + ((pixel_buffer[i].red & 0xF0)  << 8)
//											 + ((pixel_buffer[i].blue & 0xF0));
//					*(my_driver->pixel_data) = (pixel_buffer[i].green << 16)
//											 + (pixel_buffer[i].red   << 8)
//											 + (pixel_buffer[i].blue);
					for (j = 0; j<2; j++);
				}
				while (*(my_driver->busy) == 1);
				*(my_driver->print_leds) = 1;
				for (j = 0; j<2; j++);
				*(my_driver->print_leds) = 0;

				for (j = 0; j < 10; j++);

				reset_pixel_buffer();

		}
	}

	Xil_DCacheDisable();
	Xil_ICacheDisable();

	return 0;
}


int crc_ccitt(int start, int end, int crc)
{
	int index;
	for (index = start; index <= end; index++)
			crc = ((crc << 8) & 0xff00 ) ^ table[((crc>>8)&0xff)^(byte_received[index])];
	return crc & 0xffff;
}


void receive_bytes_of_data(void)
{
	u32 crc_value = 0;

	byte_received[0] = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);
	crc_value = crc_ccitt(0,0 ,crc_value );

	if (byte_received[0] == 0) // reset
	{
		byte_received[1] = 0;
		counter = 0;
	}
	else
	{

		int i = 0;
		for (i = 1 ; i < byte_received[0] ; i++)
		{
			byte_received[i] = XUartLite_RecvByte(XPAR_RS232_UART_1_BASEADDR);

			if (i <= byte_received[0] - 3) crc_value = crc_ccitt(i,i ,crc_value );

			//if (byte_received[i] == 0) counter++;
			//else counter = 0;

			if (counter == 13)
			{
				byte_received[1] = 0;
				i = byte_received[0] + 1;
			}
		}

		if (counter == 13)
		{
			byte_received[1] = 0;
			counter = 0;
		}
		else
		{
			crc_c.crc_u8[0] = byte_received[byte_received[0] - 1];
			crc_c.crc_u8[1] = byte_received[byte_received[0] - 2];

			if (crc_c.crc_u16 == crc_value) XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR, 1);
			else
			{
				XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR, 0);
				XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,(crc_value & 0xff00) >> 8);
				XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,crc_value & 0x00ff);

				XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,(crc_c.crc_u16 & 0xff00) >> 8);
				XUartLite_SendByte(XPAR_RS232_UART_1_BASEADDR,crc_c.crc_u16 & 0x00ff);
			}
		}

	}
}

//////////////////////////////////////////   Time controller ////////////////////////////////////
XStatus Initialize_TIMER(void){
	XStatus Status;
	Status = XTmrCtr_Initialize(TmrCtrInstancePtr, XPAR_AXI_TIMER_0_DEVICE_ID);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	/*
	 * Perform a self-test to ensure that the hardware was built
	 * correctly, use the 1st timer in the device (0)
	 */
	Status = XTmrCtr_SelfTest(TmrCtrInstancePtr, TmrCtrNumber);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	XTmrCtr_Start(TmrCtrInstancePtr,TmrCtrNumber);
	return XST_SUCCESS;
}


int restart_start_time(void){


	XTmrCtr_Reset(TmrCtrInstancePtr, TmrCtrNumber);

	/*
	 * Get a snapshot of the timer counter value before it's started
	 * to compare against later
	 */
	return XTmrCtr_GetValue(TmrCtrInstancePtr, TmrCtrNumber);

}

void sleep_in_s(u32 time){
	int i;
	for(i=0;i<time;i++){
		sleep_in_ms(1000);
	}
}

void sleep_in_ms(u32 time){
	u32 Value;
	u32 ms = 100000 / 2;

	Value = restart_start_time();
	while(Value < time  * ms){
		Value = XTmrCtr_GetValue(TmrCtrInstancePtr, TmrCtrNumber) - Value;
	}
}


void sleep_in_us(u32 time){
	u32 Value;
	u32 ms = 100 / 2;

	Value = restart_start_time();
	while(Value < time  * ms){
		Value = XTmrCtr_GetValue(TmrCtrInstancePtr, TmrCtrNumber) - Value;
	}
}



//////////////////////////////////////////////////////////////////////////////////////////////////////
