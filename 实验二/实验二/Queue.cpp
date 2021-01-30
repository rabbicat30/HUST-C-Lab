#include"Queue.h"
/*��ʼ��*/
QUEUE::QUEUE(int m): elems(new int[m]),max(elems ? m : 0){
	head = tail = 0;
}

/*���*/
QUEUE::QUEUE(const QUEUE& q) : max(q.max), elems(new int[q.max]),head(q.head),tail(q.tail) {
	int i;
	for (i = 0; i < q.max; i++)
		elems[i] = (q.elems)[i];
}

/*�ƶ�����,noexcept�ؼ�������˵�������в��ᷢ���쳣,�������ڱ������Գ�����������Ż�*/
QUEUE::QUEUE(QUEUE&& q)noexcept:max(q.max),head(q.head),tail(q.tail),elems(q.elems) {
	*(int**)&q.elems = 0;
	*(int*)&q.max = q.head = q.tail = 0;
}

/*���ض��е�ʵ�ʳ���*/
QUEUE::operator int() const noexcept{
	int n = tail - head;
	if (n < 0)    n = n + max;   //�������p->max=0�����
	return n;
}

/*���ض��е����Ԫ�ظ���max*/
int QUEUE:: size() const noexcept {
	return max;
}

/*����Ԫ�ص�β��*/
QUEUE& QUEUE::operator<<(int e) {
	if ((tail + 1) % max == head) {
		throw  "QUEUE is full!";
	}
	elems[tail] = e;
	tail = (tail + 1) % max;
	return *this;
}

/*�Ӷ����Ƴ�Ԫ��*/
QUEUE& QUEUE::operator>>(int& e) {
	if (tail == head) {
		throw "QUEUE is empty!";
	}
	e = elems[head];
	head = (head + 1) % max;
	return *this;
}

/*�����ֵ�����ر���ֵ�Ķ���*/
QUEUE& QUEUE::operator=(const QUEUE& q) {
	if (this == &q)
		return *this;
	if (elems) {
		delete elems;			//free�ؼ���ֻ���ͷ�malloc����Ķ����ͷ�����Ҫ��delete[]
		*(int**)&elems = 0;
	}
	*(int**)&elems = new int[q.max];
	int i = 0;
	for (; i < q.max; i++)
		elems[i] = (q.elems)[i];
	*(int*)&max = q.max;
	head = q.head;
	tail = q.tail;
	return *this;
}

/*�ƶ���ֵ*/
QUEUE& QUEUE::operator=(QUEUE&& q)noexcept {
	if (this == &q)
		return *this;
	if (elems)
		delete elems;
	*(int**)&elems = q.elems;
	*(int*)&max = q.max;
	head = q.head;
	tail = q.tail;
	*(int*)&q.elems = 0;
	*(int*)&q.max = 0;
	q.head = q.tail = 0;
	return *this;
}

/*��ӡ����*/
char* QUEUE::print(char* s) const noexcept {
	int len = operator int();
	if (len == 0)       //����ǿն���
		throw"the queue is empty!";
	int i = head;
	int j = 0;
	while (i % max != tail)
	{
		if (i != head)      //��������ţ���һ��Ԫ�����ʱǰ�治Ҫ���
			j += sprintf(s + j, "%c", ',');
		j += sprintf(s + j, "%d", elems[i % max]);
		i = (i + 1) % max;
	}
	sprintf(s + j, "%c", '\0');
	return s;
}

/*��������*/
QUEUE::~QUEUE() {
	if (elems)
	{
		delete[] elems;
		*(int**)&elems = 0;
		*(int*)&max = 0;
		head = tail = 0;
	}
}
