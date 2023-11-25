#pragma once

/*
 * 文件： H3.h
 * 作者： Legion
 * 更新时间： 2023 年 11 月 18 日
 *
 * 介绍：这是 H3 头文件库的 配置 部分，注意，此文件仅作为示例使用，如引入 H3 库，请仿照本文件自行定义 H3.h
 *
 */

// 配置
#define M_CONFIG_CPP			M_TRUE
#define M_CONFIG_BIT			M_BIT_64
#define M_CONFIG_ARCH			M_ARCH_X86_64
#define M_CONFIG_BYTE_ORDER		M_BYTE_ORDER_LITTLE
#define M_CONFIG_COMPILER		M_COMPILER_GCC

#define M_CONFIG_ISO646			M_TRUE

#define M_CONFIG_PRINTF(fmt, args...)		printf(fmt, ##args)

#include "M.h"
#include "I.h"
#include "T.h"
