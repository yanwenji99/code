#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode // 结点结构，哈夫曼树与频度链表共用
{
    char c;                  // 结点的字符
    int frequency;           // 字符的频度
    char *code;              // 字符的编码(对哈夫曼树结点有效)
    struct ListNode *parent; // 结点的双亲结点(对哈夫曼树结点有效)
    struct ListNode *left;   // 结点的左子树(对哈夫曼树结点有效)
    struct ListNode *right;  // 结点的右子树(对哈夫曼树结点有效)
    struct ListNode *next;   // 结点的后继结点(对频度链表结点有效)
} ListNode, HuffmanTree;
typedef struct
{
    ListNode *head;
    ListNode *tail;
    int len;
} List;
ListNode* find(List *L, char c)
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
    while((c=getchar())!=EOF)
    {
        if(L->head==NULL)
        {
            L->head=(ListNode *)malloc(sizeof(ListNode));
            L->head->c=c;
            L->head->frequency=1;
            L->head->code=NULL;
            L->head->parent=NULL;
            L->head->left=NULL;
            L->head->right=NULL;
            L->head->next=NULL;
            L->tail=L->head;
        }
        else
        {
            if(find(L,c)==NULL)
            {
                ListNode *p=(ListNode *)malloc(sizeof(ListNode));
                p->c=c;
                p->frequency=1;
                p->code=NULL;
                p->parent=NULL;
                p->left=NULL;
                p->right=NULL;
                p->next=NULL;
                L->tail->next=p;
                L->tail=p;
            }
            else
            {
                find(L,c)->frequency++;
            }
        }
    }
}
void sort(List *L)
{
    if (!L->head)
        return;

    ListNode *end = NULL; // 标记已排序的尾部
    ListNode *prev;
    int swapped;
    do
    {
        ListNode *current = L->head;
        prev = NULL;
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
int main()
{
    List L;
    L.head = NULL;
    L.tail = NULL;
    L.len = 0;
    CreatList(&L);
    sort(&L);
    while(L.head!=NULL)
    {
        if(L.head->c=='\n')
        {
            printf("'\\n' %d\n",L.head->frequency);
        }
        else
        {
            printf("'%c' %d\n",L.head->c,L.head->frequency);
        }
        ListNode *p=L.head;
        L.head=L.head->next;
        free(p);
    }
    return 0;
}