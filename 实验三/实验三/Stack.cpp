#include"Stack.h"
using namespace std;
/*在用STACK(int m)对栈初始化时， 为其基类和成员q的elems分配m个整型元素内存，
并初始化基类和成员q的max为m，以及初始化对应的head=tail=0。*/
STACK::STACK(int m) :QUEUE(m), q(m) {  }

/*深拷贝*/
STACK::STACK(const STACK& s) : QUEUE(s), q(s.q) {  }

/*移动构造*/
STACK::STACK(STACK&& s)noexcept :QUEUE((STACK&&)s),q((STACK&&)s.q) {
	//printf("move construct\n");
}

/*深拷贝赋值*/
STACK& STACK::operator=(const STACK& s) {
	//printf("deep assign\n");
	if (this == &s)
		return *this;
	QUEUE::operator=(s);
	q.QUEUE::operator=(s.q);
	return *this;
}
/*移动赋值*/
STACK& STACK::operator=(STACK&& s)noexcept {
	//printf("move assign\n");
	if (this == &s)
		return *this;
	QUEUE::operator=((STACK&&)s) ;		//如果不加(STACK&&)会进入队列的深拷贝进行赋值，我也不知道为什么，明明鼠标悬停显示是&&
	q.QUEUE::operator=((STACK&&)s.q);
	return *this;
}

/*返回栈的实际元素个数*/
STACK::operator int() const noexcept {
	//printf("operator int \n");
	//printf("%d\n", QUEUE::operator int() + q.QUEUE::operator int());
	return QUEUE::operator int()+q.QUEUE::operator int();
}

int  STACK::size()const noexcept {
	return 2 * QUEUE::size();
}

/*压栈*/
STACK& STACK::operator<<(int e) {
	//printf("operator<<\n");
	int m ;
	if (STACK::operator int() == STACK::size()-2) {			//这里有两个队列应该减二的呀！！！
		//栈满
		throw"STACK is full!";
	}
	if (QUEUE::operator int() != QUEUE::size()-1) {		//如果基类队列未满
		//插入一个元素到基类队列中
		QUEUE::operator<<(e);
	}
	else{		//如果基类队列满了，基类队列中移除一个元素，并将该元素插入到q队列中
		QUEUE::operator>>(m);
		q.QUEUE::operator<<(m);	
		QUEUE::operator<<(e);
	}
	return *this;
}

STACK& STACK::operator>>(int& e) {
	//printf("operator>>\n");
	int m,n;
	int lq = q.QUEUE::operator int();		//不能直接用函数求得的长度放在for循环中，因为每次移之后都会变化，但是要求是一开始的值
	int ll = QUEUE::operator int();
	//printf("翻转之前lq：%d,ll：%d\n", lq, ll);
	if (STACK::operator int() == 0) {
		//printf("empty\n");
		throw"STACK is empty!";
	}
		
	if (ll >= lq) {
		if (lq != ll) {			//如果q和基类队列长度不相等
			//将要弹的队尾元素的前面所有元素全部移动队列q中，q的元素全部移到要弹出元素的后面
			for (int i = 0; i < lq; i++)		//因为q的元素总是小于等于基类的，所以先转移q的
			{
				QUEUE::operator>>(m);		//基类弹出给m
				q.QUEUE::operator>>(n);			//q弹出给n
				QUEUE::operator<<(n);		//基类队尾插入n
				q.QUEUE::operator<<(m);			//q队尾插入m
			}
			for (int i = 0; i < ll - lq - 1; i++) {		//q的转完之后在转移基类剩下的
				QUEUE::operator>>(m);		//基类弹出给m
				q.QUEUE::operator<<(m);			//将m插入q
			}
		}
		else {		//如果q和基类队列长度相等，应该少转一次
			for (int i = 0; i < lq - 1; i++)		//因为q的元素总是小于等于基类的，所以先转移q的
			{
				QUEUE::operator>>(m);
				q.QUEUE::operator>>(n);
				QUEUE::operator<<(n);
				q.QUEUE::operator<<(m);
			}
		}
		QUEUE::operator>>(e);			//移完后基类的队首元素就是要弹出的元素
		//翻完之后要翻回来
		if (lq == ll) {			//如果之前两个队列都是满的，要先将q的队首移给基类队列，这时候基类的元素比q多一个
			q.QUEUE::operator>>(m);		//移出队首
			QUEUE::operator<<(m);		//移给基类
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
			for (int i = 0; i < ll; i++)		//翻转之后是基类元素更少
			{
				QUEUE::operator>>(m);		//基类弹出给m
				q.QUEUE::operator>>(n);			//q弹出给n
				QUEUE::operator<<(n);		//基类队尾插入n
				q.QUEUE::operator<<(m);			//q队尾插入m
			}
			for (int i = 0; i < lq - ll; i++) {		//q的转完之后在转移基类剩下的
				q.QUEUE::operator>>(m);		//基类弹出给m
				QUEUE::operator<<(m);			//将m插入q
			}
		}
		//printf("弹出之后lq：%d,ll：%d\n", q.QUEUE::operator int(), QUEUE::operator int());
	}
	else if(ll!=0&&ll!=1){		//如果基类的元素比q要少，比如开始两个队列都是满的，然后多次从基类弹出元素
		//printf("ll!=0\n");
		for (int i = 0; i < ll - 1; i++) {
			QUEUE::operator>>(m);
			//printf("queue移出m\n");
			q.QUEUE::operator>>(n);
			//printf("q移出n\n");
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
		//printf("弹出之后lq：%d,ll：%d\n", q.QUEUE::operator int(), QUEUE::operator int());
	}
	else if (ll == 1) {					//如果基类只有一个元素，弹出后q不需要在转移
		QUEUE::operator>>(e);
	}
	else if(ll==0){		//基类元素为0
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
		//printf("弹出之后lq：%d,ll：%d\n",  q.QUEUE::operator int(), QUEUE::operator int());
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



