#include <iostream>
#include <string>
#include <cstring>
//#include <cstdlib>

//#include <sys/stat.h>   //Para mkdir
#include <sys/types.h>    //Para error
#include <bits/stdc++.h>  //para strerror
#include <unistd.h>       //Para getcwd

#define MAX_PATH 1024

using namespace std;

int main(int argc, char const *argv[]) {
  // char firefox_pages[2058] = "firefox ";
  // strcat(firefox_pages, "firefox ");
  // strcat(firefox_pages, "https://uhunt.onlinejudge.org/vcontest/7854728dd13c8f71c5352c66ae79c6aa ");
  // strcat(firefox_pages, "https://uhunt.onlinejudge.org/ ");
  // strcat(firefox_pages, "https://uva.onlinejudge.org/ https://www.youtube.com/");
  // system(firefox_pages);
  // system("firefox https://uhunt.onlinejudge.org/vcontest/efe064fdb0d8f9d2fa980a3f5b978dde https://uva.onlinejudge.org/external/6/679.pdf https://uhunt.onlinejudge.org/ https://uva.onlinejudge.org/ https://www.youtube.com/");

  system("firefox https://uhunt.onlinejudge.org/vcontest/1e15789a80457c598b61da7356d0cd1a https://www.youtube.com/watch?v=XvmIf9CzIw8&t=29s");
  return 0;
}
