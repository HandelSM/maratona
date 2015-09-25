#include <stdio.h>
#include <vector>
#include <climits>
#define N 510

using namespace std;

typedef struct 
{
	int v;
	int c;
}Edge;

typedef struct
{
	int v;
	int c;
	int pai;
}Path;

vector<Edge> graph[N];
int custos[N];
int pais[N];
Path priorityTree[N];
bool visitados[N];

int n;
int lastPosition = 0;

void swap(Path* v1, Path* v2)
{
    Path swapper = *v1;
    *v1 = *v2;
    *v2 = swapper;
}
 
void insertElement(Path p)
{
    priorityTree[lastPosition] = p;
    int i = lastPosition;
    while(priorityTree[(i-1)/2].c > priorityTree[i].c)
    {
        swap(&priorityTree[(i-1)/2], &priorityTree[i]);
        i = (i-1)/2;
    }
    lastPosition++;
}

Path removeElement()
{
    lastPosition--;
    Path oldRoot = priorityTree[0];
    priorityTree[0] = priorityTree[lastPosition];
    int i = 0;
    
    while(true)
    {
        int child;
        if(2*i+2 < lastPosition)
        {
            if(priorityTree[i].c > priorityTree[2*i+1].c || priorityTree[i].c > priorityTree[2*i+2].c)
            {
                if(priorityTree[2*i+1].c < priorityTree[2*i+2].c)
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
        else if(2*i+1 < lastPosition)
        {
            if(priorityTree[i].c > priorityTree[2*i+1].c)
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
        swap(&priorityTree[child], &priorityTree[i]);
        i = child;
    }
    
    return oldRoot;
}

bool isEmpty()
{
	return lastPosition <= 0;
}

int main()
{
	int nv,ne;
	scanf("%d %d", &nv, &ne);

	for (int i = 0; i < nv; ++i)
	{
		custos[i] = INT_MAX;
		pais[i] = -2;
		visitados[i] = false;
	}

	for (int i = 0; i < ne; ++i)
	{
		int v1, v2, c;
		scanf("%d %d %d", &v1, &v2, &c);
		Edge e1;
		e1.v = v1;
		e1.c = c;
		Edge e2;
		e2.v = v2;
		e2.c = c;
		graph[v1].push_back(e2);
		graph[v2].push_back(e1);
	}
	Path root = {0,0,-1};//v c pai
	insertElement(root);
	
	while( !isEmpty() )
	{
		Path p = removeElement();
		if(visitados[p.v]) continue;
		
		custos[p.v] = p.c;
		pais[p.v] = p.pai;
		visitados[p.v] = true;
		
		for (unsigned int i = 0; i < graph[p.v].size(); i++)
		{
			Path borhood;
			borhood.v = graph[p.v][i].v;
			borhood.c = p.c + graph[p.v][i].c;
			borhood.pai = p.v;
			insertElement(borhood);
		}
	}
	
	for (int i = 0; i < nv; ++i)
	{
		printf("v=%d c= %d pai=%d\n", i, custos[i], pais[i]);
	}

	return 0;
}
