#pragma once
#ifndef _HEADER_HPP
#define _HEADER_HPP
#include <cmath>

/**
 @brief Функция возвращает сумму двух операндов
 */
template <typename T> auto add (T _left, T _right) -> T { return _left + _right; }

/**
 @brief Функция возвращает разность двух операндов
 */
template <typename T> auto sub (T _left, T _right) -> T { return _left - _right; }



/**
 * @brief Функция возвращает бесконечность
 *
 * @return std::size_t Бесконечность (8 -> oo)
 */
int _func () { return 8; }

double squareRoot(const double a) { return sqrt(a); }

#endif /// _HEADER_HPP