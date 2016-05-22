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
static const char *ng0 = "/home/bee/FinalProject/github/PhotoLite-Brite-X/ise4/ledDriver_LedStrip/ledDriver_LedStrip_top.vhd";
extern char *IEEE_P_2592010699;
extern char *IEEE_P_1242562249;
extern char *IEEE_P_3620187407;

int ieee_p_1242562249_sub_1657552908_1035706684(char *, char *, char *);
char *ieee_p_1242562249_sub_180853171_1035706684(char *, char *, int , int );
char *ieee_p_1242562249_sub_1919365254_1035706684(char *, char *, char *, char *, int );
unsigned char ieee_p_1242562249_sub_2110375371_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_1242562249_sub_2110411308_1035706684(char *, char *, char *, char *, char *);
unsigned char ieee_p_2592010699_sub_1690584930_503743352(char *, unsigned char );
unsigned char ieee_p_2592010699_sub_1744673427_503743352(char *, char *, unsigned int , unsigned int );
unsigned char ieee_p_3620187407_sub_1742983514_3965413181(char *, char *, char *, char *, char *);


static void work_a_3247614546_3212880686_p_0(char *t0)
{
    char *t1;
    char *t2;
    unsigned char t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;

LAB0:    xsi_set_current_line(95, ng0);

LAB3:    t1 = (t0 + 1696U);
    t2 = *((char **)t1);
    t3 = *((unsigned char *)t2);
    t1 = (t0 + 3528);
    t4 = (t1 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t3;
    xsi_driver_first_trans_fast_port(t1);

LAB2:    t8 = (t0 + 3460);
    *((int *)t8) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3247614546_3212880686_p_1(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;

LAB0:    xsi_set_current_line(98, ng0);

LAB3:    t1 = (t0 + 1788U);
    t2 = *((char **)t1);
    t1 = (t0 + 3564);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    memcpy(t6, t2, 24U);
    xsi_driver_first_trans_fast(t1);

LAB2:    t7 = (t0 + 3468);
    *((int *)t7) = 1;

LAB1:    return;
LAB4:    goto LAB2;

}

static void work_a_3247614546_3212880686_p_2(char *t0)
{
    char t12[16];
    char *t1;
    unsigned char t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned char t8;
    char *t9;
    char *t10;
    char *t11;
    unsigned int t13;
    unsigned int t14;
    int t15;
    char *t16;
    unsigned char t17;
    unsigned char t18;
    unsigned char t19;
    char *t20;
    char *t21;
    int t22;
    unsigned int t23;
    static char *nl0[] = {&&LAB6, &&LAB9, &&LAB8, &&LAB10, &&LAB11, &&LAB7};

LAB0:    xsi_set_current_line(113, ng0);
    t1 = (t0 + 568U);
    t2 = ieee_p_2592010699_sub_1744673427_503743352(IEEE_P_2592010699, t1, 0U, 0U);
    if (t2 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3476);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(114, ng0);
    t3 = (t0 + 3600);
    t4 = (t3 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast_port(t3);
    xsi_set_current_line(115, ng0);
    t1 = (t0 + 1696U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = ieee_p_2592010699_sub_1690584930_503743352(IEEE_P_2592010699, t2);
    t1 = (t0 + 3636);
    t4 = (t1 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = t8;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(116, ng0);
    t1 = (t0 + 3672);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(117, ng0);
    t1 = (t0 + 1972U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t1 = (char *)((nl0) + t2);
    goto **((char **)t1);

LAB5:    goto LAB3;

LAB6:    xsi_set_current_line(119, ng0);
    t4 = xsi_get_transient_memory(24U);
    memset(t4, 0, 24U);
    t5 = t4;
    memset(t5, (unsigned char)2, 24U);
    t6 = (t0 + 3708);
    t7 = (t6 + 32U);
    t9 = *((char **)t7);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    memcpy(t11, t4, 24U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(120, ng0);
    t1 = (t0 + 1604U);
    t3 = *((char **)t1);
    t1 = (t0 + 8324U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t12, t3, t1, 1);
    t5 = (t12 + 12U);
    t13 = *((unsigned int *)t5);
    t14 = (1U * t13);
    t2 = (33U != t14);
    if (t2 == 1)
        goto LAB13;

LAB14:    t6 = (t0 + 3744);
    t7 = (t6 + 32U);
    t9 = *((char **)t7);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    memcpy(t11, t4, 33U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(121, ng0);
    t1 = (t0 + 1604U);
    t3 = *((char **)t1);
    t1 = (t0 + 8324U);
    t4 = (t0 + 12026);
    t6 = (t12 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 31;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t15 = (31 - 0);
    t13 = (t15 * 1);
    t13 = (t13 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t13;
    t2 = ieee_p_1242562249_sub_2110375371_1035706684(IEEE_P_1242562249, t3, t1, t4, t12);
    if (t2 != 0)
        goto LAB15;

LAB17:    t1 = (t0 + 1604U);
    t3 = *((char **)t1);
    t1 = (t0 + 8324U);
    t4 = (t0 + 12058);
    t6 = (t12 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 31;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t15 = (31 - 0);
    t13 = (t15 * 1);
    t13 = (t13 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t13;
    t2 = ieee_p_1242562249_sub_2110375371_1035706684(IEEE_P_1242562249, t3, t1, t4, t12);
    if (t2 != 0)
        goto LAB18;

LAB19:
LAB16:    goto LAB5;

LAB7:    xsi_set_current_line(129, ng0);
    t1 = (t0 + 1604U);
    t3 = *((char **)t1);
    t1 = (t0 + 8324U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t12, t3, t1, 1);
    t5 = (t12 + 12U);
    t13 = *((unsigned int *)t5);
    t14 = (1U * t13);
    t2 = (33U != t14);
    if (t2 == 1)
        goto LAB20;

LAB21:    t6 = (t0 + 3744);
    t7 = (t6 + 32U);
    t9 = *((char **)t7);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    memcpy(t11, t4, 33U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(130, ng0);
    t1 = (t0 + 1604U);
    t3 = *((char **)t1);
    t1 = (t0 + 8324U);
    t4 = (t0 + 12090);
    t6 = (t12 + 0U);
    t7 = (t6 + 0U);
    *((int *)t7) = 0;
    t7 = (t6 + 4U);
    *((int *)t7) = 31;
    t7 = (t6 + 8U);
    *((int *)t7) = 1;
    t15 = (31 - 0);
    t13 = (t15 * 1);
    t13 = (t13 + 1);
    t7 = (t6 + 12U);
    *((unsigned int *)t7) = t13;
    t2 = ieee_p_1242562249_sub_2110411308_1035706684(IEEE_P_1242562249, t3, t1, t4, t12);
    if (t2 != 0)
        goto LAB22;

LAB24:
LAB23:    xsi_set_current_line(133, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = (t2 == (unsigned char)3);
    if (t8 != 0)
        goto LAB25;

LAB27:
LAB26:    goto LAB5;

LAB8:    xsi_set_current_line(137, ng0);
    t1 = xsi_get_transient_memory(33U);
    memset(t1, 0, 33U);
    t3 = t1;
    memset(t3, (unsigned char)2, 33U);
    t4 = (t0 + 3744);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 32U);
    t9 = *((char **)t7);
    memcpy(t9, t1, 33U);
    xsi_driver_first_trans_fast(t4);
    xsi_set_current_line(138, ng0);
    t1 = (t0 + 1512U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = (t2 == (unsigned char)2);
    if (t8 != 0)
        goto LAB28;

LAB30:
LAB29:    goto LAB5;

LAB9:    xsi_set_current_line(151, ng0);
    t1 = (t0 + 3816);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(152, ng0);
    t1 = (t0 + 3600);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)2;
    xsi_driver_first_trans_fast_port(t1);
    xsi_set_current_line(153, ng0);
    t1 = (t0 + 868U);
    t3 = *((char **)t1);
    t2 = *((unsigned char *)t3);
    t8 = (t2 == (unsigned char)3);
    if (t8 != 0)
        goto LAB37;

LAB39:
LAB38:    goto LAB5;

LAB10:    xsi_set_current_line(157, ng0);
    t1 = (t0 + 1880U);
    t3 = *((char **)t1);
    t1 = (t0 + 2156U);
    t4 = *((char **)t1);
    t1 = (t0 + 8388U);
    t15 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t4, t1);
    t22 = (t15 - 143);
    t13 = (t22 * -1);
    xsi_vhdl_check_range_of_index(143, 0, -1, t15);
    t14 = (24U * t13);
    t23 = (0 + t14);
    t5 = (t3 + t23);
    t6 = (t0 + 3708);
    t7 = (t6 + 32U);
    t9 = *((char **)t7);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    memcpy(t11, t5, 24U);
    xsi_driver_first_trans_fast(t6);
    xsi_set_current_line(158, ng0);
    t1 = (t0 + 3852);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)4;
    xsi_driver_first_trans_fast(t1);
    goto LAB5;

LAB11:    xsi_set_current_line(160, ng0);
    t1 = (t0 + 3672);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(161, ng0);
    t1 = (t0 + 3852);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)5;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(162, ng0);
    t1 = (t0 + 2156U);
    t3 = *((char **)t1);
    t1 = (t0 + 8388U);
    t4 = ieee_p_1242562249_sub_1919365254_1035706684(IEEE_P_1242562249, t12, t3, t1, 1);
    t5 = (t12 + 12U);
    t13 = *((unsigned int *)t5);
    t14 = (1U * t13);
    t2 = (32U != t14);
    if (t2 == 1)
        goto LAB40;

LAB41:    t6 = (t0 + 3888);
    t7 = (t6 + 32U);
    t9 = *((char **)t7);
    t10 = (t9 + 32U);
    t11 = *((char **)t10);
    memcpy(t11, t4, 32U);
    xsi_driver_first_trans_fast(t6);
    goto LAB5;

LAB12:    xsi_set_current_line(165, ng0);
    t1 = (t0 + 3852);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB5;

LAB13:    xsi_size_not_matching(33U, t14, 0);
    goto LAB14;

LAB15:    xsi_set_current_line(122, ng0);
    t7 = (t0 + 3780);
    t9 = (t7 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 32U);
    t16 = *((char **)t11);
    *((unsigned char *)t16) = (unsigned char)3;
    xsi_driver_first_trans_fast(t7);
    goto LAB16;

LAB18:    xsi_set_current_line(124, ng0);
    t7 = (t0 + 3780);
    t9 = (t7 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 32U);
    t16 = *((char **)t11);
    *((unsigned char *)t16) = (unsigned char)2;
    xsi_driver_first_trans_fast(t7);
    xsi_set_current_line(125, ng0);
    t1 = (t0 + 3816);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    xsi_set_current_line(126, ng0);
    t1 = (t0 + 3852);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)5;
    xsi_driver_first_trans_fast(t1);
    goto LAB16;

LAB20:    xsi_size_not_matching(33U, t14, 0);
    goto LAB21;

LAB22:    xsi_set_current_line(131, ng0);
    t7 = (t0 + 3852);
    t9 = (t7 + 32U);
    t10 = *((char **)t9);
    t11 = (t10 + 32U);
    t16 = *((char **)t11);
    *((unsigned char *)t16) = (unsigned char)2;
    xsi_driver_first_trans_fast(t7);
    goto LAB23;

LAB25:    xsi_set_current_line(134, ng0);
    t1 = (t0 + 3852);
    t4 = (t1 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)2;
    xsi_driver_first_trans_fast(t1);
    goto LAB26;

LAB28:    xsi_set_current_line(139, ng0);
    t1 = (t0 + 2156U);
    t4 = *((char **)t1);
    t1 = (t0 + 8388U);
    t5 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t12, 143, 32);
    t17 = ieee_p_1242562249_sub_2110375371_1035706684(IEEE_P_1242562249, t4, t1, t5, t12);
    if (t17 != 0)
        goto LAB31;

LAB33:    xsi_set_current_line(147, ng0);
    t1 = (t0 + 3852);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);

LAB32:    goto LAB29;

LAB31:    xsi_set_current_line(140, ng0);
    t6 = (t0 + 2064U);
    t7 = *((char **)t6);
    t18 = *((unsigned char *)t7);
    t19 = (t18 == (unsigned char)3);
    if (t19 != 0)
        goto LAB34;

LAB36:    xsi_set_current_line(144, ng0);
    t1 = (t0 + 3852);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)0;
    xsi_driver_first_trans_fast(t1);

LAB35:    goto LAB32;

LAB34:    xsi_set_current_line(141, ng0);
    t6 = xsi_get_transient_memory(32U);
    memset(t6, 0, 32U);
    t9 = t6;
    memset(t9, (unsigned char)2, 32U);
    t10 = (t0 + 3888);
    t11 = (t10 + 32U);
    t16 = *((char **)t11);
    t20 = (t16 + 32U);
    t21 = *((char **)t20);
    memcpy(t21, t6, 32U);
    xsi_driver_first_trans_fast(t10);
    xsi_set_current_line(142, ng0);
    t1 = (t0 + 3852);
    t3 = (t1 + 32U);
    t4 = *((char **)t3);
    t5 = (t4 + 32U);
    t6 = *((char **)t5);
    *((unsigned char *)t6) = (unsigned char)1;
    xsi_driver_first_trans_fast(t1);
    goto LAB35;

LAB37:    xsi_set_current_line(154, ng0);
    t1 = (t0 + 3852);
    t4 = (t1 + 32U);
    t5 = *((char **)t4);
    t6 = (t5 + 32U);
    t7 = *((char **)t6);
    *((unsigned char *)t7) = (unsigned char)3;
    xsi_driver_first_trans_fast(t1);
    goto LAB38;

LAB40:    xsi_size_not_matching(32U, t14, 0);
    goto LAB41;

}

static void work_a_3247614546_3212880686_p_3(char *t0)
{
    char t3[16];
    char *t1;
    char *t2;
    char *t4;
    unsigned char t5;
    char *t6;
    char *t7;
    char *t8;
    int t9;
    int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    char *t14;
    char *t15;
    char *t16;
    char *t17;
    char *t18;

LAB0:    xsi_set_current_line(172, ng0);
    t1 = (t0 + 684U);
    t2 = *((char **)t1);
    t1 = (t0 + 8276U);
    t4 = ieee_p_1242562249_sub_180853171_1035706684(IEEE_P_1242562249, t3, 143, 8);
    t5 = ieee_p_3620187407_sub_1742983514_3965413181(IEEE_P_3620187407, t2, t1, t4, t3);
    if (t5 != 0)
        goto LAB2;

LAB4:
LAB3:    t1 = (t0 + 3484);
    *((int *)t1) = 1;

LAB1:    return;
LAB2:    xsi_set_current_line(173, ng0);
    t6 = (t0 + 776U);
    t7 = *((char **)t6);
    t6 = (t0 + 684U);
    t8 = *((char **)t6);
    t6 = (t0 + 8276U);
    t9 = ieee_p_1242562249_sub_1657552908_1035706684(IEEE_P_1242562249, t8, t6);
    t10 = (t9 - 143);
    t11 = (t10 * -1);
    t12 = (24U * t11);
    t13 = (0U + t12);
    t14 = (t0 + 3924);
    t15 = (t14 + 32U);
    t16 = *((char **)t15);
    t17 = (t16 + 32U);
    t18 = *((char **)t17);
    memcpy(t18, t7, 24U);
    xsi_driver_first_trans_delta(t14, t13, 24U, 0LL);
    goto LAB3;

}


extern void work_a_3247614546_3212880686_init()
{
	static char *pe[] = {(void *)work_a_3247614546_3212880686_p_0,(void *)work_a_3247614546_3212880686_p_1,(void *)work_a_3247614546_3212880686_p_2,(void *)work_a_3247614546_3212880686_p_3};
	xsi_register_didat("work_a_3247614546_3212880686", "isim/ledDriver_LedStrip_Top_tb_isim_beh.exe.sim/work/a_3247614546_3212880686.didat");
	xsi_register_executes(pe);
}
