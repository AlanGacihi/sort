#include <set>
#include <iostream>
#include <cstdlib>
#include <unistd.h>

// Add stuff to the set to wast time and space
std::multiset<int> stuff;
void chase_tail()
{
    int numadds = rand() % 50000 + 20000;
    std::cout << "Adding " << numadds << " to the multiset." << std::endl;
    while(numadds--)
    {
        stuff.insert(rand());
    }
}


int main()
{
    std::cout << "Process ID: " << getpid() << std::endl;
    std::cout << "Parent procees ID: " << getppid() << std::endl;
    std::cout << "Owner's procees ID: " << getuid() << std::endl;
    std::cout << "Owner's group ID: " << getgid() << std::endl;
}