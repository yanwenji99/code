#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct arc
{
    char name1[20];
    float dist;
    struct arc *next;
} arc;

typedef struct Head
{
    char name[20];
    arc *add;
} Head;

typedef struct UNGraph
{
    int vexnum, arcnum;
    Head *head;
} *Graph;

Head *LocateVex1(Graph G, char *vex)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        if (strcmp(G->head[i].name, vex) == 0)
        {
            return &G->head[i];
        }
    }
    return NULL;
}

int LocateVex2(Graph G, char *vex)
{
    for (int i = 0; i < G->vexnum; i++)
    {
        if (strcmp(G->head[i].name, vex) == 0)
        {
            return i;
        }
    }
    return -1;
}

void CreatGraph(Graph *G)
{
    *G = (Graph)malloc(sizeof(struct UNGraph));
    (*G)->vexnum = 0;
    (*G)->arcnum = 0;
    (*G)->head = (Head *)malloc(sizeof(Head) * 30);

    char tname1[100][20], tname2[100][20];
    float data[100];
    int i = 0;

    while (1)
    {
        char name1[20], name2[20];
        float dist;
        if (scanf("%s", name1) != 1 || strcmp(name1, "END!") == 0)
        {
            break;
        }
        scanf("%s%f", name2, &dist);
        strcpy(tname1[i], name1);
        strcpy(tname2[i], name2);
        data[i] = dist;
        i++;
    }
    (*G)->arcnum = i;

    for (int j = 0; j < i; j++)
    {
        if (LocateVex1(*G, tname1[j]) == NULL)
        {
            strcpy((*G)->head[(*G)->vexnum].name, tname1[j]);
            (*G)->head[(*G)->vexnum].add = NULL;
            (*G)->vexnum++;
        }
        if (LocateVex1(*G, tname2[j]) == NULL)
        {
            strcpy((*G)->head[(*G)->vexnum].name, tname2[j]);
            (*G)->head[(*G)->vexnum].add = NULL;
            (*G)->vexnum++;
        }
    }

    for (int j = 0; j < (*G)->arcnum; j++)
    {
        Head *p1 = LocateVex1(*G, tname1[j]);
        Head *p2 = LocateVex1(*G, tname2[j]);
        if (p1 && p2)
        {
            arc *a = (arc *)malloc(sizeof(arc));
            strcpy(a->name1, tname2[j]);
            a->dist = data[j];
            a->next = p1->add;
            p1->add = a;

            arc *b = (arc *)malloc(sizeof(arc));
            strcpy(b->name1, tname1[j]);
            b->dist = data[j];
            b->next = p2->add;
            p2->add = b;
        }
    }
}

float ShortestPath_DIJ(Graph G, char *start, char *end, char shortest[][600])
{
    int n = G->vexnum;
    int start_idx = LocateVex2(G, start);
    int end_idx = LocateVex2(G, end);

    float dist[n];
    int found[n];
    int path[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = 9999999.00;
        found[i] = 0;
        path[i] = -1;
    }
    dist[start_idx] = 0.00; // 初始化

    for (int count = 0; count < n; count++)
    {
        int k = -1;
        float min_dist = 9999999.00;
        for (int i = 0; i < n; i++)
        {
            if (!found[i] && dist[i] < min_dist)
            {
                min_dist = dist[i];
                k = i;
            }
        }

        if (k == -1)
            break;

        found[k] = 1;

        Head *k_head = &G->head[k];
        arc *p = k_head->add;
        while (p != NULL)
        {
            int v_idx = LocateVex2(G, p->name1);
            if (!found[v_idx] && (dist[v_idx] > dist[k] + p->dist))
            {
                dist[v_idx] = dist[k] + p->dist;
                path[v_idx] = k;
            }
            p = p->next;
        }
    }

    float result = dist[end_idx];
    if (result >= 9999999.00)
    {
        return -1.00;
    }

    int path_stack[30];
    int top = -1;
    int current = end_idx;
    while (current != -1)
    {
        path_stack[++top] = current;
        current = path[current];
    }

    char temp[600] = "";
    for (int i = top; i >= 0; i--)
    {
        strcat(temp, G->head[path_stack[i]].name);
        if (i > 0)
        {
            strcat(temp, " ");
        }
    }
    strcpy(shortest[end_idx], temp);
    return result;
}

int main()
{
    Graph G;
    CreatGraph(&G);
    char first[20], end[20], shortest[30][600] = {""};
    scanf("%s%s", first, end);
    float shortlength = ShortestPath_DIJ(G, first, end, shortest);
    int end_idx = LocateVex2(G, end);
    printf("%s %.2f", shortest[end_idx], shortlength);
    return 0;
}