//
//  main.cpp
//  Module34-7
//
//  Created by Ольга Полевик on 13.04.2022.
//

/*
 Напишите концепт под названием ComplexConcept<T> , который будет накладывать следующие ограничения на тип:

 Наличие у типа T метода hash(), который возвращает тип, конвертируемый в long;
 Наличие у типа T метода toString(), который возвращает std::string;
 Отсутствие у типа T виртуального деструктора.
 */

/*
 С заданием справились на отлично.
 Единственное, что можно добавить - в условии задачи было еще про Отсутствие у типа T виртуального деструктора.

 Для этого была Подсказка 4 "Для проверки отсутствия у типа виртуального деструктора воспользуетесь трейтом std::has_virtual_destructor"

 Поэтому полный вариант концепта выглядит так:
 template <class T>
 concept ComplexConcept =
 !std::has_virtual_destructor<T>::value && requires(T v) {
 { v.hash() } -> std::convertible_to<long>;
 { v.toString() } -> std::same_as<std::string>;
 };
 */

#include <string>
#include <concepts>

template<typename T>
concept ComplexConcept = requires(T a)
{
{ std::hash<T>{}(a) } -> std::convertible_to<long>;
{ a.toString() } -> std::same_as<std::string>;
!std::has_virtual_destructor<T>::value;
};

int main()
{
return 0;
}
