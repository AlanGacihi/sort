#include <set>
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <time.h>
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
    clock_t start, end;
    double duration;
    long int now, after;
    
    if ((p = getpwuid(uid = geteuid())) == NULL)
        std::cerr << "getpwuid() error" << std::endl;
    
    std::cout << "Process ID: " << getpid() << std::endl;
    std::cout << "Parent procees ID: " << getppid() << std::endl;
    std::cout << "Owner's user ID: " << (int) p->pw_uid << std::endl;
    std::cout << "Owner's group ID: " << (int) p->pw_gid << std::endl;

    for (int i = 0; i <= 5; i++) {
        std::cout << "\nPriority " << i << std::endl;
        start = clock();
        now = (long int) sbk(0);
        chase_tail();
        end = clock();
        after = (long int) sbk(0);
        duration = (double(end - start)) / CLOCKS_PER_SEC;
        printf("CPU time used: %.2f seconds.\n", duration);
        printf("Memory allocated: %ld seconds.\n", after - now);
    }

    return 0;
}