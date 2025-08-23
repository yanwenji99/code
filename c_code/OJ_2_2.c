#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct ListNode // 结点结构，哈夫曼树与频度链表共用
{
    char c;                  // 结点的字符
    int frequency;           // 字符的频度
    char *code;              // 字符的编码(对哈夫曼树结点有效)
    struct ListNode *parent; // 结点的双亲结点(对哈夫曼树结点有效)
    struct ListNode *left;   // 结点的左子树(对哈夫曼树结点有效)
    struct ListNode *right;  // 结点的右子树(对哈夫曼树结点有效)
    struct ListNode *next;  // 结点的后继结点(对频度链表结点有效)
    struct ListNode *prev;  // 结点的前驱结点(对频度链表结点有效)
} ListNode, HuffmanTree;
typedef struct
{
    ListNode *head;
    ListNode *tail;
    int len;
} List;
ListNode *find(List *L, char c)
{
    ListNode *p = L->head;
    while (p != NULL)
    {
        if (p->c == c)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
void CreatList(List *L)
{
    char c;
    while ((c = getchar()) != EOF)
    {
        if (L->head == NULL)
        {
            L->head = (ListNode *)malloc(sizeof(ListNode));
            L->head->c = c;
            L->head->frequency = 1;
            L->head->code = NULL;
            L->head->parent = NULL;
            L->head->left = NULL;
            L->head->right = NULL;
            L->head->next = NULL;
            L->head->prev = NULL;
            L->tail = L->head;
            L->len = 1;
        }
        else
        {
            if (find(L, c) == NULL)
            {
                ListNode *p = (ListNode *)malloc(sizeof(ListNode));
                p->c = c;
                p->frequency = 1;
                p->code = NULL;
                p->parent = NULL;
                p->left = NULL;
                p->right = NULL;
                p->next = NULL;
                p->prev = L->tail; // 设置前驱指针
                L->tail->next = p;
                L->tail = p;
                L->len++;
            }
            else
            {
                find(L, c)->frequency++;
            }
        }
    }
}
void sort(List *L)
{
    if (!L->head)
        return;

    ListNode *end = NULL; // 标记已排序的尾部
    int swapped;
    do
    {
        ListNode *current = L->head;
        ListNode *prev = NULL;
        swapped = 0; // 重置交换标志
        while (current->next != end)
        {
            // 比较相邻节点
            if (current->frequency < current->next->frequency)
            {
                // 交换数据
                char c_temp = current->c;
                int freq_temp = current->frequency;

                current->c = current->next->c;
                current->frequency = current->next->frequency;
                current->next->c = c_temp;
                current->next->frequency = freq_temp;

                swapped = 1;
            }
            prev = current;
            current = current->next;
        }
        end = current; // 更新已排序边界
    } while (swapped); // 当发生交换时继续排序
}
void insert(List *L, ListNode *p)
{
    if (L->head == NULL)
    {
        L->head = p;
        L->tail = p;
        p->next = NULL;
        p->prev = NULL;
    }
    else
    {
        ListNode *current = L->head;
        while (current != NULL && current->frequency > p->frequency)
        {
            current = current->next;
        }
        if (current == NULL) // 插入到链表尾部
        {
            L->tail->next = p;
            p->prev = L->tail;
            p->next = NULL;
            L->tail = p;
        }
        else if (current == L->head) // 插入到链表头部
        {
            p->next = L->head;
            L->head->prev = p;
            p->prev = NULL;
            L->head = p;
        }
        else // 插入到中间
        {
            p->next = current;
            p->prev = current->prev;
            current->prev->next = p;
            current->prev = p;
        }
    }
}
ListNode* findleaf(List *L)
{
    ListNode *p = L->head;
    while (p != NULL)
    {
        if (p->left == NULL && p->right == NULL && p->code==NULL)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
void HuffmanCoding(int n,List* L)
{
    if(n<=1)
        return;
    int i;
    ListNode *p1=L->tail;
    ListNode *p2=L->tail->prev;
    for (i = 1; i < n;i++)
    {
        ListNode *p3=(ListNode *)malloc(sizeof(ListNode));
        p3->frequency = p1->frequency + p2->frequency;
        p3->c = '\0';
        p3->code = NULL;
        p3->parent = NULL;
        p3->left = p1;
        p3->right = p2;
        p3->next = NULL;
        p1->parent = p3;
        p2->parent = p3;
        insert(L, p3);
        p1=p2->prev;
        if(p1!=NULL)
        {
            p2=p1->prev;
        }
        else
        {
            break;
        }
    }
    char *cd=(char *)malloc(n * sizeof(char));
    cd[n-1]='\0';
    ListNode *p = p = findleaf(L);
    ListNode *t = p;
    for (i = 0; i < n;i++)
    {
        int start = n - 1;
        while(p->parent!=NULL)
        {
            if(p->parent->left==p)
            {
                cd[--start]='0';
            }
            else
            {
                cd[--start]='1';
            }
            p=p->parent;
        }
        t->code=(char *)malloc((n+1)*sizeof(char));
        strcpy(t->code,&cd[start]);
        p=findleaf(L);
        t = p;
    }
    free(cd);
}
int calculateWPL(List *L)
{
    int wpl = 0;
    ListNode *current = L->head;
    while (current != NULL)
    {
        if (current->c != '\0' && current->code != NULL)
        {
            // 叶子节点：字符非空且编码存在
            int length = strlen(current->code);
            wpl += current->frequency * length;
        }
        current = current->next;
    }
    return wpl;
}
int main()
{
    List L;
    L.head = NULL;
    L.tail = NULL;
    L.len = 0;
    CreatList(&L);
    sort(&L);
    HuffmanCoding(L.len,&L);
    int wpl = calculateWPL(&L);
    while (L.head != NULL)
    {
        if(L.head->c=='\0')
        {
            ListNode *p = L.head;
            L.head = L.head->next;
            free(p);
            continue;
        }
        if (L.head->c == '\n')
        {
            printf("'\\n' %d %s\n", L.head->frequency, L.head->code);
        }
        else
        {
            printf("'%c' %d %s\n", L.head->c, L.head->frequency, L.head->code);
        }
        ListNode *p = L.head;
        L.head = L.head->next;
        free(p);
    }
    printf("%d\n", wpl);
    return 0;
}