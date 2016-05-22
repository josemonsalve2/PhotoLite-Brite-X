/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xfbc00daa */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "/home/bee/FinalProject/github/PhotoLite-Brite-X/ise4/ledDriver_LedStrip/ledDriver_LedStrip_Top_tb.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;
extern char *IEEE_P_3620187407;

char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_2110375371_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_3620187407_sub_4042748798_3965413181(char *, char *, char *, char *, char *);
unsigned char ieee_p_3620187407_sub_4058165771_3965413181(char *, char *, char *, char *, char *);
char *ieee_p_3620187407_sub_436279890_3965413181(char *, char *, char *, char *, int );


static void work_a_3877743273_2372691052_p_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int64 t7;
    int64 t8;

LAB0:    t1 = (t0 + 2136U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(101, ng0);
    t2 = (t0 + 2640);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(102, ng0);
    t2 = (t0 + 1592U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 2036);
    xsi_process_wait(t2, t8);

LAB6:    *((char **)t1) = &&LAB7;

LAB1:    return;
LAB4:    xsi_set_current_line(103, ng0);
    t2 = (t0 + 2640);
    t3 = (t2 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t2);
    xsi_set_current_line(104, ng0);
    t2 = (t0 + 1592U);
    t3 = *((char **)t2);
    t7 = *((int64 *)t3);
    t8 = (t7 / 2);
    t2 = (t0 + 2036);
    xsi_process_wait(t2, t8);

LAB10:    *((char **)t1) = &&LAB11;
    goto LAB1;

LAB5:    goto LAB4;

LAB7:    goto LAB5;

LAB8:    goto LAB2;

LAB9:    goto LAB8;

LAB11:    goto LAB9;

}

static void work_a_3877743273_2372691052_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(108, ng0);

LAB3:    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t1 = (t0 + 2676);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 8U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 2588);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3877743273_2372691052_p_2(char *t0)
{
    char t8[16];
    char t18[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t9;
    unsigned int t10;
    char *t11;
    char *t12;
    char *t13;
    int t14;
    char *t15;
    char *t16;
    char *t17;
    unsigned char t19;
    char *t20;
    char *t21;
    unsigned char t22;

LAB0:    xsi_set_current_line(112, ng0);
    t1 = (t0 + 568U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2596);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(113, ng0);
    t3 = (t0 + 2712);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(114, ng0);
    t1 = (t0 + 1328U);
    t3 = *((char **)t1);
    t1 = (t0 + 5912U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t8, t3, t1, 1);
    t5 = (t8 + 12U);
    t9 = *((unsigned int *)t5);
    t10 = (1U * t9);
    t2 = (32U != t10);
    if (t2 == 1)
        goto LAB5;

LAB6:    t6 = (t0 + 2748);
    t7 = (t6 + 32U);
    t11 = *((char **)t7);
    t12 = (t11 + 32U);
    t13 = *((char **)t12);
    memcpy(t13, t4, 32U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(115, ng0);
    t1 = (t0 + 1328U);
    t3 = *((char **)t1);
    t1 = (t0 + 5912U);
    t4 = (t0 + 6040);
    t6 = (t8 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 31;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t14 = (31 - 0);
    t9 = (t14 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t2 = ieee_p_1242562249_sub_2110375371_1035706684(IEEE_P_1242562249, t3, t1, t4, t8);
    if (t2 != 0)
        goto LAB7;

LAB9:
LAB8:    xsi_set_current_line(133, ng0);
    t1 = (t0 + 1420U);
    t3 = *((char **)t1);
    t1 = (t0 + 5928U);
    t4 = (t0 + 6168);
    t6 = (t8 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 7;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t14 = (7 - 0);
    t9 = (t14 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t2 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t1, t4, t8);
    if (t2 != 0)
        goto LAB24;

LAB26:
LAB25:    goto LAB3;

LAB5:    xsi_size_not_matching(32U, t10, 0);
    goto LAB6;

LAB7:    xsi_set_current_line(116, ng0);
    t7 = xsi_get_transient_memory(32U);
    memset(t7, 0, 32U);
    t11 = t7;
    memset(t11, (unsigned char)2, 32U);
    t12 = (t0 + 2748);
    t13 = (t12 + 32U);
    t15 = *((char **)t13);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    memcpy(t17, t7, 32U);
    xsi_driver_first_trans_fast(t12);
    xsi_set_current_line(117, ng0);
    t1 = (t0 + 1420U);
    t3 = *((char **)t1);
    t1 = (t0 + 5928U);
    t4 = (t0 + 6072);
    t6 = (t8 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 7;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t14 = (7 - 0);
    t9 = (t14 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t2 = ieee_p_3620187407_sub_4058165771_3965413181(IEEE_P_3620187407, t3, t1, t4, t8);
    if (t2 != 0)
        goto LAB10;

LAB12:    t1 = (t0 + 1420U);
    t3 = *((char **)t1);
    t1 = (t0 + 5928U);
    t4 = (t0 + 6152);
    t6 = (t8 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 7;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t14 = (7 - 0);
    t9 = (t14 * 1);
    t9 = (t9 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t9;
    t2 = ieee_p_3620187407_sub_4042748798_3965413181(IEEE_P_3620187407, t3, t1, t4, t8);
    if (t2 != 0)
        goto LAB22;

LAB23:
LAB11:    goto LAB8;

LAB10:    xsi_set_current_line(118, ng0);
    t7 = (t0 + 1420U);
    t11 = *((char **)t7);
    t7 = (t0 + 5928U);
    t12 = ieee_p_3620187407_sub_436279890_3965413181(IEEE_P_3620187407, t18, t11, t7, 1);
    t13 = (t18 + 12U);
    t9 = *((unsigned int *)t13);
    t10 = (1U * t9);
    t19 = (8U != t10);
    if (t19 == 1)
        goto LAB13;

LAB14:    t15 = (t0 + 2784);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    t20 = (t17 + 32U);
    t21 = *((char **)t20);
    memcpy(t21, t12, 8U);
    xsi_driver_first_trans_fast(t15);
    xsi_set_current_line(119, ng0);
    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t19 = (t2 == (unsigned char)0);
    if (t19 != 0)
        goto LAB15;

LAB17:    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t19 = (t2 == (unsigned char)1);
    if (t19 != 0)
        goto LAB18;

LAB19:    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t19 = (t2 == (unsigned char)2);
    if (t19 != 0)
        goto LAB20;

LAB21:
LAB16:    goto LAB11;

LAB13:    xsi_size_not_matching(8U, t10, 0);
    goto LAB14;

LAB15:    xsi_set_current_line(120, ng0);
    t1 = (t0 + 6080);
    t5 = (t0 + 2820);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t11 = (t7 + 32U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 24U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(121, ng0);
    t1 = (t0 + 2856);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB16;

LAB18:    xsi_set_current_line(123, ng0);
    t1 = (t0 + 6104);
    t5 = (t0 + 2820);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t11 = (t7 + 32U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 24U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(124, ng0);
    t1 = (t0 + 2856);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB16;

LAB20:    xsi_set_current_line(126, ng0);
    t1 = (t0 + 6128);
    t5 = (t0 + 2820);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    t11 = (t7 + 32U);
    t12 = *((char **)t11);
    memcpy(t12, t1, 24U);
    xsi_driver_first_trans_fast(t5);
    xsi_set_current_line(127, ng0);
    t1 = (t0 + 2856);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB16;

LAB22:    xsi_set_current_line(130, ng0);
    t7 = (t0 + 6160);
    t12 = (t0 + 2784);
    t13 = (t12 + 32U);
    t15 = *((char **)t13);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    memcpy(t17, t7, 8U);
    xsi_driver_first_trans_fast(t12);
    goto LAB11;

LAB24:    xsi_set_current_line(134, ng0);
    t7 = (t0 + 960U);
    t11 = *((char **)t7);
    t19 = *((unsigned char *)t11);
    t22 = (t19 == (unsigned char)2);
    if (t22 != 0)
        goto LAB27;

LAB29:
LAB28:    goto LAB25;

LAB27:    xsi_set_current_line(135, ng0);
    t7 = (t0 + 2712);
    t12 = (t7 + 32U);
    t13 = *((char **)t12);
    t15 = (t13 + 32U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = (unsigned char)3;
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(136, ng0);
    t1 = (t0 + 6176);
    t4 = (t0 + 2784);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t11 = *((char **)t7);
    memcpy(t11, t1, 8U);
    xsi_driver_first_trans_fast(t4);
    goto LAB28;

}


extern void work_a_3877743273_2372691052_init()
{
	static char *pe[] = {(void *)work_a_3877743273_2372691052_p_0,(void *)work_a_3877743273_2372691052_p_1,(void *)work_a_3877743273_2372691052_p_2};
	xsi_register_didat("work_a_3877743273_2372691052", "isim/ledDriver_LedStrip_Top_tb_isim_beh.exe.sim/work/a_3877743273_2372691052.didat");
	xsi_register_executes(pe);
}
