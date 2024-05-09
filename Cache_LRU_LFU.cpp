#include <iostream>
#include <list>
#include <unordered_map>

template <typename T>
class Cache
{
protected:
    size_t capacity;

public:
    virtual T get(T) = 0;
    virtual void put(T, T) = 0;
    virtual ~Cache() {}
};

template <typename T>
class LRU : public Cache<T>
{
private:
    std::list<std::pair<T, T>> _ll;
    std::unordered_map<T, typename std::list<std::pair<T, T>>::iterator> _mp;
    size_t curr_size;

public:
    LRU(size_t cap)
    {
        this->capacity = cap;
        this->curr_size = 0;
    }
    ~LRU() {}
    T get(T key)
    {
        auto it = _mp.find(key);
        if (it != _mp.end())
        {
            _ll.splice(_ll.begin(), _ll, it->second);
            _mp[key] = _ll.begin();
            return it->second->second;
        }
        std::cout << key << " : not found!" << std::endl;
        return T{};
    }
    void put(T key, T value)
    {
        auto it = _mp.find(key);
        if (it == _mp.end())
        {
            std::pair<T, T> new_pair = std::make_pair(key, value);
            if (curr_size < this->capacity) // just add to the front
            {
                _ll.push_front(new_pair);
                _mp[key] = _ll.begin();
                curr_size++;
            }
            else
            { // remove the last node and put the new node at the begining
                std::pair<T, T> pp = _ll.back();
                _ll.pop_back();
                _ll.push_front(new_pair);
                _mp.erase(pp.first);
                _mp[key] = _ll.begin();
            }
        }
        else
        {
            it->second->second = value;
            _ll.splice(_ll.begin(), _ll, it->second);
            _mp[key] = _ll.begin();
        }
    }
};

template <typename T>
class LFU : public Cache<T>
{
private:
    int curr_size;
    int min_frequecy;
    std::unordered_map<int, std::list<std::pair<T, T>>> _llMap;
    std::unordered_map<T, int> _keyFreqMap;
    std::unordered_map<T, typename std::list<std::pair<T, T>>::iterator> _keyLocationMap;

public:
    LFU(size_t cap)
    {
        this->capacity = cap;
        this->curr_size = 0;
        this->min_frequecy = 1;
    }
    ~LFU() {}
    T get(T key)
    {
        auto it = _keyLocationMap.find(key);
        if (it != _keyLocationMap.end())
        {
            int freq = _keyFreqMap[key];
            _llMap[freq + 1].splice(_llMap[freq + 1].begin(), _llMap[freq], it->second);
            if(_llMap[freq].size() == 0 && min_frequecy == freq)
            {
                min_frequecy++;
            }
            _keyLocationMap[key] = _llMap[freq + 1].begin();
            _keyFreqMap[key]++;

            return it->second->second;
        }
        std::cout << key << " : not found!" << std::endl;
        return T{};
    }
    void put(T key, T value)
    {
        auto it = _keyFreqMap.find(key);
        if (it == _keyFreqMap.end()) // key doesnt exist, make a new key value pair
        {
            std::pair<T, T> new_pair = std::make_pair(key, value);
            if (curr_size < this->capacity) // cache has capacity, we can insert
            {
                _keyFreqMap[key]++;
                _llMap[_keyFreqMap[key]].push_front(new_pair);
                _keyLocationMap[key] = _llMap[_keyFreqMap[key]].begin();
                curr_size++;
            }
            else // need to evict a place to put the new key value pair
            {
                std::pair<T, T> last_pair = _llMap[min_frequecy].back();
                _llMap[min_frequecy].pop_back();
                T last_key = last_pair.first;
                _keyFreqMap.erase(last_key);
                _keyLocationMap.erase(last_key);
                _keyFreqMap[key]++;
                _llMap[_keyFreqMap[key]].push_front({key,value});
                _keyLocationMap[key] = _llMap[_keyFreqMap[key]].begin();
            }
            min_frequecy = 1;
        }
        else
        { // key exists, change its value
            auto it2 = _keyLocationMap.find(key);
            int freq = _keyFreqMap[key];
            it2->second->second = value;
            _llMap[freq + 1].splice(_llMap[freq + 1].begin(), _llMap[freq], it2->second);
            if(_llMap[freq].size() == 0 && min_frequecy == freq)
            {
                min_frequecy++;
            }
            _keyLocationMap[key] = _llMap[freq + 1].begin();
            _keyFreqMap[key]++;
        }
    }
};

int main()
{
    /*
    Cache<int> *l1 = new LRU<int>(3);
    l1->put(1, 1);
    l1->put(2, 2);
    std::cout << l1->get(1) << std::endl;
    l1->put(3, 3);
    std::cout << l1->get(2) << std::endl;
    l1->put(4, 4);
    std::cout << l1->get(1) << std::endl;
    std::cout << l1->get(3) << std::endl;
    std::cout << l1->get(4) << std::endl;
    */
    Cache<int> *l2 = new LFU<int>(2);
    l2->put(1, 1);
    l2->put(2, 2);
    std::cout << l2->get(1) << std::endl;
    l2->put(3, 3);
    std::cout << l2->get(2) << std::endl;
    std::cout << l2->get(3) << std::endl;
    l2->put(4, 4);
    std::cout << l2->get(1) << std::endl;
    std::cout << l2->get(3) << std::endl;
    std::cout << l2->get(4) << std::endl;
}
