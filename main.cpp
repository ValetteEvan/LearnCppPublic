#include <iostream>
#include <vector>
#include <span>


int main()
{
    int arr[] = {1,2,3,4,5};
    std::span<int> s(arr);  

    for (int val : s)
    {
        std::cout << val << " ";
    }

    return 0;
}