
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#define TIME_LIMIT 1             //determine time limit

#define VERMELHO     "\x1b[31m"
#define VERDE   "\x1b[32m"
#define AMARELO  "\x1b[33m"
#define AZUL      "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CINZA    "\x1b[36m"
#define RESET   "\x1b[0m"



int timeout = 0;
int child_done = 0;
int num_vezes = 1;
void sig_handler() {
    printf("Voce tem certeza que deseja finalizar o programa \n precione a segunda vez control-c:%d\n", num_vezes);
    if (num_vezes == 2) {
        struct sigaction s;
        s.sa_handler = SIG_DFL;
        sigemptyset(&s.sa_mask);
        printf("Chamou sigaction! %d\n", num_vezes);
        sigaction(SIGINT, &s, NULL);
    }
    num_vezes++;
}
int main() {
    int status_filho;
    int size = sizeof(all_tests)/sizeof(test_data);
    
    pid_t pid[size];
    printf("Running %d tests:\n", size);
    printf("=====================\n\n");
    int pass_count = 0;
    for (int i = 0; i < size; i++) { 
        if ((pid[i] = fork()) == 0) 
        { 
            alarm(3);
            
            if (all_tests[i].function() >= 0) {
                exit(0);
            }else
            {
                exit(-1);
            }
            
        }
    }
    struct sigaction s;
    s.sa_handler = sig_handler;
    sigemptyset(&s.sa_mask);
    s.sa_flags = 0;
    sigaction(SIGINT, &s, NULL);
    for (int i=0; i<size; i++) 
    { 
        waitpid(pid[i], &status_filho, WUNTRACED); 

        if (WIFEXITED(status_filho)){ 
            
            if(WEXITSTATUS(status_filho)==0){
                printf("%s: [PASS] valor de retorno :%d  \n", all_tests[i].name,WEXITSTATUS(status_filho));
                pass_count++;
            }
        }else
        {
            if (WIFSIGNALED(status_filho) == 1) {
                printf("%s: [FAIL] : %s\n", all_tests[i].name,strsignal(WTERMSIG(status_filho)));
        }
        }
        
        
        
            
    } 
    printf("\n\n=====================\n");
    printf("%d/%d tests passed\n", pass_count, size);
    return 0;
}
