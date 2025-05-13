


//template <typename T>
//
//void NromFnc(List<T>& List1, List<T>& List2, int size, List<T>& resList)
//{
//    
//    
//    for (int i = 0; i < size; i++)
//    {
//        resList[i] = List1[i];
//        i++;
//        resList[i] = List2[i];
//    }
//}
//
//template <typename T>
//void CheckForIdentical(List<T>& List1, List<T>& List2)
//{
//    int i = 0;
//    int j = 1;
//    for (i; i < List1.Size(); i++)
//    {
//        for (j; j < List1.Size(); j++)
//        {
//            if (List1.find(List1[i]))
//                List1.deleting(i);
//        }
//    }
//
//    i = 0;
//    j = 1;
//
//    for (i; i < List2.Size(); i++)
//    {
//        for (j; j < List2.Size(); j++)
//        {
//            if (List2.find(List2[i]))
//                List2.deleting(i);
//        }
//    }
//        
//}
#include "List.h"
#include <iostream>
#include <cstdlib>

template <typename T>
void NromFnc(List<T>& List1, List<T>& List2, int size, List<T>& resList) {
    for (int i = 0; i < size; i++) {
        if (i < List1.Size()) {
            resList.add(List1[i]);
        }
        if (i < List2.Size()) {
            resList.add(List2[i]);
        }
    }
}

template <typename T>
void CheckForIdentical(List<T>& List) {
    for (int i = 0; i < List.Size(); i++) {
        for (int j = i + 1; j < List.Size(); j++) {
            if (List[i] == List[j]) {
                List.deleting(j);
                j--; 
            }
        }
    }

}


int main()
{
    List<int> List1;
    List<int> List2;
    //List<int> resList;
    std::cout << "list1    list2" << std::endl;

    
    
    for (int i = 0; i < 10; i++)
    {
        List1.add(rand() % 10);
        List2.add(rand() % 10);
        std::cout << List1.Size() << " " << List2.Size() << std::endl;;
        std::cout << List1[i] << "        " << List2[i] << std::endl;
    }

    std::cout << std::endl;

   

    List<int> resList;
    NromFnc(List1, List2, List1.Size() + List2.Size(), resList);
    CheckForIdentical(resList);
    for (int i = 0; i < resList.Size(); i++)
        std::cout << resList[i] << " ";
}



