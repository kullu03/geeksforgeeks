#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
 
// Alphabet size (# of symbols)
#define ALPHABET_SIZE (26)
// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

// structure of a trie node 
struct trieNode{
bool isLeaf;
trieNode *children[ALPHABET_SIZE];
};

// structure of a trie
struct trie{
trieNode *root;
int count;
};

trieNode * getNode()
{
trieNode *tnode  = (trieNode *)malloc(sizeof(struct trieNode ));
if(tnode)
{
tnode->isLeaf = false;
int i;
for(int i = 0; i < ALPHABET_SIZE;i++)
tnode->children[i] = NULL;
}
return tnode;
}

// initialize the trie

void initialize(struct trie * node)
{
node->root = NULL;
node->count = 0;
}

void insert(struct trie *node,char key [])
{
int len = strlen(key);
int index;
struct trieNode *p;
node->count++;
p = node->root;

for(int i = 0 ; i <len; i++)
{

index  = CHAR_TO_INDEX(key[i]);
if(!p->children[i])
{
p->children[i] = getNode();
}

p = p->children[i];
}
p->isLeaf = true;
}
int search(trie * node,char key[])
{
int level;
int len = strlen(key);
int index;
trieNode *p;
p = node->root;
 
    for( level = 0; level < len; level++ )
    {
        index = CHAR_TO_INDEX(key[level]);
 
        if( !p->children[index] )
        {
            return 0;
        }
 
        p = p->children[index];
    }
 
    return (0 != p && p->isLeaf);


}

// Driver
int main()
{
    // Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    struct trie t;
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    initialize(&t);
 
    // Construct trie
    for(int i = 0; i < ARRAY_SIZE(keys); i++)
    {
        insert(&t, keys[i]);
    }
 
    // Search for different keys
    printf("%s --- %s\n", "the", output[search(&t, "the")] );
  //  printf("%s --- %s\n", "these", output[search(&trie, "these")] );
    //printf("%s --- %s\n", "their", output[search(&trie, "their")] );
    //printf("%s --- %s\n", "thaw", output[search(&trie, "thaw")] );
return 0; 
} 
