#include"Queue.h"
/*初始化*/
QUEUE::QUEUE(int m): elems(new int[m]),max(elems ? m : 0){
	head = tail = 0;
}

/*深拷贝*/
QUEUE::QUEUE(const QUEUE& q) : max(q.max), elems(new int[q.max]),head(q.head),tail(q.tail) {
	int i;
	for (i = 0; i < q.max; i++)
		elems[i] = (q.elems)[i];
}

/*移动构造,noexcept关键字用于说明函数中不会发生异常,这有利于编译器对程序做更多的优化*/
QUEUE::QUEUE(QUEUE&& q)noexcept:max(q.max),head(q.head),tail(q.tail),elems(q.elems) {
	*(int**)&q.elems = 0;
	*(int*)&q.max = q.head = q.tail = 0;
}

/*返回队列的实际长度*/
QUEUE::operator int() const noexcept{
	int n = tail - head;
	if (n < 0)    n = n + max;   //避免出现p->max=0的情况
	return n;
}

/*返回队列的最大元素个数max*/
int QUEUE:: size() const noexcept {
	return max;
}

/*插入元素到尾部*/
QUEUE& QUEUE::operator<<(int e) {
	if ((tail + 1) % max == head) {
		throw  "QUEUE is full!";
	}
	elems[tail] = e;
	tail = (tail + 1) % max;
	return *this;
}

/*从队首移出元素*/
QUEUE& QUEUE::operator>>(int& e) {
	if (tail == head) {
		throw "QUEUE is empty!";
	}
	e = elems[head];
	head = (head + 1) % max;
	return *this;
}

/*深拷贝赋值并返回被赋值的队列*/
QUEUE& QUEUE::operator=(const QUEUE& q) {
	if (this == &q)
		return *this;
	if (elems) {
		delete elems;			//free关键字只能释放malloc构造的对象，释放数组要用delete[]
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

/*移动赋值*/
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

/*打印队列*/
char* QUEUE::print(char* s) const noexcept {
	int len = operator int();
	if (len == 0)       //如果是空队列
		throw"the queue is empty!";
	int i = head;
	int j = 0;
	while (i % max != tail)
	{
		if (i != head)      //先输出逗号，第一个元素输出时前面不要输出
			j += sprintf(s + j, "%c", ',');
		j += sprintf(s + j, "%d", elems[i % max]);
		i = (i + 1) % max;
	}
	sprintf(s + j, "%c", '\0');
	return s;
}

/*析构函数*/
QUEUE::~QUEUE() {
	if (elems)
	{
		delete[] elems;
		*(int**)&elems = 0;
		*(int*)&max = 0;
		head = tail = 0;
	}
}
