#pragma once

/*
 * 文件： M.h
 * 作者： Legion
 * 更新时间： 2023 年 11 月 18 日
 *
 * 介绍：这是 H3 头文件库的 宏定义 部分
 *
 */

// 错误码
#define M_ERROR_UNKNOWN			-1

#define M_ERROR_NONE			0

// 逻辑值
#define M_TRUE					1
#define M_FALSE					0

// 字节
#define M_BIT_8					8
#define M_BIT_16				16
#define M_BIT_32				32
#define M_BIT_64				64
#define M_BIT_128				128

// 架构
#define M_ARCH_AARCH64			0
#define M_ARCH_ALPHA			1
#define M_ARCH_ARM				2
#define M_ARCH_AVR				3
#define M_ARCH_CRIS				4
#define M_ARCH_HPPA				5
#define M_ARCH_I386				6
#define M_ARCH_LOONGARCH64		7
#define M_ARCH_M68K				8
#define M_ARCH_MICROBLAZE		9
#define M_ARCH_MICROBLAZEEL		10
#define M_ARCH_MIPS				11
#define M_ARCH_MIPS64			12
#define M_ARCH_MIPS64EL			13
#define M_ARCH_MIPSEL			14
#define M_ARCH_NIOS2			15
#define M_ARCH_OR1K				16
#define M_ARCH_PPC				17
#define M_ARCH_PPC64			18
#define M_ARCH_RISCV32			19
#define M_ARCH_RISCV64			20
#define M_ARCH_RX				21
#define M_ARCH_S390X			22
#define M_ARCH_SH4				23
#define M_ARCH_SH4EB			24
#define M_ARCH_SPARC			25
#define M_ARCH_SPARC64			26
#define M_ARCH_TRICORE			27
#define M_ARCH_X86_64			28
#define M_ARCH_XTENSA			29
#define M_ARCH_XTENSAEB			30

// 字节序
#define M_BYTE_ORDER_LITTLE		0
#define M_BYTE_ORDER_BIG		1

// 编译器
#define M_COMPILER_GCC			0
#define M_COMPILER_CLANG		1
#define M_COMPILER_MSVC			2
#define M_COMPILER_TCC			3
#define M_COMPILER_ICC			4
#define M_COMPILER_SDCC			5

// C/C++ 版本
#define M_CCPPV_C89				0
#define M_CCPPV_C90				1
#define M_CCPPV_C99				2
#define M_CCPPV_C11				3
#define M_CCPPV_CPP89			4
#define M_CCPPV_CPP99			5
#define M_CCPPV_CPP03			6
#define M_CCPPV_CPP11			7

// 系统
#define M_OS_LINUX				0
#define M_OS_WINDOWS			1
#define M_OS_MACOS				2

// ISO646
#if (M_CONFIG_CPP == M_FALSE) && (M_CONFIG_ISO646 == M_TRUE)
	#define and 					&&
	#define and_eq 				&=
	#define bitand 				&
	#define bitor 					|
	#define compl 					~
	#define not 					!
	#define not_eq 				!=
	#define or		 				||
	#define or_eq 					|=
	#define xor 					^
	#define xor_eq 				^=
#endif

// 空白
#define M_BLANK

// 保持原型
#define M_RAW(content)			content

// 标识符转字符串
#define __M_STR8(content)		#content
#define M_STR8(content)			__M_STR8(content)

#if M_CONFIG_CPP == M_TRUE
	#define __M_STR16(content)		u ## content
	#define M_STR16(content)		__M_STR16(content)

	#define __M_STR32(content)		U ## content
	#define M_STR32(content)		__M_STR32(content)
#endif

#define M_STR					M_STR8

// 标识符拼接
#define __M_SPLIT_TOKEN(A,B)	#A ## #B
#define M_SPLIT_TOKEN(A,B)		__M_SPLIT_TOKEN(A,B)

// 编译时间
#define M_DATE					M_RAW(__DATE__)
#define M_TIME					M_RAW(__TIME__)
#define M_TIMESTAMP				M_RAW(__TIMESTAMP__)

// 编译器版本
#define M_CC_VERSION			M_RAW(__VERSION__)

// 内联
#define M_INLINE				M_RAW(inline)
#define M_ALWAYS_INLINE			M_RAW(inline __attribute__((always_inline)))

// 代码定位
#define M_FILE_LOC_FMT			"%s"
#define M_FILE_LOC				M_RAW(__FILE__)

#define M_FUNC_LOC_FMT			"%s"
#define M_FUNC_LOC				M_RAW(__FUNCTION__)

#define M_FUNCTION_LOC_FMT		"%s"
#define M_FUNCTION_LOC			M_RAW(__PRETTY_FUNCTION__)

#define M_LINE_LOC_FMT			"line %d"
#define M_LINE_LOC				M_RAW(__LINE__)

#define M_CODE_LOC_FMT			"[ %s %s line %d ]"
#define M_CODE_LOC				M_FILE_LOC, M_FUNCTION_LOC, M_LINE_LOC

// 日志打印
#define M_PRINTF(fmt, args...)			M_CONFIG_PRINTF(fmt, ##args)

#define M_LOG(fmt, args...)				M_PRINTF(fmt, ##args)
#define M_LOG_WITH_LOC(fmt, args...)	M_PRINTF(M_CODE_LOC_FMT "\r\n" fmt, M_CODE_LOC, ##args)

// 分支选择
#define M_LIKELY(exp)			__builtin_expect(!!(exp), 1)
#define M_UNLIKELY(exp)			__builtin_expect(!!(exp), 0)

// 参数无效化
#define M_ARG_UNUSED(ARG)		(void)(ARG)

// 取结构体成员偏移
#define M_OFFSET_OF(type, member)			((size_t) &((type *)0)->member)

// 取结构体指针
#define M_CONTAINER_OF(ptr, type, member) \
\
({\
	const typeof(((type *)0)->member) *__mptr = (ptr);\
	(type *)((char *)__mptr - M_OFFSET_OF(type,member));\
})

// 类型强制转换
#define M_2P(x)					(&(x))
#define M_2T(ptr)				(*(ptr))

#define M_P2P(type, ptr)		((type *)(ptr))
#define M_T2P(type, ptr)		((type *)(M_2P(ptr)))
#define M_P2T(type, ptr)		M_2T(M_P2P(type, ptr))
#define M_T2T(type, ptr)		M_P2T(M_T2P(ptr))

