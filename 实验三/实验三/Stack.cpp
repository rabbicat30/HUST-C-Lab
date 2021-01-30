#include"Stack.h"
using namespace std;
/*����STACK(int m)��ջ��ʼ��ʱ�� Ϊ�����ͳ�Աq��elems����m������Ԫ���ڴ棬
����ʼ������ͳ�Աq��maxΪm���Լ���ʼ����Ӧ��head=tail=0��*/
STACK::STACK(int m) :QUEUE(m), q(m) {  }

/*���*/
STACK::STACK(const STACK& s) : QUEUE(s), q(s.q) {  }

/*�ƶ�����*/
STACK::STACK(STACK&& s)noexcept :QUEUE((STACK&&)s),q((STACK&&)s.q) {
	//printf("move construct\n");
}

/*�����ֵ*/
STACK& STACK::operator=(const STACK& s) {
	//printf("deep assign\n");
	if (this == &s)
		return *this;
	QUEUE::operator=(s);
	q.QUEUE::operator=(s.q);
	return *this;
}
/*�ƶ���ֵ*/
STACK& STACK::operator=(STACK&& s)noexcept {
	//printf("move assign\n");
	if (this == &s)
		return *this;
	QUEUE::operator=((STACK&&)s) ;		//�������(STACK&&)�������е�������и�ֵ����Ҳ��֪��Ϊʲô�����������ͣ��ʾ��&&
	q.QUEUE::operator=((STACK&&)s.q);
	return *this;
}

/*����ջ��ʵ��Ԫ�ظ���*/
STACK::operator int() const noexcept {
	//printf("operator int \n");
	//printf("%d\n", QUEUE::operator int() + q.QUEUE::operator int());
	return QUEUE::operator int()+q.QUEUE::operator int();
}

int  STACK::size()const noexcept {
	return 2 * QUEUE::size();
}

/*ѹջ*/
STACK& STACK::operator<<(int e) {
	//printf("operator<<\n");
	int m ;
	if (STACK::operator int() == STACK::size()-2) {			//��������������Ӧ�ü�����ѽ������
		//ջ��
		throw"STACK is full!";
	}
	if (QUEUE::operator int() != QUEUE::size()-1) {		//����������δ��
		//����һ��Ԫ�ص����������
		QUEUE::operator<<(e);
	}
	else{		//�������������ˣ�����������Ƴ�һ��Ԫ�أ�������Ԫ�ز��뵽q������
		QUEUE::operator>>(m);
		q.QUEUE::operator<<(m);	
		QUEUE::operator<<(e);
	}
	return *this;
}

STACK& STACK::operator>>(int& e) {
	//printf("operator>>\n");
	int m,n;
	int lq = q.QUEUE::operator int();		//����ֱ���ú�����õĳ��ȷ���forѭ���У���Ϊÿ����֮�󶼻�仯������Ҫ����һ��ʼ��ֵ
	int ll = QUEUE::operator int();
	//printf("��ת֮ǰlq��%d,ll��%d\n", lq, ll);
	if (STACK::operator int() == 0) {
		//printf("empty\n");
		throw"STACK is empty!";
	}
		
	if (ll >= lq) {
		if (lq != ll) {			//���q�ͻ�����г��Ȳ����
			//��Ҫ���Ķ�βԪ�ص�ǰ������Ԫ��ȫ���ƶ�����q�У�q��Ԫ��ȫ���Ƶ�Ҫ����Ԫ�صĺ���
			for (int i = 0; i < lq; i++)		//��Ϊq��Ԫ������С�ڵ��ڻ���ģ�������ת��q��
			{
				QUEUE::operator>>(m);		//���൯����m
				q.QUEUE::operator>>(n);			//q������n
				QUEUE::operator<<(n);		//�����β����n
				q.QUEUE::operator<<(m);			//q��β����m
			}
			for (int i = 0; i < ll - lq - 1; i++) {		//q��ת��֮����ת�ƻ���ʣ�µ�
				QUEUE::operator>>(m);		//���൯����m
				q.QUEUE::operator<<(m);			//��m����q
			}
		}
		else {		//���q�ͻ�����г�����ȣ�Ӧ����תһ��
			for (int i = 0; i < lq - 1; i++)		//��Ϊq��Ԫ������С�ڵ��ڻ���ģ�������ת��q��
			{
				QUEUE::operator>>(m);
				q.QUEUE::operator>>(n);
				QUEUE::operator<<(n);
				q.QUEUE::operator<<(m);
			}
		}
		QUEUE::operator>>(e);			//��������Ķ���Ԫ�ؾ���Ҫ������Ԫ��
		//����֮��Ҫ������
		if (lq == ll) {			//���֮ǰ�������ж������ģ�Ҫ�Ƚ�q�Ķ����Ƹ�������У���ʱ������Ԫ�ر�q��һ��
			q.QUEUE::operator>>(m);		//�Ƴ�����
			QUEUE::operator<<(m);		//�Ƹ�����
			lq = q.QUEUE::operator int();
			ll = QUEUE::operator int();
			for (int i = 0; i < lq; i++) {
				QUEUE::operator>>(m);
				q.QUEUE::operator>>(n);
				QUEUE::operator<<(n);
				q.QUEUE::operator<<(m);
			}
			QUEUE::operator>>(m);
			q.QUEUE::operator<<(m);
		}
		else {
			lq = q.QUEUE::operator int();
			ll = QUEUE::operator int();
			for (int i = 0; i < ll; i++)		//��ת֮���ǻ���Ԫ�ظ���
			{
				QUEUE::operator>>(m);		//���൯����m
				q.QUEUE::operator>>(n);			//q������n
				QUEUE::operator<<(n);		//�����β����n
				q.QUEUE::operator<<(m);			//q��β����m
			}
			for (int i = 0; i < lq - ll; i++) {		//q��ת��֮����ת�ƻ���ʣ�µ�
				q.QUEUE::operator>>(m);		//���൯����m
				QUEUE::operator<<(m);			//��m����q
			}
		}
		//printf("����֮��lq��%d,ll��%d\n", q.QUEUE::operator int(), QUEUE::operator int());
	}
	else if(ll!=0&&ll!=1){		//��������Ԫ�ر�qҪ�٣����翪ʼ�������ж������ģ�Ȼ���δӻ��൯��Ԫ��
		//printf("ll!=0\n");
		for (int i = 0; i < ll - 1; i++) {
			QUEUE::operator>>(m);
			//printf("queue�Ƴ�m\n");
			q.QUEUE::operator>>(n);
			//printf("q�Ƴ�n\n");
			QUEUE::operator<<(n);
			q.QUEUE::operator<<(m);
		}
		QUEUE::operator>>(e);
		lq = q.QUEUE::operator int();
		for (int i = 0; i < lq; i++) {
			QUEUE::operator>>(m);
			q.QUEUE::operator>>(n);
			QUEUE::operator<<(n);
			q.QUEUE::operator<<(m);
		}
		//printf("����֮��lq��%d,ll��%d\n", q.QUEUE::operator int(), QUEUE::operator int());
	}
	else if (ll == 1) {					//�������ֻ��һ��Ԫ�أ�������q����Ҫ��ת��
		QUEUE::operator>>(e);
	}
	else if(ll==0){		//����Ԫ��Ϊ0
		for (int i = 0; i < lq - 1; i++) {
			q.QUEUE::operator>>(n);
			QUEUE::operator<<(n);
		}
		q.QUEUE::operator>>(e);
		ll = QUEUE::operator int();
		for (int i = 0; i < ll; i++) {
			QUEUE::operator>>(n);
			q.QUEUE::operator<<(n);
		}
		//printf("����֮��lq��%d,ll��%d\n",  q.QUEUE::operator int(), QUEUE::operator int());
	}
	return *this;
}

char* STACK::print(char* b)const noexcept {
	//printf("print\n");
	int l = 0;
	if (q.QUEUE::operator int()) {
		l=strlen(q.QUEUE::print(b));
		l+=sprintf(b + l, "%c", ',');
		//printf("%d\n", l);
	}
	QUEUE::print(b+l);
	return b;
}

STACK::~STACK()noexcept {
	//printf("~STACK\n");
	QUEUE::~QUEUE();
	q.QUEUE::~QUEUE();
}



