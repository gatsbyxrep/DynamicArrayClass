// DynamicArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "DynamicArray.h"


int main()
{
    std::cout << "Enter array size" << std::endl;
    size_t arraySize;
    std::cin >> arraySize;
    DynamicArray<int> intDynamicArray(arraySize);
    intDynamicArray[0] = 1;
    for (size_t i = 1; i < intDynamicArray.getSize() - 1; i++)
        intDynamicArray[i] = -static_cast<int>(i);
    intDynamicArray[intDynamicArray.getSize() - 1] = intDynamicArray.getSize() - 1;

    intDynamicArray.print();
    
    std::cout << "Array min: " << intDynamicArray.getMin() << std::endl;
    std::cout << "Sum beetween first and second positive elements: " << intDynamicArray.getSumBetweenFirstAndSecondPositiveElements() << std::endl;
    return 0;

}   




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
