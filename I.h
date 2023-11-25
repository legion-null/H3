#pragma once

/*
 * 文件： I.h
 * 作者： Legion
 * 更新时间： 2023 年 11 月 18 日
 *
 * 介绍：这是 H3 头文件库的 内联函数 部分
 *
 */

#include "M.h"

// 可变参数
typedef __builtin_va_list		va_list;

// 整数
#define d8						char
#define d16						short
#define d32						int
#define d64						long long

typedef signed d8				i8;
typedef signed d16				i16;
typedef signed d32				i32;
typedef signed d64				i64;

typedef unsigned d8			u8;
typedef unsigned d16			u16;
typedef unsigned d32			u32;
typedef unsigned d64			u64;

#undef d8
#undef d16
#undef d32
#undef d64

#if M_CONFIG_BIT == M_BIT_32
	typedef i32						iSize;
	typedef u32						uSize;
#elif M_CONFIG_BIT == M_BIT_64
	typedef i64						iSize;
	typedef u64						uSize;
#endif

#if M_CONFIG_CPP == M_TRUE
	using size_t = decltype(sizeof(void*));
#else
	typedef uSize					size_t;
#endif

typedef i8						s8;
typedef i16						s16;
typedef i32						s32;
typedef i64						s64;

typedef i8						sint8_t;
typedef i16						sint16_t;
typedef i32						sint32_t;
typedef i64						sint64_t;

typedef i8						int8_t;
typedef i16						int16_t;
typedef i32						int32_t;
typedef i64						int64_t;

typedef u8						uint8_t;
typedef u16						uint16_t;
typedef u32						uint32_t;
typedef u64						uint64_t;

// 字节
typedef u8						bit8_t;
typedef u16						bit16_t;
typedef u32						bit32_t;
typedef u64						bit64_t;

typedef bit8_t					byte_t;

// 地址
typedef byte_t*					addr_t;

// 浮点数
typedef float					f32;
typedef double					f64;
typedef long double			f128;

// 字符
typedef char					c8;

typedef c8						char8_t;

#if M_CONFIG_CPP == M_TRUE
	typedef char16_t			c16;
	typedef char32_t			c32;
#else
	typedef u16					char16_t;
	typedef u32					char32_t;

	typedef char16_t			c16;
	typedef char32_t 			c32;
#endif

typedef signed char			schar_t;

typedef char8_t					char_t;

// 字符串
typedef const char_t*			cstring_t;

// 逻辑
#if M_CONFIG_CPP != M_TRUE
	typedef u8						bool;

	#define true					M_TRUE
	#define false					M_FALSE
#endif

typedef enum {
	I_Arch_aarch64 = M_ARCH_AARCH64,
	I_Arch_alpha = M_ARCH_ALPHA,
	I_Arch_arm = M_ARCH_ARM,
	I_Arch_avr = M_ARCH_AVR,
	I_Arch_cris = M_ARCH_CRIS,
	I_Arch_hppa = M_ARCH_HPPA,
	I_Arch_i386 = M_ARCH_I386,
	I_Arch_loongarch64 = M_ARCH_LOONGARCH64,
	I_Arch_m68k = M_ARCH_M68K,
	I_Arch_microblaze = M_ARCH_MICROBLAZE,
	I_Arch_microblazeel = M_ARCH_MICROBLAZEEL,
	I_Arch_mips = M_ARCH_MIPS,
	I_Arch_mips64 = M_ARCH_MIPS64,
	I_Arch_mips64el = M_ARCH_MIPS64EL,
	I_Arch_mipsel = M_ARCH_MIPSEL,
	I_Arch_nios2 = M_ARCH_NIOS2,
	I_Arch_or1k = M_ARCH_OR1K,
	I_Arch_ppc = M_ARCH_PPC,
	I_Arch_ppc64 = M_ARCH_PPC64,
	I_Arch_riscv32 = M_ARCH_RISCV32,
	I_Arch_riscv64 = M_ARCH_RISCV64,
	I_Arch_rx = M_ARCH_RX,
	I_Arch_s390x = M_ARCH_S390X,
	I_Arch_sh4 = M_ARCH_SH4,
	I_Arch_sh4eb = M_ARCH_SH4EB,
	I_Arch_sparc = M_ARCH_SPARC,
	I_Arch_sparc64 = M_ARCH_SPARC64,
	I_Arch_tricore = M_ARCH_TRICORE,
	I_Arch_x86_64 = M_ARCH_X86_64,
	I_Arch_xtensa = M_ARCH_XTENSA,
	I_Arch_xtensaeb = M_ARCH_XTENSAEB,
} I_Arch;

static inline I_Arch I_ConfigArch() {
	return (I_Arch) M_CONFIG_ARCH;
}

typedef enum {
	I_ByteOrder_little = M_BYTE_ORDER_LITTLE, I_ByteOrder_big = M_BYTE_ORDER_BIG,
} I_ByteOrder;

static inline I_ByteOrder I_ConfigByteOrder() {
	static const u8 data[2] = { 0xAA, 0xBB };
	return M_P2T(u16, data) == 0xBBAA ? I_ByteOrder_little : I_ByteOrder_big;
}

typedef enum {
	I_Compiler_gcc = M_COMPILER_GCC,
	I_Compiler_clang = M_COMPILER_CLANG,
	I_Compiler_msvc = M_COMPILER_MSVC,
	I_Compiler_tcc = M_COMPILER_TCC,
	I_Compiler_icc = M_COMPILER_ICC,
	I_Compiler_sdcc = M_COMPILER_SDCC,
} I_Compiler;

static inline I_Compiler I_ConfigCompiler() {
	return (I_Compiler) M_CONFIG_COMPILER;
}

static inline bool I_TypeCheck() {
	if (sizeof(i8) != 1 or sizeof(i16) != 2 or sizeof(i32) != 4 or sizeof(i64) != 8)
		if (sizeof(u8) != 1 or sizeof(u16) != 2 or sizeof(u32) != 4 or sizeof(u64) != 8)
			if (sizeof(f32) != 4 or sizeof(f64) != 8 or sizeof(f128) != 16)
				if (sizeof(c8) != 1 or sizeof(c16) != 2 or sizeof(c32) != 4) {
					return true;
				}

	return false;
}

#if 0

// 内联 C 库，仅函数部分
// assert.h

// ctype.h
static inline bool I_isdigit(i32 c) {
	return (c >= '0' and c <= '9');
}

static inline bool I_isxdigit(i32 c) {
	return (I_isdigit(c) or (c >= 'a' and c <= 'z') or (c >= 'A' and c <= 'Z'));
}

static inline bool I_islower(i32 c) {
	return (c >= 'a' and c <= 'z');
}

static inline bool I_isupper(i32 c) {
	return (c >= 'A' and c <= 'Z');
}

static inline bool I_isalpha(i32 c) {
	return (I_islower(c) or I_isupper(c));
}

static inline bool I_isalnum(i32 c) {
	return (I_isalpha(c) or I_isdigit(c));
}

static inline bool I_iscntrl(i32 c) {
	return ((c >= '\x00' and c <= '\x1F') or (c == 'x7F'));
}

static inline bool I_isprint(i32 c) {
	return (not I_iscntrl(c));
}

static inline bool I_isspace(i32 c) {
	return (c == ' ' or (c >= '\t' and c <= '\r'));
}

static inline bool I_isgraph(i32 c) {
	return (I_isprint(c) and (not I_isspace(c)));
}

static inline bool I_ispunct(i32 c) {
	return (I_isgraph(c) and (not I_isalnum(c)));
}

static inline i32 I_tolower(i32 c) {
	c = c - 'A' + 'a';
	return (I_islower(c) ? c : 0);
}

static inline i32 I_toupper(i32 c) {
	c = c - 'a' + 'A';
	return (I_isupper(c) ? c : 0);
}

// math.h
static inline f64 I_acos(f64 x) {
	return 0;
}

static inline f64 I_asin(f64 x) {
	return 0;
}

static inline f64 I_atan(f64 x) {
	return 0;
}

static inline f64 I_atan2(f64 y, f64 x) {
	return 0;
}

static inline f64 I_cos(f64 x) {
	return 0;
}

static inline f64 I_cosh(f64 x) {
	return 0;
}

static inline f64 I_sin(f64 x) {
	return 0;
}

static inline f64 I_sinh(f64 x) {
	return 0;
}

static inline f64 I_tanh(f64 x) {
	return 0;
}

static inline f64 I_exp(f64 x) {
	return 0;
}

static inline f64 I_frexp(f64 x, i32 *exponent) {
	return 0;
}

static inline f64 I_ldexp(f64 x, i32 exponent) {
	return 0;
}

static inline f64 I_log(f64 x) {
	return 0;
}

static inline f64 I_log10(f64 x) {
	return 0;
}

static inline f64 I_modf(f64 x, f64 *integer) {
	return 0;
}

static inline f64 I_pow(f64 x, f64 y) {
	return 0;
}

static inline f64 I_sqrt(f64 x) {
	return 0;
}

static inline f64 I_ceil(f64 x) {
	return 0;
}

static inline f64 I_fabs(f64 x) {
	return (x > 0 ? x : -x);
}

static inline f64 I_floor(f64 x) {
	return 0;
}

static inline f64 I_fmod(f64 x, f64 y) {
	return 0;
}

// stddef.h
#define va_start	M_RAW(__builtin_va_start)
#define va_arg		M_RAW(__builtin_va_arg)
#define va_end		M_RAW(__builtin_va_end)

// stdio.h
static inline i32 I_fclose(void *stream) {
	extern int fclose(void*);

	return fclose(stream);
}

static inline void I_clearerr(void *stream) {
	extern void clearerr(void*);

	return clearerr(stream);
}

static inline i32 I_feof(void *stream) {
	extern int feof(void*);

	return feof(stream);
}

static inline i32 I_ferror(void *stream) {
	extern int ferror(void*);

	return ferror(stream);
}

static inline i32 I_fflush(void *stream) {
	extern int fflush(void*);

	return fflush(stream);
}

static inline i32 I_fgetpos(void *stream, void *pos) {
	extern int fgetpos(void*, void*);

	return fgetpos(stream, pos);
}

static inline void* I_fopen(const char_t *filename, const char_t *mode) {
	extern void* fopen(const char_t*, const char_t*);

	return fopen(filename, mode);
}

static inline size_t I_fread(void *ptr, size_t size, size_t nmemb, void *stream) {
	extern size_t fread(void*, size_t, size_t, void*);

	return fread(ptr, size, nmemb, stream);
}

static inline void* I_freopen(const char_t *filename, const char_t *mode, void *stream) {
	extern void* freopen(const char_t *filename, const char_t *mode, void *stream);

	return freopen(filename, mode, stream);
}

static inline i32 I_fseek(void *stream, i64 offset, i32 whence) {
	extern i32 fseek(void *stream, i64 offset, i32 whence);

	return fseek(stream, offset, whence);
}

static inline i32 I_fsetpos(void *stream, const void *pos) {
	return 0;
}

static inline i64 I_ftell(void *stream) {
	return 0;
}

static inline size_t I_fwrite(const void *ptr, size_t size, size_t nmemb, void *stream) {
	return 0;
}

static inline i32 I_remove(const char_t *voidname) {
	return 0;
}

static inline i32 I_rename(const char_t *old_voidname, const char_t *new_voidname) {
	return 0;
}

static inline void I_rewind(void *stream) {

}

static inline void I_setbuf(void *stream, char_t *buffer) {

}

static inline i32 I_setvbuf(void *stream, char_t *buffer, i32 mode, size_t size) {
	return 0;
}

static inline void* I_tmpvoid(void) {
	return 0;
}

static inline char_t* I_tmpnam(char_t *str) {
	return 0;
}

static inline i32 I_fprintf(void *stream, const char_t *format, ...) {
	return 0;
}

static inline i32 I_printf(const char_t *format, ...) {
	extern int vprintf(const char *format, va_list args);

	va_list ap;
	va_start(ap, format);

	i32 ret = vprintf(format, ap);

	va_end(ap);

	return ret;
}

static inline i32 I_sprintf(char_t *str, const char_t *format, ...) {
	return 0;
}

static inline i32 I_vfprintf(void *stream, const char_t *format, va_list args) {
	return 0;
}

static inline i32 I_vprintf(const char_t *format, va_list args) {
	extern int vprintf(const char *format, va_list args);

	return vprintf(format, args);
}

static inline i32 I_vsprintf(char_t *str, const char_t *format, va_list args) {
	return 0;
}

static inline i32 I_fscanf(void *stream, const char_t *format, ...) {
	return 0;
}

static inline i32 I_scanf(const char_t *format, ...) {
	return 0;
}

static inline i32 I_sscanf(const char_t *str, const char_t *format, ...) {
	return 0;
}

static inline i32 I_fgetc(void *stream) {
	return 0;
}

static inline char_t* I_fgets(char_t *str, i32 n, void *stream) {
	return 0;
}

static inline i32 I_fputc(i32 c, void *stream) {
	return 0;
}

static inline i32 I_fputs(const char_t *str, void *stream) {
	return 0;
}

static inline i32 I_getc(void *stream) {
	return 0;
}

static inline i32 I_getchar(void) {
	return 0;
}

static inline char_t* I_gets(char_t *str) {
	return 0;
}

static inline i32 I_putc(i32 c, void *stream) {
	return 0;
}

static inline i32 I_putchar(i32 c) {
	return 0;
}

static inline i32 I_puts(const char_t *str) {
	return 0;
}

static inline i32 I_ungetc(i32 c, void *stream) {
	return 0;
}

static inline void I_perror(const char_t *str) {

}

static inline i32 I_snprintf(char_t *str, size_t size, const char_t *format, ...) {
	return 0;
}

// stdlib.h
typedef struct I_div_t {

} I_div_t;

typedef struct I_ldiv_t {

} I_ldiv_t;

static inline f64 I_atof(const char_t *str) {
	return 0;
}

static inline i32 I_atoi(const char_t *str) {
	return 0;
}

static inline i64 I_atol(const char_t *str) {
	return 0;
}

static inline f64 I_strtod(const char_t *str, char_t **endptr) {
	return 0;
}

static inline i64 I_strtol(const char_t *str, char_t **endptr, i32 base) {
	return 0;
}

static inline u64 I_strtoul(const char_t *str, char_t **endptr, i32 base) {
	return 0;
}

static inline void* I_calloc(size_t nitems, size_t size) {
	return 0;
}

static inline void I_free(void *ptr) {
}

static inline void* I_malloc(size_t size) {
	return 0;
}

static inline void* I_realloc(void *ptr, size_t size) {
	return 0;
}

static inline void I_abort(void) {
}

static inline i32 I_atexit(void (*func)(void)) {
	return 0;
}

static inline void I_exit(i32 status) {
}

static inline char_t* I_getenv(const char_t *name) {
	return 0;
}

static inline i32 I_system(const char_t *string) {
	return 0;
}

static inline void* I_bsearch(const void *key, const void *base, size_t nitems, size_t size, i32 (*compar)(const void*, const void*)) {
	return 0;
}

static inline void I_qsort(void *base, size_t nitems, size_t size, i32 (*compar)(const void*, const void*)) {
}

static inline i32 I_abs(i32 x) {
	return 0;
}

static inline I_div_t I_div(i32 numer, i32 denom) {

}

static inline i64 I_labs(i64 x) {
	return 0;
}

static inline I_ldiv_t I_ldiv(i64 numer, i64 denom) {

}

static inline i32 I_rand(void) {
	return 0;
}

static inline void I_srand(u32 seed) {
}

static inline i32 I_mblen(const char_t *str, size_t n) {
	return 0;
}

static inline size_t I_mbstowcs(schar_t *pwcs, const char_t *str, size_t n) {
	return 0;
}

static inline i32 I_mbtowc(c32 *pwc, const char_t *str, size_t n) {
	return 0;
}

static inline size_t I_wcstombs(char_t *str, const c32 *pwcs, size_t n) {
	return 0;
}

static inline i32 I_wctomb(char_t *str, c32 wc8) {
	return 0;
}

// string.h
static inline void* I_memchr(const void *str, i32 c, size_t n) {
	return 0;
}

static inline i32 I_memcmp(const void *str1, const void *str2, size_t n) {
	return 0;
}

static inline void* I_memcpy(void *dest, const void *src, size_t n) {
	return 0;
}

static inline void* I_memmove(void *dest, const void *src, size_t n) {
	return 0;
}

static inline void* I_memset(void *str, i32 c, size_t n) {
	return 0;
}

static inline char_t* I_strcat(char_t *dest, const char_t *src) {
	return 0;
}

static inline char_t* I_strncat(char_t *dest, const char_t *src, size_t n) {
	return 0;
}

static inline char_t* I_strchr(const char_t *str, i32 c) {
	return 0;
}

static inline i32 I_strcmp(const char_t *str1, const char_t *str2) {
	return 0;
}

static inline i32 I_strncmp(const char_t *str1, const char_t *str2, size_t n) {
	return 0;
}

static inline i32 I_strcoll(const char_t *str1, const char_t *str2) {
	return 0;
}

static inline char_t* I_strcpy(char_t *dest, const char_t *src) {
	return 0;
}

static inline char_t* I_strncpy(char_t *dest, const char_t *src, size_t n) {
	return 0;
}

static inline size_t I_strcspn(const char_t *str1, const char_t *str2) {
	return 0;
}

static inline char_t* I_strerror(i32 errnum) {
	return 0;
}

static inline size_t I_strlen(const char_t *str) {
	return 0;
}

static inline char_t* I_strpbrk(const char_t *str1, const char_t *str2) {
	return 0;
}

static inline char_t* I_strrchr(const char_t *str, i32 c) {
	return 0;
}

static inline size_t I_strspn(const char_t *str1, const char_t *str2) {
	return 0;
}

static inline char_t* I_strstr(const char_t *haystack, const char_t *needle) {
	return 0;
}

static inline char_t* I_strtok(char_t *str, const char_t *delim) {
	return 0;
}

static inline size_t I_strxfrm(char_t *dest, const char_t *src, size_t n) {
	return 0;
}

// threads.h

enum {
	thrd_success = 0, thrd_busy = 1, thrd_error = 2, thrd_nomem = 3, thrd_timedout = 4,
};

typedef uSize I_thrd_t;
typedef i32 (*I_thrd_start_t)(void*);

enum {
	mtx_plain = 0, mtx_recursive = 1, mtx_timed = 2,
};

typedef struct {
} I_mtx_t;

typedef i32 I_once_flag;

typedef struct {

} I_cnd_t;

typedef unsigned I_tss_t;
typedef void (*I_tss_dtor_t)(void*);

static inline i32 I_thrd_create(I_thrd_t *thr, I_thrd_start_t func, void *arg) {
	return 0;
}

static inline i32 I_thrd_equal(I_thrd_t lhs, I_thrd_t rhs) {
	return 0;
}

I_thrd_t thrd_current(void) {
	return 0;
}

static inline i32 I_thrd_sleep(const struct timespec *duration, struct timespec *remaining) {
	return 0;
}

static inline void I_thrd_yield(void) {
}

static inline void I_thrd_exit(i32 res) {

}

static inline i32 I_thrd_detach(I_thrd_t thr) {
	return 0;
}

static inline i32 I_thrd_join(I_thrd_t thr, i32 *res) {
	return 0;
}

static inline i32 I_mtx_init(I_mtx_t *mutex, i32 type) {
	return 0;
}

static inline i32 I_mtx_lock(I_mtx_t *mutex) {
	return 0;
}

static inline i32 I_mtx_timedlock(I_mtx_t *__restrict mutex, const struct timespec *__restrict time_point) {
	return 0;
}

static inline i32 I_mtx_trylock(I_mtx_t *mutex) {
	return 0;
}

static inline i32 I_mtx_unlock(I_mtx_t *mutex) {
	return 0;
}

static inline void I_mtx_destroy(I_mtx_t *mutex) {
}

static inline void I_call_once(I_once_flag *flag, void (*func)(void)) {
}

static inline i32 I_cnd_init(I_cnd_t *cond) {
	return 0;
}

static inline i32 I_cnd_signal(I_cnd_t *cond) {
	return 0;
}

static inline i32 I_cnd_broadcast(I_cnd_t *cond) {
	return 0;
}

static inline i32 I_cnd_wait(I_cnd_t *cond, I_mtx_t *mutex) {
	return 0;
}

static inline i32 I_cnd_timedwait(I_cnd_t *__restrict cond, I_mtx_t *__restrict mutex, const struct timespec *__restrict time_point) {
	return 0;
}

static inline void I_cnd_destroy(I_cnd_t *cond) {
}

static inline i32 I_tss_create(I_tss_t *tss_key, I_tss_dtor_t destructor) {
	return 0;
}

static inline void* I_tss_get(I_tss_t tss_key) {
	return 0;
}

static inline i32 I_tss_set(I_tss_t tss_id, void *val) {
	return 0;
}

static inline void I_tss_delete(I_tss_t tss_id) {

}

#endif
