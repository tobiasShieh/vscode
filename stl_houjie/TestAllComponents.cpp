#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
namespace jj30
{
    using namespace std;

    void test_all_components()
    {
        cout << "\ntest_all_components().......... \n";
        
        int ia[7] = { 27, 210, 12, 47, 109, 83, 40 };
        /*
            容器：提供逻辑存储结构，使用者只需要关注如何添加数据和组织数据即可，不需要知道如何分配内存；

            分配器：为容器提供内存分配与管理；
                注意，容器的类型和分配器分配的内存单元必须一致；
            算法：用于处理容器中的数据；
                注意，这里的算法是独立于容器存在的，而不是容器类中包含的函数；
            迭代器：泛型指针，和算法结合使用；
            仿函数：结构体，但是实现了()，传入对象之后，就可以通过此对象调用operator();
            适配器：对原始结构进行限制，比如新的数据结构是由基本数据结构表示；

        */
        vector<int,allocator<int>> vi(ia,ia+7); //定义一个vector容器，该容器用于存储int类型数据，并指定使用allocator<int>分配内存
    
        //count_if就是算法，用于统计满足条件的元素的个数
        //begin和end可以获取迭代器；
        //less就是一个仿函数；
        //bind2nd和not1都是仿函数适配器，前置用于绑定第二参数，后者用于取反
        cout << count_if(vi.begin(), vi.end(), 
                not1(bind2nd(less<int>(), 40)));	//5
        cout << endl;          
    }															 
}
#if 1
int main()
{
    using namespace jj30;
    test_all_components();

    cin.get();
    return 0;
}
#endif