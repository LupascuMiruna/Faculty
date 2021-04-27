#include <bits/stdc++.h>
#include <malloc.h>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

//https://www.geeksforgeeks.org/fibonacci-heap-insertion-and-union/
/*
1) Find Max:      Θ(1)     [Same as both Binary and Binomial]
2) Delete Max:    O(Log n) [Θ(Log n) in both Binary and Binomial]
3) Insert:        Θ(1)     [Θ(Log n) in Binary and Θ(1) in Binomial]
4) Decrease-Key:  Θ(1)     [Θ(Log n) in both Binary and Binomial]
5) Merge:         Θ(1)     [Θ(m Log n) or Θ(m+n) in Binary and Θ(Log n) in Binomial]
*/

//https://infoarena.ro/problema/mergeheap + BUILD în O(n) din n elemente!
//Insert, delete min, build, merge


struct nod
{
    nod* parent;
    nod* child;
    nod* left;
    nod* right;
    int val;
    int degree;
};

///initilize max
///double linked list, so if we know the maxi, we can access any node in the tree
struct nod* maxi = 0;

///nr nodes in heap
int sz_heap;

///insertion
void insertion(int val)
{
    ///create a new node

    //http://www.cplusplus.com/reference/cstdlib/malloc/
    //locates a block of size bytes of memory, returning a pointer to the beginning of the block.
    //The content of the newly allocated block of memory is not initialized, remaining with indeterminate values.
    nod* newn = (nod*)malloc(sizeof(nod));

    ///suppose it's the only one, it points at itself
    newn->val = val;
    newn->degree = 0;
    newn->parent = 0; //no childs
    newn->child = 0; //no parent
    newn->left = newn;
    newn->right = newn;

    if (maxi != 0)
    {
        ///recreate the links
        ///INSERT NEAR THE MINI
        (maxi->left)->right = newn;
        newn->right = maxi;
        newn->left = maxi->left;
        maxi->left = newn;

        if (val > maxi->val)
            maxi = newn;
    }
    else
    {
       maxi = newn;
    }
    sz_heap++;

}

///kept sorted
void display(nod* maxi)
{
    nod *p = maxi;
    if(p == 0)
    {
        fout << "The heap is empty";
    }
    else
        {
            fout << "The root nodes of the heap: \n";
            do
            {
                fout << p->val;
                p = p->right;
                if(p != maxi)///we still have nodes
                {
                    fout << "-->";
                }
            }while(p != maxi && p->right != 0);

        }
}

///linking thea heap nodes in parent-child realtionship
///P1 > P2
void fibonacci_link(nod *p2, nod *p1)
{
    ///extract them from the list --> we have to remake the link in:  o-o-p1-o-o-p2-o
    ///--> o-o--o-o--o

    (p2->right)->left = p2->left;
    (p2->left)->right = p2->right;

    if(p1->right == p1)
        maxi = p1;
    p2->left = p2;
    p2->right = p2;///points to itself
    p2->parent = p1;

    ///      p1
    ///     / |
    ///    p2 o
    ///    |
    ///    o

    if(p1 ->child == NULL)
       p1->child = p2;
    p2->right = p1->child;      ///insert to the right of the child
    p2->left = (p1->child)->left;
    ((p1->child)->left)->right = p2;
    (p1->child)->left = p2;

    if(p2->val > (p1->child)->val)  ///keep pointer to the maxim child
        p1->child = p2;
    p1->degree++;

}
///consolodate trees so that no two toots have the same degree
void consolidate()
{
    int temp1;
    float temp2 = (log(sz_heap)) / (log(2)); /// lg of the array where we keep the degrees
    int temp3 = temp2;
    nod* arr[temp3];
    int i;

    for(i = 0; i <= temp3; ++i)
        arr[i] = NULL;  ///we don't have any tree yet
    nod *p1 = maxi;
    nod *p2, *p3, *p4 = p1;

    do{                 ///for each node we union them till we still have trees with the same degree
        p4 = p4->right; ///start the union from the right
        temp1 = p1->degree;
        while(arr[temp1] != NULL)       ///search for trees with same degree
        {
            p2 = arr[temp1];
            if(p1->val < p2->val)       ///swap them            THE ORDER DESIRED: P1 > P2
            {
                p3 = p1;
                p1 = p2;
                p2 = p3;
            }

            if(p2 == maxi)          ///?????????????????????????
                maxi = p1;

            fibonacci_link(p2, p1);     ///union the trees

            if(p1->right == p1)
                maxi = p1;
            arr[temp1] = NULL;  ///there is not any tree with this degree anymore
            temp1++;    ///increase the degree
        }

        arr[temp1] = p1;       ///keep at that degree the new resulted tree
        p1 = p1->right;        ///move to the next tree;
    }while(p1 != maxi);         /// we still have trees that we haven't union them yet
    maxi = NULL;
    for(i = 0; i <= temp3; ++i)
    {
        if(arr[i] != NULL)      ///we have a tree with that degree
        {
            arr[i]->left = arr[i];      ///remake the duble liked list
            arr[i]->right = arr[i];     ///if it's the only root

            if(maxi != NULL)        ///insert the tree near the maxi
            {
                (maxi->left)->right = arr[i];
                arr[i]->right = maxi;
                arr[i]->left = maxi->left;
                maxi->left = arr[i];

                if(arr[i]->val > maxi->val)     ///we know that the max is in the root of the tree
                    maxi = arr[i];
            }
            else
            {
                maxi = arr[i];
            }

            if(maxi == NULL || arr[i]->val > maxi->val)     ///the new max
                maxi = arr[i];
        }
    }
}

void extract_max()
{
    if(maxi == NULL)
        fout << "The heap is empty\n";
    else
    {
        fout << maxi->val << " ";
        nod *temp = maxi;
        nod *p;
        p = temp;
        nod* x = NULL;
        if(temp -> child != NULL)
        {
            x = temp->child;
            do          ///remake the links
            {
                p = x->right;   ///keep the next node for which we will apply the algh
                (maxi->left)->right = x;
                x->right = maxi;    ///duble linked list to the left element
                x->left = maxi->left;
                maxi->left = x;
                if(x->val > maxi->val)
                    maxi = x;
                x->parent = NULL; ///it s on the firt floor
                x = p;
            }while(p != temp ->child); ///till we still have to update nodes on that nivel
        }
        (temp->left)->right = temp->right;///remake the link in order to delete the "maxi"
        (temp->right)->left = temp->left;
        maxi = temp->right;
        if(temp == temp->right && temp->child == 0) ///no more nodes in the heap
            maxi = NULL;
        else
        {
            maxi = temp->right;     ///the new maxi
            consolidate();      ///update the degrees

        }
        sz_heap--;
    }
}
int main()
{
    sz_heap = 7;
    insertion(4);
    insertion(3);
    insertion(7);
    insertion(10);
    insertion(5);
    insertion(2);
    insertion(10);

    //display(maxi);
    extract_max();
    extract_max();
    extract_max();
    extract_max();
    return 0;
}
