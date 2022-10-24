#include <set>
#include <iostream>
#include <cstdlib>
#include <sys/types.h>
#include <pwd.h>
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
    struct passwd *p;
    uid_t  uid;
    
    if ((p = getpwuid(uid = geteuid())) == NULL)
        std::cerr << "getpwuid() error" << std::endl;
    
    std::cout << "Process ID: " << getpid() << std::endl;
    std::cout << "Parent procees ID: " << getppid() << std::endl;
    std::cout << "Owner's user ID: " << (int) p->pw_uid << std::endl;
    std::cout << "Owner's group ID: " << (int) p->pw_gid << std::endl;
    std::cout << "Name: " << p->pw_name << std::endl;


}