#include <string>
using namespace std;

typedef struct word
{
	string key; /* key with which the specified value is to be associated */
	string value; /* value to be associated with the specified key */
} word;

class Dict{
private:
	int size;
	word dict[5000];

public:
	Dict(): size(0) {}
	void printDict();
	/**
	 * Add a word to your dictionary
	 * If the dictionary previously contained a mapping for the key, the old
	 * value is replaced.
	 *
	 * @param word a struct which contains the key and value
	 * @return whether it is inserted successfully
	 */
	bool add(const word &w);
	/**
	 * Returns the value to which the specified key is mapped,
	 * or "" if this map contains no mapping for the key.
	 *
	 * More formally, if this map contains a mapping from a key to 
	 * a value such that key=="" ? k=="" : key.equals(k),
	 * then this method returns value; otherwise it returns "" 
	 * (There can be at most one such mapping.)
	 *
	 * @return A return value of "" does not necessarily indicate 
	 *         that the map contains no mapping for the key; it's also
	 *         possible that the map explicitly maps the key to "".
	 *
	 * @see bool add(const word &w)
	 */
	string search(const string &key);
	 /**
	 * Removes the mapping for the specified key from this map if present.
	 *
	 * @param  key key whose mapping is to be removed from the map
	 * @return the previous value associated with key or
	 *         "" if there was no mapping for key. (A "" return can 
	 *         also indicate that the map previously associated "" with key.)
	 */
	string remove(const string &key);
	/**
	 * Update an already existed word in your dictionary
	 * NOTE: Do not insert the word to your dictionary if there was no 
	 * such key
	 * 
	 * @param word a struct which contains the key and value
	 * @return the previous value associated with key or "" if 
	 *         there was no such key in your dictionary
	 */
	string update(const word &w);
};