#include"Stack.h"
#include<stdlib.h>
extern const char* TestSTACK(int& s);
/*主函数*/
int main(void) {
    int a;
    int& q = a;
    printf("U201814788 CS1806 刘美 实验三");
    printf("\n%s\n", TestSTACK(q));
    printf("%d\n", a);
    STACK s(3);
    printf("插入三个元素1,2,3构造s栈\n");
    s.operator<<(1);
    s.operator<<(2);
    s.operator<<(3);
    printf("打印a的元素\n");
    char* str=(char*)malloc(sizeof(char)*20);
    s.print(str);
    printf("%s", str);
    printf("\n求a的实际元素和最大容量\n");
    printf("最大容量：%d，实际大小：%d \n", s.size(), s.operator int());
    printf("弹出一个元素\n");
    int e;
    s.operator>>(e);
    printf("弹出之后： ");
    s.print(str);
    printf("%s", str);
    const STACK& ss = s;
    printf("\ns深拷贝ss，ss：\n");
    STACK s1(ss);
    s.print(str);
    printf("%s", str);
    STACK s2(3);
    STACK& ss1 =s2;
    s2.operator<<(4);
    s2.operator<<(5);
    s2.operator<<(6);
    printf("\n利用新的栈4，5，6 s2来深拷贝赋值给s：\n");
    s.operator=(ss1);
    s.print(str);
    printf("%s", str);
    printf("\n用s2移动构造s3");
    STACK s3((STACK&&)s2);
    printf("移动构造后，s3：\n");
    s3.print(str);
    printf("%s", str);
    printf("\n移动构造后s2的实际大小：%d，容量：%d\n",s2.size(),s2.operator int());
    printf("移动构造后s3的实际大小：%d，容量：%d\n", s3.size(), s3.operator int());
    printf("再把s3移动赋值给s4\n");
    STACK s4(3);
    s4.operator=((STACK&&)s3);
    printf("输出s4\n");
    s4.print(str);
    printf("%s", str);













}