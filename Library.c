#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int id;
    char title[100];
    char author[50];
    int copies;
    struct Book *next;
};

struct Book *create(int id, char title[], char author[], int copies)
{
    struct Book *newbook = (struct Book *)malloc(sizeof(struct Book));
    newbook->id = id;
    strcpy(newbook->title, title);
    strcpy(newbook->author, author);
    newbook->copies = copies;
    newbook->next = NULL;
    return newbook;
}

// functs for books

void display_all(struct Book *b1)
{
    struct Book *ptr = b1;
    while (ptr != NULL)
    {
        printf("\nBOOK_TITLE: %s", ptr->title);
        printf(", ID::%i", ptr->id);
        ptr = ptr->next;
    }
}

struct Book *add_book(struct Book *b1, int id, char title[], char author[], int copies)
{
    struct Book *ptr = b1;
    struct Book *newnode = create(id, title, author, copies);

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->next = NULL;
    return b1;
}

int search(struct Book *b1, char title[])
{
    struct Book *ptr = b1;
    if (b1 == NULL)
    {
        return 0;
    }
    while (ptr != NULL)
    {
        if (strcmp(ptr->title, title) == 0)
        {
            return 1;
        }
        ptr = ptr->next;
    }
    return 0;
}

struct Book *delete_book(struct Book *b1, char title[])
{
    struct Book *ptr = b1;
    struct Book *q = b1->next;
    if(strcmp(ptr->title,title)==0)
    {
        struct Book *temp=ptr;
        b1=b1->next;
        free(temp);
        return b1;
    }

    while (q!=NULL && strcmp(q->title, title) != 0)
    {
        q = q->next;
        ptr = ptr->next;
    }

    if(q==NULL)
    {
        printf("Book not found");
        return b1;
    }
    ptr->next = q->next;
    free(q);
    return b1;
}
int main()
{

    int n, c, id, r, ch;
    char b_title[50];
    char b_author[100];
    // b1 is head
    struct Book *b1 = create(101, "Don Quixote", "Miguel de Cervantes", 20);
    struct Book *b2 = create(102, "Alice's Adventures in Wonderland", "Lewis Carroll", 15);
    struct Book *b3 = create(103, "Harry Potter", "J.K Rowling", 10);
    struct Book *b4 = create(104, "Wings of Fire: An Autobiography", "A. P. J. Abdul Kalam, Arun Tiwari", 7);

    b1->next = b2;
    b2->next = b3;
    b3->next = b4;
    b4->next = NULL;

    do
    {
        printf("\n---Menu---");
        printf("\n1.Display all Books");
        printf("\n2.Add a book");
        printf("\n3.Search a book");
        printf("\n4.Delete a book");
        printf("\n5.Exit");

        printf("\nEnter choice:");
        scanf("%i", &ch);

        switch (ch)
        {
        case 1:
            printf("\ndisplay all books:");
            display_all(b1);
            break;

        case 2:
            printf("\nAdd a new book:");
            printf("\nEnter details to add new book:");
            printf("\nEnter book id:");
            scanf("%i", &n);
            getchar();
            printf("Enter title:");
            fgets(b_title, sizeof(b_title), stdin); // using fgets to include spaces
            b_title[strcspn(b_title, "\n")] = '\0'; // using cspn-to remone newline which happens due to fgets
            printf("Enter author:");
            fgets(b_author, sizeof(b_author), stdin);
            b_author[strcspn(b_author, "\n")] = '\0';
            printf("Enter copies:");
            scanf("%i", &c);
            getchar();
            b1 = add_book(b1, n, b_title, b_author, c);
            display_all(b1);

            break;

        case 3:
            printf("Search a book:");
            while((getchar()!='\n'));
            printf("\nEnter title of book to be searched:");
            fgets(b_title, sizeof(b_title), stdin);
            b_title[strcspn(b_title, "\n")] = '\0';

            r = search(b1, b_title);
            if (r == 1)
            {
                printf("book found");
            }
            else
            {
                printf("book not found");
            }
            break;

        case 4:
            printf("\nDelete a book:");
            while ((getchar()) != '\n');
            printf("\nwhich book you want to delete by title:");
            fgets(b_title, sizeof(b_title), stdin);
            b_title[strcspn(b_title, "\n")] = '\0';
            printf("\nAfter deleting a book,list of books is:");
            b1 = delete_book(b1, b_title);
            display_all(b1);
            break;
        
        case 5:
            printf("Exit");
            break;

        default:
            printf("enter valid choice");

        }
    }while(ch!=5);

        return 0;
    }
