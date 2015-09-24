#include <stdio.h>
#define N 510
 
int vetor[N];
int heap[N];
int n;
int lastPosition = 0;
int result[N];

void swap(int* v1, int* v2)
{
    int swapper = *v1;
    *v1 = *v2;
    *v2 = swapper;
}
 
void insertElement(int v)
{
    heap[lastPosition] = v;
    int i = lastPosition;
    while(heap[(i-1)/2]<heap[i])
    {
        swap(&heap[(i-1)/2], &heap[i]);
        i = (i-1)/2;
    }
    lastPosition++;
}

int removeElement()
{
    lastPosition--;
    int oldRoot = heap[0];
    heap[0] = heap[lastPosition];
    int i = 0;
    
    while(true)
    {
        int child;
        if(2*i+2<lastPosition)
        {
            if(heap[i]<heap[2*i+1] || heap[i]<heap[2*i+2])
            {
                if(heap[2*i+1]>heap[2*i+2])
                {
                    child = 2*i+1;
                }
                else
                {
                    child = 2*i+2;
                }
            }
            else
            {
                break;
            }
        }
        else if(2*i+1<lastPosition)
        {
            if(heap[i]<heap[2*i+1])
            {   
                child = 2*i+1;
            }
            else
            {
                break;
            }
        }
        else
        {
            break;
        }
        swap(&heap[child], &heap[i]);
        i = child;
    }
    
    return oldRoot;
}
 
 
int main()
{
    scanf("%d", &n);
 
    for(int i = 0; i<n; i++)
    {
        scanf("%d", &vetor[i]);
        insertElement(vetor[i]);
    }
     
    for(int i = 0; i<n; i++)
    {
        result[i] = removeElement();
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}