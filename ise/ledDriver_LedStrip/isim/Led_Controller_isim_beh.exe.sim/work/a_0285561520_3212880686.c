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
static const char *ng0 = "/home/bee/ledDriver_LedStrip/Led_Controller.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_3620187407;
extern char *IEEE_P_1242562249;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_2592010699_sub_2545490612_503743352(char *, unsigned char , unsigned char );
char *ieee_p_3620187407_sub_674691591_3965413181(char *, char *, char *, char *, unsigned char );


static void work_a_0285561520_3212880686_p_0(char *t0)
{
    char t11[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    unsigned int t17;
    char *t18;
    char *t19;
    int t20;
    int t21;
    unsigned int t22;
    unsigned char t23;
    char *t24;
    char *t25;

LAB0:    xsi_set_current_line(52, ng0);
    t1 = (t0 + 752U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2748);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(53, ng0);
    t3 = (t0 + 1512U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(72, ng0);
    t1 = xsi_get_transient_memory(4U);
    memset(t1, 0, 4U);
    t3 = t1;
    memset(t3, (unsigned char)2, 4U);
    t4 = (t0 + 2888);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(73, ng0);
    t1 = xsi_get_transient_memory(6U);
    memset(t1, 0, 6U);
    t3 = t1;
    memset(t3, (unsigned char)2, 6U);
    t4 = (t0 + 2924);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 6U);
    xsi_driver_first_trans_fast(t4);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(54, ng0);
    t3 = (t0 + 2816);
    t7 = (t3 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)3;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(55, ng0);
    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t1 = (t0 + 4948U);
    t4 = (t0 + 5012);
    t8 = (t11 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 0;
    t9 = (t8 + 4U);
    *((int *)t9) = 3;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t12 = (3 - 0);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t13;
    t2 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t1, t4, t11);
    if (t2 != 0)
        goto LAB8;

LAB10:
LAB9:    xsi_set_current_line(60, ng0);
    t1 = (t0 + 1144U);
    t3 = *((char **)t1);
    t1 = (t0 + 4932U);
    t4 = (t0 + 5016);
    t8 = (t11 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 0;
    t9 = (t8 + 4U);
    *((int *)t9) = 5;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t12 = (5 - 0);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t13;
    t2 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t1, t4, t11);
    if (t2 != 0)
        goto LAB13;

LAB15:
LAB14:    xsi_set_current_line(64, ng0);
    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t1 = (t0 + 4948U);
    t4 = (t0 + 5022);
    t8 = (t11 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 0;
    t9 = (t8 + 4U);
    *((int *)t9) = 3;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t12 = (3 - 0);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t13;
    t5 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t1, t4, t11);
    if (t5 == 1)
        goto LAB19;

LAB20:    t2 = (unsigned char)0;

LAB21:    if (t2 != 0)
        goto LAB16;

LAB18:
LAB17:    xsi_set_current_line(67, ng0);
    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t1 = (t0 + 4948U);
    t4 = (t0 + 5026);
    t8 = (t11 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 0;
    t9 = (t8 + 4U);
    *((int *)t9) = 3;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t12 = (3 - 0);
    t13 = (t12 * 1);
    t13 = (t13 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t13;
    t2 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t1, t4, t11);
    if (t2 != 0)
        goto LAB22;

LAB24:
LAB23:    xsi_set_current_line(70, ng0);
    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t1 = (t0 + 4948U);
    t4 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t11, t3, t1, (unsigned char)3);
    t7 = (t11 + 12U);
    t13 = *((unsigned int *)t7);
    t17 = (1U * t13);
    t2 = (4U != t17);
    if (t2 == 1)
        goto LAB25;

LAB26:    t8 = (t0 + 2888);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t14 = (t10 + 32U);
    t15 = *((char **)t14);
    memcpy(t15, t4, 4U);
    xsi_driver_first_trans_fast(t8);
    goto LAB6;

LAB8:    xsi_set_current_line(56, ng0);
    t9 = (t0 + 2852);
    t10 = (t9 + 32U);
    t14 = *((char **)t10);
    t15 = (t14 + 32U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t9);
    xsi_set_current_line(57, ng0);
    t1 = xsi_get_transient_memory(4U);
    memset(t1, 0, 4U);
    t3 = t1;
    memset(t3, (unsigned char)2, 4U);
    t4 = (t0 + 2888);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(58, ng0);
    t1 = (t0 + 1144U);
    t3 = *((char **)t1);
    t1 = (t0 + 4932U);
    t4 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t11, t3, t1, (unsigned char)3);
    t7 = (t11 + 12U);
    t13 = *((unsigned int *)t7);
    t17 = (1U * t13);
    t2 = (6U != t17);
    if (t2 == 1)
        goto LAB11;

LAB12:    t8 = (t0 + 2924);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t14 = (t10 + 32U);
    t15 = *((char **)t14);
    memcpy(t15, t4, 6U);
    xsi_driver_first_trans_fast(t8);
    goto LAB9;

LAB11:    xsi_size_not_matching(6U, t17, 0);
    goto LAB12;

LAB13:    xsi_set_current_line(61, ng0);
    t9 = xsi_get_transient_memory(6U);
    memset(t9, 0, 6U);
    t10 = t9;
    memset(t10, (unsigned char)2, 6U);
    t14 = (t0 + 2924);
    t15 = (t14 + 32U);
    t16 = *((char **)t15);
    t18 = (t16 + 32U);
    t19 = *((char **)t18);
    memcpy(t19, t9, 6U);
    xsi_driver_first_trans_fast(t14);
    xsi_set_current_line(62, ng0);
    t1 = (t0 + 2816);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB14;

LAB16:    xsi_set_current_line(65, ng0);
    t16 = (t0 + 2852);
    t18 = (t16 + 32U);
    t19 = *((char **)t18);
    t24 = (t19 + 32U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t16);
    goto LAB17;

LAB19:    t9 = (t0 + 592U);
    t10 = *((char **)t9);
    t9 = (t0 + 1144U);
    t14 = *((char **)t9);
    t9 = (t0 + 4932U);
    t20 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t14, t9);
    t21 = (t20 - 23);
    t13 = (t21 * -1);
    xsi_vhdl_check_range_of_index(23, 0, -1, t20);
    t17 = (1U * t13);
    t22 = (0 + t17);
    t15 = (t10 + t22);
    t6 = *((unsigned char *)t15);
    t23 = (t6 == (unsigned char)2);
    t2 = t23;
    goto LAB21;

LAB22:    xsi_set_current_line(68, ng0);
    t9 = (t0 + 2852);
    t10 = (t9 + 32U);
    t14 = *((char **)t10);
    t15 = (t14 + 32U);
    t16 = *((char **)t15);
    *((unsigned char *)t16) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t9);
    goto LAB23;

LAB25:    xsi_size_not_matching(4U, t17, 0);
    goto LAB26;

}

static void work_a_0285561520_3212880686_p_1(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int64 t8;

LAB0:    xsi_set_current_line(81, ng0);
    t1 = (t0 + 660U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2756);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(82, ng0);
    t3 = (t0 + 2960);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(83, ng0);
    t8 = (10 * 1000LL);
    t1 = (t0 + 2960);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 0U, 1, t8);
    t7 = (t0 + 2960);
    xsi_driver_intertial_reject(t7, t8, t8);
    goto LAB3;

}

static void work_a_0285561520_3212880686_p_2(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;

LAB0:    xsi_set_current_line(88, ng0);

LAB3:    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 1328U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = ieee_p_2592010699_sub_2545490612_503743352(IEEE_P_2592010699, t3, t5);
    t1 = (t0 + 2996);
    t7 = (t1 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = t6;
    xsi_driver_first_trans_fast(t1);

LAB2:    t11 = (t0 + 2764);
    *((int *)t11) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_0285561520_3212880686_p_3(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(90, ng0);

LAB3:    t1 = (t0 + 1236U);
    t2 = *((char **)t1);
    t1 = (t0 + 3032);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 4U);
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t7 = (t0 + 2772);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_0285561520_3212880686_init()
{
	static char *pe[] = {(void *)work_a_0285561520_3212880686_p_0,(void *)work_a_0285561520_3212880686_p_1,(void *)work_a_0285561520_3212880686_p_2,(void *)work_a_0285561520_3212880686_p_3};
	xsi_register_didat("work_a_0285561520_3212880686", "isim/Led_Controller_isim_beh.exe.sim/work/a_0285561520_3212880686.didat");
	xsi_register_executes(pe);
}
