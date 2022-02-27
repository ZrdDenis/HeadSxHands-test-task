# HeadSxHands-test-task
HxH test 
Задача
На входе функция получает параметр n - натуральное число.
Необходимо сгенерировать n-массивов, заполнить их случайными числами, каждый массив имеет случайный размер.
Размеры массивов не должны совпадать. Далее необходимо отсортировать массивы.
Массивы с четным порядковым номером отсортировать по возрастанию, с нечетным порядковым номером - по убыванию.
На выходе функция должна вернуть массив с отсортированными массивами.
/
/
Пояснения к решению: 
Было принято решение создавать массив с массивами(т.е создать динамический двумерный массив)
Можно было выводить и по одному массиву, необходимости в вышеописанном нет. Более того, это было бы проще
и значительно выигрышнее по памяти. Однако в таком случае мы не имели бы доступа к ранее созданным массивам, что ограничевает 
модифицируемость программы(например, если нужно будет работать с массивами между собой).
Для сортировки использовался встроенный "qsort", тк в задаче не было указано, нужно ли использовать свою :)
Если нужно, написать можно и свою.
Оптимизировать можно:
1) путём выбора сортировки в зависимости от размера массива
2) (Немного нечестно!) Вместо проверки размеров предыдущих массивов для исключения можно просто каждый следующий рандомайзить
начиная с размера предыдущего (очевидно они тогда будут больших размеров, но если n - небольшое, то высока вероятность получить прирост скорости)
