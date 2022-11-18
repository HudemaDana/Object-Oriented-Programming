#include <stdio.h>
#include <assert.h>

void menu() 
{
    // ***********************
    // 
    //return: It prints the menu to the user in order to choose a command
    //
    //************************
    printf("\n\n-----------------------\n\n");
    printf(" Welcome to problem 7\n\n\n");
    printf("1. Read a list of numbers\n");
    printf("2. Read a sequences of numbers and find the maxim element (local and global)\n");
    printf("3. Find the longest contigous subsequence s.t all element are in a given interval\n");
    printf("4. Exit\n");
    printf("5. Extra Problem\n\n");
    printf("-----------------------\n\n");

}

typedef struct
{
    int len, array[101];
}Vector;

typedef struct
{
    int start, end, len;

}Interval;

int read_command() 
{
    // ***********************
    // 
    //return: Read the command typed by the user
    //
    //************************


    printf("Choose a thing to do: ");

    int n;
    scanf("%d", &n);

    return n;
}

//first requierment

Vector option_1() 
{
    // ***********************
    // 
    //return: It's created a vector type function which is going to return a vector v which is read from the keyboard
    //
    //************************


    Vector v;
    printf("Len of the array is gonna be: ");
    scanf("%d", &v.len);

    printf("The array is: ");
    for (int i = 0; i < v.len; i++)
        scanf("%d", &v.array[i]);

    return v;

}


//second requierment


int max(int a, int b) 
{
    // ***********************
    // 
    // param a: an integer number
    // param b: an integer number
    // return: The function returns maximum between a and b, where a and b are 2 integer numbers
    //
    //************************

    if (a > b)
        return a;
    return b;
}

int read_sequences(int a[],int* n,int local_max,int global_max) 
{
    // ***********************
    // 
    // param a[]: a vector of integers in which we save the local maximum from each sequence
    // param local_max: an integer number of the current max in the sequence
    // param global_max: an integer number which represent the max from all the sequences
    // return: It returns the maximum from all the read sequences 
    //         We read a sequence one by one, a sequence being ended by 0. While we read a sequence, we are looking for the maximum element in it. When a sequence is ended, 
    //         we check if the local_max is bigger than the global one and change it if needed. 
    //
    //************************

   
    int nr,k=-1;
    printf("Read numbers: ");
    scanf("%d", &nr);

    while (nr!=-1) 
    {
        if (nr == 0)
        {
            a[++k] = local_max;
            printf("max: %d \n", a[k]);
            global_max = max(global_max, local_max);
            local_max = -1;
        }

        local_max = max(local_max, nr);
        scanf("%d", &nr);
    }

    a[++k] = local_max;
    global_max = max(global_max, local_max);

    return global_max;

}

void print_local_global(int a[], int n, int global_max)
{
    // ***********************
    // 
    //return: print each local maximum from sequences and the global maximum
    //
    //************************

    printf("LOCAL MAXIM FOR EACH SEQUENCE: ");
    int i = 0;
    while (a[i]!=0)
        printf("%d ", a[i++]);
    printf("\nGLOBAL MAXIM OF ALL SEQUENCES: %d", global_max);
}


void option_2()
{
    // ***********************
    // 
    //return: We initialize a local and global maximum and a vector to save local max and the we read and find the maxims in the sequences
    //
    //************************

    int local_max = -1, global_max = -1, a[100] = {0},n=0;
    global_max = read_sequences(a, n,local_max, global_max);
    print_local_global(a, n,global_max);
    
}


//third requiement

Interval interval(Vector v,int a,int b)
{
    // ***********************
    // 
    // param v: a vector of type vector (it has a len and the elements)
    // param a: the beggining of the given interval
    // param b: the end of the given interval
    // return: We go though the array and if the element is in the given interval we count it. If we find an element out of the interval, it means that the sequence is over and we check if is the max one.
    //         In the end, we make one last check of a max sequence and change if needed. After that we return the max sequence in the format of an Interval type.
    //
    //************************

    Interval sequence,max_sequence;
    
    sequence.start = sequence.end = sequence.len = 0;
    max_sequence.start = max_sequence.end = max_sequence.len = 0;

    int i = 0;
    while (i < v.len)
    {
        if (v.array[i] >= a && v.array[i] <= b)
        {
            sequence.end++;
            sequence.len++;
        }

        else
        {
            if (sequence.len > max_sequence.len)
                max_sequence = sequence;
            sequence.start = sequence.end=i+1;
            sequence.len = 0;
        }

        i++;
    }

    if (sequence.len > max_sequence.len)
        max_sequence = sequence;
    
    return max_sequence;
}

void print_max_sequence(Interval seq,Vector v)
{
    // ***********************
    //
    // param seq: a sequence of type Interval, where is stored the initial and the final position of the max sequence in the vector  
    // param v: a vector of integer numbers of type Vector
    // return: it prints the max sequence of elements in a given inteval
    //
    //************************

    for (int i = seq.start; i < seq.end; i++)
        printf("%d ", v.array[i]);
}

void option_3(Vector v) 
{
    // ***********************
    //
    // param v: a vector of integer numbers of type Vector
    // return: The function it will read the interval and then find the max sequence in which the elements are in the given interval.
    //         After that it prints the max sequence. 
    //
    //************************

        int a, b;
        printf("Start of the interval: ");
        scanf("%d", &a);

        printf("End of the interval: ");
        scanf("%d", &b);

        Interval sequence;
        sequence = interval(v, a, b);

        print_max_sequence(sequence,v);
}

int is_prime(int n)
{
    // param n: in integer number
    // check if n is a prime number 

    if (n < 2)
        return 0;
    if (n == 2)
        return 1;

    for (int d = 2; d * d <= n; d++)
        if (n % d == 0)
            return 0;
    return 1;
}

int small_prime_numbers(int a[], int n)
{
    // param a[]: an array in which we will save the prime numbers
    // param n: an integer number
    // we go in decreasing order from n to 2 and check if which numbers are prime --> if they are prime, we save them in an array

    int i, k = 0;
    if (is_prime(n) == 1)
        n--;
    while (n >= 2)
    {
        if (is_prime(n) == 1)
            a[k++] = n;
        n--;
    }

    return k;
}

void extra_problem(int n)
{
    int a[100] = { 0 }, len_a = 0;
    len_a = small_prime_numbers(a, n);
    for (int i = 0; i < len_a; i++)
        printf("%d ", a[i]);
}

int main()
{   
    
    Vector v;
    int ok = 0;

    while (1) 
    {
        menu();
        int command;
        command = read_command();

        if (command == 1)
        {
            ok = 1;
            v = option_1();
        }

        else if (command == 2)
            option_2();

        else if (command == 3)
        {
            if (ok == 0)
                printf("An error occured. You can't access this requirment if you didn't type an array");
            else
                option_3(v);
        }
        else if (command == 4)
            return 0;
        else if (command == 5)
        {
            int n;
            printf("Read a number: ");
            scanf("%d", &n);
            extra_problem(n);
        }
        else
            printf("Invalid command. Please try again");

    }


    return 0;

}