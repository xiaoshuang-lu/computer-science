# include <cstdint>

# include <list>
# include <unordered_map>

template<typename KEY_TYPE, typename VALUE_TYPE>
class entry
{
    public:
        entry(KEY_TYPE const & key, VALUE_TYPE const & value)
        :
        key(key), value(value)
        {
        }

        KEY_TYPE key;
        VALUE_TYPE value;
};

template<typename KEY_TYPE, typename VALUE_TYPE>
class lru_cache
{
    private:
        typedef typename std::list<entry<KEY_TYPE, VALUE_TYPE>>::iterator list_iterator;
        typedef typename std::unordered_map<KEY_TYPE, list_iterator>::iterator unordered_map_iterator;

    public:
        lru_cache(intmax_t capacity)
        {
            this->capacity = capacity;
        }

        VALUE_TYPE & read(KEY_TYPE const & key)
        {
            unordered_map_iterator iterator = this->unordered_map.find(key);

            if (iterator != this->unordered_map.end())
            {
                entry<KEY_TYPE, VALUE_TYPE> entry(key, iterator->second->value);

                this->list.erase(iterator->second);

                this->list.push_front(entry);

                iterator->second = this->list.begin();

                return iterator->second->value;
            }
            else
            {
                throw intmax_t(0);
            }
        }

        void write(KEY_TYPE const & key, VALUE_TYPE const & value)
        {
            unordered_map_iterator iterator = this->unordered_map.find(key);

            entry<KEY_TYPE, VALUE_TYPE> entry(key, value);

            if (iterator != this->unordered_map.end())
            {
                this->list.erase(iterator->second);

                this->list.push_front(entry);

                iterator->second = this->list.begin();
            }
            else
            {
                if (this->list.size() == this->capacity)
                {
                    this->unordered_map.erase(this->list.back().key);

                    this->list.pop_back();
                }

                this->list.push_front(entry);

                this->unordered_map[key] = this->list.begin();
            }
        }

    private:
        std::list<entry<KEY_TYPE, VALUE_TYPE>> list;
        std::unordered_map<KEY_TYPE, list_iterator> unordered_map;
        intmax_t capacity;
};

# include <cinttypes>
# include <string>

int main()
{
    lru_cache<intmax_t, std::string> cache(8);

    return 0;
}
