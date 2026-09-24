#include <stdlib.h>
#include <stdio.h>
#include <kv.h>

kv_t *kv_init(size_t capacity) {
    if (capacity == 0) return NULL;

    kv_t *table = malloc(sizeof(kv_t));

    if (table == NULL) {
        perror("malloc");
        return NULL;
    }

    kv_entry_t *entries = calloc(capacity, capacity * sizeof(kv_entry_t));

    if (entries == NULL) {
        perror("calloc");
        free(table);
        return NULL;
    }

    table->entries = entries;
    table->capacity = capacity;
    table->count = 0;
    return table;
}
