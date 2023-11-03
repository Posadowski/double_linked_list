#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_LEN 33

#define PRINT 1
#define NO_PRINT 0

typedef struct queue_el
{
    int value;
    struct queue_el *next;
    struct queue_el *prev;
} queue_el;

/*A function that adds an item to the queue.

  Two pointers must be used to handle this queue:
  head - points to the first element of the queue
  tail - points to the last element of the queue
*/
void enque(queue_el **head, queue_el **tail, int value)
{
    queue_el *new_element = (queue_el *)malloc(sizeof(queue_el));
    new_element->value = value;
    new_element->next = NULL;
    new_element->prev = NULL;

    if (*head == NULL)
    {
        /*If the queue is empty, create the first elementt*/
        *head = new_element;

        /*Changing the tail of the queue to a new element*/
        *tail = new_element;
    }
    else
    {
        /*If the queue is not empty, save the current last element*/
        queue_el *old_element = (queue_el *)malloc(sizeof(queue_el));
        old_element->value = (*tail)->value;
        old_element->next = (*tail)->next;
        old_element->prev = *tail;

        /*add new element at the end*/
        (*tail)->next = new_element;
        
        /*Changing the tail of the queue to a new element*/
        *tail = new_element;
        /*save address of the previous item*/
        (*tail)->prev = old_element->prev;
    }
}

/*Function that removes the last element from the queue.*/
void deque(queue_el **head, queue_el **tail, int print)
{
    if (*head == NULL)
    {
        /*Error handling when trying to remove an item from an empty queue*/
        if (print == PRINT)
        {
            printf("error\n");
        }
    }
    else
    {
        int value;
        queue_el *old_head = *head;

        if (*(tail) == *(head))
        {
            /*If the last element is removed, the head pointer must also be modified*/
            (*head)->next = NULL;
            *tail = NULL;
        }

        *head = (*head)->next;
        value = old_head->value;

        free(old_head);

        if (print == PRINT)
        {
            printf("%d\n", value);
        }
    }
}
/*Function that removes the first element from the queue.*/
void pop(queue_el **head, queue_el **tail, int print)
{
    if (*head == NULL)
    {
        /*Error handling when trying to remove an item from an empty queue*/
        if (print == PRINT)
        {
            printf("error\n");
        }
    }
    else
    {
        int value;
        queue_el *old_tail = *tail;
        if (*(tail) == *(head))
        {
            /*If the last element is removed, the head pointer must also be modified*/
            (*tail)->prev = NULL;
            *head = NULL;
        }
        *tail = (*tail)->prev;
        value = old_tail->value;

        free(old_tail);

        if (print == PRINT)
        {
            printf("%d\n", value);
        }
    }
}

int main()
{
    queue_el *head = NULL;
    queue_el *tail = NULL;

    char buffer[BUFF_LEN];

    while (fgets(buffer, BUFF_LEN, stdin) != NULL)
    {
        if (strcmp(buffer, "deque\n") == 0)
        {
            deque(&head, &tail, PRINT);
        }
        else if (strncmp(buffer, "enque ", 6) == 0)
        {
            int value = atoi(&buffer[6]);

            enque(&head, &tail, value);
        } else if(strcmp(buffer, "pop\n") == 0){
            pop(&head, &tail, PRINT);
        }
        else
        {
            printf("invalid command\n");
        }
    }

    /*clear queue*/
    while (head != NULL)
    {
        deque(&head, &tail, NO_PRINT); 
    }

    return 0;
}