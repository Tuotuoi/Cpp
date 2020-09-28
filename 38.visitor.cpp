#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
class a;
class b;
class c;
class d;
class e;
class class_zimu{
public:
	class Visitor{
	public:
		virtual void visit(a *) = 0;
		virtual void visit(b *) = 0;
		virtual void visit(c *) = 0;
		virtual void visit(d *) = 0;
		virtual void visit(e *) = 0;
	};
	virtual ~class_zimu(){
	};
	
	virtual void Accept(Visitor *vis) = 0;
};


class a :public class_zimu{
	virtual void Accept(Visitor *vis) {
		vis->visit(this);
	}
};
class b:public class_zimu {
	virtual void Accept(Visitor *vis) {
		vis->visit(this);
	}
};
class c:public class_zimu {
	virtual void Accept(Visitor *vis) {
		vis->visit(this);
	}
};
class d:public class_zimu {
	virtual void Accept(Visitor *vis) {
		vis->visit(this);
	}
};
class e:public class_zimu {
	virtual void Accept(Visitor *vis) {
		vis->visit(this);
	}
};

class Cnt_class: public class_zimu::Visitor {

public: 
	int cnt_a = 0;
	int cnt_b = 0;
	int cnt_c = 0;
	int cnt_d = 0;
	int cnt_e = 0;
	virtual void visit(a *obj) {
		this->cnt_a++;
	}
	virtual void visit(b *obj) {
		this->cnt_b++;
	}
	virtual void visit(c *obj) {
		this->cnt_c++;
	}
	virtual void visit(d *obj) {
		this->cnt_d++;
	}
	virtual void visit(e *obj) {
		this->cnt_e++;
	}
};

int main() {
	srand(time(0));
    class_zimu *arr[10];
    for (int i = 0; i < 10; i++) {
        switch(rand() % 5) {
            case 0: arr[i] = new a(); break;
            case 1: arr[i] = new b(); break;
            case 2: arr[i] = new c(); break;
            case 3: arr[i] = new d(); break;
            case 4: arr[i] = new e(); break;
        }
    }
	Cnt_class vis;
    for (int i = 0; i < 10; i++) {
        arr[i]->Accept(&vis);
    }
    cout << "a:" <<vis.cnt_a << endl;
    cout << "b:" <<vis.cnt_b << endl;
    cout << "c:" <<vis.cnt_c << endl;
    cout << "d:" <<vis.cnt_d << endl;
    cout << "e:" <<vis.cnt_e << endl;
	
	return 0;
}
