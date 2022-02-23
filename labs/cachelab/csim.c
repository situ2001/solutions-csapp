#include "cachelab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <unistd.h>
#include <malloc.h>
#include <limits.h>

int hflag = 0;
int vflag = 0;
int s, E, b;
int S, B;    // (s, E, b) => (S, E. B)
char t[128]; // relative dir of trace

int hits = 0;
int misses = 0;
int evictions = 0;

// Struct Line
typedef struct
{
    int valid;
    int tag;
    int flag;
} Line;
typedef Line *Set;
typedef Set *Cache;

Cache cache;

void init_cache()
{
    cache = (Cache)malloc(sizeof(Set) * S);
    for (int i = 0; i < S; i++)
    {
        cache[i] = (Set)malloc(sizeof(Line) * E);
        for (int j = 0; j < E; j++)
        {
            Line *l = &cache[i][j];
            l->valid = 0;
            l->tag = -1;
            l->flag = 0;
        }
    }
}

void _access(char op, unsigned addr, int block_size)
{
    unsigned tag = addr >> (s + b);
    unsigned set_index = (addr >> b) & ((1 << s) - 1);

    Set target = cache[set_index];

    // find tag
    for (int i = 0; i < E; i++)
    {
        if (target[i].tag == tag)
        {
            // hit += 1
            target[i].valid = 1;
            target[i].flag = 0;
            hits += 1;
            return;
        }
    }

    // if tag is not found
    for (int i = 0; i < E; i++)
    {
        if (target[i].valid == 0)
        {
            misses += 1;
            // place there
            target[i].flag = 0;
            target[i].valid = 1;
            target[i].tag = tag;
            return;
        }
    }

    // if it is full
    misses += 1;
    evictions += 1;
    int least_visited = -1;
    int largetest_flag = INT_MIN;
    for (int i = 0; i < E; i++)
    {
        if (target[i].flag > largetest_flag)
        {
            largetest_flag = target[i].flag;
            least_visited = i;
        }
    }
    // place into target[]
    target[least_visited].tag = tag;
    target[least_visited].flag = 0;
}

void simulate()
{
    FILE *fp = fopen(t, "r");
    if (!fp)
    {
        perror("File opening failed");
        exit(-1);
    }

    char op;
    unsigned addr;
    int block_size;
    while (fscanf(fp, " %c %x,%d", &op, &addr, &block_size) != EOF)
    {
        // printf("%c, 0x%x, %d\n", op, addr, block_size);
        switch (op)
        {
        case 'I':
            break;
        case 'M':
            hits++;
        default:
            _access(op, addr, block_size);
            break;
        }
        // update flag
        for (int i = 0; i < S; i++)
        {
            for (int j = 0; j < E; j++)
            {
                if (cache[i][j].valid == 1)
                {
                    cache[i][j].flag += 1;
                }
            }
        }
    }
    fclose(fp);
}

int main(int argc, char **argv)
{
    int c;
    while ((c = getopt(argc, argv, "hvs:E:b:t:")) != -1)
    {
        // printf("%c\n", c);
        switch (c)
        {
        case 'h':
            hflag = 1;
            break;
        case 'v':
            vflag = 1;
            break;
        case 's':
            s = atoi(optarg);
            S = 1 << s;
            break;
        case 'E':
            E = atoi(optarg);
            break;
        case 'b':
            b = atoi(optarg);
            B = 1 << b;
            break;
        case 't':
            // pass char* to function that reads content of files
            strcpy(t, optarg);
            break;
        }
    }

    // printf("vflag=%d, hflag=%d, s=%d, E=%d, b=%d\n", vflag, hflag, s, E, b);
    // printf("(S, E, B) = (%d, %d, %d)\n", S, E, B);
    // printf("relative path: %s\n", t);

    init_cache();
    simulate();

    printSummary(hits, misses, evictions);
}
