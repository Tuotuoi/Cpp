/*************************************************************************
	> File Name: 34.thread_pool.cpp
	> Author: huguang
	> Mail: hug@haizeix.com
	> Created Time: 四  8/13 16:07:49 2020
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
#include <cmath>
using namespace std;
namespace haizei {
class Task {
public:
    template<typename T, typename ...ARGS>
    Task(T func, ARGS... args) {
        this->func = std::bind(func, std::forward<ARGS>(args)...);
    }
    void operator()() {
        this->func();
        return ;
    }
    ~Task() {}

private:
    std::function<void()> func;
};

class ThreadPool {
public :
    ThreadPool(int n = 5) 
    : max_threads_num(n),
    m_mutex(),
    m_cond() {}
    void start() {
        for (int i = 0; i < this->max_threads_num; i++) {
            threads.push_back(new std::thread(&ThreadPool::worker, this));
            // 成员方法作为入口， 并且绑定this指针, 虽然this是隐藏参数，也要跟着work进行传递绑定 成员方法要加&
        }
        return ;
    }
    void worker() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = true; //获取线程id后在是其状态变为运行
        while (is_running[id]) {
            Task *t = this->getOneTask();
            (*t)();
            delete t;
        }
        return ;
    }
    void stop() {
        for (int i = 0; i < this->max_threads_num; i++) {
            this->addOneTask(&ThreadPool::stop_task, this);
        }
        for (int i = 0; i < this->max_threads_num; i++) {
            threads[i]->join();
            delete threads[i];
        }
        threads.clear();
        return ;
    }

    template<typename T, typename ...ARGS>
    void addOneTask(T func, ARGS...args) {
        std::unique_lock<std::mutex> lock(m_mutex);
        //std::cout << std::this_thread::get_id() << " add one task" << std::endl;
        this->task_queue.push(new Task(func, std::forward<ARGS>(args)...));
        m_cond.notify_one();
        return ;
    }

private:
    void stop_task() {
        std::thread::id id = std::this_thread::get_id();
        is_running[id] = false;
        return ;
    }
    Task *getOneTask() {
        std::unique_lock<std::mutex> lock(m_mutex); // 抢碗
        while (task_queue.empty()) {
            //std::cout << std::this_thread::get_id() << " wait one task" << std::endl;
            m_cond.wait(lock);
        }// 等待，直到队列中存在任务
        //std::cout << std::this_thread::get_id() << " take one task" << std::endl;
        Task *t = task_queue.front();
        task_queue.pop();
        return t;
    }

    int max_threads_num;
    std::vector<std::thread *> threads;
    std::queue<Task *> task_queue;
    std::map<std::thread::id, bool> is_running;
    
    std::mutex m_mutex;
    std::condition_variable m_cond;
};
} // end of namespace haizei

void thread_func1(int a, int b) {
    std::cout << a << " + " << b << " = " << a + b << std::endl;
    return ;
}

void thread_func2(int &n) {
    n += 1;
    return ;
}

void (*func)();

void task_func(int x) {
    std::cout << "thread task func" << std::endl;
    return ;
}

int is_Prime(int n) {
    if(n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

static int sum = 0;
void Prime_func(int left, int right) {
    for (int i = left; i < right; i++) {
        if (is_Prime(i)) {

            __sync_fetch_and_add(&sum, 1);
        }
    }
}

int main() {
    haizei::Task t1(thread_func1, 3, 4);
    haizei::Task t2(thread_func1, 5, 6);
    haizei::Task t3(thread_func1, 7, 8);
    t1(), t2(), t3();
    int n = 0;
    
    haizei::Task t4(thread_func2, std::ref(n));
    t4(), t4(), t4();
    std::cout << n << std::endl;

    haizei::ThreadPool tp(5);
    tp.start();
    tp.addOneTask(Prime_func, 1, 200000);
    tp.addOneTask(Prime_func, 200001, 400000);
    tp.addOneTask(Prime_func, 400001, 600000);
    tp.addOneTask(Prime_func, 600001, 800000);
    tp.addOneTask(Prime_func, 800001, 1000000);
    tp.stop();
    std::cout << sum << std::endl;
    return 0;
}
