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
static const char *ng0 = "/home/bee/FinalProject/github/PhotoLite-Brite-X/ise4/ledDriver_LedStrip/ledDriver_LedStrip.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;

char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );
char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_2110375371_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_1242562249_sub_2110411308_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );


static void work_a_1566496653_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(74, ng0);

LAB3:    t1 = (t0 + 1420U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3104);
    t4 = (t1 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 3044);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_1566496653_3212880686_p_1(char *t0)
{
    char t13[16];
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    int t14;
    unsigned char t15;
    char *t16;
    char *t17;
    char *t18;
    char *t19;
    char *t20;
    static char *nl0[] = {&&LAB6, &&LAB7, &&LAB8, &&LAB9};
    static char *nl1[] = {&&LAB14, &&LAB14, &&LAB12, &&LAB13, &&LAB14, &&LAB14, &&LAB14, &&LAB14, &&LAB14};

LAB0:    xsi_set_current_line(78, ng0);
    t1 = (t0 + 1604U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3140);
    t4 = (t1 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(79, ng0);
    t1 = (t0 + 568U);
    t3 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t3 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3052);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(81, ng0);
    t2 = (t0 + 3176);
    t4 = (t2 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t2);
    xsi_set_current_line(82, ng0);
    t1 = (t0 + 3212);
    t2 = (t1 + 32U);
    t4 = *((char **)t2);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(84, ng0);
    t1 = (t0 + 1512U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (char *)((nl0) + t3);
    goto **((char **)t1);

LAB5:    goto LAB3;

LAB6:    xsi_set_current_line(86, ng0);
    t4 = (t0 + 3212);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)2;
    xsi_driver_first_trans_fast(t4);
    goto LAB5;

LAB7:    xsi_set_current_line(88, ng0);
    t1 = (t0 + 3176);
    t2 = (t1 + 32U);
    t4 = *((char **)t2);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    goto LAB5;

LAB8:    xsi_set_current_line(90, ng0);
    goto LAB5;

LAB9:    xsi_set_current_line(92, ng0);
    t1 = (t0 + 1328U);
    t2 = *((char **)t1);
    t9 = (23 - 23);
    t10 = (t9 * -1);
    t11 = (1U * t10);
    t12 = (0 + t11);
    t1 = (t2 + t12);
    t3 = *((unsigned char *)t1);
    t4 = (char *)((nl1) + t3);
    goto **((char **)t4);

LAB10:    goto LAB5;

LAB11:    goto LAB5;

LAB12:    xsi_set_current_line(94, ng0);
    t5 = (t0 + 1144U);
    t6 = *((char **)t5);
    t5 = (t0 + 6848U);
    t7 = (t0 + 1844U);
    t8 = *((char **)t7);
    t14 = *((int *)t8);
    t7 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t13, t14, 32);
    t15 = ieee_p_1242562249_sub_2110411308_1035706684(IEEE_P_1242562249, t6, t5, t7, t13);
    if (t15 != 0)
        goto LAB15;

LAB17:
LAB16:    goto LAB11;

LAB13:    xsi_set_current_line(98, ng0);
    t1 = (t0 + 1144U);
    t2 = *((char **)t1);
    t1 = (t0 + 6848U);
    t4 = (t0 + 1912U);
    t5 = *((char **)t4);
    t9 = *((int *)t5);
    t4 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t13, t9, 32);
    t3 = ieee_p_1242562249_sub_2110411308_1035706684(IEEE_P_1242562249, t2, t1, t4, t13);
    if (t3 != 0)
        goto LAB18;

LAB20:
LAB19:    goto LAB11;

LAB14:    xsi_set_current_line(102, ng0);
    t1 = (t0 + 3212);
    t2 = (t1 + 32U);
    t4 = *((char **)t2);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB11;

LAB15:    xsi_set_current_line(95, ng0);
    t16 = (t0 + 3212);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    t19 = (t18 + 32U);
    t20 = *((char **)t19);
    *((unsigned char *)t20) = (unsigned char)2;
    xsi_driver_first_trans_fast(t16);
    goto LAB16;

LAB18:    xsi_set_current_line(99, ng0);
    t6 = (t0 + 3212);
    t7 = (t6 + 32U);
    t8 = *((char **)t7);
    t16 = (t8 + 32U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)2;
    xsi_driver_first_trans_fast(t6);
    goto LAB19;

}

static void work_a_1566496653_3212880686_p_2(char *t0)
{
    char t12[16];
    char t21[16];
    char t22[16];
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
    unsigned char t11;
    unsigned int t13;
    unsigned int t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;
    int t19;
    unsigned int t20;
    int t23;
    unsigned int t24;
    char *t25;
    char *t26;
    char *t27;
    static char *nl0[] = {&&LAB15, &&LAB16, &&LAB17, &&LAB18};

LAB0:    xsi_set_current_line(114, ng0);
    t1 = (t0 + 568U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3060);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(115, ng0);
    t3 = (t0 + 868U);
    t4 = *((char **)t3);
    t5 = *((unsigned char *)t4);
    t6 = (t5 == (unsigned char)3);
    if (t6 != 0)
        goto LAB5;

LAB7:
LAB6:    xsi_set_current_line(118, ng0);
    t1 = (t0 + 684U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t5 = (t2 == (unsigned char)3);
    if (t5 != 0)
        goto LAB8;

LAB10:
LAB9:    xsi_set_current_line(124, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    xsi_set_current_line(116, ng0);
    t3 = (t0 + 3248);
    t7 = (t3 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)0;
    xsi_driver_first_trans_fast(t3);
    goto LAB6;

LAB8:    xsi_set_current_line(119, ng0);
    t1 = (t0 + 1512U);
    t4 = *((char **)t1);
    t6 = *((unsigned char *)t4);
    t11 = (t6 == (unsigned char)1);
    if (t11 != 0)
        goto LAB11;

LAB13:
LAB12:    goto LAB9;

LAB11:    xsi_set_current_line(120, ng0);
    t1 = (t0 + 3248);
    t7 = (t1 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    *((unsigned char *)t10) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB12;

LAB14:    goto LAB3;

LAB15:    xsi_set_current_line(126, ng0);
    t4 = (t0 + 1144U);
    t7 = *((char **)t4);
    t4 = (t0 + 6848U);
    t8 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t12, t7, t4, 1);
    t9 = (t12 + 12U);
    t13 = *((unsigned int *)t9);
    t14 = (1U * t13);
    t5 = (32U != t14);
    if (t5 == 1)
        goto LAB20;

LAB21:    t10 = (t0 + 3284);
    t15 = (t10 + 32U);
    t16 = *((char **)t15);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    memcpy(t18, t8, 32U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(127, ng0);
    t1 = (t0 + 1144U);
    t3 = *((char **)t1);
    t1 = (t0 + 6848U);
    t4 = (t0 + 2048U);
    t7 = *((char **)t4);
    t19 = *((int *)t7);
    t4 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t12, t19, 32);
    t2 = ieee_p_1242562249_sub_2110375371_1035706684(IEEE_P_1242562249, t3, t1, t4, t12);
    if (t2 != 0)
        goto LAB22;

LAB24:
LAB23:    goto LAB14;

LAB16:    xsi_set_current_line(132, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t3 = t1;
    memset(t3, (unsigned char)2, 32U);
    t4 = (t0 + 3284);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(133, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t3 = t1;
    memset(t3, (unsigned char)2, 32U);
    t4 = (t0 + 3320);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 32U);
    xsi_driver_first_trans_fast(t4);
    goto LAB14;

LAB17:    xsi_set_current_line(135, ng0);
    t1 = (t0 + 960U);
    t3 = *((char **)t1);
    t1 = (t0 + 3356);
    t4 = (t1 + 32U);
    t7 = *((char **)t4);
    t8 = (t7 + 32U);
    t9 = *((char **)t8);
    memcpy(t9, t3, 24U);
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(136, ng0);
    t1 = (t0 + 3248);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(137, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t3 = t1;
    memset(t3, (unsigned char)2, 32U);
    t4 = (t0 + 3284);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(138, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t3 = t1;
    memset(t3, (unsigned char)2, 32U);
    t4 = (t0 + 3320);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 32U);
    xsi_driver_first_trans_fast(t4);
    goto LAB14;

LAB18:    xsi_set_current_line(140, ng0);
    t1 = (t0 + 1144U);
    t3 = *((char **)t1);
    t1 = (t0 + 6848U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t12, t3, t1, 1);
    t7 = (t12 + 12U);
    t13 = *((unsigned int *)t7);
    t14 = (1U * t13);
    t2 = (32U != t14);
    if (t2 == 1)
        goto LAB25;

LAB26:    t8 = (t0 + 3284);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t15 = (t10 + 32U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 32U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(141, ng0);
    t1 = (t0 + 1144U);
    t3 = *((char **)t1);
    t1 = (t0 + 6848U);
    t4 = (t0 + 1980U);
    t7 = *((char **)t4);
    t19 = *((int *)t7);
    t4 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t12, t19, 32);
    t2 = ieee_p_1242562249_sub_2110375371_1035706684(IEEE_P_1242562249, t3, t1, t4, t12);
    if (t2 != 0)
        goto LAB27;

LAB29:
LAB28:    goto LAB14;

LAB19:    xsi_set_current_line(150, ng0);
    t1 = (t0 + 3248);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB14;

LAB20:    xsi_size_not_matching(32U, t14, 0);
    goto LAB21;

LAB22:    xsi_set_current_line(128, ng0);
    t8 = xsi_get_transient_memory(32U);
    memset(t8, 0, 32U);
    t9 = t8;
    memset(t9, (unsigned char)2, 32U);
    t10 = (t0 + 3284);
    t15 = (t10 + 32U);
    t16 = *((char **)t15);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    memcpy(t18, t8, 32U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(129, ng0);
    t1 = (t0 + 3248);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    *((unsigned char *)t8) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB23;

LAB25:    xsi_size_not_matching(32U, t14, 0);
    goto LAB26;

LAB27:    xsi_set_current_line(142, ng0);
    t8 = (t0 + 1328U);
    t9 = *((char **)t8);
    t13 = (23 - 22);
    t14 = (t13 * 1U);
    t20 = (0 + t14);
    t8 = (t9 + t20);
    t15 = ((IEEE_P_2592010699) + 2312);
    t16 = (t22 + 0U);
    t17 = (t16 + 0U);
    *((int *)t17) = 22;
    t17 = (t16 + 4U);
    *((int *)t17) = 0;
    t17 = (t16 + 8U);
    *((int *)t17) = -1;
    t23 = (0 - 22);
    t24 = (t23 * -1);
    t24 = (t24 + 1);
    t17 = (t16 + 12U);
    *((unsigned int *)t17) = t24;
    t10 = xsi_base_array_concat(t10, t21, t15, (char)97, t8, t22, (char)99, (unsigned char)2, (char)101);
    t24 = (23U + 1U);
    t5 = (24U != t24);
    if (t5 == 1)
        goto LAB30;

LAB31:    t17 = (t0 + 3356);
    t18 = (t17 + 32U);
    t25 = *((char **)t18);
    t26 = (t25 + 32U);
    t27 = *((char **)t26);
    memcpy(t27, t10, 24U);
    xsi_driver_first_trans_fast(t17);
    xsi_set_current_line(143, ng0);
    t1 = xsi_get_transient_memory(32U);
    memset(t1, 0, 32U);
    t3 = t1;
    memset(t3, (unsigned char)2, 32U);
    t4 = (t0 + 3284);
    t7 = (t4 + 32U);
    t8 = *((char **)t7);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    memcpy(t10, t1, 32U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(144, ng0);
    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t1 = (t0 + 6864U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t12, t3, t1, 1);
    t7 = (t12 + 12U);
    t13 = *((unsigned int *)t7);
    t14 = (1U * t13);
    t2 = (32U != t14);
    if (t2 == 1)
        goto LAB32;

LAB33:    t8 = (t0 + 3320);
    t9 = (t8 + 32U);
    t10 = *((char **)t9);
    t15 = (t10 + 32U);
    t16 = *((char **)t15);
    memcpy(t16, t4, 32U);
    xsi_driver_first_trans_fast(t8);
    xsi_set_current_line(145, ng0);
    t1 = (t0 + 1236U);
    t3 = *((char **)t1);
    t1 = (t0 + 6864U);
    t4 = (t0 + 7047);
    t8 = (t12 + 0U);
    t9 = (t8 + 0U);
    *((int *)t9) = 0;
    t9 = (t8 + 4U);
    *((int *)t9) = 31;
    t9 = (t8 + 8U);
    *((int *)t9) = 1;
    t19 = (31 - 0);
    t13 = (t19 * 1);
    t13 = (t13 + 1);
    t9 = (t8 + 12U);
    *((unsigned int *)t9) = t13;
    t2 = ieee_p_1242562249_sub_2110375371_1035706684(IEEE_P_1242562249, t3, t1, t4, t12);
    if (t2 != 0)
        goto LAB34;

LAB36:
LAB35:    goto LAB28;

LAB30:    xsi_size_not_matching(24U, t24, 0);
    goto LAB31;

LAB32:    xsi_size_not_matching(32U, t14, 0);
    goto LAB33;

LAB34:    xsi_set_current_line(146, ng0);
    t9 = (t0 + 3248);
    t10 = (t9 + 32U);
    t15 = *((char **)t10);
    t16 = (t15 + 32U);
    t17 = *((char **)t16);
    *((unsigned char *)t17) = (unsigned char)1;
    xsi_driver_first_trans_fast(t9);
    goto LAB35;

}


extern void work_a_1566496653_3212880686_init()
{
	static char *pe[] = {(void *)work_a_1566496653_3212880686_p_0,(void *)work_a_1566496653_3212880686_p_1,(void *)work_a_1566496653_3212880686_p_2};
	xsi_register_didat("work_a_1566496653_3212880686", "isim/ledDriver_LedStri_tb_isim_beh.exe.sim/work/a_1566496653_3212880686.didat");
	xsi_register_executes(pe);
}
