/**
 * @file integer.hpp
 * @brief Содержит класс Integer 
 */

#ifndef CAS_NUMBERS_INTEGER_HPP_
#define CAS_NUMBERS_INTEGER_HPP_

#include "natural.hpp"
#include <string>
#include <ostream>
#include <istream>

/**
 * @brief Длинное целое число.
 *
 * Использует \c std::vector для хранения цифр. Используется десятичная система счисления.
 * Для этого класса перегружены основные арифметические операторы, что позволяет красиво записывать различные вычисления.
 */
class Integer {
    Natural natural;
    bool sign;
public:
    /** @brief Создает новое целое число, равное нулю */
    Integer();

    /** @brief Создает новое целое число из строки */
    explicit Integer(const char *str);

    /** @brief Создает новое целое число из натурального числа */
    explicit Integer(const Natural & number);
    /** @brief Преобразует число в его строковое представление */
    std::string asString();

    /**
     * @brief NZER_N_B - Выполняет проверку на ноль для целого числа
     * @returns true, если число не равно нулю.
     * @returns false, если число равно нулю. 
     */
    operator bool();

    friend std::ostream& operator<<(std::ostream& os, const Integer& number);
    friend std::istream& operator>>(std::istream& is, Integer& number);
};

/**
 * @brief Выводит целое число в поток вывода
 * 
 * @param os            Поток вывода, в который будет выведено число
 * @param[in] number    Число, которое будет выведено
 */
std::ostream& operator<<(std::ostream& os, const Integer& number);

/**
 * @brief Вводит целое число из потока ввода
 * 
 * @param is            Поток ввода, из которого будет введено число
 * @param[out] number   Ссылка на число, в которое будет записан результат
 */
std::istream& operator>>(std::istream& is, Integer& number);


#endif
