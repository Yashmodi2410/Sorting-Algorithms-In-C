#include <stdio.h>
#include <stdlib.h>
#include<time.h>

double tc;
time_t start,end;

struct btreenode
{
    struct btreenode *leftchild ;
    int data ;
    struct btreenode *rightchild ;
} ;

void insert ( struct btreenode **, int ) ;
void inorder ( struct btreenode * ) ;

void main( )
{
    struct btreenode *bt ;
    int arr[10] = { 1, 10, 2, 3, 4, 1, 2, 100,23, 2} ;
    int i ;

    bt = NULL ;

    start = clock();

    for ( i = 0 ; i <= 9 ; i++ )
        insert ( &bt, arr[i] ) ;

    printf ( "In-order traversal of binary tree:\n" ) ;
    inorder ( bt ) ;

    end = clock();

     tc=((double)(end-start)/CLOCKS_PER_SEC);
    printf("\ntime efficiency of Binarytree is %f",tc);
}

void insert ( struct btreenode **sr, int num )
{
    if ( *sr == NULL )
    {
        *sr = malloc ( sizeof ( struct btreenode ) ) ;

        ( *sr ) -> leftchild = NULL ;
        ( *sr ) -> data = num ;
        ( *sr ) -> rightchild = NULL ;
    }
    else
    {
        if ( num < ( *sr ) -> data )
            insert ( &( ( *sr ) -> leftchild ), num ) ;
        else
            insert ( &( ( *sr ) -> rightchild ), num ) ;
    }
}

void inorder ( struct btreenode *sr )
{
    if ( sr != NULL )
    {
        inorder ( sr -> leftchild ) ;
        printf ( "%d ", sr -> data ) ;
        inorder ( sr -> rightchild ) ;
    }
}
