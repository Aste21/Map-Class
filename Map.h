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
};

template <class keyType, class valueType> class Map
{
    private:
        Pair* map;
    public:
        
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

