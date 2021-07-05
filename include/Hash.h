#ifndef HASH_H
#define HASH_H

struct pair_
{
    int key;
    int data;

    pair_()
    : key(0), data(0)
    {}
    pair_(int key, int data)
    : key(key), data(data)
    {}
    void print()
    {
        std::cout << "Key: " << key << " Value: " << data << std::endl;
    }
};

class Hash
{
private:
    const int n = 10;
    const int step = 3;
    pair_* h = new pair_[n];

private:
    int hashing(int key);

public:
    void push(pair_ p);
    void pop(int k);
    void print();
    pair_ look(int key);
    Hash()
    {
        for(int i = 0; i < n; i++)
        {
            pair_ k;
            h[i] = k;
        }
    }

};
pair_ Hash::look(int key)
{
    int i = hashing(key);
    for(int k = 0; k < n; k++)
        if(h[i].key == key)
            return h[i];
        else
            i += step;
    return pair_();
}
int Hash::hashing(int key)
{
    return key % n;
}
void Hash::push(pair_ p)
{
    int k = 1;
    int i = hashing(p.key);
    while(h[i].key != 0 && k<n)
    {
        i = (i + step) % n;
    }
    if(k<n)
        h[i] = p;
}
void Hash::pop(int k)
{

}
void Hash::print()
{
    for(int i = 0; i < n; i++)
        h[i].print();
}
#endif // HASH_H
