#include <stdio.h>
#include <string.h>

int main()
{
    char *url = "http://www.naver.com/module/121/298.png";
    char domain[100]={0};
    char *p;

    puts("<< 도메인 출력 >>");
    strcpy(domain, url);

    p = strtok(domain, "//");
    puts(p);
    p = strtok(NULL, "/");
    puts(p);

    char *p1 = strstr(url, "//");
    char *p2 = strchr(p1+2, '/');
    strncpy(domain, p2-p1-2, sizeof(domain));

    puts(domain);

    return 0;
}
