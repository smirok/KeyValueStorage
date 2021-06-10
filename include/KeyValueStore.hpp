#ifndef KEYVALUESTORAGE_KEYVALUESTORE_HPP
#define KEYVALUESTORAGE_KEYVALUESTORE_HPP

#include <optional>
#include <storage/Trie.hpp>
#include "model/KeyValue.hpp"
#include "storage/BloomFilter.hpp"
#include "storage/Log.hpp"
#include "storage/Storage.hpp"

namespace kvs {
    class KeyValueStore {
    public:
        KeyValueStore(BloomFilter &bloomFilter,
                      Log &log,
                      Trie &trie,
                      Storage<Record> &_recordStorage);

        void add(const KeyValue &);

        [[nodiscard]] std::optional<KeyValue> get(const Key &) const;

        void del(const Key &);

        void clear();

    private:

        void rebuild();

        BloomFilter &_bloomFilter;

        Log &_log;

        Trie &_trie;

        Storage<Record> &_recordStorage;
    };
}

#endif //KEYVALUESTORAGE_KEYVALUESTORE_HPP