// node of queue

struct QNode {
int pageNumber;
struct QNode *front;
struct QNode *rear;
};


//structure for cache memory 
struct cache{
int capacity;
int filled;
struct QNode * front;
struct QNode * rear;
};

struct mainMemory{
int mainCapacity;
struct QNode* *array;
};

// create a Queue Node
struct QNode * createQueueNode(int pNumber)
{
struct QNode * temp = (struct QNode *)malloc(sizeof(struct QNode));
temp->pageNumber = pNumber;
temp->front = NULL;
temp->rear = NULL;
return temp;
}

// initialize cache memory

struct cache * initializeCache(int capacity)
{

struct cache * cm = (struct cache *)malloc(sizeof(struct cache));
cm->capacity = capacity;
cm->filled = 0;
cm->front = NULL;
cm->rear = NULL;
return cm;
}

// initialize mainMemory

struct mainMemory * initializemainMemory(int capcaity)
{

struct mainMemory *mm = (struct mainMemory *)malloc (sizeof(struct mainMemory));

mm->mainCapacity = capacity;
mm->array = (QNode **) malloc( mm->mainCapacity * sizeof( QNode* ) );

// initialize main memory entries by NULL
for(int i = 0; i < mm->mainCapcity; i ++)
{
mm->array[i] = NULL;
}
return mm;
}

// check if cache  is full

int isCacheFull(struct cache *cm)
{

return cm->capacity == cm->filled;
}



void enQueue(struct cache cacheMemory, struct mainMemory Main,int page)
{

// create a Qnode with corresponding page
struct QNode * node = createQueueNode(page);

// Now check if  cache memory is full

if(isCahceFull(cacheMemory))
{

// now remove page from mainmemory also

Main->array[page] = NULL;

// now remove front page from cache that is least recenty used
dequeue(cacheMemory);

}




}



