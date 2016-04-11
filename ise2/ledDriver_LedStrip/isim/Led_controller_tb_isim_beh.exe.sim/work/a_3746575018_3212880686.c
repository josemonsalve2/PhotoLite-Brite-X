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
extern char *IEEE_P_1242562249;
extern char *IEEE_P_3620187407;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
unsigned char ieee_p_1242562249_sub_1781507893_1035706684(char *, char *, char *, int );
char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
char *ieee_p_3620187407_sub_674691591_3965413181(char *, char *, char *, char *, unsigned char );


static void work_a_3746575018_3212880686_p_0(char *t0)
{
    char t15[16];
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
    char *t11;
    int t12;
    char *t13;
    char *t14;
    unsigned int t16;
    unsigned int t17;
    char *t18;
    char *t19;
    int t20;
    int t21;
    int t22;
    char *t23;
    char *t24;
    char *t25;
    char *t26;
    char *t27;
    char *t28;
    unsigned int t29;
    static char *nl0[] = {&&LAB13, &&LAB15, &&LAB14};

LAB0:    xsi_set_current_line(70, ng0);
    t1 = (t0 + 660U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:    t1 = (t0 + 844U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB8;

LAB9:    t1 = (t0 + 1120U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB10;

LAB11:
LAB3:    t1 = (t0 + 2680);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(71, ng0);
    t3 = (t0 + 1328U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 != (unsigned char)0);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(72, ng0);
    t3 = (t0 + 2732);
    t7 = (t3 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(75, ng0);
    t3 = xsi_get_transient_memory(4U);
    memset(t3, 0, 4U);
    t4 = t3;
    memset(t4, (unsigned char)2, 4U);
    t7 = (t0 + 2768);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    memcpy(t11, t3, 4U);
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(76, ng0);
    t1 = xsi_get_transient_memory(6U);
    memset(t1, 0, 6U);
    t3 = t1;
    memset(t3, (unsigned char)2, 6U);
    t4 = (t0 + 2804);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 6U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(77, ng0);
    t1 = xsi_get_transient_memory(16U);
    memset(t1, 0, 16U);
    t3 = t1;
    memset(t3, (unsigned char)2, 16U);
    t4 = (t0 + 2840);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 16U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(78, ng0);
    t1 = (t0 + 2732);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);
    goto LAB3;

LAB10:    xsi_set_current_line(81, ng0);
    t3 = (t0 + 1328U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t3 = (char *)((nl0) + t5);
    goto **((char **)t3);

LAB12:    goto LAB3;

LAB13:    xsi_set_current_line(83, ng0);
    t7 = (t0 + 2876);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    *((unsigned char *)t11) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t7);
    xsi_set_current_line(84, ng0);
    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t1 = (t0 + 5100U);
    t4 = (t0 + 1820U);
    t7 = *((char **)t4);
    t12 = *((int *)t7);
    t2 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t3, t1, t12);
    if (t2 != 0)
        goto LAB17;

LAB19:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t1 = (t0 + 5100U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t15, t3, t1, 1);
    t7 = (t15 + 12U);
    t16 = *((unsigned int *)t7);
    t17 = (1U * t16);
    t2 = (16U != t17);
    if (t2 == 1)
        goto LAB20;

LAB21:    t8 = (t0 + 2840);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 32U);
    t13 = *((char **)t11);
    memcpy(t13, t4, 16U);
    xsi_driver_first_trans_fast(t8);

LAB18:    goto LAB12;

LAB14:    xsi_set_current_line(93, ng0);
    t1 = (t0 + 1420U);
    t3 = *((char **)t1);
    t1 = (t0 + 5116U);
    t4 = (t0 + 5235);
    t8 = (t15 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 0;
    t9 = (t8 + 4U);
    *((int *)t9) = 5;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t12 = (5 - 0);
    t16 = (t12 * 1);
    t16 = (t16 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t16;
    t2 = ieee_std_logic_unsigned_equal_stdv_stdv(IEEE_P_3620187407, t3, t1, t4, t15);
    if (t2 != 0)
        goto LAB22;

LAB24:
LAB23:    xsi_set_current_line(100, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t1 = (t0 + 5247);
    t12 = xsi_mem_cmp(t1, t3, 4U);
    if (t12 == 1)
        goto LAB26;

LAB31:    t7 = (t0 + 5251);
    t20 = xsi_mem_cmp(t7, t3, 4U);
    if (t20 == 1)
        goto LAB27;

LAB32:    t9 = (t0 + 5255);
    t21 = xsi_mem_cmp(t9, t3, 4U);
    if (t21 == 1)
        goto LAB28;

LAB33:    t11 = (t0 + 5259);
    t22 = xsi_mem_cmp(t11, t3, 4U);
    if (t22 == 1)
        goto LAB29;

LAB34:
LAB30:    xsi_set_current_line(124, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t1 = (t0 + 5132U);
    t4 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t15, t3, t1, (unsigned char)3);
    t7 = (t15 + 12U);
    t16 = *((unsigned int *)t7);
    t17 = (1U * t16);
    t2 = (4U != t17);
    if (t2 == 1)
        goto LAB47;

LAB48:    t8 = (t0 + 2768);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 32U);
    t13 = *((char **)t11);
    memcpy(t13, t4, 4U);
    xsi_driver_first_trans_fast(t8);

LAB25:    goto LAB12;

LAB15:    xsi_set_current_line(128, ng0);
    t1 = (t0 + 5267);
    t4 = (t0 + 2768);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(129, ng0);
    t1 = (t0 + 5271);
    t4 = (t0 + 2804);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 6U);
    xsi_driver_first_trans_fast(t4);
    goto LAB12;

LAB16:    xsi_set_current_line(132, ng0);
    t1 = (t0 + 2732);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB12;

LAB17:    xsi_set_current_line(85, ng0);
    t4 = xsi_get_transient_memory(16U);
    memset(t4, 0, 16U);
    t8 = t4;
    memset(t8, (unsigned char)2, 16U);
    t9 = (t0 + 2840);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    t13 = (t11 + 32U);
    t14 = *((char **)t13);
    memcpy(t14, t4, 16U);
    xsi_driver_first_trans_fast(t9);
    xsi_set_current_line(86, ng0);
    t1 = (t0 + 2732);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB18;

LAB20:    xsi_size_not_matching(16U, t17, 0);
    goto LAB21;

LAB22:    xsi_set_current_line(94, ng0);
    t9 = (t0 + 5241);
    t11 = (t0 + 2804);
    t13 = (t11 + 32U);
    t14 = *((char **)t13);
    t18 = (t14 + 32U);
    t19 = *((char **)t18);
    memcpy(t19, t9, 6U);
    xsi_driver_first_trans_fast(t11);
    xsi_set_current_line(95, ng0);
    t1 = (t0 + 2732);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(96, ng0);
    t1 = (t0 + 2876);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB23;

LAB26:    xsi_set_current_line(102, ng0);
    t14 = (t0 + 1512U);
    t18 = *((char **)t14);
    t14 = (t0 + 5132U);
    t19 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t15, t18, t14, (unsigned char)3);
    t23 = (t15 + 12U);
    t16 = *((unsigned int *)t23);
    t17 = (1U * t16);
    t2 = (4U != t17);
    if (t2 == 1)
        goto LAB36;

LAB37:    t24 = (t0 + 2768);
    t25 = (t24 + 32U);
    t26 = *((char **)t25);
    t27 = (t26 + 32U);
    t28 = *((char **)t27);
    memcpy(t28, t19, 4U);
    xsi_driver_first_trans_fast(t24);
    xsi_set_current_line(103, ng0);
    t1 = (t0 + 2876);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB25;

LAB27:    xsi_set_current_line(107, ng0);
    t1 = (t0 + 2876);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(108, ng0);
    t1 = (t0 + 5263);
    t4 = (t0 + 2768);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 4U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(109, ng0);
    t1 = (t0 + 1420U);
    t3 = *((char **)t1);
    t1 = (t0 + 5116U);
    t4 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t15, t3, t1, (unsigned char)3);
    t7 = (t15 + 12U);
    t16 = *((unsigned int *)t7);
    t17 = (1U * t16);
    t2 = (6U != t17);
    if (t2 == 1)
        goto LAB38;

LAB39:    t8 = (t0 + 2804);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 32U);
    t13 = *((char **)t11);
    memcpy(t13, t4, 6U);
    xsi_driver_first_trans_fast(t8);
    goto LAB25;

LAB28:    xsi_set_current_line(113, ng0);
    t1 = (t0 + 592U);
    t3 = *((char **)t1);
    t1 = (t0 + 1420U);
    t4 = *((char **)t1);
    t1 = (t0 + 5116U);
    t12 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t4, t1);
    t20 = (t12 - 23);
    t16 = (t20 * -1);
    xsi_vhdl_check_range_of_index(23, 0, -1, t12);
    t17 = (1U * t16);
    t29 = (0 + t17);
    t7 = (t3 + t29);
    t2 = *((unsigned char *)t7);
    t5 = (t2 == (unsigned char)2);
    if (t5 != 0)
        goto LAB40;

LAB42:
LAB41:    xsi_set_current_line(116, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t1 = (t0 + 5132U);
    t4 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t15, t3, t1, (unsigned char)3);
    t7 = (t15 + 12U);
    t16 = *((unsigned int *)t7);
    t17 = (1U * t16);
    t2 = (4U != t17);
    if (t2 == 1)
        goto LAB43;

LAB44:    t8 = (t0 + 2768);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 32U);
    t13 = *((char **)t11);
    memcpy(t13, t4, 4U);
    xsi_driver_first_trans_fast(t8);
    goto LAB25;

LAB29:    xsi_set_current_line(120, ng0);
    t1 = (t0 + 2876);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(121, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t1 = (t0 + 5132U);
    t4 = ieee_p_3620187407_sub_674691591_3965413181(IEEE_P_3620187407, t15, t3, t1, (unsigned char)3);
    t7 = (t15 + 12U);
    t16 = *((unsigned int *)t7);
    t17 = (1U * t16);
    t2 = (4U != t17);
    if (t2 == 1)
        goto LAB45;

LAB46:    t8 = (t0 + 2768);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 32U);
    t13 = *((char **)t11);
    memcpy(t13, t4, 4U);
    xsi_driver_first_trans_fast(t8);
    goto LAB25;

LAB35:;
LAB36:    xsi_size_not_matching(4U, t17, 0);
    goto LAB37;

LAB38:    xsi_size_not_matching(6U, t17, 0);
    goto LAB39;

LAB40:    xsi_set_current_line(114, ng0);
    t8 = (t0 + 2876);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 32U);
    t13 = *((char **)t11);
    *((unsigned char *)t13) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t8);
    goto LAB41;

LAB43:    xsi_size_not_matching(4U, t17, 0);
    goto LAB44;

LAB45:    xsi_size_not_matching(4U, t17, 0);
    goto LAB46;

LAB47:    xsi_size_not_matching(4U, t17, 0);
    goto LAB48;

}

static void work_a_3746575018_3212880686_p_1(char *t0)
{
    char t15[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    int t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    char *t12;
    char *t13;
    char *t14;
    unsigned int t16;
    unsigned int t17;

LAB0:    xsi_set_current_line(140, ng0);
    t1 = (t0 + 752U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 2688);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(141, ng0);
    t3 = (t0 + 1052U);
    t4 = *((char **)t3);
    t3 = (t0 + 5084U);
    t5 = (t0 + 1752U);
    t6 = *((char **)t5);
    t7 = *((int *)t6);
    t8 = ieee_p_1242562249_sub_1781507893_1035706684(IEEE_P_1242562249, t4, t3, t7);
    if (t8 != 0)
        goto LAB5;

LAB7:    xsi_set_current_line(145, ng0);
    t1 = (t0 + 1052U);
    t3 = *((char **)t1);
    t1 = (t0 + 5084U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t15, t3, t1, 1);
    t5 = (t15 + 12U);
    t16 = *((unsigned int *)t5);
    t17 = (1U * t16);
    t2 = (8U != t17);
    if (t2 == 1)
        goto LAB8;

LAB9:    t6 = (t0 + 2912);
    t9 = (t6 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 32U);
    t12 = *((char **)t11);
    memcpy(t12, t4, 8U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(146, ng0);
    t1 = (t0 + 2948);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);

LAB6:    goto LAB3;

LAB5:    xsi_set_current_line(142, ng0);
    t5 = xsi_get_transient_memory(8U);
    memset(t5, 0, 8U);
    t9 = t5;
    memset(t9, (unsigned char)2, 8U);
    t10 = (t0 + 2912);
    t11 = (t10 + 32U);
    t12 = *((char **)t11);
    t13 = (t12 + 32U);
    t14 = *((char **)t13);
    memcpy(t14, t5, 8U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(143, ng0);
    t1 = (t0 + 2948);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB6;

LAB8:    xsi_size_not_matching(8U, t17, 0);
    goto LAB9;

}


extern void work_a_3746575018_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3746575018_3212880686_p_0,(void *)work_a_3746575018_3212880686_p_1};
	xsi_register_didat("work_a_3746575018_3212880686", "isim/Led_controller_tb_isim_beh.exe.sim/work/a_3746575018_3212880686.didat");
	xsi_register_executes(pe);
}
