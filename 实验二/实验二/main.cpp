#include "Queue.h"
#include<stdlib.h>
/*������*/
int main(void) {
    int a;
    int& t = a;
    printf("U201814788 CS1806 ���� ʵ���");
    printf("\n%s\n", TestQUEUE(t));
    printf("%d\n", a);
    char* str = (char*)malloc(sizeof(char) * 4);
    int e = 0;
    printf("��������Ԫ�������Ķ���q\n");
    QUEUE q(4);
    printf("q��������%d��q��ʵ��Ԫ�ظ�����%d\n", q.size(), q.operator int());
    q.operator<<(1);
    q.operator<<(2);
    q.operator<<(3);
    printf("����1��2��3����Ԫ�غ�q��ʵ��Ԫ�ظ�����%d\n", q.operator int());
    printf("��ӡq\n");
    q.print(str);
    printf("%s", str);
    printf("\n����һ��Ԫ�غ��q��\n");
    q.operator>>(e);
    q.print(str);
    printf("%s", str);
    printf("\n��q�������q1\n��ӡq1\n");
    QUEUE q1((QUEUE&)q);
    q1.print(str);
    printf("%s", str);
    printf("\n��q�ƶ�����q2\n");
    QUEUE q2 = ((QUEUE&&)q);
    printf("�ƶ������q��������%d��ʵ��Ԫ�ظ�����%d\n",q.size(),q.operator int());
    printf("q2��������% d, q2��ʵ��Ԫ�ظ�����% d\n��ӡq2��\n",q2.size(), q2.operator int());
    q2.print(str);
    printf("%s", str);
    QUEUE q3(2);
    q3.operator<<(1);
    printf("\n��һ��Ԫ��1�Ķ���q3�ƶ���ֵ��q2\n");
    q2.operator=((QUEUE&&)q3);
    printf("�ƶ���ֵ��q3��������%d��q3��ʵ��Ԫ�ظ�����%d��q2��������%d��q2��ʵ��Ԫ�ظ�����%d\n��ӡq2\n", q3.size(), q3.operator int(), q2.size(), q2.operator int());
    q2.print(str);
    printf("%s", str);
    printf("\n����q2�����ֵ��q3\n");
    q3.operator=((QUEUE&)q2);
    printf("�����ֵ��q2��������%d��q2��ʵ��Ԫ�ظ�����%d��q3��������%d��q3��ʵ��Ԫ�ظ�����%d\n��ӡq3\n", q2.size(), q2.operator int(), q3.size(), q3.operator int());
    q3.print(str);
    printf("%s", str);



}

