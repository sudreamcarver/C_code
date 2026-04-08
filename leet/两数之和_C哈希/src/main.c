#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 自引用
typedef struct HashNode
{
    int key;
    int val;
    struct HashNode *next;
} HashNode;

// 链表的表
typedef struct
{
    HashNode **table;
    int size;
} HashTable;

HashTable *
CreatHashTable (int size)
{
    HashTable *ht = (HashTable *)malloc (sizeof (HashTable));
    ht->size = size;
    ht->table = (HashNode **)calloc (size, sizeof (HashNode *));
    return ht;
}

int
Hash (int key, int size)
{
    return (key % size + size) % size;
    ;
}

void
Insert (HashTable *ht, int key, int val)
{
    int index = Hash (key, ht->size);
    HashNode *newNode = (HashNode *)malloc (sizeof (HashNode));
    newNode->key = key;
    newNode->val = val;
    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

int
find (HashTable *ht, int key, int *value)
{
    int index = Hash (key, ht->size);
    HashNode *cur = ht->table[index];
    while (cur)
        {
            if (cur->key == key)
                {
                    *value = cur->val;
                    return 1;
                }
            cur = cur->next;
        }
    return 0;
}

int *
twoSum (int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *res = (int *)malloc (2 * sizeof (int));

    HashTable *ht = CreatHashTable (numsSize);

    for (int i = 0; i < numsSize; i++)
        {
            int complement = target - nums[i];
            int val;

            if (find (ht, complement, &val))
                {
                    res[0] = val;
                    res[1] = i;
                    free (ht);
                    return res;
                }
            Insert (ht, nums[i], i);
        }
    free (ht);
    return NULL;
}
