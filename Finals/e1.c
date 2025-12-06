#include<stdio.h>
#include<stdlib.h>
int *initialize_status(int initial_value) {
    int *status = (int *)malloc(sizeof(int));
    if (status == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    *status = initial_value;
    return status;
}
void increment_counter(int *config_status_ptr)
{
    static int call_count = 0;
    call_count++;printf("%d\n",call_count);
    if (call_count % 2 == 0)
    {
        if (*config_status_ptr == 1)
        {
            *config_status_ptr = 0;
        }
        else
        {
            *config_status_ptr = 1;
        }
        
    }
    
}
int main() {
    int *config_status = initialize_status(0);
    for (int i = 0; i < 5; i++) {
        increment_counter(config_status);
    }
    printf("%d",*config_status);
}

    