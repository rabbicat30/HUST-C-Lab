#include"Stack.h"
#include<stdlib.h>
extern const char* TestSTACK(int& s);
/*������*/
int main(void) {
    int a;
    int& q = a;
    printf("U201814788 CS1806 ���� ʵ����");
    printf("\n%s\n", TestSTACK(q));
    printf("%d\n", a);
    STACK s(3);
    printf("��������Ԫ��1,2,3����sջ\n");
    s.operator<<(1);
    s.operator<<(2);
    s.operator<<(3);
    printf("��ӡa��Ԫ��\n");
    char* str=(char*)malloc(sizeof(char)*20);
    s.print(str);
    printf("%s", str);
    printf("\n��a��ʵ��Ԫ�غ��������\n");
    printf("���������%d��ʵ�ʴ�С��%d \n", s.size(), s.operator int());
    printf("����һ��Ԫ��\n");
    int e;
    s.operator>>(e);
    printf("����֮�� ");
    s.print(str);
    printf("%s", str);
    const STACK& ss = s;
    printf("\ns���ss��ss��\n");
    STACK s1(ss);
    s.print(str);
    printf("%s", str);
    STACK s2(3);
    STACK& ss1 =s2;
    s2.operator<<(4);
    s2.operator<<(5);
    s2.operator<<(6);
    printf("\n�����µ�ջ4��5��6 s2�������ֵ��s��\n");
    s.operator=(ss1);
    s.print(str);
    printf("%s", str);
    printf("\n��s2�ƶ�����s3");
    STACK s3((STACK&&)s2);
    printf("�ƶ������s3��\n");
    s3.print(str);
    printf("%s", str);
    printf("\n�ƶ������s2��ʵ�ʴ�С��%d��������%d\n",s2.size(),s2.operator int());
    printf("�ƶ������s3��ʵ�ʴ�С��%d��������%d\n", s3.size(), s3.operator int());
    printf("�ٰ�s3�ƶ���ֵ��s4\n");
    STACK s4(3);
    s4.operator=((STACK&&)s3);
    printf("���s4\n");
    s4.print(str);
    printf("%s", str);













}