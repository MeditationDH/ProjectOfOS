#include <stdio.h>

// 定义任务结构体
typedef struct {
    int priority; // 任务优先级
    char* message; // 任务要输出的信息
} Task;

// 任务执行函数
void executeTask(Task task) {
    for (int i = 0; i < task.priority; i++)
        printf("%s\n\r", task.message);
}

// 优先级调度函数
void priorityScheduling(Task tasks[], int numTasks) {
    // 简单的选择排序，根据任务的优先级进行排序
    for (int i = 0; i < numTasks - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < numTasks; j++) {
            if (tasks[j].priority > tasks[maxIndex].priority) {
                maxIndex = j;
            }
        }
        // 交换元素
        Task temp = tasks[i];
        tasks[i] = tasks[maxIndex];
        tasks[maxIndex] = temp;
    }

    // 按照优先级顺序执行任务
    for (int i = 0; i < numTasks; i++) {
        executeTask(tasks[i]);
    }
}

int main() {
    // 初始化4个任务
    Task tasks[4] = {
        {16, "Task 1: Highest Priority"},
        {10, "Task 2"},
        {8, "Task 3"},
        {6, "Task 4: Lowest Priority"}
    };

    // 调用优先级调度函数
    while(1)
        priorityScheduling(tasks, 4);

    return 0;
}
