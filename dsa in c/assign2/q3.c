#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *prev, *next;
} node;
node *create_node()
{
    int data;
    node *new_node = (node *)malloc(sizeof(node));
    printf("enter data : ");
    scanf("%d", &data);
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// void func( int *xptr){
//     cout<<(*xptr)<<endl;
// }

// int main(){
//     int x= 10;
//     func(&x);
// }
void createList(node **headptr)
{
    if (*headptr != NULL)
        return;
    // *head
    int n, data;
    node *temp = NULL, *prev_node = NULL;
    printf("how many nodes to insert ? : ");
    scanf("%d", &n);

    // head  = 10  (head , *headptr)
    // adding nodes to the end
    for (int i = 0; i < n; i++)
    {
        temp = create_node(); // 20 , 30
        if (*headptr == NULL)
            *headptr = temp; // 10

        //
        if (prev_node != NULL) // 10, 20
        {
            prev_node->next = temp; // 10->next = 20 , 20->next = 30
            temp->prev = prev_node; // 20->prev = 10   30->prev = 20
        }
        // 10-><-20
        prev_node = temp; // 10, 20
    }
}
void print(node *head)
{
    // node *cur = (node *)malloc(sizeof(node));
    node *cur = head;
    while (cur)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    return;
}
void insert_head(node **headptr)
{
    // head->null
    //

    // head = null
    node *new_node = create_node();  // 5
    new_node->next = *headptr;       // 5->next = null
    if (*headptr != NULL)            // head== (*headptr)
        (*headptr)->prev = new_node; // 5<-10

    *headptr = new_node; // head->5-null
}

void insert_tail(node **headptr)
{
    node *new_node = create_node();
    // if list is empty,
    if (*headptr == NULL)
    {
        *headptr = new_node;
        return;
    }
    // head->10
    // 10->20->30->null

    node *curr = *headptr;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    // curr contains last node
    curr->next = new_node;
    new_node->prev = curr;
    return;
}
void insert_after_kthnode(node **headptr)
{
    int k;
    printf("enter position k : ");
    scanf("%d", &k);
    if (*headptr == NULL)
        return;

    if (k == 0)
    {
        insert_head(headptr);
        return;
    }

    node *curr = *headptr;
    // k=2
    // head->10
    // 10->20->30->40->null

    while (curr != NULL && --k) // 1 , 0
    {
        curr = curr->next; // 20
    }
    if (curr == NULL)
    {
        printf("invalid k \n");
        return;
    }
    // curr = 20
    // curr->next = 30

    //
    node *nxt = curr->next;
    node *new_node = create_node(); // 25
    curr->next = new_node;          // 20->25
    new_node->prev = curr;          //   20<-25

    //
    new_node->next = nxt; // 25->30
    nxt->prev = new_node; // 25<-30
    return;
}

void insert_after_value(node *head)
{
    int val;
    printf("enter value : ");
    scanf("%d", &val);
    if (head == NULL)
        return;

    node *curr = head;
    while (curr != NULL && curr->data != val)
        curr = curr->next;

    // printf("\n %d \n", curr->data);
    if (curr == NULL)
    {
        printf("element not found . couldnt insert new node !! \n");
        return;
    }
    node *new_node = create_node();
    node *nxt = curr->next;
    curr->next = new_node;
    new_node->prev = curr;

    // 10->20->30->null
    // 25
    // 20->25 ->30   25<-30
    new_node->next = nxt;
    if (nxt != NULL)
        nxt->prev = new_node;
    return;
}
void insert_before_kthnode(node **head)
{
    int k;
    printf("enter k : ");
    scanf("%d", &k);
    if (k == 1)
    {
        insert_head(head);
        return;
    }
    node *curr = *head;
    --k;
    while (--k)
    {
        curr = curr->next;
    }
    node *new_node = create_node();
    node *nxt = curr->next;
    curr->next = new_node;
    new_node->prev = curr;

    new_node->next = nxt;
    nxt->prev = new_node;
}
void insert_before_value(node **head)
{
    int val;
    printf("enter value : ");
    scanf("%d", &val);
    if (*head == NULL)
        return;
    // if ist node matches
    if ((*head)->data == val)
    {
        insert_head(head);
        return;
    }
    node *curr = *head;
    while (curr != NULL && curr->data != val)
        curr = curr->next;

    // printf("\n %d \n", curr->data);
    if (curr == NULL)
    {
        printf("element not found . couldnt insert new node !! \n");
        return;
    }
    node *new_node = create_node();
    node *prev = curr->prev;
    curr->prev = new_node;
    new_node->next = curr;

    new_node->prev = prev;
    prev->next = new_node;
    return;
}
void delete_ist(node **head)
{
    if (*head == NULL)
        return;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    return;
}
void delete_last(node **head)
{
    if (*head == NULL)
        return;
    node *curr = *head;
    // traverse till laast node
    while (curr->next != NULL)
        curr = curr->next;

    // when curr is the ist node( when we have only 1 node in the dll)
    if (curr->prev == NULL)
    {
        *head = NULL;
        return;
    }

    // head->10->null
    node *previous_node = curr->prev; // 10
    previous_node->next = NULL;

    free(curr);
}
void delete_after_kthnode(node **headptr)
{
    // head->10
    // 10->20->30->null
    // k=10000
    // 0nodes
    if (*headptr == NULL)
        return;
    int k;
    printf("enter k : ");
    scanf("%d", &k);
    if (k == 0)
    {
        delete_ist(headptr);
        return;
    }
    node *curr = *headptr;
    // k=1
    while (curr != NULL && k--)
        curr = curr->next;

    if (curr == NULL)
    {
        printf("no. of nodes less than k");
        return;
    }
    // head->10
    // 10->20->30->null
    // 10->30
    (curr->prev)->next = curr->next;
    if ((curr->next) != NULL)
        (curr->next)->prev = curr->prev;
    // 10<- 30

    free(curr);
}
void delete_before_kthnode(node **head)
{
    int k;
    printf("enter k : ");
    scanf("%d", &k);
    // k=5
    // 10->20->30->40->50->null
    if (*head == NULL || (*head)->next == NULL || k < 2)
        return;

    node *curr = *head;
    k -= 2;     // 3
    while (k--) // 3 2 1 0
        curr = curr->next;

    // cuurr= 40
    if (curr == *head)
    {
        // head->20
        // null<-20-.30->null
        node *temp = *head;    // 10
        *head = (*head)->next; // new head
        (*head)->prev = NULL;  //
        free(temp);
        return;
    }

    // head->10
    // 10->20->30->nul
    (curr->prev)->next = curr->next;
    if ((curr->next) != NULL)
        (curr->next)->prev = curr->prev;

    free(curr);
}
void delete_kthnode(node **head)
{
    int k;
    printf("enter k :  ");
    scanf("%d", &k);

    if (k == 0)
    {
        printf("invalid k \n");
        return;
    }

    if (k == 1)
    {
        delete_ist(head);
        return;
    }

    node *curr = *head;
    while (curr != NULL && --k)
        curr = curr->next;

    if (curr == NULL)
    {
        printf("k is greater than the size of  the dll \n");
        return;
    }
    // 10->20->null
    // 20->next = null
    //
    (curr->prev)->next = curr->next;
    if ((curr->next) != NULL)
        (curr->next)->prev = curr->prev;

    free(curr);
}
void delete_value(node **head)
{
    int val;
    printf("enter value to delete : ");
    scanf("%d", &val);

    node *curr = *head;
    while (curr != NULL && curr->data != val)
        curr = curr->next;

    if (curr == NULL)
    {
        printf("node with given value not found \n");
        return;
    }
    if (curr == *head)
    {
        delete_ist(head);
        return;
    }
    (curr->prev)->next = curr->next;
    if ((curr->next) != NULL)
        (curr->next)->prev = curr->prev;

    free(curr);
}
void reverse(node **headptr)
{
    // head->10
    // null<-10->null
    node *temp = NULL, *curr = *headptr;
    while (curr != NULL)
    {
        // head->10
        // 20<-10->null
        // 20<->30<->null

        temp = curr->prev;       // null
        curr->prev = curr->next; // 20
        curr->next = temp;       // null

        // int temp = a[i];
        // a[i] = a[i + 1];
        // a[i + 1] = temp;

        curr = curr->prev;
    }
    // head->10->20->30->null
    // 30->20->10->null

    // head->10
    // no nodes
    // 1 node
    if (temp != NULL)
        *headptr = temp->prev; // 30

    return;
}
void main()
{
    node *head = NULL;
    int ch;
    do
    {
        printf("\n1.create \n2.print \n3.insert at head \n4.insert at tail \n5.insert after kth node \n6. insert node after given value node \n7.insert node before kth node \n8. insert node before given value node \n9. delete ist node \n10. delete last node \n11. delete node after kth node \n12. delete node before kth node \n13. delete kth nodeṇ \n14.delete specified value node \n15. reverse the list.  \n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            createList(&head);
            break;
        case 2:
            print(head);
            break;
        case 3:
            insert_head(&head);
            break;
        case 4:
            insert_tail(&head);
            break;
        case 5:
            insert_after_kthnode(&head);
            break;
        case 6:
            insert_after_value(head);
            break;
        case 7:
            insert_before_kthnode(&head);
            break;
        case 8:
            insert_before_value(&head);
            break;
        case 9:
            delete_ist(&head);
            break;
        case 10:
            delete_last(&head);
            break;
        case 11:
            delete_after_kthnode(&head);
            break;
        case 12:
            delete_before_kthnode(&head);
            break;
        case 13:
            delete_kthnode(&head);
            break;
        case 14:
            delete_value(&head);
            break;
        case 15:
            reverse(&head);
            break;
        default:
            break;
        }

    } while (ch >= 1 && ch <= 15);
}