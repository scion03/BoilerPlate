#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
  pid_t pid = fork();
  if (pid == 0)
  {
    cout << "child process" << endl;
    exit(0);
  }
  else if (pid > 0)
  {
    sleep(100);
    cout << "parent process" << endl;
  }
  else
  {
    cout << "fork error" << endl;
    exit(1);
  }
  return 0;
}