// A buggy program which simulate the act of producing and consuming from shared memory.
// This is a linear execution of problem.

#include <stdio.h>

#define BUFFER_SIZE 10

typedef struct item
{
    int number;
} item;

void print_buffered_array(item buffered_array[BUFFER_SIZE]);

int main(void)
{
    item buffer[BUFFER_SIZE];
    int in = 0;
    int out = 0;

    printf("Before start buffering!\n");
    print_buffered_array(buffer);

    int producer_counter = 0;
    item next_produced;
    // 1 indicate produced buffer
    next_produced.number = 1;
    // producer
    while (producer_counter < BUFFER_SIZE)
    {
        // hardcode
        if (in != BUFFER_SIZE - 1)
            while ((in + 1) % BUFFER_SIZE == out)
                ;
        buffer[in] = next_produced;
        // hardcode
        if (in == BUFFER_SIZE - 1)
            break;
        in = (in + 1) % BUFFER_SIZE;
        producer_counter++;
    }

    printf("After producer job!\n");
    print_buffered_array(buffer);

    int consumer_counter = 0;
    item next_consumed;
    // consumer
    while (consumer_counter < BUFFER_SIZE)
    {
        // hardcode
        if (out != BUFFER_SIZE - 1)
            while (in == out)
                ;
        next_consumed = buffer[out];
        printf("Consuming %d at index %d\n", next_consumed.number, out);
        out = (out + 1) % BUFFER_SIZE;
        consumer_counter++;
    }
    return 0;
}

void print_buffered_array(item buffered_array[BUFFER_SIZE])
{
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        printf("%d\t", buffered_array[i].number);
    }
    printf("\n");
}