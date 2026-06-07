class Task:
    def __init__(self, task_id, description, priority):
        self.id = task_id
        self.description = description
        self.priority = priority

    def __str__(self):
        return f"id={self.id}, описание='{self.description}', приоритет={self.priority}"


class TaskQueue:
    def __init__(self):
        self.items = []

    def enqueue(self, task):
        self.items.append(task)

    def dequeue(self):
        if self.is_empty():
            print("Очередь пуста")
            return None
        return self.items.pop(0)

    def front(self):
        if self.is_empty():
            print("Очередь пуста")
            return None
        return self.items[0]

    def is_empty(self):
        return len(self.items) == 0

    def __str__(self):
        if self.is_empty():
            return "Очередь пуста"
        parts = " -> ".join(f"[{task}]" for task in self.items)
        return f"Очередь: {parts}"


queue = TaskQueue()

while True:
    print("\n1 — Добавить задачу")
    print("2 — Извлечь задачу (dequeue)")
    print("3 — Посмотреть первую (front)")
    print("4 — Проверить isEmpty")
    print("5 — Вывести очередь")
    print("0 — Выход")

    choice = input("Выберите действие: ").strip()

    if choice == "1":
        task_id_raw = input("ID задачи: ").strip()
        if not task_id_raw.isdigit():
            print("ID должен быть числом.")
        else:
            description = input("Описание: ").strip()
            priority_raw = input("Приоритет (число): ").strip()
            if not priority_raw.isdigit():
                print("Приоритет должен быть числом.")
            else:
                queue.enqueue(Task(int(task_id_raw), description, int(priority_raw)))
                print("Задача добавлена.")

    elif choice == "2":
        task = queue.dequeue()
        if task:
            print("Извлечена:", task)

    elif choice == "3":
        task = queue.front()
        if task:
            print("Первая задача:", task)

    elif choice == "4":
        print("Очередь пуста?", queue.is_empty())

    elif choice == "5":
        print(queue)

    elif choice == "0":
        print("До свидания!")
        break

    else:
        print("Неизвестная команда.")
