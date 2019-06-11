#include "mintest/macros.h"
#include <unistd.h>

int test1() {
    test_printf("Hello! %d %f\n", 3, 3.14);
    return 0;
}

int test2() {
    test_assert(1 == 0, "This always fails!");
    return 0;
}

int test3() {
    test_printf("<-- Name of the function before the printf!\n");
    test_assert(1 == 1, "This always succeeds");
    return 0;
}
int test4() {
    int *p=NULL;
    test_printf("Sempre falha com falha de segmentacao\n");
    printf("%d\n",*p + 1);
    return 0;
}
int test5() {
    test_printf("divisao por 0\n");
    int mnumero=5/0;
    printf("%d\n",mnumero);
    return 0;
}
int test6() {
    test_printf("Loop infinito\n");
    for (;;){
        
    }
    
    return 0;
}
int test7() {
    test_printf("loop demorado...\n");
    for (size_t i = 0; i < 10000; i++)
    {
        if(1==1){

        }
    }
    
    
    return 0;
}
int test8() {
    test_printf("asserts que falham e acertam ( se um falhar todos falham)\n");
    test_assert(1 == 1, "This always succeeds");
    test_assert(1 == 0, "This always fails!");
    test_assert(1 == 1, "This always succeeds");
    
    
    
    return 0;
}
int test9() {
    test_printf("muitos prints...\n");
    for (size_t i = 0; i < 100; i++)
    {

        test_printf("%ld\n",i);
    }
    
    
    
    return 0;
}
int test10() {
    test_printf(" rapido...\n");
    sleep(1);
    
    
    
    return 0;
}
int test11() {
    test_printf(" demorado...\n");
    sleep(2);
    
    
    
    return 0;
}


test_list = { TEST(test1), TEST(test2), TEST(test3), TEST(test4),TEST(test5),TEST(test6),TEST(test7),TEST(test8),TEST(test9),TEST(test10),TEST(test11)    };

#include "mintest/runner.h"
