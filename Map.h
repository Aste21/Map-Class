#include <cstdlib>
#include <iostream>

template <class keyType, class valueType>
class Pair
{
private:
    keyType key;
    valueType value;

public:
    Pair() = default;
    ~Pair() = default;
    Pair(keyType newKey, valueType newValue);
    keyType getKey();
    void setKey(keyType newKey);
    valueType getValue();
    void setValue(valueType newValue);
    valueType *getValuePointer();
    Pair<keyType, valueType> &operator=(Pair<keyType, valueType> newPair);
};

template <class keyType, class valueType>
class Map
{

private:
    Pair<keyType, valueType> *map;
    size_t numberOfPairs;

public:
    Map();
    ~Map();
    Map(const Map<keyType, valueType> &other);
    void add(keyType key, valueType value);
    valueType *find(keyType key);
    void printMap();
    void clear();
    Map<keyType, valueType> &operator=(const Map<keyType, valueType> &other);
    bool isInMap(keyType key);
    template <class k, class v>
    friend std::ostream &operator<<(std::ostream &out, const Map<k, v> &toWrite);
};

class OutOfRangeException
{
};

template <class keyType, class valueType>
Pair<keyType, valueType>::Pair(keyType newKey, valueType newValue)
    : key{newKey}, value{newValue} {}

template <class keyType, class valueType>
keyType Pair<keyType, valueType>::getKey()
{
    return key;
}

template <class keyType, class valueType>
void Pair<keyType, valueType>::setKey(keyType newKey)
{
    key = newKey;
}

template <class keyType, class valueType>
valueType Pair<keyType, valueType>::getValue()
{
    return value;
}

template <class keyType, class valueType>
void Pair<keyType, valueType>::setValue(valueType newValue)
{
    value = newValue;
}

template <class keyType, class valueType>
Pair<keyType, valueType> &Pair<keyType, valueType>::operator=(Pair<keyType, valueType> newPair)
{
    key = newPair.key;
    value = newPair.value;
    return *this;
}

template <class keyType, class valueType>
valueType *Pair<keyType, valueType>::getValuePointer()
{
    return &value;
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class keyType, class valueType>
Map<keyType, valueType>::Map()
    : map{nullptr}, numberOfPairs{0} {}

template <class keyType, class valueType>
Map<keyType, valueType>::Map(const Map<keyType, valueType> &other)
{
    // Allocate new memory
    numberOfPairs = other.numberOfPairs;
    map = new Pair<keyType, valueType>[numberOfPairs];

    // Copy data from other to this
    for (size_t i = 0; i < numberOfPairs; ++i)
    {
        map[i] = other.map[i];
    }
}

template <class keyType, class valueType>
Map<keyType, valueType>::~Map()
{
    if(map != nullptr)
    {
        delete[] map;
    }
    map = nullptr;
    numberOfPairs = 0;
}

template <class keyType, class valueType>
void Map<keyType, valueType>::add(keyType key, valueType value)
{
    if (numberOfPairs == 0)
    {
        map = new Pair<keyType, valueType>[1];
        map[0] = Pair<keyType, valueType>(key, value);
        numberOfPairs += 1;
    }
    else
    {
        if (!isInMap(key))
        {
            size_t insertPosition = 0;
            while (insertPosition < numberOfPairs && key > map[insertPosition].getKey())
            {
                insertPosition++;
            }

            Pair<keyType, valueType> *newMap = new Pair<keyType, valueType>[numberOfPairs + 1];

            for (size_t i = 0; i < insertPosition; ++i)
            {
                newMap[i] = map[i];
            }

            newMap[insertPosition] = Pair<keyType, valueType>(key, value);

            for (size_t i = insertPosition; i < numberOfPairs; ++i)
            {
                newMap[i + 1] = map[i];
            }

            delete[] map;

            map = newMap;

            numberOfPairs += 1;
        }
    }
}

template <class keyType, class valueType>
valueType *Map<keyType, valueType>::find(keyType key)
{
    for (size_t i = 0; i < numberOfPairs; i++)
    {
        if (map[i].getKey() == key)
        {
            return map[i].getValuePointer();
        }
    }
    throw OutOfRangeException(); // this is what .at() in classic Map does if it doesnt find anything
}

template <class keyType, class valueType>
bool Map<keyType, valueType>::isInMap(keyType key)
{
    for (size_t i = 0; i < numberOfPairs; i++)
    {
        if (map[i].getKey() == key)
        {
            return true;
        }
    }
    return false;
}

template <class keyType, class valueType>
void Map<keyType, valueType>::printMap()
{
    for (size_t i = 0; i < numberOfPairs; i++)
    {
        std::cout << map[i].getKey() << "    " << map[i].getValue() << std::endl;
    }
}

template <class keyType, class valueType>
std::ostream &operator<<(std::ostream &out, const Map<keyType, valueType> &toWrite)
{
    for (size_t i = 0; i < toWrite.numberOfPairs; i++)
    {
        out << toWrite.map[i].getKey() << "    " << toWrite.map[i].getValue() << std::endl;
    }
    return out;
}

template <class keyType, class valueType>
void Map<keyType, valueType>::clear()
{
    if (map != nullptr)
    {
        delete[] map;
    }
    map = nullptr;
    numberOfPairs = 0;
}

template <class keyType, class valueType>
Map<keyType, valueType> &Map<keyType, valueType>::operator=(const Map<keyType, valueType> &other)
{
    // Check for self-assignment
    if (this == &other)
    {
        return *this;
    }

    // Clear existing data
    clear();

    // Allocate new memory
    numberOfPairs = other.numberOfPairs;
    map = new Pair<keyType, valueType>[numberOfPairs];

    // Copy data from other to this
    for (size_t i = 0; i < numberOfPairs; ++i)
    {
        map[i] = other.map[i];
    }

    return *this;
}
