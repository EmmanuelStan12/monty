#ifndef HEADER_FILE
#define HEADER_FILE
#define  _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define INSTRUCTION_SIZE 11

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern instruction_t instructions[];

/**
 * struct args_s - arguments for opcode
 * @tokens: the arguments
 * @opcode: the opcode
 * 
 * Description: opcode and it's arguments
 */
typedef struct args_s {
	char **tokens;
	char *opcode;
	int t_size;
} args_t;

extern args_t args;

extern int stack_size;

/**
 * struct args_s - arguments for opcode
 * @tokens: the arguments
 * @opcode: the opcode
 *
 * Description: opcode and it's arguments
 */
typedef struct file_details {
	char **lines;
	int no_of_lines;
} file_details;

extern file_details fd;

char **getlines(int no_of_lines, char *filename);

int lines_size(char *filename);

void free_list(char **lines);

void free_stack(stack_t **stack);

void push(stack_t **stack, unsigned int line_number);

void pall(stack_t **stack, unsigned int line_number);

void pint(stack_t **stack, unsigned int line_number);

void pop(stack_t **stack, unsigned int line_number);

void swap(stack_t **stack, unsigned int line_number);

void add(stack_t **stack, unsigned int line_number);

void nop(stack_t **stack, unsigned int line_number);

void sub(stack_t **stack, unsigned int line_number);

void _div(stack_t **stack, unsigned int line_number);

void mul(stack_t **stack, unsigned int line_number);

void mod(stack_t **stack, unsigned int line_number);

void clean_up(stack_t **stack, int line_number);

char **tokenize(int size, char *token, char *delim);

int token_size(char *line, char *delim);

void execute(int line_no, stack_t **stack);

char *trim(char *str);

int check_input(stack_t **stack, char *input, int line_no);

int check_comment(char *line);

#endif
