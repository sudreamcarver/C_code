#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 自引用
// 定义哈希表节点结构：数字+下标
typedef struct HashNode
{
    int key;
    int val;
    struct HashNode *next;
} HashNode;

// 定义哈希表结构，节点数组
typedef struct
{
    HashNode **table;
    int size;
} HashTable;

HashTable *
CreatHashTable (int size)
{
    // 节点数组的地址
    HashTable *ht = (HashTable *)malloc (sizeof (HashTable));
    ht->size = size;
    // 申请内存
    ht->table = (HashNode **)calloc (size, sizeof (HashNode *));
    return ht;
}

// 将数字映射为数组下标
int
Hash (int key, int size)
{
    // 返回数组下标
    return (key % size + size) % size;
}

void
Insert (HashTable *ht, int key, int val)
{
    int index = Hash (key, ht->size);
    HashNode *newNode = (HashNode *)malloc (sizeof (HashNode));
    newNode->key = key;
    newNode->val = val;
    // table[index]是哈希表内节点的地址，把新节点的next指针指向表内节点
    newNode->next = ht->table[index];
    // 把新节点挂到表的最前面
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
