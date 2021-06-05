#ifndef KEYVALUESTORAGE_KEY_HPP
#define KEYVALUESTORAGE_KEY_HPP

#include <cstddef>
#include <functional>

namespace kvs {

    class Key {
    public:
        Key(const char *key, size_t size);

        Key(const Key& key);

        Key &operator=(const Key &key);

        ~Key();

        const char *getKey() const;

        size_t getSize() const;

        bool operator==(const Key &key) const;

    private:

        char *_key;
        size_t _size;
    };

}

namespace std {
    template<>
    struct hash<kvs::Key> {
        std::size_t operator()(kvs::Key const &s) const noexcept {
            std::size_t h1 = std::hash<const char *>{}(s.getKey());
            return h1;
        }
    };
}

#endif //KEYVALUESTORAGE_KEY_HPP