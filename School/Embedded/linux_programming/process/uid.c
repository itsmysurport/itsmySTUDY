#include <stdio.h>
#include <pwd.h>
#include <grp.h>

/* Print User ID*/
int main()
{
    int pid;
    printf("My Actual User ID: %d(%s) \n", getuid(), getpwuid(getuid()) -> pw_name);
    printf("My vaild User Id: %d(%s) \n", geteuid(), getpwuid(geteuid()) -> pw_name);
    printf("My Actual Group ID: %d(%s) \n", getgid(), getgrgid(getgid()) -> gr_name);
    printf("My vaild Group Id: %d(%s) \n", getegid(), getgrgid(getegid()) -> gr_name);
}
