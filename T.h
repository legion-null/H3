#pragma once

/*
 * 文件： M.h
 * 作者： Legion
 * 更新时间： 2023 年 11 月 18 日
 *
 * 介绍：这是 H3 头文件库的 模板 部分
 *
 */

#include "I.h"

#if M_CONFIG_CPP == M_TRUE

template<typename T>
inline cstring_t T_name_of() {
	return "unkown type";
}

#define T_name_set(type, name) \
\
template<>\
inline cstring_t T_name_of<type>() {\
	return (cstring_t) M_STR(name);\
}

#define T_name_set_default(type)		T_name_set(type, type)

T_name_set_default(i8)
T_name_set_default(i16)
T_name_set_default(i32)
T_name_set_default(i64)

template<typename T1, typename T2>
struct T_is_same {
	bool value = false;
};

template<typename T1>
struct T_is_same<T1, T1> {
	bool value = true;
};

template<bool Exp, typename T1, typename T2>
struct T_if{
	using type = T2;
};

template<typename T1, typename T2>
struct T_if<true, T1, T2>{
	using type = T1;
};

template<bool Exp, typename T1>
struct T_if<Exp, T1, void>{
	using type = void;
};

template<typename T1>
struct T_if<true, T1, void>{
	using type = T1;
};

#endif
