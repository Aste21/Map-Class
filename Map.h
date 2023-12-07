#include <cstdlib>

template <class keyType, class valueType> class Pair{
    private:
        keyType key;
        valueType value;
    public:
        Pair() = default;
        Pair(keyType newKey, valueType newValue);
        keyType getKey();
        void setKey(keyType newKey);
        valueType getValue();
        void setValue(valueType newValue);
        Pair<keyType, valueType> &operator=(Pair<keyType, valueType> newPair);
};

template <class keyType, class valueType> class Map
{
    private:
        Pair<keyType, valueType>* map;
        size_t numberOfPairs;
    public:
        Map();
        void add(keyType key, valueType value);
        valueType find(keyType key);
};

template<class keyType, class valueType> Pair<keyType, valueType>::Pair(keyType newKey, valueType newValue)
    : key{newKey}, value{newValue} {}


template<class keyType, class valueType> keyType Pair<keyType, valueType>::getKey()
{
    return key;
}

template<class keyType, class valueType> void Pair<keyType, valueType>::setKey(keyType newKey)
{
    key = newKey;
}

template<class keyType, class valueType> valueType Pair<keyType, valueType>::getValue()
{
    return value;
}

template<class keyType, class valueType> void Pair<keyType, valueType>::setValue(valueType newValue)
{
    value = newValue;
}

template<class keyType, class valueType> Pair<keyType, valueType> &Pair<keyType, valueType>::operator=(Pair<keyType, valueType> newPair)
{
    key = newPair.key;
    value = newPair.value;
    return *this;
}

////////////////////////////////////////////////////////////////////////////////////////////

template <class keyType, class valueType> Map<keyType, valueType>::Map()
    : map{NULL}, numberOfPairs{0} {}

template <class keyType, class valueType> void Map<keyType, valueType>::add(keyType key, valueType value)
{
    if(numberOfPairs == 0)
    {
        map = new Pair<keyType, valueType>;
        map[0] = Pair(key, value);
        numberOfPairs += 1;
    }
    else
    {
        map = new Pair<keyType, valueType>;
        map[numberOfPairs] = Pair(key, value);
        numberOfPairs += 1;
    }
}

template <class keyType, class valueType> valueType Map<keyType, valueType>::find(keyType key)
{
    for(size_t i = 0; i < numberOfPairs; i++)
    {
        if(map[i].getKey() == key)
        {
            return map[i].getValue();
        }
    }
    return 0;
}