#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  pid_t pid = fork();

  if (pid == -1)
  {
    std::cerr << "Не удалось создать процесс" << std::endl;
    return 1;
  }
  else if (pid > 0)
  {
    // Выполнение кода родительским процессом
    std::cout << "Родительский процесс PID: " << getpid() << std::endl;

    // Родитель спит некоторое время, чтобы можно было проверить состояние зомби
    sleep(30);
  }
  else
  {
    // Выполнение кода дочерним процессом
    std::cout << "Дочерний процесс. Мой PID: " << getpid() << std::endl;
    std::cout << "Я собираюсь завершиться через 30 сек, чтобы можно было проверить состояние зомби" << std::endl;
    // Дочерний процесс завершается
  }

  return 0;
}
