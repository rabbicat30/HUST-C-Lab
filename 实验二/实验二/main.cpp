#include "Queue.h"
#include<stdlib.h>
/*主函数*/
int main(void) {
    int a;
    int& t = a;
    printf("U201814788 CS1806 刘美 实验二");
    printf("\n%s\n", TestQUEUE(t));
    printf("%d\n", a);
    char* str = (char*)malloc(sizeof(char) * 4);
    int e = 0;
    printf("构造三个元素容量的队列q\n");
    QUEUE q(4);
    printf("q的容量：%d，q的实际元素个数：%d\n", q.size(), q.operator int());
    q.operator<<(1);
    q.operator<<(2);
    q.operator<<(3);
    printf("插入1，2，3三个元素后，q的实际元素个数：%d\n", q.operator int());
    printf("打印q\n");
    q.print(str);
    printf("%s", str);
    printf("\n弹出一个元素后的q：\n");
    q.operator>>(e);
    q.print(str);
    printf("%s", str);
    printf("\n用q深拷贝构造q1\n打印q1\n");
    QUEUE q1((QUEUE&)q);
    q1.print(str);
    printf("%s", str);
    printf("\n用q移动构造q2\n");
    QUEUE q2 = ((QUEUE&&)q);
    printf("移动构造后q的容量：%d，实际元素个数：%d\n",q.size(),q.operator int());
    printf("q2的容量：% d, q2的实际元素个数：% d\n打印q2：\n",q2.size(), q2.operator int());
    q2.print(str);
    printf("%s", str);
    QUEUE q3(2);
    q3.operator<<(1);
    printf("\n用一个元素1的队列q3移动赋值给q2\n");
    q2.operator=((QUEUE&&)q3);
    printf("移动赋值后，q3的容量：%d，q3的实际元素个数：%d，q2的容量：%d，q2的实际元素个数：%d\n打印q2\n", q3.size(), q3.operator int(), q2.size(), q2.operator int());
    q2.print(str);
    printf("%s", str);
    printf("\n再用q2深拷贝赋值给q3\n");
    q3.operator=((QUEUE&)q2);
    printf("深拷贝赋值后，q2的容量：%d，q2的实际元素个数：%d，q3的容量：%d，q3的实际元素个数：%d\n打印q3\n", q2.size(), q2.operator int(), q3.size(), q3.operator int());
    q3.print(str);
    printf("%s", str);



}

