#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct book
{
	char title[50];
	char author[30];
};

struct book addname();
void list_func(book);

int main()
{
	struct book book1,book2;

	book1=addname();
	book2=addname();

	printf("\n\nBooks available");
	list_func(book1);
	list_func(book2);

   getch();
}
struct book addname()
{
	struct book buku;
	printf("\n\nEnter book's title: ");
	gets(buku.title);
	printf("\nEnter author's name: ");
	gets(buku.author);
	return (buku);
}

void list_func(book list)
{
	printf("\n\nBook's Title: %s",list.title);
	printf("\nAuthor: %s",list.author);
   return;
}

