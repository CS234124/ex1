#include <stdio.h>
#include <stdlib.h>
struct Test{
    int test;
};

struct Test* creator(){
    struct Test *test = (struct Test*)(malloc(sizeof(struct Test)));
    test->test = 5;
    return test;
}

int main(){
    struct Test *temp = creator();
    printf("%d", temp->test);
    free(temp);
    return 0;
}