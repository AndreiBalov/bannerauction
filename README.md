# bannerauction
Тестовое задание - Рекламный аукцион.

Предположим, у нас есть страница с несколькими рекламными местами.
На этих рекламных местах показываются баннеры.
Каждый баннер определяется:
   - ценой
   - идентификатором рекламной кампании
   - списком стран для показа; если список пустой, то подходит любая страна.

Нужно реализовать функцию аукциона, которая определяет, какие из баннеров показать.
На вход функции подается:
     - массив с баннерами
     - число рекламных мест
     - страна

Функция должна возвращать баннеры, удовлетворяющие следующим условиям:
1) идентификатор рекламной кампании должен быть уникальным для баннеров в результате выдачи
2) должны возвращаться только те баннеры, которые предназначены для этой страны
3) в случае если цена одинакова, баннеры должны отдаваться равновероятно

Cопроводите решение тестами
доп требования: cmake, stl (т.е. без буста и прочих внешних зависимостей), c++11 собираться будет gcc version 4.8.4 на Ubuntu 14.04.4 LTS

плюсами будет
* возможность добавления дополнительных фильтров (не только по стране)
* возможность добавления дополнительных полей для приоретизации баннеров