#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <cmath>
#include <stdlib.h>
int GetMissingValue(const int* _values, unsigned int _count) {
    std::vector<int> nums;
    bool checkNum = false;

    for (int i = 1;i < _count + 1;i++) { nums.push_back(i); }
    
    for (int i = 0;i < _count - 1;i++) {
        
        for (int j = 0;checkNum == false;j++) {

            if (nums[j] == _values[i]) {
                nums.erase(nums.begin() + j);
                checkNum = true;               
            }

        }
        checkNum = false;
    }

    return nums.back();
}
int GetMissingValue1(const int* _values, unsigned int _count) { 
    std::list<int> nums;
    bool checkNum = false;
    auto it = nums.begin();

    for (int i = 1;i < _count;i++) {nums.push_back(i);}// создаётся последовательность для проверки
    
    for (int i = 0;i < _count - 1;i++) {
        int j = 0;
        for (;it != nums.end() && checkNum == false;it++,j++) {
            
            if (*it == _values[i]) {
                nums.erase(it);
                checkNum = true;  
                for (int c = 0;c < j;c++, it--);              
            }
      
        }
        checkNum = false;
    }

    return nums.front();
}
int* sortarray(const int values,int* arr) { //вариант сорнтировки по заданию
    std::sort(arr ,arr + values);
    return arr;
}
template <class T, int N>
void sort(T(&arr)[N]) { //доп вариант сортировки
    std::sort(std::begin(arr), std::end(arr));
}

int* GenerateRandomArray(int _maxValue) {
    int* _result = new int[_maxValue];
    int count = 1;
    
    for (int i = 0;i < _maxValue ;i++){
        _result[i] = 0;
    }
   
        while (count < _maxValue + 1 ) {
            int _rand = 0 + rand() % (_maxValue + 1 - 1);
            
            if (_result[_rand] == 0) {
                
                _result[_rand] = count;
                count++;
            
            }
        
        }
    
    return _result;
}
int binConv(int num) { //Binary converter - конвертатор в бинарное число
    int count = 0;
    int result = 0;
    std::list<int> remainders;
    
    while (num > 0) {
       
        int a = num % 2;
        remainders.push_back(num % 2);
        num /= 2;
        count++;
    
    }

    for (int i = 0;i < count;i++) {
        
        result = result + remainders.front() * (pow(10,i));
        remainders.pop_front();

    }

    return result;
}
int main()
{ 
        int a;
        std::cout << "BinConv: " << std::endl << "enter the number:" << std::endl;
        std::cin >> a;
        std::cout << "in binary: " << binConv(a) << std::endl << "------------------" << std::endl;
    
    std::cout << "GENERATERANDOMARRAY:" << std::endl;
    
    int* arr = GenerateRandomArray(a);
    
    for (int i = 0;i < a;i++) {
        std::cout << arr[i] << std::endl;
    }
    
    std::cout << "-----------------------------------------" << std::endl;
   
    std::cout << "SORTARRAY:" << std::endl;

    arr = sortarray(a,arr);

    for (int i = 0;i < a;i++) {
        std::cout << arr[i] << std::endl;
    }
    
    std::cout << "-----------------------------------------" << std::endl;
    
    std::cout << " GETMISSINGVALUE:    -- " << GetMissingValue(arr, a);
   
    return 0;
}

