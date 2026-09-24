#include <stdlib.h>
#include <stdio.h>
#include <kv_t.h>

kv_t *kv_init(size_t capacity) {
    kv_t *db = malloc(sizeof(kv_t));

    if (db == NULL) {
        perror("malloc");
        return NULL;
    }

    kv_entry_t *entries = calloc(capacity, capacity * sizeof(kv_entry_t));

    if (entries == NULL) {
        perror("calloc");
        free(db);
        return NULL;
    }

    db->entries = entries;
    db->capacity = capacity;
    db->count = 0;
    return db;
}
