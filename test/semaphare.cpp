#include "gtest/gtest.h"
#include <iostream>
#include <Windows.h>

using namespace std;

HANDLE hSemaphore;
uint32_t times = 100;
std::atomic<uint32_t> semNum = 0;

void WorkerThread(int id) {
    while (true) {
        // 等待信号量，减少信号量计数, wait 会消耗一个信号
        DWORD dwWaitResult = WaitForSingleObject(hSemaphore, 200);
        if (dwWaitResult == WAIT_OBJECT_0) {
            int num = semNum.fetch_add(1) + 1;
            std::cout << "Worker thread " << id << "  times = " << num << std::endl;
        } else {
            std::cerr << "WaitForSingleObject failed: " << GetLastError() << std::endl;
            break;
        }
    }
}

TEST(Semaphare, semphare_test1)
{
    // 创建一个初始计数为 0 的信号量，最大计数为 5
    hSemaphore = CreateSemaphore(NULL, 0, 1000, NULL);
    if (hSemaphore == NULL) {
        std::cerr << "CreateSemaphore failed: " << GetLastError() << std::endl;
        return;
    }

    // 创建多个工作线程
    std::thread worker1(WorkerThread, 1);
    std::thread worker2(WorkerThread, 2);
    std::thread worker3(WorkerThread, 3);

    // 主线程重复释放信号量，增加计数器
    for (int i = 0; i < times; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        if (!ReleaseSemaphore(hSemaphore, 1, NULL)) {
            std::cerr << "ReleaseSemaphore failed: " << GetLastError() << std::endl;
        }
    }

    // 等待工作线程完成
    worker1.join();
    worker2.join();
    worker3.join();
    cout << " sedNum = " << semNum << endl;
    // 关闭信号量对象
    CloseHandle(hSemaphore);
    EXPECT_EQ(semNum, times);
}
