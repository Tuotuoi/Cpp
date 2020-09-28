/*************************************************************************
	> File Name: 35.thread_pool_2.cpp
	> Author: LuoJinXv 
	> Mail: m18999624868_1@163.com 
	> Created Time: 2020年08月14日 星期五 19时31分30秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include<thread>
#include <vector>
#include <mutex>
#include <condition_variable>
using namespace std;

class Task {
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, (forward<ARGS>)(args)...); // 按照参数类型列表进行展开
    }
    void operator()() {
        this->func();
        return ;
    }

private:
    function<void()> func;
};

class Thread_Pool {
public :
    Thread_Pool(int n = 5) : is_running(false), max_threads_num(n){
    }
    void start() {
        if (is_running) return ; // 线程池已经再工作
        is_running = true;
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new thread(&Thread_Pool::worker, this, i)); 
            // 成员方法作为入口， 并且绑定this指针, 虽然this是隐藏参数，也要跟着work进行传递绑定 成员方法要加&

        }
        return ;
    }
    void worker(int i) { 
        // 隐藏this指针
        while(is_running) {
            //取任务
            Task *t = this->getOneTask();
            if (t == nullptr) break;
            (*t)();
            delete t;
            is_running = false;
            //执行任务
            //释放任务

        }
        return ;

    }
    void stop() {
        if (is_running == false) return ;
        do {
            unique_lock<mutex> lock(m_mutex);
            //is_running = false;
            m_cond.notify_all();

        } while(0);
        for (int i = 0 ; i < max_threads_num; i++) {
            while(is_running) {
                continue;
            }
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        do {
            unique_lock<mutex> lock(m_mutex);
            while(!task_queue.empty()) task_queue.pop();
        }while(0);
        return ;
    }
    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS...args) {
        unique_lock<mutex> lock(m_mutex);
        this->task_queue.push(new Task(func, forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }
private:
    Task *getOneTask() {
        unique_lock<mutex> lock(m_mutex);
        while(is_running && task_queue.empty()) {

            m_cond.wait(lock);
        }//等待到有任务为止
        if (is_running == false) return nullptr;
        Task *t = task_queue.front();
        task_queue.pop();
        return t;

    }
    bool is_running;
    std::condition_variable m_cond;
    std::mutex m_mutex;
    int max_threads_num;
    queue<Task *> task_queue; 
    vector<thread *> threads;
};

/****************************************************************/
void thread_func1(int a, int b) {
    cout << a <<" + " << b << " = " << a + b << endl;
}
void thread_func2(int &n) {
    n += 1;
    return ;
}

void task_func(int x) {
    cout << "task_func:" << x << endl;
    return ;
}

int main() {
    Task t(thread_func1, 1, 2);
    t();
    int n = 0;
    Task t1(thread_func2, ref(n));
    t1(), t1();
    cout << n << endl;
    Thread_Pool tp(6); // 容量为6的线程池
    tp.start();
    tp.addOneTask(task_func, 123);
    tp.addOneTask(task_func, 1123);
    tp.addOneTask(task_func, 1223);
    tp.addOneTask(task_func, 1233);
    tp.addOneTask(task_func, 1234);
    tp.addOneTask(task_func, 1234);
    tp.addOneTask(task_func, 1234);
    tp.addOneTask(task_func, 1234);
    tp.addOneTask(task_func, 1235);
    //for (int i = 0; i < 1000000; i++);
    tp.stop();
    Thread_Pool tp2(4);
    tp2.start();
    tp.addOneTask(task_func, 323);
    tp.addOneTask(task_func, 213);
    tp.addOneTask(task_func, 423);
    tp2.stop();
    return 0;
}

