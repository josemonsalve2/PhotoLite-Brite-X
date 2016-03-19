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


static void work_a_2373014322_3212880686_p_0(char *t0)
{
    char t12[16];
    unsigned char t1;
    char *t2;
    char *t3;
    unsigned char t4;
    unsigned char t5;
    unsigned char t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;
    char *t11;
    int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    unsigned int t20;
    int t21;
    int t22;
    unsigned int t23;
    char *t24;
    char *t25;

LAB0:    xsi_set_current_line(51, ng0);
    t2 = (t0 + 1420U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)3);
    if (t5 == 1)
        goto LAB5;

LAB6:    t1 = (unsigned char)0;

LAB7:    if (t1 != 0)
        goto LAB2;

LAB4:    t2 = (t0 + 1420U);
    t3 = *((char **)t2);
    t4 = *((unsigned char *)t3);
    t5 = (t4 == (unsigned char)2);
    if (t5 == 1)
        goto LAB31;

LAB32:    t1 = (unsigned char)0;

LAB33:    if (t1 != 0)
        goto LAB29;

LAB30:
LAB3:    t2 = (t0 + 2520);
    *((int *)t2) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(52, ng0);
    t7 = (t0 + 2580);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)3;
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(53, ng0);
    t2 = (t0 + 1052U);
    t3 = *((char **)t2);
    t2 = (t0 + 4524U);
    t7 = (t0 + 4605);
    t9 = (t12 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 5;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t13 = (5 - 0);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t14;
    t1 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t2, t7, t12);
    if (t1 != 0)
        goto LAB8;

LAB10:
LAB9:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t2 = (t0 + 4540U);
    t7 = (t0 + 4617);
    t9 = (t12 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 3;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t13 = (3 - 0);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t14;
    t1 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t2, t7, t12);
    if (t1 != 0)
        goto LAB11;

LAB13:    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t2 = (t0 + 4540U);
    t7 = (t0 + 4625);
    t9 = (t12 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 3;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t13 = (3 - 0);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t14;
    t4 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t2, t7, t12);
    if (t4 == 1)
        goto LAB18;

LAB19:    t1 = (unsigned char)0;

LAB20:    if (t1 != 0)
        goto LAB16;

LAB17:    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t2 = (t0 + 4540U);
    t7 = (t0 + 4629);
    t9 = (t12 + 0U);
    t10 = (t9 + 0U);
    *((int *)t10) = 0;
    t10 = (t9 + 4U);
    *((int *)t10) = 3;
    t10 = (t9 + 8U);
    *((int *)t10) = 1;
    t13 = (3 - 0);
    t14 = (t13 * 1);
    t14 = (t14 + 1);
    t10 = (t9 + 12U);
    *((unsigned int *)t10) = t14;
    t1 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t2, t7, t12);
    if (t1 != 0)
        goto LAB23;

LAB24:    xsi_set_current_line(68, ng0);
    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t2 = (t0 + 4540U);
    t7 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t12, t3, t2, (unsigned char)3);
    t8 = (t12 + 12U);
    t14 = *((unsigned int *)t8);
    t20 = (1U * t14);
    t1 = (4U != t20);
    if (t1 == 1)
        goto LAB27;

LAB28:    t9 = (t0 + 2688);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t15 = (t11 + 32U);
    t16 = *((char **)t15);
    memcpy(t16, t7, 4U);
    xsi_driver_first_trans_fast(t9);

LAB12:    goto LAB3;

LAB5:    t2 = (t0 + 752U);
    t6 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t2, 0U, 0U);
    t1 = t6;
    goto LAB7;

LAB8:    xsi_set_current_line(54, ng0);
    t10 = (t0 + 4611);
    t15 = (t0 + 2616);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    t18 = (t17 + 32U);
    t19 = *((char **)t18);
    memcpy(t19, t10, 6U);
    xsi_driver_first_trans_fast(t15);
    xsi_set_current_line(55, ng0);
    t2 = (t0 + 2580);
    t3 = (t2 + 32U);
    t7 = *((char **)t3);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    *((unsigned char *)t9) = (unsigned char)2;
    xsi_driver_first_trans_fast(t2);
    goto LAB9;

LAB11:    xsi_set_current_line(58, ng0);
    t10 = (t0 + 2652);
    t11 = (t10 + 32U);
    t15 = *((char **)t11);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t10);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 4621);
    t7 = (t0 + 2688);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    memcpy(t11, t2, 4U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(60, ng0);
    t2 = (t0 + 1052U);
    t3 = *((char **)t2);
    t2 = (t0 + 4524U);
    t7 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t12, t3, t2, (unsigned char)3);
    t8 = (t12 + 12U);
    t14 = *((unsigned int *)t8);
    t20 = (1U * t14);
    t1 = (6U != t20);
    if (t1 == 1)
        goto LAB14;

LAB15:    t9 = (t0 + 2616);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t15 = (t11 + 32U);
    t16 = *((char **)t15);
    memcpy(t16, t7, 6U);
    xsi_driver_first_trans_fast(t9);
    goto LAB12;

LAB14:    xsi_size_not_matching(6U, t20, 0);
    goto LAB15;

LAB16:    xsi_set_current_line(62, ng0);
    t17 = (t0 + 2652);
    t18 = (t17 + 32U);
    t19 = *((char **)t18);
    t24 = (t19 + 32U);
    t25 = *((char **)t24);
    *((unsigned char *)t25) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t17);
    xsi_set_current_line(63, ng0);
    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t2 = (t0 + 4540U);
    t7 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t12, t3, t2, (unsigned char)3);
    t8 = (t12 + 12U);
    t14 = *((unsigned int *)t8);
    t20 = (1U * t14);
    t1 = (4U != t20);
    if (t1 == 1)
        goto LAB21;

LAB22:    t9 = (t0 + 2688);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t15 = (t11 + 32U);
    t16 = *((char **)t15);
    memcpy(t16, t7, 4U);
    xsi_driver_first_trans_fast(t9);
    goto LAB12;

LAB18:    t10 = (t0 + 592U);
    t11 = *((char **)t10);
    t10 = (t0 + 1052U);
    t15 = *((char **)t10);
    t10 = (t0 + 4524U);
    t21 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t15, t10);
    t22 = (t21 - 23);
    t14 = (t22 * -1);
    xsi_vhdl_check_range_of_index(23, 0, -1, t21);
    t20 = (1U * t14);
    t23 = (0 + t20);
    t16 = (t11 + t23);
    t5 = *((unsigned char *)t16);
    t6 = (t5 == (unsigned char)2);
    t1 = t6;
    goto LAB20;

LAB21:    xsi_size_not_matching(4U, t20, 0);
    goto LAB22;

LAB23:    xsi_set_current_line(65, ng0);
    t10 = (t0 + 2652);
    t11 = (t10 + 32U);
    t15 = *((char **)t11);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t10);
    xsi_set_current_line(66, ng0);
    t2 = (t0 + 1144U);
    t3 = *((char **)t2);
    t2 = (t0 + 4540U);
    t7 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t12, t3, t2, (unsigned char)3);
    t8 = (t12 + 12U);
    t14 = *((unsigned int *)t8);
    t20 = (1U * t14);
    t1 = (4U != t20);
    if (t1 == 1)
        goto LAB25;

LAB26:    t9 = (t0 + 2688);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t15 = (t11 + 32U);
    t16 = *((char **)t15);
    memcpy(t16, t7, 4U);
    xsi_driver_first_trans_fast(t9);
    goto LAB12;

LAB25:    xsi_size_not_matching(4U, t20, 0);
    goto LAB26;

LAB27:    xsi_size_not_matching(4U, t20, 0);
    goto LAB28;

LAB29:    xsi_set_current_line(71, ng0);
    t7 = (t0 + 4633);
    t9 = (t0 + 2688);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t15 = (t11 + 32U);
    t16 = *((char **)t15);
    memcpy(t16, t7, 4U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(72, ng0);
    t2 = (t0 + 4637);
    t7 = (t0 + 2616);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    memcpy(t11, t2, 6U);
    xsi_driver_first_trans_fast(t7);
    goto LAB3;

LAB31:    t2 = (t0 + 752U);
    t6 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t2, 0U, 0U);
    t1 = t6;
    goto LAB33;

}

static void work_a_2373014322_3212880686_p_1(char *t0)
{
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    int64 t8;

LAB0:    xsi_set_current_line(79, ng0);
    t1 = (t0 + 660U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2528);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(81, ng0);
    t3 = (t0 + 2724);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t3);
    xsi_set_current_line(82, ng0);
    t8 = (20 * 1000LL);
    t1 = (t0 + 2724);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_delta(t1, 0U, 1, t8);
    t7 = (t0 + 2724);
    xsi_driver_intertial_reject(t7, t8, t8);
    goto LAB3;

}

static void work_a_2373014322_3212880686_p_2(char *t0)
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

LAB0:    xsi_set_current_line(87, ng0);

LAB3:    t1 = (t0 + 1328U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 1236U);
    t4 = *((char **)t1);
    t5 = *((unsigned char *)t4);
    t6 = ieee_p_2592010699_sub_2545490612_503743352(IEEE_P_2592010699, t3, t5);
    t1 = (t0 + 2760);
    t7 = (t1 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = t6;
    xsi_driver_first_trans_fast(t1);

LAB2:    t11 = (t0 + 2536);
    *((int *)t11) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}


extern void work_a_2373014322_3212880686_init()
{
	static char *pe[] = {(void *)work_a_2373014322_3212880686_p_0,(void *)work_a_2373014322_3212880686_p_1,(void *)work_a_2373014322_3212880686_p_2};
	xsi_register_didat("work_a_2373014322_3212880686", "isim/Led_controller_tb_isim_beh.exe.sim/work/a_2373014322_3212880686.didat");
	xsi_register_executes(pe);
}
